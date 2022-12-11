#pragma once

#include <string>

#include "token.h"


class NumberToken : public Token{
public:
    explicit NumberToken(int val) : value_(val) {};

    void accept(TokenVisitor& visitor) override;

    [[nodiscard]] int getValue() const{
        return value_;
    }

    [[nodiscard]] std::string toString() const override{
        return std::to_string(value_);
    }

private:
    int value_;
};
