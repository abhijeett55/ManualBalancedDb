#include "FileHandler.hpp"

FILE *open_file(char t_name[], char perm[]) {
    FILE * fp;
    struct stats st = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char *name = (char *)malloc(sizeof(char) *(2 * MAX_MNAME + 15));
     strcpy(name, "./table/");

    if(stats(name , &st) == -1)
        mkdir(name, 0775);

    strcat(name , t_name);
    strcat(name, "/")

    if(stats(name, &st) == -1)
        mkdir(name, 0775);

    strcat(name , "met");
    fp = fopen(name, perm);
    if(!fp) {
        printf("\nError in Opening File\n");
    }
    free(name);
    return fp;
}


int store_meta_data(struct table *t_ptr) {
    FILE *fp = open_file(t_ptr->name, const_cast<char*>("w"));
    fwrite(t_ptr, sizeof(struct table), 1, fp);
    fclose(fp);
    return 0;
}