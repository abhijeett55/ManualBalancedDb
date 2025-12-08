#ifndef EXPR_HPP
#define EXPR_HPP

#include <cstdlib>
#include <memory>
#include <vector>


namespace sql {
    class SelectStatement;

    char* substr(const char* source, int from, int to);

    enum ExprType {
        kExprLiteralFloat,
        kExprLiteralString,
        kExprLiteralInt,
        kExprStar,
        //
    }

    typedef struct Expr Expr;

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

        Expr(ExprType type);

        ~Expr();

        ExprType type;

        Expr* expr;






    };

}






#define
