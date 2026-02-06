#include "Header.hpp"

// Balanced BTree
class BPTreenode;
class BPTree {
    private:
        int files_till_now, root_num;
        char tablename[BPTREE_MAX_FILE_PATH_SIZE];;
    void write_node(int file_num, Btreenode n);
    void update_meta_deta();

public:
    BPTree();
    BPTree(char tablename[]);

    void read_node(int filenum, BPTreenode& n);
    int insert_record(int primary_key, int record_num);
    BPTreenode search_leaf(int primary_key);
    int get_record(int primary_key);
};