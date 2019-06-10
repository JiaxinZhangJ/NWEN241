#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h> // for close
#include "a5.h"

int loadfile(char *fn, movie_t *movies, int len_movies){
    int index = 0;

    FILE *data = fopen("scifi.csv", "r"); // read file
    if(!data){
        printf("Can not open file \n");
        return -1;
    }
    while(!(feof(data)) && index < len_movies){
        fscanf(data,"%[^,],%[^,],%d,%d,%[^\n]%*c",
               movies[index].title,
               movies[index].director,
               &movies[index].year,
               &movies[index].oscars_won,
               movies[index].origin_country);
               index++;

    }//read all the data in the file
    fclose(data); // close the file

    return 0;// file read successful

}


int main(void){
    int read_result;
    int sockfd, bindret, fd, clientfd;
    socklen_t children;
    socklen_t clilen;
    movie_t movies[NUMBER_RECORDS];
    char buffer[DEFAULT_STRLEN];


/* Load CSV database file */
    read_result = loadfile(FILENAME,movies,NUMBER_RECORDS);
    if(read_result< 0){
      printf("Error Occured when reading file.\n" );
    }
    struct sockaddr_in serv_addr, cli_addr;;
    int r,s;


    /* Create and bind socket */
    // step 1 create socklen_t
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
      printf("ERROR : Unable to open socket\n");
      exit(1);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(DEFAULT_PORT);

    /* Step 2 : Bind the socket to an address using the bind() system call */
    bindret = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (bindret < 0) {
       printf("Error: Unable to bind\n");
       exit(1);
    }
    for(;;){
    /* Step 3 : Listen for connections with the listen() system call */
    if (listen(sockfd,SOMAXCONN) < 0){
      printf("Error: Unable to bind\n");
      exit(1);
    }
    clilen = sizeof(cli_addr);
    /* Step 4 : Accept a connection with the accept() system call */
    clientfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    int pid,new;
    if (clientfd < 0) {
       printf("Error: Unable to accept\n");
       exit(1);
    }

    /// Create fork
    else{//connected
      strncpy(buffer, "HELLO\n", 7);
      s = send(clientfd,buffer,strlen(buffer), 0);
    
      pid = fork();
      if(pid == 0){

        int r_number;
        int row;
        char cmd[1024];
        while(1){
          /*reset the buffer*/
          memset(buffer, 0, DEFAULT_STRLEN);

          /* Step 5 : Send and receive data */
          r = recv(clientfd,buffer,DEFAULT_STRLEN, 0);

          if (r < 0) {
             printf("Error: Unable to read from socket");
             exit(1);
          }

          printf("Message received: %s\n",buffer);
          char temp[DEFAULT_STRLEN];
          r_number= sscanf(buffer, "%s %d", temp, &row);

        /* Deals with \n character for excit from NC */
        if(r_number==1){
          if ((strcasecmp(temp, "BYE") == 0) || (strcasecmp(buffer, "BYE\n") == 0) ){
            printf("Closing connection with client.\n");
            close(clientfd);
            exit(0);
          }
          if(strcasecmp(temp, "GET") ==0){//ignore case
            printf("Print all the records\n");
            for(int i = 0; i < NUMBER_RECORDS; i++){

                snprintf(buffer, 5*DEFAULT_STRLEN, "%d: %s, %s, %d, %d, %s\r\n", i, movies[i].title, movies[i].director,
                  movies[i].year, movies[i].oscars_won, movies[i].origin_country);
                s=send(clientfd,buffer,strlen(buffer),0);
              // printf("%d: %s, %s, %d, %d, %s\r\n",i, movies[i].title, movies[i].director,movies[i].year, movies[i].oscars_won, movies[i].origin_country );
            }
          }
        }
          else if(r_number ==2){
            if(strcasecmp(temp, "GET") ==0){
              if(row<0 || row > NUMBER_RECORDS){
                printf("Index out of bounds\n" );
                exit(1);
              }
              else{
                snprintf(buffer, 5*DEFAULT_STRLEN, "%d: %s, %s, %d, %d, %s\r\n", row, movies[row].title, movies[row].director,
                  movies[row].year, movies[row].oscars_won, movies[row].origin_country);
                s=send(clientfd,buffer,strlen(buffer),0);

              }
            }

          }



            // /* Step 5 : Send and receive data */
            // s = send(clientfd,buffer,strlen(buffer), 0);
            //
            if (s < 0) {
               printf("Error: Unable to write to socket\n");
               exit(1);
             }

           }

           




       
      }
      else{
          continue;
    }




    }
  }




    return 0;

}
