#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int ders,ogrenci;
	printf("Ders ve ogrenci  sayini giriniz : ");
	scanf("%d",&ders);
	scanf("%d",&ogrenci);
	float notlar[ders][ogrenci];
	int i,j;
	for(i=0;i<ders;i++)
	{
		for(j=0;j<ogrenci;j++)
		{
			printf("%d. dersten  %d. ogrencinin aldigi notu girin : ",i+1,j+1);
			scanf("%f",&notlar[i][j]);
		}
	}
	float ortalama[i];
	for(i=0;i<ders;i++)
	{
		for(j=0;j<ogrenci;j++)
		{
			printf("%d. dersten  %d. ogrencinin aldigi notu : %.1f , ",i+1,j+1,notlar[i][j]);
			ortalama[i]+=notlar[i][j];
			
		}
		ortalama[i]/=ogrenci;
		
		printf("\n");
	}
	for(i=0;i<ders;i++)
	printf("%d. dersin ortalamasi: %.1f,\n",i+1,ortalama[i]);
	
	
	
	
	
	
	return 0;
}
