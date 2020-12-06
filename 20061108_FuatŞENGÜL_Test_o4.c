#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Etler
{
    char etUrunuKarakter;
    char paketlemeTarih[12];
    char sonKullanmaTarihi[12];
} et;

typedef struct TarimUrunleri
{
    char tarimUrunuKarakter;
    char alinmaTarihi[12];
} tarim;

typedef struct SutUrunleri
{
    char sonKullanmaTarihi[12];
} sut;

typedef struct KonserveUrunleri
{
    int reyonNumarasi;
    char reyonTarafi;
    char sonKullanmaTarihi[7];
} konserve;

typedef struct GidaDisi
{
    char gidaUrunuKarakter;
    int reyonNumarasi;
    char reyonTarafi;
} gida;

typedef struct UrunEkVeri
{
    et *etBaglanti;
    tarim *tarimBaglanti;
    sut *sutBaglanti;
    konserve *konserveBaglanti;
    gida *gidaBaglanti;
} iliski;

typedef struct UrunBilgi
{
    char urunAdi[20];
    int urunMaliyet;
    char urunKategori;
    struct UrunBilgi *next;
    iliski *iliskiBaglanti;
} urun_bilgi;

urun_bilgi *baslangic = NULL;
iliski *mevcut = NULL;

urun_bilgi *destroy(urun_bilgi *baslangic)
{
    if (baslangic == NULL)
    {
        printf("Liste zaten bos\n");
        return baslangic;
    }
    urun_bilgi *temp2;
    while (baslangic != NULL)
    { // while içindeki koşul temp2 -> next, NULL değilse
        temp2 = baslangic;
        baslangic = baslangic->next;
        free(temp2);
    }
    return baslangic;
}

