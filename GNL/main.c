#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// FILE READ MAIN
// int	main(void)
// {
//     char *line;
//     int fd = open("test.txt", O_RDONLY);

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }

// TERMINAL READ MAIN
// int	main(void)
// {
//     char *line;
//     int fd = 0;

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }

// REVERSE FILE READ MAIN
// int	main(void)
// {
//     char *line;

//     int i = 0;
//     int j = 28;
//     while (j > 0)
//     {
//         int fd = open("get_next_line.h", O_RDONLY);
//         while (i < j)
//         {
//             line = get_next_line(fd);
//             i++;
//         }
//         printf("%s", line);
//         i = 0;
//         j--;
//     }
// }

int main(void)
{
    // int fd1;
    // int fd2;
    // char    *line1;
    // char    *line2;

   
    // fd2 = open("deneme2.txt", O_CREAT | O_RDWR, 0777);

    // line1 = get_next_line(fd1);
    // line2 = get_next_line(fd2);
    // printf("%s", line1);
    // printf("%s\n", line2);

    int fd1;
    int fd2;
    char    *line1;
    char    *line2;
    fd1 = open("deneme1.txt", O_CREAT | O_RDWR, 0777);
    fd2 = open("deneme2.txt", O_CREAT | O_RDWR, 0777);

    
    while((line1 = get_next_line(fd1)) && (line2 = get_next_line(fd2)))
    {
        if (line1)
            printf("%s", line1);
        if (line2)
            printf("%s", line2);
    }
}