#include "get_next_line.h"

int has_newline(t_stash *head)
{
    t_stash *curr;
    int     i;

    curr = head;
    while (curr)
    {
        i = 0;
        while (i < curr->number_of_used_bytes)
        {
            if (curr->data[i] == '\n')
                return (1);
            i++;
        }
        curr = curr->next;
    }
    return (0);
}