int urun_kaydet(char isim[20], int fiyat, char kategori, iliski *data)
{
    urun_bilgi *temp, *ptr;
    temp = (urun_bilgi *)malloc(sizeof(urun_bilgi));

    strcpy(temp->urunAdi, isim);
    temp->urunMaliyet = fiyat;
    temp->urunKategori = kategori;
    temp->iliskiBaglanti = data;
    temp->next = NULL;

    if (baslangic == NULL)
    {
        baslangic = temp;
    }
    else
    {
        ptr = baslangic;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    return 1;
}
int urun_goster()
{
    if (baslangic == NULL)
    {
        printf("Listede eleman yok");
        return 0;
    }
    printf("-----------------Kayıtlı Ürünler-----------------\n");
    urun_bilgi *temp2 = baslangic;
    while (temp2 != NULL)
    {
        if (temp2->urunKategori == 'E')
        {
            printf("%s %d TL %c %s %s\n", temp2->urunAdi,
                   temp2->urunMaliyet,
                   temp2->iliskiBaglanti->etBaglanti->etUrunuKarakter,
                   temp2->iliskiBaglanti->etBaglanti->paketlemeTarih,
                   temp2->iliskiBaglanti->etBaglanti->sonKullanmaTarihi);
        }
        if (temp2->urunKategori == 'T')
        {
            printf("%s %d TL %c %s\n", temp2->urunAdi,
                   temp2->urunMaliyet,
                   temp2->iliskiBaglanti->tarimBaglanti->tarimUrunuKarakter,
                   temp2->iliskiBaglanti->tarimBaglanti->alinmaTarihi);
        }
        if (temp2->urunKategori == 'K')
        {
            printf("%s %d TL %c %d %s\n", temp2->urunAdi,
                   temp2->urunMaliyet,
                   temp2->iliskiBaglanti->konserveBaglanti->reyonTarafi,
                   temp2->iliskiBaglanti->konserveBaglanti->reyonNumarasi,
                   temp2->iliskiBaglanti->konserveBaglanti->sonKullanmaTarihi);
        }
        if (temp2->urunKategori == 'G')
        {
            printf("%s %d TL %c %d %c\n", temp2->urunAdi,
                   temp2->urunMaliyet,
                   temp2->iliskiBaglanti->gidaBaglanti->gidaUrunuKarakter,
                   temp2->iliskiBaglanti->gidaBaglanti->reyonNumarasi,
                   temp2->iliskiBaglanti->gidaBaglanti->reyonTarafi);
        }
        if (temp2->urunKategori == 'S')
        {
            printf("%s %d TL %s\n", temp2->urunAdi,
                   temp2->urunMaliyet,
                   temp2->iliskiBaglanti->sutBaglanti->sonKullanmaTarihi);
        }
        temp2 = temp2->next;
    }
    printf("-------------------------------------------------\n");
    return 1;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Turkish");

    char kategori;
    char isim[20];
    int fiyat;
    et etUrunVeri;
    tarim tarimUrunVeri;
    sut sutUrunVeri;
    konserve konserveUrunVeri;
    gida gidaUrunVeri;

    while (1)
    {

        printf("Ürün Kategorisi Seçiniz (E,T,S,K,G) ->");
        scanf("%s", &kategori);

        printf("\n");

        getchar();
        printf("Ürün adını giriniz ->");
        scanf("%[^\n]", &isim);

        printf("\n");

        printf("Ürünün TL cinsinden birim maliyetini giriniz ->");
        scanf("%d", &fiyat);

        printf("\n");

        switch (kategori)
        {
        case 'E':

            printf("Et türünü gösteren karakter(R: Kırmızı Et, B: Balık, P : Tavuk) ->");
            scanf("%s", &etUrunVeri.etUrunuKarakter);

            printf("\n");

            printf("Paketleme Tarihi(##-##-####) ->");
            scanf("%s", &etUrunVeri.paketlemeTarih);

            printf("\n");

            printf("Son Kullanma Tarihi(##-##-####) ->");
            scanf("%s", &etUrunVeri.sonKullanmaTarihi);

            et *etUrun = (et *)malloc(sizeof(et));
            etUrun->etUrunuKarakter = etUrunVeri.etUrunuKarakter;
            strcpy(etUrun->paketlemeTarih, etUrunVeri.paketlemeTarih);
            strcpy(etUrun->sonKullanmaTarihi, etUrunVeri.sonKullanmaTarihi);

            iliski *data1 = (iliski *)malloc(sizeof(iliski));
            data1->etBaglanti = etUrun;
            urun_kaydet(isim, fiyat, kategori, data1);

            break;
        case 'T':

            printf("Tarım türünü gösteren karakter (M: Meyve, S: Sebze) ->");
            scanf("%s", &tarimUrunVeri.tarimUrunuKarakter);

            printf("\n");

            printf("Alınma Tarihi(##-##-####) ->");
            scanf("%s", &tarimUrunVeri.alinmaTarihi);

            tarim *tarimUrun = (tarim *)malloc(sizeof(tarim));
            tarimUrun->tarimUrunuKarakter = tarimUrunVeri.tarimUrunuKarakter;
            strcpy(tarimUrun->alinmaTarihi, tarimUrunVeri.alinmaTarihi);

            iliski *data2 = (iliski *)malloc(sizeof(iliski));
            data2->tarimBaglanti = tarimUrun;

            urun_kaydet(isim, fiyat, kategori, data2);
            break;
        case 'S':

            printf("Son Kullanma Tarihi(##-##-####) ->");
            scanf("%s", &sutUrunVeri.sonKullanmaTarihi);

            sut *sutUrun = (sut *)malloc(sizeof(sut));
            strcpy(sutUrun->sonKullanmaTarihi, sutUrunVeri.sonKullanmaTarihi);

            iliski *data3 = (iliski *)malloc(sizeof(iliski));
            data3->sutBaglanti = sutUrun;

            urun_kaydet(isim, fiyat, kategori, data3);
            break;
        case 'K':

            printf("Reyon numarası (bir tam sayı) ->");
            scanf("%d", &konserveUrunVeri.reyonNumarasi);

            printf("\n");

            printf("Reyon Tarafı (A ya da B) ->");
            scanf("%s", &konserveUrunVeri.reyonTarafi);

            printf("\n");

            printf("Son Kullanma Tarihi (##-####) ->");
            scanf("%s", &konserveUrunVeri.sonKullanmaTarihi);

            konserve *konserveUrun = (konserve *)malloc(sizeof(konserve));
            strcpy(konserveUrun->sonKullanmaTarihi, konserveUrunVeri.sonKullanmaTarihi);
            konserveUrun->reyonNumarasi = konserveUrunVeri.reyonNumarasi;
            konserveUrun->reyonTarafi = konserveUrunVeri.reyonTarafi;

            iliski *data4 = (iliski *)malloc(sizeof(iliski));
            data4->konserveBaglanti = konserveUrun;

            urun_kaydet(isim, fiyat, kategori, data4);
            break;
        case 'G':

            printf("Türünü gösteren karakter(C: Temizlik Ürünleri, P: Eczane, D :Diğer ürünler) ->");
            scanf("%s", &gidaUrunVeri.gidaUrunuKarakter);

            printf("\n");

            printf("Reyon numarası (bir tam sayı) ->");
            scanf("%d", &gidaUrunVeri.reyonNumarasi);

            printf("\n");

            printf("Reyon Tarafı (A ya da B) ->");
            scanf("%s", &gidaUrunVeri.reyonTarafi);

            gida *gidaUrun = (gida *)malloc(sizeof(gida));
            gidaUrun->gidaUrunuKarakter = gidaUrunVeri.gidaUrunuKarakter;
            gidaUrun->reyonNumarasi = gidaUrunVeri.reyonNumarasi;
            gidaUrun->reyonTarafi = gidaUrunVeri.reyonTarafi;

            iliski *data5 = (iliski *)malloc(sizeof(iliski));
            data5->gidaBaglanti = gidaUrun;

            urun_kaydet(isim, fiyat, kategori, data5);
            break;
        default:
            printf("Bu şekilde bir ürün kategorisi bulunamadı!!!\n");
            break;
        }

        urun_goster();
    }

    return 0;
}
