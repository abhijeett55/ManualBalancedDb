#ifndef CREATESTATEMENT_HPP
#define CREATESTATEMENT_HPP


namespace sql {
    struct SelectStatement;

    struct ColumnDefinition {

        enum DataType {
            UNKNOWN,
            TEXT,
            INT,
            DOUBLE,
        };


        ColumnDefinition(char* name , DataType type);
        virtual ~ColumnDefinition();

        char* name;
        DataType* type;

    };

    struct CreateStatement : {
        enum CreateType {
            kTable;
            
        };

    };
}



#endif