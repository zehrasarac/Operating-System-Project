#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sistemcagrisi(){
    printf("Sistem Cagrisi\n");
}

void surecbasladi(){
    char *s1 = "Surec Basladi";
    printf("%s\n",s1);
}

void surecbitti(){
    printf("Surec Bitti\n");
}

void zamanlayicikesmesi(){
    printf("Zamanlayici Kesmesi\n");
}


void beklemeSuresi(int olaylar[], int n,
						int bt[], int wt[])
{

	wt[0] = 0;


	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}


void donusSuresi( int olaylar[], int n,
				int bt[], int wt[], int tat[])
{

	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void ortalamaSure( int olaylar[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;


	beklemeSuresi(olaylar, n, bt, wt);


	donusSuresi(olaylar, n, bt, wt, tat);


	printf("Surec Calisma Suresi Bekleme Suresi Geri Dönüş Suresi\n");


	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d ",(i+1));
		printf("	 	        %d ", bt[i] );
		printf("	 	        %d",wt[i] );
		printf("	 	        %d\n",tat[i] );
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat / (float)n;
	printf("Ortalama Bekleme Süresi = %d",s);
	printf("\n");
	printf("Ortalama Geri Dönüş Süresi = %d ",t);
}
void rastgeleOlay(int olaylar[], int olay_sayisi, int olay_tipi_s){
	srand(time(NULL));

	for (int i = 0; i < olay_sayisi; i++){
		olaylar[i] = rand() % olay_tipi_s;
	}
}

void olayCagir(int olayTipi){
	switch (olayTipi)
	{
	case 1:
		surecbasladi();
		break;
	case 2:
		sistemcagrisi();
		break;	
	case 3:
		surecbitti();
		break;
	
	case 4:
		zamanlayicikesmesi();
		break;
	}
}


int main()
{

	int olay_sayisi = 5;
    int olay_tipi_s = 4;

    
    int olaylar[olay_sayisi];
	rastgeleOlay(olaylar,olay_sayisi,olay_tipi_s);

    for (int i=0;i<4;i++){
		olayCagir(olaylar[i]);
	}

	
	int n = sizeof olaylar / sizeof olaylar[0];

	int donus_suresi[] = {10, 5, 8,3,6};

	ortalamaSure(olaylar, n, donus_suresi);



	return 0;
}