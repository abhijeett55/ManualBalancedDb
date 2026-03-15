#include "Btree.hpp"
#include "Declaration.hpp"
#include "Create.hpp"
#include "Insert.hpp"
#include "Display.hpp"
#include "Search.hpp"
#include "Drop.hpp"
#include "Parser.hpp"

using namespace std;

void help() {
    printf("\n\n\n Welcome to the ManualBalancedDb\n\n"
            "ManualBalancedDb is a simple database design engine in which you can implement basic queries.\n\nQUERIES SUPPORTED ARE::"
            "\n1.create a new table\n2.insert data into existing table\n3.drop table\n4.search in the table\n\n"
            "1.For creating table \na>enter the table name\nb>enter no. of columns\nc>enter col name,datatype(1.INTEGER(INT)\t2.VARCHAR"
            ") and maximum size for it.\n"
            "\n2.For inserting data into table\na>enter table name\nb>it will display how many details to be filled\nc>"
            "enter all the details\nd>your data is inserted into the table\n\n"
            "3.For deleting table just enter the table name\n\n"
            "4.For search into table \na>you can search for a particular table if it exists or not\nb>"
            "b>You can search for a particular entry if it exists in the table or not\n"
            "c>For particular entry searching , search is based on primary key, so enter col[0] value of table to search\n\n"
            "---------------------------------------------------------------------------------------------------");
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
    input();
}

int main(int argc, char *argv[]) {
    if(argc == 4 || argc == 5) {
        if(strcmp(argv[1], "-m") == 0 && strcmp(argv[3], "-k") == 0) {
            char *username = (char*)malloc(sizeof(char)*MAX_NAME);
            strcpy(username, argv[2]);
            const char *mypass = "1234";
            char *password = getpass("Enter Password: ");

            if(strcmp(password, mypass) == 0) cout<<"Correct Password!\n";
            else {
                cout<<"Incorrect password!\n";
                return 0;
            }
        } else {
            printf("\n usage:: ./manualdb -m username -k password\n .existing ...\n\n");
            return 0;
        }
    } else {
        printf("\nusage:: ./manualdb -m username -k password\n .exiting ...\n\n");
        return 0;
    }

    start_system();
    return 0;
}