#ifndef DELETESTATEMENT_HPP
#define DELETESTATEMENT_HPP

namespace sql {
    struct DeleteStatement {
        DeleteStatement();

        virtual ~DeleteStatement();

        char* name;
        Expr* expr;
    };
}

#endif