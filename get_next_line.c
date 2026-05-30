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
    char *line;

    int line_length = 0;
    int index = 0;
    t_stash *current = *head;
    while (current)
    {
        index = 0; 
        while (index < current->number_of_used_bytes)
        {
            line_length++;
            if (current->data[index] == '\n')
            {
                break;
            }
            index++;
        }
        if (index < current->number_of_used_bytes && current->data[index] == '\n')
            break;
        current = current->next;
    }

    line = malloc(line_length + 1);

    current = *head; 

    int i = 0;
    int j = 0;
    
    while (current)
    {
        i = 0;
        while (i < current->number_of_used_bytes)
        {
            line[j] = current->data[i];
            j++;
            
            if (current->data[i] == '\n')
            {
                line[j] = '\0';
                return line;
            }
            i++;
        }
        current = current->next;
    }
    
    line[j] = '\0';
    return line;
}

void append_node(t_stash **head, t_stash *new_node)
{
    t_stash *temporary;

    if (!*head)
    {
        *head = new_node;
        return;
    }
    temporary = *head;
    while (temporary->next)
    {
        temporary = temporary->next;
    }
    temporary->next = new_node;
}

t_stash *read_chunk(int fd, int *bytes_read)
{
    t_stash *new_node;

    *bytes_read = -1;
    new_node = malloc(sizeof(t_stash));
    new_node->data = malloc(BUFFER_SIZE);
    *bytes_read = read(fd, new_node->data, BUFFER_SIZE);
    new_node->number_of_used_bytes = *bytes_read;
    new_node->next = NULL;
    return (new_node);
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

    // fd kontrolünü buraya eklemek zorunda kaldım yoksa fd=open eksi dönerse direkt patlıyor sistem
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    fill_stash(fd, &head);
    line = extract_line(&head);
    trim_stash(&head);
    
    return line;
}

