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
    char *satır;

    int satır_length = 0;
    int index = 0;
    t_stash *curr = *head;
    while (curr)
    {
        index = 0; 
        while (index < curr->number_of_used_bytes)
        {
            satır_length++;
            if (curr->data[index] == '\n')
            {
                break;
            }
            index++;
        }
        if (index < curr->number_of_used_bytes && curr->data[index] == '\n')
            break;
        curr = curr->next;
    }

    satır = malloc(satır_length + 1);

    curr = *head; 

    int i = 0;
    int j = 0;
    
    while (curr)
    {
        i = 0;
        while (i < curr->number_of_used_bytes)
        {
            satır[j] = curr->data[i];
            j++;
            
            if (curr->data[i] == '\n')
            {
                satır[j] = '\0';
                return satır;
            }
            i++;
        }
        curr = curr->next;
    }
    
    satır[j] = '\0';
    return satır;
}

int check_newline(t_stash *node)
{
    int i = 0;
    if (!node || !node->data)
        return (0);
    while (i < node->number_of_used_bytes)
    {
        if (node->data[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

void ekle_sona_ekle(t_stash **head, t_stash *new_node)
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

int fill_stash(int fd, t_stash **head)
{
    t_stash *new_node;
    int n;

    while (1)
    {
        new_node = malloc(sizeof(t_stash));
        if (!new_node)
            return (-1);
            
        new_node->data = malloc(BUFFER_SIZE);
        if (!new_node->data)
        {
            free(new_node);
            return (-1);
        }

        n = read(fd, new_node->data, BUFFER_SIZE);
        
        if (n < 0)
        {
            free(new_node->data);
            free(new_node);
            return (-1);
        }
        if (n == 0)
        {
            free(new_node->data);
            free(new_node);
            return (0);
        }
        
        new_node->number_of_used_bytes = n;
        new_node->next = NULL;

        ekle_sona_ekle(head, new_node);

        if (check_newline(new_node))
        {
            return (1);
        }
    }
}

char *gnl(int fd)
{
    static t_stash *head = NULL;
    char *satır;

    // fd kontrolünü buraya eklemek zorunda kaldım yoksa fd=open eksi dönerse direkt patlıyor sistem
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    fill_stash(fd, &head);
    satır = extract_line(&head);
    trim_stash(&head);
    
    return satır;
}


int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return 1;

    while (1)
    {
        line = gnl(fd);
        if (!line)
            break;
            
        printf("GELEN SATIR: %s", line);
        free(line);
    }
    close(fd);
    return 0;
}
