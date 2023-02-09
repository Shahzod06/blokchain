#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#ifndef READLINE_READ_SIZE
#define READLINE_READ_SIZE 32
#endif
#define OB  '\0'

typedef struct s_bocklist {
    char* data;
    size_t size;
    struct s_bocklist* next;
} blck;

typedef struct s_nodelist {
    int id;
    blck* blocklist;
    struct s_nodelist* next;
} list;

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array {
    int size;
    char** array;
} listnode;
#endif
char* my_strtok(char*,const char*);
listnode* my_split(char*, char*);
void putch(char );
void putstr(char*);
bool like(char*, char*);
void trim(char* , char*);

void itoa(int , char[]);
void reverse(char[]);
char* my_readline(int );

bool is_sync(list**);
int count_nodes(list**);
void read_linked_list(list**);
int blockchain(list**, listnode*);