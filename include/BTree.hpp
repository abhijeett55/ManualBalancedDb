#include "Header.hpp"

// Balanced BTree
class Btreenode;
class BTree {
    private:
        int files_till_now, root_num;
        char tablename[BPTREE_MAX_FILE_PATH_SIZE];;
    void write_node(int file_num, Btreenode n);
    void update_meta_deta();

public:
    BTree();
    BTree(char tablename[]);

    void read_node(int filenum, Btreenode& n);
    int insert_record(int primary_key, int record_num);
    Btreenode search_leaf(int primary_key);
    int get_record(int primary_key);
};