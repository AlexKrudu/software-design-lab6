#pragma once

#include "token.h"

class Brace : public Token {
public:
    enum class BraceType{
        BRACE_OPEN,
        BRACE_CLOSE
    };

    explicit Brace(BraceType type) : type_(type){};

    void accept(TokenVisitor& visitor) override;

    [[nodiscard]] std::string toString() const override;

    BraceType getBracketType(){
        return type_;
    }

private:
    BraceType type_;

};