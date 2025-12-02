#ifndef EXPR_HPP
#define EXPR_HPP

#include <cstdio>
#include <memory>
#include <vector>


namespace sql {
    class SelectStatement;

    char* substr(const char* source, int from, int to);

    struct Expr {
        enum OperatiorType  {
            NONE,


            BETWEEN,
            CASE,


            SIMPLE_OP,
            NOT_EQUALS,
            LESS_EQ,
            GREATER_EQ,

            LIKE,
            NOt_LIKE,
            AND,
            OR,
            IN,

            NOT,
            UMINUS,
            ISNULL,
            EXISTS
        };
    };

}




#define
