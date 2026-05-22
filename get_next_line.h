#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 24


// chunklar halinde okicaz o yüzden bir strcut oluşturalım linked list yapısı
typedef struct s_okuma_chunk_burkay_bey
{
    char* data;
    int number_of_used_bytes;
    // sonraki node'a geçebilmek için aynı veri türüne ait bir değişkeni de barındırıyor anladınız mı?
    struct okuma_chunk_burkay_bey* next;
} t_okuma_chunk_burkay_bey;



#endif