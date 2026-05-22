#include "get_next_line.h"

void ekle_sona_ekle(t_okuma_chunk_burkay_bey **head, t_okuma_chunk_burkay_bey *new_node)
{

}


int toplayici(int fd, t_okuma_chunk_burkay_bey **head)
{
    t_okuma_chunk_burkay_bey *niv_node;
    int n;

    // İçeride return görene kadar dön babam dön
    while (1)
    {
        niv_node = malloc(sizeof(t_okuma_chunk_burkay_bey));
        if (!niv_node)
            return (-1);
            
        niv_node->data = malloc(BUFFER_SIZE);
        if (!niv_node->data) // düzeltiyorum sorry: ->data kontrolü yapılmalıydı okey sorry tamam özür okey
        {
            free(niv_node);
            return (-1);
        }

        // okuyoruz burada:
        n = read(fd, niv_node->data, BUFFER_SIZE);
        
        if (n < 0) // HATA DURUMU hata hata
        {
            free(niv_node->data);
            free(niv_node);
            return (-1); // Hata -1 dönüyoruz -1 for hatalar -1
        }
        if (n == 0) // EOF yani okuyacak bir şey kalmadığı için 0 döncez return
        {
            free(niv_node->data);
            free(niv_node);
            return (0);
        }
        
        // buraya kadar geldiyse başarılı okudu anladık mı buraya kadar
        niv_node->number_of_used_bytes = n;
        niv_node->next = NULL;

        // okuduğumuz bu yeni kısmı listeye ekliyecez.
        ekle_sona_ekle(head, niv_node);

        //yeni okuduğumuz bu kısmın içinde newline var mı bakacauz.
        // varsa, artık okumaya gerek yok, döngüyü bitir.
        if (check_newline(niv_node))
        {
            return (1); // 1 = Başarıyla yeni satır buldum demektiir. Successful ingilizcesi.
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