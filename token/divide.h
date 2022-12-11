#pragma once

#include "operation.h"

class Divide : public Operation{
    int getPriority() override{
        return 0;
    }

    int doCalc(int lhs, int rhs) override{
        return lhs / rhs;
    }

    [[nodiscard]] std::string toString() const override{
        return "/";
    }
};