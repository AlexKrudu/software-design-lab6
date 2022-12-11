#include <iostream>
#include "parser/tokenizer.h"
#include "visitor/parser_visitor.h"
#include "visitor/print_visitor.h"
#include "visitor/calc_visitor.h"

// (23 + 10) * 5 – 3 * (32 + 5) * (10 – 4 * 5) + 8
int main() {
    std::string infix_expr;
    std::cout << "Enter your infix expression: ";
    std::getline(std::cin, infix_expr);

    auto tokenizer = Tokenizer{std::move(infix_expr)};
    auto tokens = tokenizer.tokenize();

    auto parser_visitor = ParserVisitor{};
    for (auto token: tokens) {
        token->accept(parser_visitor);
    }
    auto parsed_tokens = parser_visitor.getParsedTokens();
    std::cout << "Same expression in polish notation: ";

    auto print_visitor = PrintVisitor{};
    for (auto token: parsed_tokens) {
        token->accept(print_visitor);
    }
    std::cout << print_visitor.getRes() << std::endl;

    std::cout << "Calculated expression: ";

    auto calc_visitor = CalcVisitor{};
    for (auto token: parsed_tokens) {
        token->accept(calc_visitor);
    }
    std::cout << calc_visitor.getResult();

    return 0;
}
