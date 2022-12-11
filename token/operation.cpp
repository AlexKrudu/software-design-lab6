#include "operation.h"

#include "../visitor/token_visitor.h"

void Operation::accept(TokenVisitor &visitor) {
    visitor.visit(this);
}