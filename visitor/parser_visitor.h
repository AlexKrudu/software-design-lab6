#pragma once

#include <deque>
#include <vector>

#include "token_visitor.h"

class ParserVisitor : public TokenVisitor {
private:
    void visit(Operation *token) override {
        while (!calc_stack_.empty()) {
            auto maybe_top_operation = dynamic_cast<Operation *>(calc_stack_.front());
            if (maybe_top_operation == nullptr || maybe_top_operation->getPriority() > token->getPriority()) {
                break;
            }
            out_tokens_.push_back(calc_stack_.front());
            calc_stack_.pop_front();
        }
        calc_stack_.push_front(token);
    };

    void visit(Brace *token) override {
        if (token->getBracketType() == Brace::BraceType::BRACE_OPEN) {
            calc_stack_.push_front(token);
            return;
        }

        bool met_open_bracket = false;
        while (!calc_stack_.empty()) {
            auto val = calc_stack_.front();
            calc_stack_.pop_front();
            auto maybe_brace = dynamic_cast<Brace *>(val);
            if (maybe_brace != nullptr && maybe_brace->getBracketType() == Brace::BraceType::BRACE_OPEN) {
                met_open_bracket = true;
                break;
            }
            out_tokens_.push_back(val);
        }

        if (!met_open_bracket) {
            throw std::logic_error{"Invalid token sequence"};
        }

    };

    void visit(NumberToken *token) override {
        out_tokens_.push_back(token);
    };

public:
    std::vector<Token *> getParsedTokens() {
        while (!calc_stack_.empty()) {
            auto maybe_brace = dynamic_cast<Brace *>(calc_stack_.front());
            if (maybe_brace != nullptr && maybe_brace->getBracketType() == Brace::BraceType::BRACE_OPEN) {
                throw std::logic_error("Incorrect brackets");
            }
            out_tokens_.push_back(calc_stack_.front());
            calc_stack_.pop_front();
        }
        return out_tokens_;
    }

private:
    std::vector<Token *> out_tokens_;
    std::deque<Token *> calc_stack_;
};