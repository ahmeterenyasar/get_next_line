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

char *get_next_line(int fd);
int has_newline(t_stash *node);
void trim_stash(t_stash **head);
char *extract_line(t_stash **head);
void append_node(t_stash **head, t_stash *new_node);
int fill_stash(int fd, t_stash **head);
int get_line_size(t_stash *head);
void copy_to_line(t_stash *head, char *line);
t_stash *read_chunk(int fd, int *bytes_read);

#endif