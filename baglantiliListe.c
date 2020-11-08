/*
Öğrenci No: 20110608
Ad Soyad: Fuat ŞENGÜL
Konu: Veri Yapıları Dersi / Bağlantılı Liste İndex Tablosu
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Musteri
{
    char *_musteriAdi;
    int _faturaMiktari;
    struct Musteri *next;
} _musteri;

typedef struct MusteriSira
{
    char *_musteriAdi;
    int _faturaMiktari;
    struct MusteriSira *next;

} _musteriSira;

typedef struct FaturaSira
{
    char *_musteriAdi;
    int _faturaMiktari;
    struct FaturaSira *next;

} _faturaSira;

_musteri *_firstMusteri = NULL, *p, *q; //Müsteri Normal Ekleme
_faturaSira *_firstFatura = NULL, *temp, *fatura;
_musteriSira *_firstM = NULL, *tempM, *musteriS;

void ekleMusteri(char *, int);
void yazdirAd(char *);
void yazdirTutar(int);
void SiralaFatura(char *, int miktar);
void SiralaMusteriAdi(char *, int miktar);
int main()
{
    ekleMusteri("Ahmet", 100);
    ekleMusteri("Bilal", 1000);
    ekleMusteri("Cemal", 600);
    ekleMusteri("Adem", 650);
    ekleMusteri("Yasin", 350);
    ekleMusteri("Esin", 270);
    ekleMusteri("Emel", 410);
    ekleMusteri("Mustafa", 750);
    ekleMusteri("Ayten", 600);
    ekleMusteri("Ceylan", 1000);
    ekleMusteri("Nesrin", 900);
    ekleMusteri("Bekir", 850);
    ekleMusteri("Emin", 790);
    ekleMusteri("Hakan", 610);
    ekleMusteri("Hatice", 550);
    while (p != NULL)
    {
        SiralaFatura(p->_musteriAdi, p->_faturaMiktari);
        p = p->next;
    }
    while (q != NULL)
    {
        SiralaMusteriAdi(q->_musteriAdi, q->_faturaMiktari);
        q = q->next;
    }  
    yazdirAd("A");
    printf("--------\n");
    yazdirTutar(900);
}

void ekleMusteri(char *musteriAdi, int faturaMiktari)
{
    int i = 0;
    _musteri *_yeniMusteri = (_musteri *)malloc(sizeof(_musteri));
    _yeniMusteri->_musteriAdi = musteriAdi;
    _yeniMusteri->_faturaMiktari = faturaMiktari;
    _yeniMusteri->next = _firstMusteri;
    _firstMusteri = _yeniMusteri;

    if (i == 0)
    {
        p = _firstMusteri;
        q = _firstMusteri;
        i++;
    }
}
void SiralaMusteriAdi(char *ad, int miktar)
{

    if (_firstM == NULL)
    {
        _firstM = (_musteriSira *)malloc(sizeof(_musteriSira));
        _firstM->_musteriAdi = ad;
        _firstM->_faturaMiktari = miktar;
        _firstM->next = NULL;
    }
    else
    {
        if (strcmp(_firstM->_musteriAdi, ad) > 0)
        {
            musteriS = (_musteriSira *)malloc(sizeof(_musteriSira));
            musteriS->_musteriAdi = ad;
            musteriS->_faturaMiktari = miktar;
            musteriS->next = _firstM;
            _firstM = musteriS;
        }
        else
        {
            tempM = _firstM;
            musteriS = (_musteriSira *)malloc(sizeof(_musteriSira));
            musteriS->_faturaMiktari = miktar;
            musteriS->_musteriAdi = ad;

            while (tempM != NULL)
            {
                if (tempM->next == NULL && (strcmp(tempM->_musteriAdi, ad) <= 0))
                {
                    musteriS->next = NULL;
                    tempM->next = musteriS;
                    break;
                }

                if (strcmp(tempM->next->_musteriAdi, ad) > 0)
                {
                    musteriS->next = tempM->next;
                    tempM->next = musteriS;
                    break;
                }
                tempM = tempM->next;
            }
        }
    }
}
void SiralaFatura(char *ad, int miktar)
{

    if (_firstFatura == NULL)
    {
        _firstFatura = (_faturaSira *)malloc(sizeof(_faturaSira));
        _firstFatura->_musteriAdi = ad;
        _firstFatura->_faturaMiktari = miktar;
        _firstFatura->next = NULL;
    }
    else
    {
        if ((_firstFatura->_faturaMiktari) < (miktar))
        {
            fatura = (_faturaSira *)malloc(sizeof(_faturaSira));
            fatura->_musteriAdi = ad;
            fatura->_faturaMiktari = miktar;
            fatura->next = _firstFatura;
            _firstFatura = fatura;
        }
        else
        {
            temp = _firstFatura;
            fatura = (_faturaSira *)malloc(sizeof(_faturaSira));
            fatura->_faturaMiktari = miktar;
            fatura->_musteriAdi = ad;

            while (temp != NULL)
            { 
                if (temp->next == NULL && (temp->_faturaMiktari) >= (miktar))
                {
                    fatura->next = NULL;
                    temp->next = fatura;
                    break;
                } 
                if ((temp->next->_faturaMiktari) < (miktar))
                {
                    fatura->next = temp->next;
                    temp->next = fatura;
                    break;
                }
                temp = temp->next;
            }
        }
    }
}
void yazdirAd(char *ad)
{
    int iter = 0, i = 0;
    if (_firstM == NULL)
    {
        printf("Liste Bos\n");
    }
    else
    {
        tempM = _firstM;

        while (tempM != NULL)
        {   
            if (strncmp(tempM->_musteriAdi,ad,1)==0)
            {
               iter++;
            }else
            {
                break;
            }
            

            
            tempM = tempM->next;
        }
    }
    tempM = _firstM;
    while (i < iter)
    {
        printf("%s - %d\n", tempM->_musteriAdi, tempM->_faturaMiktari);
        i++;
        tempM = tempM->next;
    }
}
void yazdirTutar(int tutar)
{
    int iter = 0, i = 0;
    if (_firstFatura == NULL)
    {
        printf("Liste Bos\n");
    }
    else
    {
        temp = _firstFatura;

        while (temp != NULL)
        {
            if (temp->_faturaMiktari < tutar)
            {
                break;
            }

            iter++;
            temp = temp->next;
        }
    }
    temp = _firstFatura;
    while (i < iter)
    {
        printf("%s - %d\n", temp->_musteriAdi, temp->_faturaMiktari);
        i++;
        temp = temp->next;
    }
}
