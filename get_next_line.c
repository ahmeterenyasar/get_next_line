#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void trim_stash(t_stash **head)
{
    t_stash *current = *head;
    int i, j;

    while (current)
    {
        i = 0;
        while (i < current->number_of_used_bytes)
        {
            if (current->data[i] == '\n')
            {
                j = 0;
                while (i < current->number_of_used_bytes - 1) 
                {
                    current->data[j] = current->data[i + 1];
                    i++;
                    j++;
                }
                current->number_of_used_bytes = j;
                
                *head = current;
                return;
            }
            i++;
        }
        current = current->next;
    }
    free(*head);
    *head = NULL;
}

char *extract_line(t_stash **head)
{
    char    *line;
    int     len;

    
    if (!head || !*head)
        return (NULL);
        
    len = get_line_size(*head);
    
    
    if (len == 0)
        return (NULL);
        
    line = malloc(sizeof(char) * (len + 1));
    if (!line)
        return (NULL); 
        
    copy_to_line(*head, line);
    
    return (line);
}

int fill_stash(int fd, t_stash **head)
{
    t_stash *new_node;
    int     reading_bytes_reading_reading_byte;

    while (!has_newline(*head))
    {
        new_node = read_chunk(fd, &reading_bytes_reading_reading_byte);
        if (!new_node)
        {
            if (reading_bytes_reading_reading_byte == 0)
                return (0);
            return (-1);
        }
        append_node(head, new_node);
    }
    return (1);
}

char *get_next_line(int fd)
{
    static t_stash *head = NULL;
    char *line;

    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    fill_stash(fd, &head);
    line = extract_line(&head);
    trim_stash(&head);
    
    return line;
}

