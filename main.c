#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDWR);
    char *line;
    line = get_next_line(fd);

    printf("%s", line);
}
