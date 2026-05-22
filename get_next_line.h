#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_

// chunklar halinde okicaz o yüzden bir strcut oluşturalım linked list yapısı
struct okuma_chunk_burkay_bey
{
    char* data;
    int number_of_used_bytes;
    // sonraki node'a geçebilmek için aynı veri türüne ait bir değişkeni de barındırıyor anladınız mı?
    struct okuma_chunk_burkay_bey* next;
};

#endif