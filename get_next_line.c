#include "get_next_line.h"

int toplayici(int fd, t_okuma_chunk_burkay_bey **head)
{
    t_okuma_chunk_burkay_bey *niv_node;

    int n;
    // neden 1 dimi neden 2 değil 3 değil. bu da değişicek.
    while (1)
    {
        niv_node = malloc(sizeof(t_okuma_chunk_burkay_bey));
        if (!niv_node)
        {
            return -1;
        }
        niv_node->data = malloc(BUFFER_SIZE);
        if (!niv_node)
        {
            free(niv_node);
            return -1;
        }

        //okuyoruz burada:
        n = read(fd, niv_node->data, BUFFER_SIZE);
        if (n <= 0)
        {
            free(niv_node->data);
            free(niv_node);
            return 0;
            // neden 0? bekle kardeşim öğreticez tm
        }
        
    }
    
}

void gnl(int fd)
{
    static t_okuma_chunk_burkay_bey *head = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return ;

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