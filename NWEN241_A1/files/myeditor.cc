/**
 * myeditor.cc
 *
 * You must implement the member functions, including constructors, of your class defined in myeditor.hh.
 * Consult the assignment handout for the detailed specifications of each of the member functions.
 *
 * Student ID:300390526
 * Name:Yongbo Yu
 */
#include "myeditor.hh"
// #include "editor.hh"
#include <iostream>
#include <string>
using namespace editor;
bool MyEditingBuffer::replace(char c, char replacement, int offset){
    if(offset > BUFFER_LEN) return false;
    for (int i = offset; i < BUFFER_LEN; ++i) {
        if(buffer[i] == c){
            buffer[i] = replacement;
            return true;
        }
    }
    return false;
}
//
int  MyEditingBuffer::replace(std::string str, std::string replacement, int offset){
        int start_index = -1;//store the start index in str
        int m = 0;//used to remember the current length that had been iterated in replacement string
        int replacement_length = replacement.length();
        int str_length = str.length();
        if(offset > BUFFER_LEN) {
         // cout << "Offset too big" << endl;
          return -1;
        }

        for(int i = offset; i < BUFFER_LEN; ++i){//start searching from the offset
          if(replacement.at(0) == buffer[i]){
            while (m < replacement_length){
              if(replacement.at(m) != buffer[(i+m)]){
                break;
              }
              m++;
            }
            start_index = i;
          }
        }
        if(start_index!=-1){
          if(replacement_length < str_length){//if the replacement string is shorter then we need to move to the left
            for(int i = 0; i < replacement_length; i++){
              buffer[i+start_index] = replacement.at(i);
            }
            for(int m=start_index+replacement_length; m < BUFFER_LEN; m++){
              if(m < BUFFER_LEN-(str_length-replacement_length)){
                  buffer[m] = buffer[m+1];
              }
              else{//the reset cell set to \0
                buffer[m] = '\0';
              }
            }
            return 1;
          }
          if(replacement_length > str_length){//if the replacement string is longer then we need to move to right also we need to check if the replacement gonna exceed or not
              if((start_index + replacement_length ) > BUFFER_LEN){
                // for(int i = 0; i < length_str; i++){
                //   buffer[start_index+i] = replacement.at[i];
                // }
                return BUFFER_LEN-1;
              }
              else{
                int difference = replacement_length - str_length;
                for(int k = 0; k < difference; k++){//move right k times
                  for(int n=BUFFER_LEN; n > start_index+str_length; n--) {
                    buffer[n] = buffer[n-1];
                  }
                }
                for(int m = 0; m < replacement_length; m++ ){
                  buffer[start_index+m] = replacement.at(m);
                }
                return 1;
              }
          }
        }
 return 0;
}

void  MyEditingBuffer::justify(char **viewingBuffer, int rows, int cols){
  int i,j;
  int index_in_buffer = 0;
  char *p[rows];// line pointer
  for(i=0; i< rows; i++){
    p[i] = (char*)viewingBuffer + cols*i;
    for(j=0; j< cols; j++){
      if(index_in_buffer > BUFFER_LEN) {return;}
      if(buffer[index_in_buffer] =='\n'){
        for(int k =j; k < cols; k++){
          p[i][k] = '\0';
        }
        j=0;
        i++;
      }
        else if(j==cols-2){ // when pointing to the second last check the element in buffer to make sure the second last is filled with a letter
          if(buffer[index_in_buffer]=='\0'){
            while(buffer[index_in_buffer]!='\0'){
              index_in_buffer++;
            }
          }
        }
        else if(j ==cols-1){//else if we are reaching the last col in the viewing buffer
            p[i][j] = '\0';
          }
        else{
          p[i][j] = buffer[index_in_buffer];
          index_in_buffer++;
        }
    }
  }


  return;
}
// int main(){
//   MyEditingBuffer meb;
//
//   char test[BUFFER_LEN] = "The quick brown fox\0\0";
//   meb.setBuffer(test,21);
//   bool r = meb.replace('b','B',5);
//   if(r){
//     printf("%s\n","1" );
//   }
// }
