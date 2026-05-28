#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 24


// chunklar halinde okicaz o yüzden bir strcut oluşturalım linked list yapısı
typedef struct s_stash
{
    char* data;
    int number_of_used_bytes;
    struct s_stash* next;
} t_stash;



#endif