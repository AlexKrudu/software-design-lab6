#pragma once

#include <string>

#include "token.h"

class Operation : public Token{

    void accept(TokenVisitor& visitor) override;

public:
    virtual int getPriority() = 0;

    virtual int doCalc(int lhs, int rhs) = 0;
};