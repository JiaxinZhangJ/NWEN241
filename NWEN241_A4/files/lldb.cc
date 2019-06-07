#include "lldb.hh"
#include <iostream>

using namespace dbms2;
using namespace std;

LinkedListDbTable::LinkedListDbTable(){
    head = NULL;//set the head to null when created

}
LinkedListDbTable::~LinkedListDbTable(){//destructor

        node *current_node = head;
        for(int i = 1; i < count; i++) {
                node *next = current_node->next;
                delete current_node;//free the current node
                current_node = next;
        }
}


int LinkedListDbTable::rows(){
    return count;
}

bool LinkedListDbTable::remove(unsigned long id ){
    struct node * current_node = head;
    for(int i = 0; i < count-1; i++){
        if(current_node->next->data.id == id){//find the target node

            node *Next_next = current_node->next->next;

            if(Next_next ==NULL){
                free(current_node->next);   //destruct the target node
                node *tail = NULL;
                current_node->next = NULL;
                count--;
            }
            //destruct the target node
            else{
                free(current_node->next);
                current_node->next = Next_next;

                count--;
            }
            return true
        }
        current_node = current_node->next;
    }
    return false;
}

movie* LinkedListDbTable::get(int index){
    if(index >= rows() || index<0) return NULL;

    node *current_node = head;
    for(int i = 0; i< index; i++){
        current_node =current_node->next;

    }
    movie *mov = &current_node->data;
    return mov;
}

bool LinkedListDbTable::add(movie &movie){
    node *new_node = (node *)malloc(sizeof (node));

    new_node->data = movie;

    new_node->next = NULL;

    if(count == 0) {head = new_node;
    return true;}
    else{
          node *current = head;
        for(int i =0; i < count; i++){

            if(current->next == NULL){
                current->next = new_node;
                return true;
            }
        }


    }
    return false;
}


bool LinkedListDbTable::show(int row) {

        if(row >= length || row < 0){return false;}


        linked_list_node *current = head;
        for(int i = 0; i < row; i++) {
                current = current->next;
        }

        movie movie = current->data;
        cout << movie.id << '||' << movie.title << '||' << movie.year << '||' << movie.director << endl;
        return true;
}
















