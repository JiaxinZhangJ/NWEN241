

namespace dbms2 
{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };
    
    class AbstractDbTable {
    public:
        virtual int rows()  = 0;
       
        virtual bool remove(unsigned long id) = 0;
        virtual movie *get(int index)  = 0;
        virtual bool show(int index) = 0;
        virtual bool add(movie &m) = 0;
        bool loadCSV(const char *infn);
        bool saveCSV(const char *outfn);        
    };
}
