
namespace  dbms{
  struct album{
    unsigned long id;
    char title[100];
    unsigned short  year;
    char artist[100];
  };

    class DbTable {
    public:
        unsigned int rows();
        unsigned  int allocated();
        DbTable();//constructor
        ~DbTable();//destructor
        bool show(unsigned int r);
        bool add(album &alb);
        bool remove(unsigned long id);

    private:
        album *table;
        unsigned int rowsTotal;
        unsigned int rowsUsed;
    };
}
