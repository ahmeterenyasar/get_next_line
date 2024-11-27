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
