#include <cstring>
#include <iostream>
#include "editor2.hh"
#include <cctype>
namespace editor2{

 int EditorUtilities::countWords(const char *editing_buffer, int size){
  int word_counter =0;
  int boolean =0;
  for (int i=0; i < size;) {
    printf("%c\n", *(editing_buffer+i) );
    if(*(editing_buffer+i)==' '
          || *(editing_buffer+i)=='\t'|| *(editing_buffer+i)=='\n'
          || *(editing_buffer+i)=='\v'|| *(editing_buffer+i)=='\f'
          || *(editing_buffer+i)=='\r'){
                            std::cout<<"meet space : "<<word_counter<<"   "<< i <<std::endl;
            word_counter++;
          }
      while(*(editing_buffer+i) == ' ' //skip all the white space since the last counting
        || *(editing_buffer+i) == '\n'
        || *(editing_buffer+i) == '\t'
        || *(editing_buffer+i) == '\f'
        || *(editing_buffer+i) == '\v'
        || *(editing_buffer+i) == '\r'){
          boolean =1;
          std::cout<<"in the while"<<*(editing_buffer+i)<<std::endl;
          i++;
          if (i==(size-1)) {
                std::cout<<"in the while number of words"<<word_counter<<"   "<< i <<std::endl;
            return word_counter;
          }
        }
        if(boolean){
          i--;
          boolean = 0;
        }
        if(*(editing_buffer+i) =='\0'){//signal of reaching the end
          if(*(editing_buffer+i-1) != ' '
            && *(editing_buffer+i-1) != '\n'
            && *(editing_buffer+i-1) != '\t'
            && *(editing_buffer+i-1) != '\f'
            && *(editing_buffer+i-1) != '\v'
            && *(editing_buffer+i-1) != '\r'){
              word_counter++;
              std::cout<<"in the end"<<word_counter<<"   "<<i<<std::endl;
              return word_counter;
            }
          }
          i++;
  }
  return word_counter;
}


/////to dodooooooooooo the place of return seems wrong and redo the case caster
int EditorUtilities::searchMultipleNoCase(const char *editing_buffer, int bufflen, std::string to_search, int *indexs, int k){
    // char* temp = editing_buffer;
    // int count =0;
    // int index = 0;
    // for (int i= 0; i < len; i++) {
    //       const char* ignore_case_editting_bf = strcasestr(temp,to_search.c_str());
    //       count++;
    //       *indexs = (int)(ignore_case_editting_bf -editing_buffer);//ignore_case_editting_bf is the start address of the target ,editing_buffer is the address of the start
    //       indexs++;
    //       temp = ignore_case_editting_bf + strlen(to_search.c_str());
    // }
    // return count;



    // const char* temp = editing_buffer;
    int counter = 0;
    int index = 0;
    int target_length = to_search.length();//length of the target string
    const char *target = to_search.c_str();//convert the string to a char*
    int count_occurence = 0;//counting the number of occurences;
    printf("%s%d\n","The length of target :", target_length );
    int temp =-1;
    int j= 0;
        for (int i=0; i < bufflen; ) {
          while ((*(editing_buffer+i)== *(target+counter))||(*(editing_buffer+i)== (*(target+counter)+32))) {//if it equals to a lower case or higher case;
              counter++;
              i++;
              // if(i>=bufflen) return *indexs;
          }
          if(count_occurence >= k) return *indexs;// if already found k occurrences then return
          if(counter == target_length){
            counter=0;
            count_occurence++;
            index =(int) ( i - target_length);// found the index in the editing_buffer
            printf("%s%d\n","Here is the value of the index : ", index );
            *indexs = index;
            indexs++;//move the pointer to the next position, which can let the next index store in the next cell
          }
          else{
            i++;
          }
        }
      return count_occurence;

}




}
