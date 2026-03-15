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

    ret = obj.insert_record(*((int *)data[0]), temp->rec_count);
    if(ret == 2) {
        std::cout<<"\nKey already exists\n";
        std::cout<<"\nexiting...\n";
        return ;
    }

    fp = open_file(tname, const_cast<char*>("w+"));
    int file_num = temp->rec_count;
    temp->rec_count = temp->rec_count+1;
    temp->data_size = total;
    fwrite(temp, sizeof(table), 1, fp);
    fclose(fp);

    char *str;
    str = (char *)malloc(sizeof(char)*MAX_PATH);
    sprintf(str, "table/%s/file%d.dat", tname, file_num);
    FILE *fpr = fopen(str,"w+");

    int x;
    char y[MAX_NAME];
    for(int i = 0; i < temp->count; j++) {
        if(temp->col[i].type == INT) {
            x = *(int *)data[j];
            fwrite(&x, sizeof(int), 1, fpr);
        }
        else if (temp->col[i].type == VARCHAR) {
            strcpy(y, (char *)data[j]);
            fwrite(y, sizeof(char)*MAX_NAME, 1, fpr);
        }
    }

    fclose(fpr);
    free(str);
    free(temp);
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
        int i = 0;
        while(fread(&inp1, sizeof(table), 1, fp)) {
            printf("----------------------------------------\n");
            std::cout<<"\nInsert the following details:: \n";
            printf("----------------------------------------\n");
            count = inp1.count;
            for(i = 0; i < inp1.count; i++){
                std::cout << inp1.col[i].col_name << "(" << inp1.col[i].type << "),size:" << inp1.col[i].size;
                std::cout << "\t";
            }
        }

        printf("\n---------------------------------------\n");
        char var[MAX_NAME+1];
        void * data[MAX_ATTR];

        int size = 0;
        int total = 0;
        for(int i = 0; i < count; i++){
            if(inp1.col[i].type == INT){
                data[i] = (int*) malloc(sizeof(int));
                total += sizeof(int);
                std::string inp_int;
                std::cin >> inp_int;
                if(inp_int.length() > (unsigned)inp1.col[i].size){
                    printf("\nwrong input, size <= %d\nexiting...\n",inp1.col[i].size);
                    return;
                }
                else{
                    int num = 0;
                    int factor_10 = 1;
                    for(int j = inp_int.length()-1; j >= 0; j--){
                        if(inp_int[j] < 48 || inp_int[j] > 57){
                            printf("\nwrong input, input should be integer\nexiting...\n");
                            return;
                        }else{
                            num += (inp_int[j] - 48) * factor_10;
                            factor_10 = factor_10 * 10;
                        }
                    }
                    *((int*)data[i]) = num;
                }
                size++;
            }
            else if(inp1.col[i].type == VARCHAR) {
                data[i] = malloc(sizeof(char) * (MAX_NAME + 1));
                int flag = 1;
                while(flag){
                    std::cin >> var;
                    total += sizeof(char) * (MAX_NAME + 1);
                    if(strlen(var) > (unsigned int)inp1.col[i].size){
                        std::cout << "\nERROR\nEntered size of string is greater than specified \n";
                    }
                    else flag = 0;
                }
                strcpy((char*)(data[i]), var);
                size++;
            }
        }
        insert_command(tab,data, total);
    }
    free(tab);

}