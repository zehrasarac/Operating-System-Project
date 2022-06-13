#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dosyaOlusturYaz(){
	FILE *dosya = fopen("simple-os.txt", "w");
   fprintf(dosya, "\nSimple OS System");
   fclose(dosya);
   printf("\nDosya oluþturma islemi basarili");
}
void dosyaSil(){
	int sonuc = remove("simple-os.txt");

  if(sonuc == 0){
    fprintf(stdout, "Dosya silindi ");
  } else {
    fprintf(stderr, "Dosya silinemedi");
  }

}
void dosyaOkuma(){
	FILE * dosya;
	char * veri;
	int veri_uzunlugu=40;
	int okunan=0;
	const char * dosya_adi="simple-os.txt";
 
	dosya=fopen(dosya_adi,"r");

	if(dosya==NULL){
		printf("Dosya acilamadý.");
	}

	veri=(char *)malloc(veri_uzunlugu);

	if(veri==NULL){
		printf("Bellek hatasý oluþtu.\n");
		fclose(dosya);
	}

	okunan=fread(veri,1,veri_uzunlugu,dosya);

	if(okunan>0){
		if(veri[okunan-1]!=0){
			veri[okunan-1]=0;
		}
	}

	printf("Okunan veri: %s\n",veri );
	printf("%s dosyasýndan %d bayt okundu.\n",dosya_adi,okunan);

	fclose(dosya);

	free(veri);
}
void sistemcagrisi(){
    printf("Sistem Cagrisi\n");
}

void surecbasladi(){
    printf("Surec Basladi\n");
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

	printf("Surec Calisma Suresi Bekleme Suresi Geri Dönüþ Suresi\n");

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
	printf("Ortalama Geri Dönüþ Süresi = %d ",t);
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
void tdonusSuresi(int olaylar[], int n,
int bt[], int wt[], int tat[]) {
   for (int i = 0; i < n ; i++)
   tat[i] = bt[i] + wt[i];
}
void tbeklemeSuresi(int olaylar[], int n,
int bt[], int wt[], int quantum) {
   int rem_bt[n];
   for (int i = 0 ; i < n ; i++)
   rem_bt[i] = bt[i];
   int t = 0; 

   while (1) {
      bool done = true;
      for (int i = 0 ; i < n; i++) {
         if (rem_bt[i] > 0) {
            done = false; 
            if (rem_bt[i] > quantum) {
               t += quantum;
               rem_bt[i] -= quantum;
            }
            else {
               t = t + rem_bt[i];
               wt[i] = t - bt[i];
               rem_bt[i] = 0;
            }
         }
      }
      if (done == true)
         break;
   }
}
void tortalamaSure(int olaylar[], int n, int bt[],
int quantum) {
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   tbeklemeSuresi(olaylar, n, bt, wt, quantum);
   tdonusSuresi(olaylar, n, bt, wt, tat);
   printf("Surec Calisma Suresi Bekleme Suresi Geri Dönüþ Suresi\n");
   for (int i=0; i<n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      printf("\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1, bt[i], wt[i], tat[i]);
   }
   printf("Ortalama Bekleme Suresi = %f", (float)total_wt / (float)n);
   printf("\nOrtalama Geri Dönüþ Suresi = %f\n", (float)total_tat / (float)n);
}

int main()
{
	int olay_sayisi = 5;
    int olay_tipi_s = 4;
	int quantum = 2;
 
    int olaylar[olay_sayisi];
	rastgeleOlay(olaylar,olay_sayisi,olay_tipi_s);

    for (int i=0;i<4;i++){
		olayCagir(olaylar[i]);
	}

	int n = sizeof olaylar / sizeof olaylar[0];

	int donus_suresi[] = {10, 5, 8,3,6};

	int cizelgelemeSecimi;
	menu:
	printf("\nYapmak istediginiz islemi seciniz:\n1.FCFS\n2.Round\n3.Dosya olustuma\n4.Dosya sil\n5.Dosya okuma\n");
	scanf("%d",&cizelgelemeSecimi);
	switch (cizelgelemeSecimi)
	{
	case 1:
		ortalamaSure(olaylar, n, donus_suresi);
		goto menu;
		break;
	case 2:
		tortalamaSure(olaylar, n, donus_suresi, quantum);
		goto menu;
		break;
	case 3:	
		dosyaOlusturYaz();
		goto menu;
		break;
	case 4:
		dosyaSil();
		goto menu;
		break;
	case 5:	
		dosyaOkuma();
		goto menu;
		break;	
	}

	return 0;
}