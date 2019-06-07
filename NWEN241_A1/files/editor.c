/**
* editor.c
*
* You must implement the functions in editor.h in this file.
* Consult the assignment handout for the detailed specifications of each of the functions.
*
* Student ID:300390526
* Name: Vincent Yu
*/
#include <stdio.h>
#include "editor.h"
#include <string.h>
char editing_buffer[EDITING_BUFLEN];

int editor_insert_char(char *editing_buffer, char to_insert, int pos){
  if(pos >= EDITING_BUFLEN || pos < 0) return -1;
  for (int i = EDITING_BUFLEN-1; i > pos; i--) {
    char temp ='\0';
    *(editing_buffer+i) = *(editing_buffer+i-1);
  }
  *(editing_buffer+pos) = to_insert;
  return 1;
}

int editor_delete_char(char *editing_buffer, char to_delete, int offset){
  if(offset < 0 || offset > EDITING_BUFLEN) return -1;
  for(int i = offset; i < strlen(editing_buffer); ++i){
    if(editing_buffer[i] == to_delete){
      for(int j = i; j < strlen(editing_buffer) - 1; ++j){
        editing_buffer[j] = editing_buffer[j+1];
      }
      editing_buffer[strlen(editing_buffer) - 1] = '\0';
      printf("%c", '\0');
      return 1; //return 1 if the character is succesffuly delelted.
    }
  }

}

int editor_replace_str(char *editing_buffer, const char *str, const char *replacement, int offset) {
   int checker = -1;
   int length_str = 0;
   int length_replacement = 0;
   int start_index = -1;
   if (offset >= EDITING_BUFLEN || offset < 0) return -1;
   length_str = strlen(str) ;//this could give the length of the array
   length_replacement = strlen(replacement);
   for (int i = 0; i < EDITING_BUFLEN/100; i++) {
       if(editing_buffer[i] == str[0]){
         int index= 0 ;
         while(index < length_str){
           if(editing_buffer[index+i] != str[index]){
             break;
           }
           if(index == (length_str-1)){
             checker =1;
             start_index =i;
             goto Find;

           }
           index++;
         }

       }

       }
   Find:
   if(checker==1){
     // printf("\n%s","here in the checker");

       for(int index = start_index; index < length_str+start_index; index++){
           editor_delete_char(editing_buffer,editing_buffer[start_index],start_index);
       }
       for(int m = 0; m < length_replacement; m++){
           editor_insert_char(editing_buffer,replacement[m],start_index+m);
       }
       return 1;
   }
   return -1;

}

// int editor_replace_str(char *editing_buffer, const char *str, const char *replacement, int offset){
//   // int start_index = 0;
//     printf("\n%s",str);





  void editor_view(char **viewing_buffer, const char *editing_buffer, int wrap){
    // printf("%s\n","123123123213123" );
    int current_row = 0;
    int current_col = 0;
    int i=0;
    int j=0;
    int index_in_editing_buffer=0;
    int r,c;

    char *p[VIEWING_ROWS];

//initialise the array
    for(int m= 0; m < VIEWING_ROWS; m++){//iterating through the whole viewing_buffer array
      p[m] = (char*)viewing_buffer + VIEWING_COLS *m;//set the line pointer to curent row
      for(int n =0; n < VIEWING_COLS; n++){
          p[m][n] = '\0';
        }

    }






    for(current_row= 0; current_row < VIEWING_ROWS; current_row++){//iterating through the whole viewing_buffer array
      p[current_row] = (char*)viewing_buffer + VIEWING_COLS *current_row;//set the line pointer to curent row
      for(current_col =0; current_col < VIEWING_COLS; current_col++){
        if(index_in_editing_buffer >= EDITING_BUFLEN){//check the index if greater than the length of editing buffer then just return
            printf("%s\n", "Out of the editing buffer");
          return;
        }
        if(editing_buffer[index_in_editing_buffer] == '\n'){//if the current element is change line terminator
          index_in_editing_buffer++; //move the cursor to the next element in the editing buffer
            while(current_col < VIEWING_COLS){//fill the rest cells in the current row with \0
              p[current_row][current_col] = '\0';
              current_col++;
            }
            current_col=0;//reset the current col to the begining
            current_row++;//change to next row
          }
if(index_in_editing_buffer< EDITING_BUFLEN){
  if(current_row< VIEWING_ROWS){
        if(current_col < VIEWING_COLS-1){//just assign the value in the editing buffer to the viewing buffer
          printf("%d\n",current_col );
          printf("%d\n",VIEWING_COLS);
          p[current_row][current_col] = editing_buffer[index_in_editing_buffer];
          index_in_editing_buffer++;//increase the index
    }
  }
}
        if(current_col == VIEWING_COLS-1){//once we reach the second last col we need to check wrap or not
            if(wrap != 0){//no wrap
              p[current_row][current_col] = '\0';//just set the last column to \0
              // current_col=0;//reset the col cursor
              // current_row++;//move to next line
            }
            else{//wrapping
              while(editing_buffer[index_in_editing_buffer]!='\n'){
                index_in_editing_buffer++;//wrapping the elements in the editing buffer
              }
            }
          }
        }
      }


      return;

    }




//
// int main(){
//   char editing_buffer_2 [EDITING_BUFLEN] = "The quick brown fox\0";
//   char editing_buffer_3 [EDITING_BUFLEN] = "The quick brown fox\0";
//   char editing_buffer_4 [EDITING_BUFLEN] = "The quick brown fox\0";
//   char editing_buffer_5 [EDITING_BUFLEN] = "The quick brown\n fox jumps over\n\n the lazy dog\n\0\0\0";
//   char viewing_buffer[VIEWING_COLS][VIEWING_ROWS] = {};
//   editor_insert_char(editing_buffer_2,'s',9);
//   for(int i=0; i <EDITING_BUFLEN; i++ ){
//     printf("%c",editing_buffer_2[i]);
//   }
//   printf("\n");
//   int r = editor_delete_char(editing_buffer_3,'f',10);
//   for(int i=0; i <EDITING_BUFLEN; i++ ){
//     printf("%c",editing_buffer_3[i]);
//   }
//
//   printf("\n");
//   //printf("%d", sizeof("brown"));
//
//   int r_1 = editor_replace_str(editing_buffer_4,"brown", "blue", 0);
//   // for(int i=0; i <EDITING_BUFLEN; i++ ){
//   //   printf("%c",editing_buffer_4[i]);
//   // }
//   editor_view((char**)viewing_buffer,editing_buffer_5,1);
//   char *p[VIEWING_ROWS];
//   for(int i =0; i<VIEWING_ROWS; i++){
//     for(int j =0 ; j < VIEWING_COLS; j++){
//       printf("viewing_buffer[%d][%d] = %c", i, j, viewing_buffer[i][j]);
//     }
//   }
// }
