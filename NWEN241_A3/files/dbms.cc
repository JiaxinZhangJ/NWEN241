#include <cstring>
#include <cstdlib>
#include <iostream>
#include "dbms.hh"
using namespace std;
namespace dbms{
  DbTable::DbTable(){//default total rows =5 usedrows =0 and allocate memmory space to the table
    rowsTotal = 5;
    rowsUsed = 0;
    table= (album*) calloc(5,5*sizeof(album));
  }
  DbTable::~DbTable(){//free the memory allocated to the table
    free(table);
  }
  unsigned int DbTable::rows(){//return the number of rows have been occupied
    return rowsUsed;
  }
  unsigned int DbTable::allocated(){//return the total number of rows in the current table
    return rowsTotal;
  }
  bool DbTable::show(unsigned int r)  {//show line r in table
    if(r > rowsUsed) return false;//index out of bounds
    album *t = table+r;
    cout << " || " << t->id << " || " << t->title << " || " << t->artist << " || " << endl; //printing
    return true;
  }
  bool DbTable::add(album &alb){
    album *temp;
    if(!(rowsUsed>=rowsTotal)){
        table[rowsUsed++] = alb;
        return true;
    }
    if(rowsUsed>=rowsTotal){
      temp = (album *)realloc(table,rowsTotal*sizeof(album) + 5 * sizeof(album));//make the table five more elements bigger
      if(temp == NULL) return false;
      table = temp;
      rowsTotal += 5;//increase the number of totalrows by five
    }
    return true;


  }
  bool DbTable::remove(unsigned long id){
    bool checker = false;
    for(int i=0; i < rowsUsed; i++){
        if(table[i].id == id){//matched here need to delete the value in this row
            for(int j =i; j < rowsUsed-1; j++){
                table[j] = table[j+1];
            }
            checker = true;
            break;//found and delete the line matching then we break the for loop
        }
    }
    if(checker)//if we found a match
    {
        rowsUsed--;
        if(rowsTotal - rowsUsed >=5 && rowsUsed !=0){//if we have the empty line more than 5 then we need to reduce the memory allocate for table by five albums
            rowsTotal = rowsTotal - 5;//reduce the total rows
            album *temp = (album*) realloc(table,rowsTotal*sizeof(album));//re-allocate memory to the new table
            if(temp == NULL) return false;//if nothing in the table then return false
            memcpy(temp,table,rowsUsed*sizeof(album));
            free(table);//free the memory occupied by the old table
            table = temp;//re-assigned the new table back
        }
    }
    return checker;
}
}
