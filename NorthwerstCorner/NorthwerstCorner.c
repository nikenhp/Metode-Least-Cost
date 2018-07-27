
#include <stdio.h>
#include <conio.h>

int cost[10][10], alok[10][10];
int sup[10], dem[10];
int b, k, brs, kol, biaya;
int supply[10], demand[10];
int pil;

void input()
{
	int i,j;
	printf("Masukan jumlah sumber (Supply) = ");
	scanf("%d",&b);						//total supp diinputkan ke var b 
	printf("Masukan jumlah Tujuan (Demand) = ");
	scanf("%d",&k);						//total supply diinputkan ke var k
	printf("\n\n");
	if(dem==0 || sup==0) {
		printf("Jumlah Sumber dan Tujuan harus lebih dari 0 \n\n");
	}
	else
	{
		for(i=1; i<=b; i++) {
			printf("Masukkan Supply - %d = ", i);
			scanf("%d", &sup[i]);
			supply[i] = sup[i];
		}

		printf("\n");
		for(j=1;j<=k;j++){
			printf("Masukkan Demand - %d = " ,j);
			scanf("%d", &dem[j]);
			demand[j] = dem[j];

		}

		printf("\n\n");
		for(i=1; i<=b; i++){
			for(j=1; j<=k; j++){
				printf("Masukan cost matriks [%d,%d] = ", i,j);
				scanf("%d", &cost[i][j]);
			}
		}
	}
}

void hitung()
{
	int batas, i,j;
	batas = b+1;
	brs = 1;
	kol = 1;

	//karena NorthWest cost diminta utk alokasi terbesar dipojok kiri itu artinya alokasi terbesar di index[1][1] 

	do {
		if(sup[brs] <= dem[kol]){				//cek sup[1] <= dem[1]
			alok[brs][kol] = sup[brs];			//jika ya, alokasi[1][1] ditempati supp
			dem[kol] -= alok[brs][kol];			//pengurangan utk mencari kekurangan supp
			brs += 1;							//increment baris selanjutnya
		}else{
			alok[brs][kol] = dem[kol];			//cek[1][1] = dem [1]
			sup[brs] -= alok[brs][kol];			//jika ya, sup[1]-alokasi[1][1]
			kol += 1;							//increment utk kolom selanjutnya
		}
	}
	while (brs != batas);

	biaya = 0;
	for(i=1; i<=b; i++){
		for(j=1; j<=k; j++){
			biaya += (alok[i][j] * cost[i][j]);
		}
	}	

	printf("\n\n\n----- Tabel Awal -----\n");

	printf("\t\t");
    for (i=1; i<=b; i++)
		printf("  Tujuan %d\t|", i);
		printf(" Supply");

    for (j=1; j<=b; j++){
		printf("\n   Sumber %d \t|",j);
		for(i=1; i<=k; i++)
			printf("  %d\t\t|",cost[j][i]);		//cetak cost
			printf("  %d",supply[j]);			//cetak supply
    }

    printf("\n   Demand\t|");
    for(i=1; i<=k; i++)
		printf("  %d\t\t|",demand[i]);
		printf("\n\n\n");

	//Cetak Untuk Tabel hasil
    printf("\n\n----- Tabel Alokasi Hasil -----\n");
	printf("\t\t");
    for (i=1; i<=k; i++)
		printf("  Tujuan%d\t|", i);
		printf(" Supply");

    for (j=1; j<=b; j++){
		printf("\n   Sumber%d \t|",j);
		for(i=1; i<=k; i++)
		printf("  %d\t\t|",alok[j][i]);
		printf("  %d",supply[j]);
    }

    printf("\n   Demand\t|");
    for(i=1; i<=k; i++)
		printf("  %d\t\t|",demand[i]);
	printf("\n\n");

    printf("\nTotal biaya minimum adalah %d \n\n",biaya);
	getch();
}

void main()
{
	printf("-- Menu Aplikasi NWC --\n\n");
	printf("\n1. Niken Hastaning Putri	(2103161038)");
	printf("\n2. Ach Abiddurahman		(2103161048)");
	printf("\n3. Andre Tenosel		(2103161054)\n\n");
	input();
	hitung();
	getch();
}