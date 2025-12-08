#ifndef DELETESTATEMENT_HPP
#define DELETESTATEMENT_HPP

#include "SQLStatement.hpp"

namespace sql {
    struct DeleteStatement : SQLStatement {
        DeleteStatement();

        virtual ~DeleteStatement();

        char* name;
        Expr* expr;
    };
}

#endif