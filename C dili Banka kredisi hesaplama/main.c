#include <stdlib.h>
#include <stdio.h>

double aylikOdemeHesapla(double ,double , double );/* �ncelikli bu alt fonksiyonumuz oldu�unu belirttik */
double ustcarp(double faiz,double taksit);/* �st alma fonksiyonumuzu ba�tan belirttik */


int main(){
    double krediTutari,faizOrani,taksitSayisi;   /*  kullan�c�dan kredi tutari faiz orani taksit sayisini kullan�c�dan ald�k scanflede belle�e kaydettik */
    printf("ALMAK ISTEDIGINIZ KREDI MIKTARI : ");
    scanf("%lf",&krediTutari);
    printf("BANKA FAIZ ORANI : ");
    scanf("%lf",&faizOrani);
    printf("KAC TAKSIT : ");
    scanf("%lf",&taksitSayisi);
    aylikOdemeHesapla(krediTutari,faizOrani,taksitSayisi);/* double fonksiyonu i�ine g�nderdik kredi faiz ve taksiti hesaplamak i�in */
	return 0;
}


double aylikOdemeHesapla(double krediTutari,double faizOrani, double taksitSayisi){
    
    double ustal;/* �st ald���m�z say�y� ustal e�itlemek i�in i�leme sokamabilmek i�in ba�ka bi de�i�kene e�itledik   */
	ustal=ustcarp(faizOrani,taksitSayisi); /* return ile gelen say�y� ustal e�itledik   */
	
	
	faizOrani=faizOrani/100;/* faizin y�zdesini ald�k   */
    double TaksitTutari=krediTutari*(faizOrani*ustal)/(ustal-1);/* ayl�k �denecek tutar� hesaplad�k   */
    
    double toplamkredi;/*de�i�ken belirkeldik    */
    toplamkredi=TaksitTutari*taksitSayisi;/* ayl�k �denecek tutar� taksit say�yla �arpt�k faizle �denecek toplam tutar� hesaplad�k   */
  
		printf("\nTaksit No         Taksit Tutari     Odenen Faiz Tutari        Odenen Ana Para Tutari         Kalan Ana Para Borcu\n");
		  double i;
		for (  i=1;i<=taksitSayisi ;i++){/*taksit say�s� kadar taksit noyu yazd�rmak s�ras�yla ve taksit tutari �denen faiz ana para ve kalan para yazd�rmak i�in bi forla t�m i�lemleri onun i�inde yapt�k    */
		double odenenfaiz;/*  �denen faiz hesaplamak i�in de�i�ken double de�i�keni tan�mlad�k  */
		double odenenanapara=TaksitTutari;/*taksit tutar�n� ayl�k hesab�n� �denenenparay� hesaplamak i�in e�itledik taksit tutar�n� i�lem yaparak de�i�mesin diye    */
	    double kalanpara;/* kalan para hesaplamak i�in double de�i�keni belirledik   */
	   
		odenenfaiz=(krediTutari*faizOrani);/*  �denen ayl�k faiz tutar�n� hesaplad�k   */
		odenenanapara=odenenanapara-odenenfaiz;/* �dedi�imiz ana paray� hesaplamak i�in ayl�k �denen faiz oran�ndan ��kartt�k   */
		
	
		kalanpara=krediTutari-odenenanapara;/*  �d�yce�imiz kalan paray� hesaplad�k  */
		
		krediTutari=krediTutari-odenenanapara; /*�ekilen kredi miktar� �denenen ana paradan ��kartt�p �denecek di�er aydaki �denen faiz oranlar�n� hesaplamak i�in  */
		
			printf("%0.0lf\t\t     %0.2lf\t\t%0.2lf\t\t             %0.2lf\t\t\t  %0.2lf\n",i,TaksitTutari,odenenfaiz,odenenanapara,kalanpara);/*ekrana yazd�rd�k hesaplamalar�m�z�  */
	         
			}
			
		printf("\nAylik Odemeniz:    %0.2lf\n",TaksitTutari);/* ayl�k �d�yce�imiz paray� ekrana yazd�rd�k */
		printf("Toplam Kredi Odemesi:    %0.2lf",toplamkredi); /* �d�yce�imiz faizle beraber toplam paray� hesaplad�k  */
}



 double ustcarp(double faiz,double taksit){  /*double fonksiyonumuzda faiz ile taksit ald�k �st almak i�in bu fonksiyon kulland�k    */

   double sonuc=1; /* e�er kullan�c� taksit say�s�n� 1 yaparsa girelen faiz e�it olmas� i�in sonucu 1 e�itledik e�er taksit 0 olursada fora girmeden 1 sonucu versin   */
    faiz=faiz/100; /*faiz 100 desini ald�k    */
    faiz=1+faiz; /* formuldeki hesaplamay� uygulad�k */
    double i;	
	for( i=0;i<taksit;i++){ /* girelen taksit say�s� kadar for d�nd�rs�n �st als�n  */
		sonuc=sonuc*faiz; /* faiz oran� girilen taksit say�s� kadar s�rekli faizle �arpmas� i�in   */
		
	}
	
	return sonuc;/*  geriye �st ald���m�z say�y� g�ndermesi i�in  return terim kulland�k */
 }



