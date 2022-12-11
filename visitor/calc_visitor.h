#pragma once

#include <deque>

#include "token_visitor.h"

class CalcVisitor : public TokenVisitor {
private:
    void visit(Operation *token) override {
        if (calc_stack_.size() < 2) {
            throw std::logic_error{"Not enough operands for binary operation"};
        }
        int rhs = calc_stack_.front();
        calc_stack_.pop_front();
        int lhs = calc_stack_.front();
        calc_stack_.pop_front();
        calc_stack_.push_front(token->doCalc(lhs, rhs));

    }

    void visit(Brace *token) override {
        throw std::logic_error{"Met unexpected bracket"};
    }

    void visit(NumberToken *token) override {
        calc_stack_.push_front(token->getValue());
    }

public:
    int getResult() {
        if (calc_stack_.size() != 1) {
            throw std::logic_error{"Wrong number of operands"};
        }
        int res = calc_stack_.front();
        calc_stack_.pop_front();
        return res;
    }

private:
    std::deque<int> calc_stack_;
};