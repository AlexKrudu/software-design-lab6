#include "number_token.h"

#include "../visitor/token_visitor.h"

void NumberToken::accept(TokenVisitor &visitor) {
    visitor.visit(this);
}