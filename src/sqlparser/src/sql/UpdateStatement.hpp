#ifndef UPDATE_STATEMENT_HPP
#define UPDATE_STATEMENT_HPP

#include "SQLStatement.hpp"


namespace sql {

    // Represents "column = value" expressions
    struct UpdateClause {
        char* name;
        Expr* value;
    };

    //Represent SQL Update Statements
    struct UpdateStatement : SQLStatement {
        UpdateStatement();

        virtual ~UpdateStatement();

        TableRef* table;
        std::vector<UpdateClause*>* updates;
        Expr* where;
    };
}

#endif