#pragma once

#include <memory>

class TokenVisitor;

class Token{

public:
    [[nodiscard]] virtual std::string toString() const = 0;

    virtual void accept(TokenVisitor& visitor) = 0;
};