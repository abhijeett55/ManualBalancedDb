#include "Header.cpp"
void drop() {
    char *tab;
    char *temp;
    char* temp1;
    temp1 = (char*)malloc(sizeof(char)*MAX_NAME);
    temp = (char*)malloc(sizeof(char)*MAX_NAME);
    tab = (char*)malloc(sizeof(char)*MAX_NAME);
    cout<<"-----------------------\n"
    cout<<"Enter the table Name: ";
    cin>>tab;
    strcpy(temp1, tab);
    int check = search_table(tab);

    if(check == 0) printf("\n%s doesn't exist\n\n", tab);
    else if (check == 1) {
        sprintf(temp, "rm - R ./table/%s", tab);
        system(temp);

        sprintf(temp, "grep -v \"%s\" ./table/table_list > ./table/temp ; mv ./table/temp ./table/table_list", tab);
        system(temp);
        printf("\n%s deleted\n\n", temp1);
        printf("-----------------------------");
    }
    else {
        printf("\n Error \nnexting...\n\n");
        return;
    }
}