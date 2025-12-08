#ifndef SELECTSTATEMENT_HPP
#define SELECTSTATEMENT_HPP

#include "Table.hpp"
#include "Expr.hpp"
#include "SQLStatement.hpp"

namespace sql {
    enum OrderType {
        kOrderAsc,
        kOrderDesc
    };

    struct OrderDescription {
        OrderDescription(OrderType type, Expr* expr);
        virtual ~OrderDescription();

        OrderType type;
        Expr* expr;
    };

    const int64_t kNoLimit = -1;
    const int64_t kNoOffset = -1;

    struct LimitDescription {
        LimitDescription(int64_t limit, int64_t offset);

        int64_t limit;
        int64_t offset; 
    };


    struct GroupByDescription {
        GroupByDescription();
        ~GroupByDescription();


        std::vector<Expr*> columns;
        Expr* having;
    };

    struct SelectStatement : SQLStatement {
        SelectStatement();
        virtual ~SelectStatement();

        TableRef* fromTable;
        bool selectDistinct;
        std::vector<Expr*>* selectList;
        Expr* whereClause;
        GroupByDescription* groupBy;


        SelectStatement* unionSelect;
        std::vector<OrderDescription*>* order;
        LimitDescription* limit;
    };

}


#endif