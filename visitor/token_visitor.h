#pragma once

#include "../token/number_token.h"
#include "../token/brace.h"
#include "../token/operation.h"


class TokenVisitor{
public:
    virtual void visit(Operation* token) = 0;

    virtual void visit(Brace* token) = 0;

    virtual void visit(NumberToken* token) = 0;
};