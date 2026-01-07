#include "Btree.hpp"
// depcreated

using namespace std;

void help() {
    printf("\n\n\n Welcome to the ManualBalancedDb\n\n");
}

int take_input_option() {
    string option;
    fflush(stdout);
    fflush(stdin);
    printf("\n\n ------------------------------------------------------\n \n");
    printf("\n Select the query to implement\n");
    printf("\n 1.Show all tables in database\n 
        2.Create table\n
        3.Insert into table\n
        4.Drop table contents\n
        5.Display table contents\n
        6.Search table or Search inside table\n
        7.Help \n
        8. quit \n\n");

    cin>>option;
    if(option.length() > 1) {
        printf("\nWrong inputs\nExisting....\n\n");
        exit(0);
    } else {
        if(option[0] > 48 && option[0] < 58) {
            return option[0]-48;
        } else {
            printf("\nWrong input \nExiting....\n\n");
            exit(0);
        }
    }

}

void input() {
    int c = take_input_option();
    while(c < 9 && c > 0) {
        switch(c) {
        case 1:
            show_tables();
            break;
        case 2:
            //pares_create();
            create();
            break;
        case 3:
            insert();
            break;
        case 4:
            drop();
            break;
        case 5:
            //display();
            get_query();
            break;
        case 6:
            search();
            break;
        case 7:
            help():
            break;
        case 8:
            printf("\nExiting...\n");
            printf("\n\t\t Good Bye!!!!\n\n");
            exit(0);
            break;
        default:
            printf("\nPlease  choose a correct option\n");
            break;
        }
        c = take_input_option();
    }
}


void start_system() {
    system("clear");
    printf("\n\t\t\tWelcome\n\n");
    printf("\t\t Welcome to the ManualBalancedDb \n\n");
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 Welcome to ManualBalancedDb Monitor \n\n");
int main() {
    start_system();
    return 0;
}
