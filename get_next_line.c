#include "get_next_line.h"

int toplayici(int fd, t_okuma_chunk_burkay_bey **head)
{

}

void gnl(int fd)
{
    static t_okuma_chunk_burkay_bey *head;
    head = NULL;
    // ulan bi üst satır hatalı bakın sonradan null ataması yaparsam hep nulla eşitlenicek tekrar çağırdığım zaman böyle olmaz
    // düzelticem bu committen sonra

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return ;
    }

    // TOPLAMA
    // ÇIKARMA
    // TEMİZLEME
    // + MAIN yazalım ve test edelim sürekli
}

int main(int argc, char** argv)
{
    int fd = open("test.txt", O_RDONLY);
    gnl(fd);
    close(fd);
}