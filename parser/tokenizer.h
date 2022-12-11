#pragma once

#include <string>
#include <utility>
#include <optional>
#include <vector>

#include "../token/token.h"
#include "../token/add.h"
#include "../token/subtract.h"
#include "../token/multiply.h"
#include "../token/divide.h"
#include "../token/brace.h"
#include "../token/number_token.h"


class Tokenizer {
    enum class State {
        START,
        NUMBER,
        ERROR,
        END
    };

    Token *nextToken() {
        switch (state_) {
            case State::START: {
                auto symbol = getNext();
                auto token = tryMapSymbolToToken(symbol);
                if (token.has_value())
                    return *token;
                if (symbol == 0) {
                    state_ = State::END;
                    return nextToken();
                }
                if (std::isspace(symbol)) {
                    return nextToken();
                }
                if (std::isdigit(symbol)) {
                    state_ = State::NUMBER;
                    return nextToken();
                }
                state_ = State::ERROR;
                return nextToken();
            }
            case State::NUMBER: {
                int cur_num = input_[cur_pos] - '0';
                while (std::isdigit(getNext())) {
                    cur_num = cur_num * 10 + input_[cur_pos] - '0';
                }
                cur_pos--;
                state_ = State::START;
                return new NumberToken{cur_num};
            }
            case State::ERROR: {
                throw std::logic_error{"Parsing error"};
            }

            case State::END: {
                return nullptr;
            }

            default:
                throw std::runtime_error{"Unexpected state"};
        }
    }

    char getNext() {
        if (cur_pos + 1 < input_.size()){
            return input_[++cur_pos];
        }
        cur_pos = input_.size();
        return 0;
    }

    static std::optional<Token *> tryMapSymbolToToken(char symbol) {
        switch (symbol) {
            case '(':
                return new Brace(Brace::BraceType::BRACE_OPEN);
            case ')':
                return new Brace(Brace::BraceType::BRACE_CLOSE);
            case '+':
                return new Add{};
            case '-':
                return new Subtract{};
            case '*':
                return new Multiply{};
            case '/':
                return new Divide{};
            default:
                return std::nullopt;
        }
    }


public:
    explicit Tokenizer(std::string &&input) : input_(std::move(input)) {}

    std::vector<Token *> tokenize() {
        std::vector<Token *> res;
        while (true) {
            auto token = nextToken();
            if (token != nullptr) {
                res.push_back(token);
                continue;
            }
            return res;
        }
    }

private:
    std::string input_;
    std::size_t cur_pos = -1;
    State state_ = State::START;
};