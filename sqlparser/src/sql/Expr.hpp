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
        kExprPlaceHolder,
        kExprColumnRef,
        kExprFunctionRef,
        kExprOperator,
        kExprSelect
    };

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


        bool isType(ExprType etype);

        bool isLiteral();

        bool hasAlias();

        bool hasTable();

        char* getName();

        bool isSimpleOp();

        bool isSimpleOp(char op);

        static Expr* makeOpUnary(OperatiorType op, Expr* expr);

        static Expr* makeOpBinary(Expr* expr1, char op, Expr* expr2);

        static Expr* makeOpBinary(Expr* expr1, OperatiorType op, Expr* expr2);

        static Expr* makeBetween(Expr* expr, Expr* left, Expr* right);

        static Expr* makeCase(Expr* expr, Expr* then, Expr* other);
        //generic case
        static Expr* makeLiteral(int64_t val);

        static Expr* makeLiteral(double val);

        static Expr* makeLiteral(char* val);

        static Expr* makeColumnRef(char* name);

        static Expr* makeColumnRef(char* table, char* name);

        static Expr* makeFunctionRef(char* func_name, std::vector<Expr*>* exprList, bool distinct);

        static Expr* makePlaceHolder(int id);

        static Expr* makeSelect(SelectStatement* select);

        static Expr* makeExists(SelectStatement* select);

        static Expr* makeInOperator(Expr* expr, std::vector<Expr*>* exprList);

        static Expr* makeInOperator(Expr* expr, SelectStatement* select);
    };

    #define ALLOC_EXPR(var, type) Expr* var;
        do {
            Expr* zero = {type};
            var = (Expr*)malloc(sizeof *var);
            *var = zero;
        } while(0);
    #undef ALLOC_EXPR

}

#endif