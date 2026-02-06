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
    FILE *fp = open_file(tname, const_cast<char*>("r"));
    temp = (table*)malloc(sizeof(table));
    fread(temp, sizeof(table), 1, fp);
}



void insert() {
    char *tab;
    tab = (char*)malloc(sizeof(char)*MAX_PATH+1);
    std::cout<< "Enter table Name: ";
    std::cin>>tab;
    int check = search_table(tab);
    if(check == 0) {
        printf("\n Table \" %s \" don't exist in database\n", tab);
        return;
    } else {
        std::cout<<"\nTable exists, enter data\n\n";

        table input1;
        int count;
        File *fp = open_file(tab, const_cast<char*>("r"));
    }
}