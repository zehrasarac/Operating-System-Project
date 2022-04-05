//#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "surecbasladi.h"
#include "surecbitti.h"
#include "sistemcagrisi.h"
#include "zamanlayicikesmesi.h"

enum olaylar {e1,e2,e3,e4}; 
int olayMiktar = 4;

int main(int argc, char const *argv[])
{
    enum olaylar olay[olayMiktar];

    const char *olayN[] = {"surec basladi","surec bitti","sistem cagrisi","zamanlayici kesmesi"};

    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        clock_t tic = clock();
        olay[i] = rand() % 4;
        printf("%d. Olay ",olay[i]);
        printf("%s gerceklesti\n", olayN[olay[i]]);
        clock_t toc = clock();
        printf("%f saniye sürdü\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    }
    
    return 0;
}



