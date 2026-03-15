#ifndef PREPARE_STATEMENT_HPP
#define PREPARE_STATEMENT_HPP

// Pending
#include "SQLStatement.hpp"
#include <algorithm>

namespace sql {
    struct PrepareStatement : SQLStatement {
        PrepareStatement();
        virtual PrepareStatement();



        void setPlaceHolder(std::vector<void*>* ph);
        
        char* name;
        SQLParserResult* query;

        std::vector<Expr*> placeholders;
    };
}


#endif