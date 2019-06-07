#include "dbms2.hh"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
namespace dbms2 {
    bool AbstractDbTable::loadCSV(const char *infn){
        ifstream data;
        if(!infn){return false;}// The file name is null return false
        data.open(infn);
        if(!data.is_open()){
            cout<< "Error: File is not opened" <<'\n';
            return false;
        }
            struct movie m;;//temp variables
            string id;
            string title;
            string year;
            string director;
        while(data.good()){
            getline(data,id,',');
            m.id = strtoul(id.c_str(), NULL, 10);//convert the string to a unsigned long
            getline(data,title,',');
            strcpy(m.title, title.c_str());//copy the string to m.title
            getline(data,year,',');
            m.year = (unsigned short)strtoul(year.c_str(), NULL, 10);//convert string to a unsigned short and assigned the value to m.year
            getline(data,director,'\n');
            strcpy(m.director, director.c_str());
            add(m);
        }
        bool check_end = data.eof();//check if reach the end of the file
        data.close();//close the file been open
        return check_end;//return the result
        return false;//default return false
    }
    
    bool AbstractDbTable::saveCSV(const char *outfn){
        FILE *fp = fopen(outfn, "w");
        
        if(fp == NULL) return false;
        
        unsigned int i = 0;
        while(i < rows()) {
            const struct movie *m = get(i);
            if(m == NULL){break;//nothing to write then break it}
            cout << m->id << ",";
            cout << m->title << ",";
            cout << m->year << ",";
            cout << m->director << endl;//finished the line and to the next line hence endln here
            i++;
        }
        fclose(fp);
        return true;
    } 
    
}
}



