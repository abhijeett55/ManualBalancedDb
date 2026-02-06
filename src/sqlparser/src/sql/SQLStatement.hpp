#ifndef SQL_STATEMENT_HPP
#define SQL_STATEMENT_HPP

#include "Expr.hpp"
#include <vector>


namespace sql {
    enum StatementType {
        kStatementError,
        kStatementSelect,
        kStatementImport,
        kStatementInsert,
        kStatementUpdate,
        kStatementDelete,
        kStatementCreate,
        kStatementDrop,
        kStatementPrepare,
        kStatementExecute,
        kStatementExport,
        kStatementRename,
        kStatementAlter
    };


    struct SQLStatement {
        SQLStatement(StatementType type);
        virtual ~SQLStatement();

        virtual StatementType type() const;
    private:
            StatementType type;
    };
    
}

#endif