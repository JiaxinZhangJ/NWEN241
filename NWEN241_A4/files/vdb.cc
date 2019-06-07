#include<iostream>
#include"vdb.hh"
#include <vector>
using namespace std;

namespace dbms2{
int VectorDbTable::rows(){//return the total number of rows
    return movies.size();
}
bool VectorDbTable::show(int r){
    if(r>=rows()){//if the input parameter is greater than row
       return false;

    }
     movie m = movies.at(r);
     cout<< " , " << m.id << " , " << m.title << " , " << m.year << " , " << m.director << " , " <<endl;
     // print out the details of the movie
     return true;
}
bool VectorDbTable::add(moive &m){

//    movies.insert(m,movies.beigin())
    movies.push_back(m);//add the element to the back of the table
    return true;
}

bool VectorDbTable::remove(unsigned long id){
    for (int i = 0; i < rows(); i++){
        if(moives[i].id == id){
            movies.erase(movies.begin()+i);
            return true;
        }
    }
    return false;
}

 movie *VectorDbTable::get(int r){
    if(r>=rows()){
        return NULL;
    }
        return &movies.at(r);
    }

}




