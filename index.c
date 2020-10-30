#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int sayi[2][15] = {{18060311, 20060045, 19061091, 20060134, 20060678, 18061086, 20060032, 20060067, 19060456, 18060245, 20060110, 20060234, 20060141, 20060011, 20060012},
                       {40, 50, 75, 90, 40, 75, 50, 60, 60, 75, 40, 90, 60, 50, 60}};
int N=15;

int main(void)
{    for (int i = 0; i < N; i++)
    {
        printf("%d-%d\n",sayi[0][i],sayi[1][i]);
    }
     printf("---------------\n");
    ekle(sayi);

    for (int i = 0; i < N; i++)
    {
        printf("%d-%d\n",sayi[0][i],sayi[1][i]);
    }
    printf("---------------\n");
    yazdir(sayi,50);
    printf("---------------\n");

    degistir(sayi,20060234,80);
    for (int i = 0; i < N; i++)
    {
        printf("%d-%d\n",sayi[0][i],sayi[1][i]);
    }
}

degistir(int sayi[2][15],int ogrNo,int yeniNot){
     for (int i = 0; i < N; i++)
    {
        if (sayi[0][i]==ogrNo)
        {
            sayi[1][i]=yeniNot;
            break;
        }
        
    }

    ekle(sayi);
}

ekle(int sayi[2][15]){
    int i, gecici, tut;
    for (gecici = 1; gecici < N; gecici++)
    {
        for (i = 0; i < 15 - 1; i++)
        {
            if (sayi[1][i] < sayi[1][i + 1])
            {
                tut = sayi[1][i];
                sayi[1][i] = sayi[1][i + 1];
                sayi[1][i + 1] = tut;

                tut = sayi[0][i];
                sayi[0][i] = sayi[0][i + 1];
                sayi[0][i + 1] = tut;



            }
              else if (sayi[1][i] == sayi[1][i + 1])
            {
                if (sayi[0][i] > sayi[0][i + 1])
                {
                    tut = sayi[0][i];
                    sayi[0][i] = sayi[0][i + 1];
                    sayi[0][i + 1] = tut;

                    tut = sayi[1][i];
                    sayi[1][i] = sayi[1][i + 1];
                    sayi[1][i + 1] = tut;
                }
            } 
          
        }
    } 
}

yazdir(int sayi[2][15],int puan){
    for (int i = 0; i < N; i++)
    {
        if (sayi[1][i]>=puan)
        {
            printf("%d-%d\n",sayi[0][i],sayi[1][i]);
        }
        
    }
    
}

sil(int sayi[2][15],int indis){
    
}