#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int sayi,sure,puan=0,saniye,kackere=0;
	char tus,sorulan,alinan,alfabe[] = "abcdefghijklmnopqrstuvwxyz";
	time_t start,end;
	sure = time(NULL);
	srand(sure);
	
	printf("Lutfen harflerin girilmesi icin gereken sureyi belirleyiniz\n");
	scanf("%d", &saniye);
	
	sayi = 26 * (rand() / (RAND_MAX + 1.0));
	sorulan = alfabe[sayi];
	printf("'%c' harfini giriniz\n", sorulan);
	sure = time(NULL);
	while (1)
	{
		if (kbhit())
		{
		time(&start);
		tus = getch();
		time(&end);
			if (tus == 2)
			{
			printf("Puaniniz: %d Toplam %d tusa bastiniz.\nProgramdan cikmak icin enter.", puan, kackere);
			break;
			}
			else
			{
			kackere = kackere + 1;
			alinan = tus;
				if (sorulan == alinan && (time(NULL) - sure) <= saniye && difftime(end,start)<=saniye)
				{
				printf("'%c' harfini girdiniz\n\n",tus);
				puan = puan + 5;
				}
				else
				{
				printf("-----harfi belirtilen surede giremediniz ya da yanlis harf girdiniz-----\n\n\a\a\a");
				puan = puan -3;
				}
				sayi = 26 * (rand() / (RAND_MAX + 1.0));
				sorulan = alfabe[sayi];
				printf("'%c' harfini giriniz\n", sorulan);
				sure = time(NULL);
			}
		}
	}
getch();
return 0;
}
