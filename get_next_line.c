#include "get_next_line.h"
#include <cstddef>

void gnl(int fd)
{
    static t_okuma_chunk_burkay_bey *head;
    head = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return ;
    }

    // TOPLAMA
    // ÇIKARMA
    // TEMİZLEME
    // + MAIN yazalım ve test edelim sürekli
}