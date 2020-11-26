/*
Öğrenci No: 20061108
Ad SOyad: Fuat ŞENGÜL
Konu: Veri Yapıları Dersi / LIFO ile Hanoi Kulesi Çözümü
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int deger;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
    int sayac;
} stck;

int ekle(stck *s, int t)
{
    if (s->sayac == 0)
    {
        node *n1 = (node *)malloc(sizeof(node));
        n1->deger = t;
        n1->next = s->top;
        s->sayac++;
        s->top = n1;

        return 1;
    }
    else
    {   

        if (s->top->deger > t)
        {
            node *n1 = (node *)malloc(sizeof(node));
            n1->deger = t;
            n1->next = s->top;
            s->top = n1;
            s->sayac++;
            return 1;
        }
        return 0;
    }
} 
int cikar(stck *s)
{
    node *n2 = s->top;
    s->sayac--;
    s->top = n2->next;
    int deger = n2->deger;
    free(n2);

    return deger;
}

void goster(stck *st)
{
    node *s = st->top;
    while (s != NULL)
    {
        printf("%d-", s->deger);
        s = s->next;
    }
    printf("\n");
}

void main()
{
    int cubukSayisi = 3;
    int cikanDeger = 0; 

    stck cubuk1, cubuk2, cubuk3;

    cubuk1.sayac = 0;
    cubuk1.top = NULL;

    cubuk2.sayac = 0;
    cubuk2.top = NULL;

    cubuk3.sayac = 0;
    cubuk3.top = NULL;

    for (int j = 3; j >= 1; j--)
    {
        ekle(&cubuk1, j);
    }
    

    printf("1. Çubuk:");
    goster(&cubuk1);
    printf("2. Çubuk:");
    goster(&cubuk2);
    printf("3. Çubuk:");
    goster(&cubuk3);
    printf("------------------------\n");

    for (size_t i = 1; i <= 7; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 7)
        { 
            cikanDeger=cikar(&cubuk1);
            if (ekle(&cubuk3, cikanDeger) == 0)
            {
                printf("İşlem:%d\n",i);
                ekle(&cubuk2, cikanDeger);
            }
        }

        if (i == 3)
        {
            printf("İşlem:%d\n",i);
            ekle(&cubuk2, cikar(&cubuk3));
        }
        if (i == 5 || i == 6)
        { 
            cikanDeger=cikar(&cubuk2);
            if (ekle(&cubuk1, cikanDeger) == 0)
            {
                printf("İşlem:%d\n",i);
                ekle(&cubuk3, cikanDeger);
            }
        }

        printf("1. Çubuk:");
        goster(&cubuk1);
        printf("2. Çubuk:");
        goster(&cubuk2);
        printf("3. Çubuk:");
        goster(&cubuk3);
        printf("------------------------\n");
    }
}
