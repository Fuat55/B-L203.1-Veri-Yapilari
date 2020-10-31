/*
Öğrenci No: 20110608
Ad SOyad: Fuat ŞENGÜL
Konu: Veri Yapıları Dersi / Index Tablosu Oluşturma
*/
#include <stdio.h>

int N = 15;
int ogrenciNotlari[2][15] = {{18060311, 20060045, 19061091, 20060134, 20060678, 18061086, 20060032, 20060067, 19060456, 18060245, 20060110, 20060234, 20060141, 20060011, 20060012},
                             {40, 50, 75, 90, 40, 75, 50, 60, 60, 75, 40, 90, 60, 50, 60}};

int index[15];
int main()
{
    //ekle();
    //sil(5,index);
    //degistir(18060245,90);
    //yazdir(55);
}

ekle()
{
    int i;
    int j;
    for (i = 0; i < N; i++)
    {
        index[i] = i;
    }

    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            int temp;

            if (ogrenciNotlari[1][index[i]] < ogrenciNotlari[1][index[j]])
            {
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
            else if (ogrenciNotlari[1][index[i]] == ogrenciNotlari[1][index[j]])
            {
                if (ogrenciNotlari[0][index[i]] > ogrenciNotlari[0][index[j]])
                {
                    temp = index[i];
                    index[i] = index[j];
                    index[j] = temp;
                }
            }
        }
    }
}

sil(int ind)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (index[i] == ind)
        {
            break;
        }
    }

    for (int j = i; j < N; j++)
    {
        index[j] = index[j + 1];
    }
}

degistir(int ogrNo, int yeniNot)
{

    int i;
    for (int i = 0; i < N; i++)
    {
        if (ogrenciNotlari[0][i] == ogrNo)
        {
            ogrenciNotlari[1][i] = yeniNot;
            break;
        }
    }

    ekle(ogrenciNotlari, index);
}

yazdir(int filtreNot)
{

    int i;
    for (i = N-1; i>0; i--)
    {
        if (ogrenciNotlari[1][index[i]] > filtreNot)
        {
            break;
        }
    }
     
    
    for (int j = 0; j <=i; j++)
    {
        printf("%d-%d\n", ogrenciNotlari[0][index[j]], ogrenciNotlari[1][index[j]]);
    }
}
