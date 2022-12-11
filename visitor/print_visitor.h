#pragma once

#include "token_visitor.h"

class PrintVisitor : public TokenVisitor {

    void visit(Operation *token) override {
        out_res_ += token->toString() + " ";
    }

    void visit(Brace *token) override {
        out_res_ += token->toString() + " ";
    }

    void visit(NumberToken *token) override {
        out_res_ += token->toString() + " ";
    };

public:
    std::string getRes() {
        return out_res_;
    }

private:
    std::string out_res_;
};