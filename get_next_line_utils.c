#include "get_next_line.h"

int has_newline(t_stash *node)
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