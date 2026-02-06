#include "Insert.hpp"
#include "Aes.hpp"
#include "BPTree.hpp"
#include "File_Handler.hpp"

int search_table(char tab_name[]) {
    char str[MAX_NAME+1];
    strcpy(str,"grep -Fxq ");
    strcpy(str, tab_name);
    strcat(str, " ./table/table_list");

    int x = system(str);
    if(x == 0) return 1;
    else return 0;
    return 0;
}


void insert_command(char tname[], void *data[], int total) {
    table *temp;
    int ret;
    BPTree obj(tname);
}
