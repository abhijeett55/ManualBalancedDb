#include <cstdio>
#include <string>
#include "Expr.hpp"
#include "SelectStatement.hpp"

namespace sql {
    Expr::Expr(ExprType type) :
        type(type),
        expr(NULL),
        expr2(NULL),
        exprList(NULL),
        select(NULL),
        name(NULL),
        table(NULL),
        alias(NULL) {};


    Expr::~Expr() {
        delete expr;
        delete expr2;
        delete select;
        free(name);
        free(table);
        free(alias);

        if(exprList  != NULL) {
            for(Expr* e : *exprList) {
                delete e;
            }
            delete exprList;
        }
    }

    //



    bool Expr::isType(ExprType etype) {
        return etype == type;
    }

    bool Expr::isLiteral() {
        return isType(kExprLiteralInt) || isType(kExprLiteralFloat) || isType(kExprLiteralString) || isType(kExprPlaceholder);
    }

    bool Expr::hasAlias() {
        return alias != NULL;
    }

    bool Expr::hasTable() {
        return table != NULL;
    }

    char* Expr::getName() {
        if(alias != NULL) return alias;
        else return name;
    }

    bool Expr::isSimpleOp() {
        return opType == SIMPLE_OP;
    }

    bool Expr::isSimpleOp(char op) {
        return isSimpleOp() && opChar == op;
    }

    char* substr(const char* source, int from, int to) {
        int len = to - from;
        char* copy = (char*)malloc(len+1);
        strcpy(copy, source+ from, len);
        copy[len] = '\0';
        return copy;
    }

}