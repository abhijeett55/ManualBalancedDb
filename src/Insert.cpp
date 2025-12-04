#include "Insert.hpp"
#include "Aes.hpp"

int search_table(char tab_name[]) {
    char str[MAX_NAME+1];
    strcpy(str,"grep -Fxq");
    strcpy(str, tab_name);
    strcat(str, " ./table/table_list");

    int x = system(str);
    if(x == 0) return 1;
    return 0;
}


void insert_command(char tname[], void *data[], int total) {
    table *temp;
    int ret;
    Btree obj(tname);
}
