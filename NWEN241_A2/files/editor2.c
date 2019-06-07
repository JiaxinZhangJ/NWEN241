#include "editor2.h"
#include <stdio.h>
#include "string.h"


int editor_count_lines(const char *editing_buffer, int bufflen){
    int counter = 0;
    // if(counter >= bufflen){
    //   printf("%d\n", counter );
    //   printf("%s\n", "Out of the buffer");
    // }
    for (int i= 0; i < bufflen; i++,editing_buffer++){
      if(*editing_buffer == '\n'){
        printf("%s\n","we found n" );
        ++counter;
        printf("%d\n", counter );
      }
      else if(*editing_buffer == '\0' && *(editing_buffer-1)!='\n'){
        // if(*(editing_buffer-1)!='\n'){
          printf("%s\n","we reach the end of line but not the end" );
            ++counter;
            return counter;
          // }
        }
        else if(*editing_buffer =='\0' && (*(editing_buffer-1)=='\n')){//if this is the end of the line then we return the counter

          printf("%s\n","Reach the end of documents" );
          return counter;
        }
      }
    return counter;
}

int editor_search_multiple(const char *editing_buffer, int bufflen, char *target,int *indexs, int k){
    const char *start_buf = editing_buffer;//store the address for the start of the string
    const char *start_tar = target;//store the address of the first element in target string
    int counter = 0;
    int count_occurence = 0;
    const int target_length = strlen(target);
    printf("%s%d\n","The length of target :", target_length );
    int temp =-1;
    int index= 0;
    int j= 0;
        for (int i=0; i < bufflen; ) {
          while (*(editing_buffer+i)== *(target+counter)) {
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
// #define TEST_STRING \
//   "Nasus playing the main \n"\
//   "crash the jungles and lanes,\n"\
//   "got stack stack stack hard\n"\
//   "nailed the whole game no one cant ignore!\n"\
//   "the second life and death CONTINUE!.\n\n\0\0\0\0\0\0\0\0"
//
// int main(void)
// {
//   char buffer[] = TEST_STRING;
//
//   // printf("Buffer contents: %s", buffer);
//   int r = editor_count_lines(buffer, sizeof(buffer));
//   printf("Output of editor_count_lines()  : %d\n", r);
//   printf("Actual number of lines in buffer: 6\n");
//
//   return 0;
// // }
// #define TEST_STRING "The good, the bad and the lucky. lucky, lucky.\n"
// int main(void){
//   char buffer[] = TEST_STRING;
//   int positions[20];
//   int *pp = positions;
//
//   // printf("Buffer contents: %s", buffer);
//   int r = editor_search_multiple(buffer, sizeof(buffer), "lucky", positions, 20);
//   printf("\nOutput of editor_search_multiple(): %d\n", r);
//   printf("Positions: { ");
//   for(int i=0; i<r; i++) { printf("%d ", *pp); pp++; }
//   printf("}\nActual number of occurrences in buffer of 'lucky': 3\n");
//   printf("Positions: { 10 22 }\n");
//
// return 0;




}
