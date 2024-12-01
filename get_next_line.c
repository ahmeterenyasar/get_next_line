#include "get_next_line.h"

char    *ft_read_and_save(int fd, char *save)
{
    char    *buffer;
    int read_bytes;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
    {
        return (NULL);
    }
    read_bytes = 1;
    while (!ft_strchr(save, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[read_bytes] = '\0';
        save = ft_strjoin(save, buffer);
    }
    free(buffer);
    return (save);
}

char    *get_next_line(int fd)
{
    char    *line;
    static  char *save;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (0);
    }
    save = ft_read_and_save(fd, save);
    
}