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
            // Ternary 
            BETWEEN,
            CASE,
            //Binary
            SIMPLE_OP,
            NOT_EQUALS,
            LESS_EQ,
            GREATER_EQ,
            LIKE,
            NOt_LIKE,
            AND,
            OR,
            IN,
            //Unary
            NOT,
            UMINUS,
            ISNULL,
            EXISTS
        };

        Expr(ExprType type);

        ~Expr();

        ExprType type;

        Expr* expr1;
        Expr* expr2;
        std::vector<Expr1*>* exprList;
        SelectStatement* select;


        char* name;
        char* table;
        char* alias;
        float fval;
        int64_t ival1;
        int64_t ival2;

        OperatiorType opType;
        char opChar;
        bool distinct;


    };

}






#define
