#include "dbms2.hh"

namespace dbms2{
    struct node{
           struct movie data;
           struct node *next;
    };
    class LinkedListTable : public AbstractDbTable{
    public:
        LinkedListTable();
        ~LinkedListTable();
        int rows();
        bool show(int r);
        bool add( movie &a);
        bool remove(unsigned long id);
         movie *get()
    private:
         struct node *head;
        int count;
    }
           
    

}
