#include <stdlib.h>
#include <stdio.h>

double aylikOdemeHesapla(double ,double , double );/* öncelikli bu alt fonksiyonumuz olduðunu belirttik */
double ustcarp(double faiz,double taksit);/* üst alma fonksiyonumuzu baþtan belirttik */


int main(){
    double krediTutari,faizOrani,taksitSayisi;   /*  kullanýcýdan kredi tutari faiz orani taksit sayisini kullanýcýdan aldýk scanflede belleðe kaydettik */
    printf("ALMAK ISTEDIGINIZ KREDI MIKTARI : ");
    scanf("%lf",&krediTutari);
    printf("BANKA FAIZ ORANI : ");
    scanf("%lf",&faizOrani);
    printf("KAC TAKSIT : ");
    scanf("%lf",&taksitSayisi);
    aylikOdemeHesapla(krediTutari,faizOrani,taksitSayisi);/* double fonksiyonu içine gönderdik kredi faiz ve taksiti hesaplamak için */
	return 0;
}


double aylikOdemeHesapla(double krediTutari,double faizOrani, double taksitSayisi){
    
    double ustal;/* üst aldýðýmýz sayýyý ustal eþitlemek için iþleme sokamabilmek için baþka bi deðiþkene eþitledik   */
	ustal=ustcarp(faizOrani,taksitSayisi); /* return ile gelen sayýyý ustal eþitledik   */
	
	
	faizOrani=faizOrani/100;/* faizin yüzdesini aldýk   */
    double TaksitTutari=krediTutari*(faizOrani*ustal)/(ustal-1);/* aylýk ödenecek tutarý hesapladýk   */
    
    double toplamkredi;/*deðiþken belirkeldik    */
    toplamkredi=TaksitTutari*taksitSayisi;/* aylýk ödenecek tutarý taksit sayýyla çarptýk faizle ödenecek toplam tutarý hesapladýk   */
  
		printf("\nTaksit No         Taksit Tutari     Odenen Faiz Tutari        Odenen Ana Para Tutari         Kalan Ana Para Borcu\n");
		  double i;
		for (  i=1;i<=taksitSayisi ;i++){/*taksit sayýsý kadar taksit noyu yazdýrmak sýrasýyla ve taksit tutari ödenen faiz ana para ve kalan para yazdýrmak için bi forla tüm iþlemleri onun içinde yaptýk    */
		double odenenfaiz;/*  ödenen faiz hesaplamak için deðiþken double deðiþkeni tanýmladýk  */
		double odenenanapara=TaksitTutari;/*taksit tutarýný aylýk hesabýný ödenenenparayý hesaplamak için eþitledik taksit tutarýný iþlem yaparak deðiþmesin diye    */
	    double kalanpara;/* kalan para hesaplamak için double deðiþkeni belirledik   */
	   
		odenenfaiz=(krediTutari*faizOrani);/*  ödenen aylýk faiz tutarýný hesapladýk   */
		odenenanapara=odenenanapara-odenenfaiz;/* ödediðimiz ana parayý hesaplamak için aylýk ödenen faiz oranýndan çýkarttýk   */
		
	
		kalanpara=krediTutari-odenenanapara;/*  ödüyceðimiz kalan parayý hesapladýk  */
		
		krediTutari=krediTutari-odenenanapara; /*çekilen kredi miktarý ödenenen ana paradan çýkarttýp ödenecek diðer aydaki ödenen faiz oranlarýný hesaplamak için  */
		
			printf("%0.0lf\t\t     %0.2lf\t\t%0.2lf\t\t             %0.2lf\t\t\t  %0.2lf\n",i,TaksitTutari,odenenfaiz,odenenanapara,kalanpara);/*ekrana yazdýrdýk hesaplamalarýmýzý  */
	         
			}
			
		printf("\nAylik Odemeniz:    %0.2lf\n",TaksitTutari);/* aylýk ödüyceðimiz parayý ekrana yazdýrdýk */
		printf("Toplam Kredi Odemesi:    %0.2lf",toplamkredi); /* ödüyceðimiz faizle beraber toplam parayý hesapladýk  */
}



 double ustcarp(double faiz,double taksit){  /*double fonksiyonumuzda faiz ile taksit aldýk üst almak için bu fonksiyon kullandýk    */

   double sonuc=1; /* eðer kullanýcý taksit sayýsýný 1 yaparsa girelen faiz eþit olmasý için sonucu 1 eþitledik eðer taksit 0 olursada fora girmeden 1 sonucu versin   */
    faiz=faiz/100; /*faiz 100 desini aldýk    */
    faiz=1+faiz; /* formuldeki hesaplamayý uyguladýk */
    double i;	
	for( i=0;i<taksit;i++){ /* girelen taksit sayýsý kadar for döndürsün üst alsýn  */
		sonuc=sonuc*faiz; /* faiz oraný girilen taksit sayýsý kadar sürekli faizle çarpmasý için   */
		
	}
	
	return sonuc;/*  geriye üst aldýðýmýz sayýyý göndermesi için  return terim kullandýk */
 }



