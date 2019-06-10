#ifndef __a5__
#define __a5_H__
#include <netinet/in.h> 
 
 
#define DEFAULT_STRLEN 100
#define DEFAULT_PORT 12345
#define NUMBER_RECORDS 25
#define FILENAME  "scifi.csv"
struct movie {
    char title[DEFAULT_STRLEN];
    char director[DEFAULT_STRLEN];
    short year;
    short oscars_won;
    char origin_country[DEFAULT_STRLEN];
};

typedef struct movie movie_t;

/*
 * File reader----load the data
 */
int loadfile(char *fn, movie_t *movies, int len_movies);


/*
 * Create the server socket
 * 
 */
//int create_socket(struct sockaddr_in *serv_addr)


#endif
