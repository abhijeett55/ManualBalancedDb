#ifndef TABLE_HPP
#define TABLE_HPP


#include <cstdio>
#include <vcetor>

namespace sql {
    struct SelectStatement;
    struct JoinDefinition;
    struct TableRef;

    enum TableRefType {
        kTableName;
        kTableSelect;
        kTableJoin;
        kTableCrossProduct;
    };

    struct TableRef {
        TableRef(TableRefType type);
        virtual ~TableRef();

        TableRefType type;

        char* schema;
        char* name;
        char* alias;

        SelectStatement* select;
        std::vector<TableRef*>* list;
        JoinDefinition* join;
        bool hasSchema();

        char* getName();
    };

    enum JoinType {
        kJoinInner;
        kJoinOuter;
        kJoinLeft;
        kJoinRight;
        kJoinLeftOuter;
        kJoinRightOuter;
        kJoinCross;
        kJoinNatural;
    };


    struct JoinDefinition {
        JoinDefinition();
        virtual ~JoinDefinition();

        TableRef* left;
        TableRef* right;
        Expr* condition;

        JoinType type;
    };
}


#endif