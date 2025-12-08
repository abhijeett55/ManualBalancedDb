#ifndef EXECUTESTATEMENT_HPP
#define EXECUTESTATEMENT_HPP

#include "SQLStatement.hpp"

namespace sql {
    struct ExecuteStatement: SQLStatement {
        ExecuteStatement();
        virtual ~ExecuteStatement();

        char* name;
        std::vector<Expr*>* parameters;
    };
}