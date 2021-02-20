#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void goster(string,string,string,int ,int ,int ,double);
//method ile class karýþýmý birþey uydurdum private publiclerle neler yapýldýðýný normal dýþardaki fonksiyon farkýyla koymayý 
class profil{
	private :
		string cinsiyet;
		string ad;
		string soyad;
		int yas;
		int boy;
		int kilo;
		double hesap;
 public :
		string cinsiyet1;
		string ad1;
		string soyad1;
		int yas1;
		int boy1;
		int kilo1;
		double hesap1;
		 		
		
	void hesaplaendexPublic(string cinsiyet1,int yas1,int boy1){
		if(cinsiyet1=="ERKEK")
		hesap1 = (double(boy1) - 100 + double(yas1) / 10) * 0.9 ;
	
		if(cinsiyet1=="KADIN")
		hesap1 = (double(boy1) - 100 + double(yas1) / 10) * 0.8;	
	}
	void hesaplaendexPrivate(string cinsiyet,int yas,int boy){
		if(cinsiyet=="ERKEK")
		hesap = (double(boy) - 100.0 + double(yas) / 10) * 0.9;
		if(cinsiyet=="KADIN")
		hesap = (double(boy) - 100.0 + double(yas) / 10) * 0.9;
	}

//PRÝVATE KOY
	void cinsiyetkoy (string pcinsiyet){
   	cinsiyet=pcinsiyet;
   	
   }
   void adkoy(string pad){
   	ad=pad;
   
   }
   void soyadkoy(string psoyad){
   	soyad=psoyad;
  
   }
   void yaskoy(int pyas){
   	yas=pyas;
   
   }
  void boykoy(int pboy){
   	boy=pboy;
   	
   }
	void kilokoy(int pkilo){
   	kilo=pkilo;
   
   }
   
   
   
   //DÖNDÜR
   	string cinsiyetkoyR (){
   	
   	return cinsiyet;
   	
   }
   
   string adkoyR(){
   	
   	return ad;
   }
   
   string soyadkoyR(){
   
   	return soyad;
   }
   
   int yaskoyR(){
   	
   	return yas;
   }
   
   int boykoyR(){
   
   	return boy;
   }
   
	int kilokoyR(){
   	
   	return kilo;
   }
   
   int hesapdondurR(){
   	return hesap;
   }

	
};

int main(int argc, char** argv) {
	
	//direk konulan standartlarýmýz
		cout<<"NESNEMIZE KAYITLI OLAN ILK KISI"<<endl<<endl;
      profil nesne;
      nesne.cinsiyet1="ERKEK";
      nesne.ad1="sakir";
      nesne.soyad1="vural";
      nesne.yas1=21;
      nesne.boy1=185;
      nesne.kilo1=85;
      nesne.hesap1=10.0;
      nesne.hesaplaendexPublic(nesne.cinsiyet1,nesne.yas1,nesne.boy1);
      
	  goster(nesne.cinsiyet1,nesne.ad1,nesne.soyad1,nesne.yas1,nesne.boy1,nesne.kilo1,nesne.hesap1);//3 defa gösterceðim için sürekli cout yazmak yerine fonksiyon attým
	// nesnemize biz birþeyler koyduk
	cout<<"_______________________________________________________________________________________________________________________"<<endl<<endl;
	cout<<"KAYIT ISLEMI"<<endl<<endl;
	cout<<"Cinsiyet gir = ";
	cin>>nesne.cinsiyet1;
	cout<<"isim gir = ";
	cin>>nesne.ad1;
	cout<<"soyad gir = ";
	cin>>nesne.soyad1;
	cout<<"yas gir = ";
	cin>>nesne.yas1;
	cout<<"boy gir = ";
	cin>>nesne.boy1;
	cout<<"kilo gir = ";
	cin>>nesne.kilo1;
	nesne.hesaplaendexPublic(nesne.cinsiyet1,nesne.yas1,nesne.boy1);
	cout<<endl<<"PUBLIC KAYDETTIGIMIZ KISIMIZ"<<endl<<endl;
	goster(nesne.cinsiyet1,nesne.ad1,nesne.soyad1,nesne.yas1,nesne.boy1,nesne.kilo1,nesne.hesap1);
	//private nesne oluþturma 
		cout<<"_______________________________________________________________________________________________________________________"<<endl<<endl;
	cout<<"KAYIT ISLEMI"<<endl<<endl;
	string cinsiyet,ad,soyad;
	int yas,boy,kilo;
	cout<<"Cinsiyet gir = ";
	cin>>cinsiyet;
	cout<<"isim gir = ";
	cin>>ad;
	cout<<"soyad gir = ";
	cin>>soyad;
	cout<<"yas gir = ";
	cin>>yas;
	cout<<"boy gir = ";
	cin>>boy;
	cout<<"kilo gir = ";
	cin>>kilo;
	
	 nesne.cinsiyetkoy(cinsiyet);
	 nesne.adkoy(ad);
	 nesne.soyadkoy(soyad);
	 nesne.yaskoy(yas);
	 nesne.boykoy(boy);
	 nesne.kilokoy(kilo);
	 
	 nesne.hesaplaendexPrivate(nesne.cinsiyetkoyR(),nesne.yaskoyR(),nesne.boykoyR());

	 cout<<"PRIVATE  KAYDETTIGIMIZ KISI"<<endl<<endl;
	 goster(nesne.cinsiyetkoyR(),nesne.adkoyR(),nesne.soyadkoyR(),nesne.yaskoyR(),nesne.boykoyR(),nesne.kilokoyR(),nesne.hesapdondurR());
   	
  
	return 0;
}
void goster(string gostercinsiyet,string gosterad,string gostersoyad,int gosteryas,int gosterboy,int gosterkilo,double idealkilo){//ekran göstermesini istediklerimi topladým
	cout<<"cinsiyet = "<<gostercinsiyet<<endl<<"ad = "<<gosterad<<endl<<"soyad = "<<gostersoyad<<endl<<"yas = "<<gosteryas<<endl<<"boy = "<<gosterboy<<endl<<"kilo = "<<gosterkilo<<endl<<"Ideal Kilonuz = "<<idealkilo<<endl<<endl ;
}

