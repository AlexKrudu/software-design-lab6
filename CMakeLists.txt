cmake_minimum_required(VERSION 3.21)
project(software_design_lab6)

set(CMAKE_CXX_STANDARD 20)

add_executable(software_design_lab6 main.cpp token/token.h visitor/token_visitor.h token/number_token.h token/operation.h token/brace.h token/add.h token/subtract.h token/multiply.h token/divide.h parser/tokenizer.h token/brace.cpp token/operation.cpp token/number_token.cpp visitor/parser_visitor.h visitor/calc_visitor.h visitor/print_visitor.h)
