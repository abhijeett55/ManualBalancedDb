#include "Display.hpp"


void display(char tab[], std::map<std::string, int> &display_col_list);

void process_select(std::vector<std::string>& token_vector) {
    std::map<std::string , int> display_col_list;
    int numOfCol = 0;
    int whereflag = 0;

    if(token_vector[1][0] == 42) {
        display_col_list.insert(make_pair("All_columns_set", 0));
        numOfCol = 1;
    } else {
        for(unsigned int i = 1; i < token_vector.size() - 2; i++) {
            if(token_vector[i] == "from") break;
            else {
                numOfCol += 1;
                display_col_list.insert(make_pair(token_vector[i],0));
            }
        }
    }

    int((int)token_vector.size() > numOfCol + 3) {
        if(token_vector[numOfCol + 3] == "where") {
            whereflag = 1;
            std::string col_to_search = token_vector[numOfCol + 4];
        }
    }

    if(token_vector[token_vector.size() - 1] == " " || token_vector[token_vector.size() - 1] == "\n") {
        printf("\nInternal server error\n");
        return;
    }

    if(whereflag == 0) {
        const char *name = (char*)malloc(sizeof(char)*MAX_NAME);
        name = token_vector[numOfCol + 2].c_str();
        display((char*)name, display_col_list);
    }
}

void show_tables() {
    char* name;
    printf("\n\n LIST OF TABLES\n\n");
    printf("------------------------------\n");
    int tabcount = 0;
    name = (char*)malloc(sizeof(char)*MAX_NAME);
    FILE *FP = fopen();

    if(tabcount == 0) printf("Database Empty!!!!!\n");
    printf("-------------------------------\n");
    free(name);
}