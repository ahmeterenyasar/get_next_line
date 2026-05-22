#include "get_next_line.h"

void temizleyiciii(t_okuma_chunk_burkay_bey **head)
{
    t_okuma_chunk_burkay_bey *temp = *head;
}

char *çıkarıcı(t_okuma_chunk_burkay_bey **head)
{
    char *satır;

    int satır_length = 0;
    int index = 0;
    t_okuma_chunk_burkay_bey *curr = *head;
    while (curr)
    {
        index = 0; 
        while (index < curr->number_of_used_bytes)
        {
            satır_length++;
            if (curr->data[index] == '\n')
            {
                break;
            }
            index++;
        }
        if (index < curr->number_of_used_bytes && curr->data[index] == '\n')
            break;
        curr = curr->next;
    }

    satır = malloc(satır_length + 1);

    int i = 0;
    int j = 0;
    
    while (curr)
    {
        i = 0;
        while (i < curr->number_of_used_bytes)
        {
            satır[j] = curr->data[i];
            j++;
            
            if (curr->data[i] == '\n')
            {
                satır[j] = '\0';
                return satır;
            }
            i++;
        }
        curr = curr->next;
    }
    
    satır[j] = '\0';
    return satır;
}

int check_newline(t_okuma_chunk_burkay_bey *node)
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

void ekle_sona_ekle(t_okuma_chunk_burkay_bey **head, t_okuma_chunk_burkay_bey *new_node)
{
    t_okuma_chunk_burkay_bey *temporary;

    if (!*head)
    {
        *head = new_node;
        return;
    }
    temporary = *head;
    while (temporary->next)
    {
        temporary = temporary->next;
    }
    temporary->next = new_node;
}

int toplayici(int fd, t_okuma_chunk_burkay_bey **head)
{
    t_okuma_chunk_burkay_bey *new_node;
    int n;

    // İçeride return görene kadar dön babam dön
    while (1)
    {
        new_node = malloc(sizeof(t_okuma_chunk_burkay_bey));
        if (!new_node)
            return (-1);
            
        new_node->data = malloc(BUFFER_SIZE);
        if (!new_node->data) // düzeltiyorum sorry: ->data kontrolü yapılmalıydı okey sorry tamam özür okey
        {
            free(new_node);
            return (-1);
        }

        // okuyoruz burada:
        n = read(fd, new_node->data, BUFFER_SIZE);
        
        if (n < 0) // HATA DURUMU hata hata
        {
            free(new_node->data);
            free(new_node);
            return (-1); // Hata -1 dönüyoruz -1 for hatalar -1
        }
        if (n == 0) // EOF yani okuyacak bir şey kalmadığı için 0 döncez return
        {
            free(new_node->data);
            free(new_node);
            return (0);
        }
        
        new_node->number_of_used_bytes = n;
        new_node->next = NULL;

        ekle_sona_ekle(head, new_node);

        if (check_newline(new_node))
        {
            return (1);
        }
    }
}

char *gnl(int fd)
{
    static t_okuma_chunk_burkay_bey *head = NULL;
    char *satır;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return ;

    // TOPLAMA
    toplayici(fd, &head);


    // ÇIKARMA
    satır = çıkarıcı(&head);
    

    // TEMİZLEME
    temizleyiciii(&head);
    
    return satır;
}


int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return 1;

    printf("--- GNL TEST BASLIYOR BURKAY BEEEY ---\n");
    while (1)
    {
        line = gnl(fd);
        if (!line)
            break;
            
        printf("GELEN SATIR: %s", line);
        free(line);
    }
    printf("\n--- GNL TEST BITTII BURKAY BEEEY---\n");
    
    close(fd);
    return 0;
}