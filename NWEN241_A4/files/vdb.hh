#include <vector>
#include "dbms2.hh"

using namespace std;
namespace dbms2 {  
    // 
    class VectorDbTable : public AbstractDbTable {
    public:
         int rows();
         bool remove(unsigned long id);
         movie *get(int index);
         bool show(int index);
         bool add(movie &m);
        ~VectorDbTable();
        VectorDbTable();
        
    private:
        vector<movie> movies;
    };
}
