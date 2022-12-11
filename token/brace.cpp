#include "brace.h"

#include "../visitor/token_visitor.h"


void Brace::accept(TokenVisitor &visitor) {
    visitor.visit(this);
}

std::string Brace::toString() const {
    if (type_ == BraceType::BRACE_OPEN) {
        return "(";
    } else {
        return ")";
    }
}