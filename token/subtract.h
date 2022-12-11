#pragma once

#include "operation.h"

class Subtract : public Operation{
    int getPriority() override{
        return 1;
    }

    int doCalc(int lhs, int rhs) override{
        return lhs - rhs;
    }

    [[nodiscard]] std::string toString() const override{
        return "-";
    }
};