#ifndef EXECUTE_STATEMENT_HPP
#define EXECUTE_STATEMENT_HPP

#include "SQLStatement.hpp"

namespace sql {
    struct ExecuteStatement: SQLStatement {
        ExecuteStatement();
        virtual ~ExecuteStatement();

        char* name;
        std::vector<Expr*>* parameters;
    };
}