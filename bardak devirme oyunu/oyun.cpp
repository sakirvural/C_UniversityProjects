#include <iostream>
#include "oyun.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sstream>
using namespace std;


void oyun::oyunTuret(){
	

	string boyut;
	cout<<"Oyunu baslatmak icin kucuk-orta-buyuk boy bardak giriniz."<<endl;
	cout<<"Boyutu giriniz = ";
	cin>>boyut;//bardak boyutumuzu ald�k
	while(1){//kullan�c� boyut do�ru girene kadar �al��t�r
	
	if(boyut=="kucuk"){// kullan�c�n girdi�i bardak boyu kucukse bardak boyutu 15 at�p while ��kt�k
		bardakBoyutu=15;
		system("CLS");
		break;
	}
	else if(boyut=="orta"){// kullan�c�n girdi�i bardak boyu orta bardak boyutu 10 at�p while ��kt�k
		bardakBoyutu=10;
		system("CLS");
		break;
	}
	
	else if(boyut=="buyuk"){// kullan�c�n girdi�i bardak boyu buyukse bardak boyutu 8 at�p while ��kt�k
		system("CLS");
		bardakBoyutu=8;
		break;
	}
	else{//kucuk-orta-buyuk bardak d���nda girerse d�ng� birdaha �al��s�n 
		system("CLS");
		cout<<"Lutfen kucuk-orta-buyuk bardak boyu giriniz = ";
		cin>>boyut;
	}
	}
	for(int i=0;i<bardakBoyutu*3;i++){//t�m dizimize x att�k
	
		*(oyundizisi+i)='x';
		
	}
	int K=0,M=0,Y=0;//k�rm�z� mavi ve ye�il rasgele at�ca��m�z i�in �ncelikle dedik ki 0 yapal�m yapal�m hepsini
	while(K!=4){//K e�it de�ilse 4 ko�ulu
	rasgeleSayi=rand()%(bardakBoyutu*3);//kullan�n�n girdi�i boyuta g�re 3 raf oldu�u i�in 3 ile carp�p tek boyutlu dizimizde rasgele bir yer bulduk
	//dedik ki dizimizin i�inde x varsa K'yazal�m 2 olan ko�ul ise belki gene ayni yere K atma ihtimali i�in ko�ul koyduk
	if(*(oyundizisi+rasgeleSayi)=='x' && *(oyundizisi+rasgeleSayi)!='K'){
		*(oyundizisi+rasgeleSayi)='K';//K dizimize yazd�k
		K++;//K m�z� 1 artt�rd�k
	}
	}
	while(M!=5){//M e�it de�ilse 5 ko�ulu
	rasgeleSayi=rand()%(bardakBoyutu*3);
	//burada da �stekinin ayn�s� fakat bu sefer M ekledi�imizde belki ayni yere M at�p M say�m�z� artt�p 5 tane atmadan d�ng�den ��kmas�n diye
	if(*(oyundizisi+rasgeleSayi)=='x' && *(oyundizisi+rasgeleSayi)!='K' && *(oyundizisi+rasgeleSayi)!='M' ){
		*(oyundizisi+rasgeleSayi)='M';
		M++;//M 1 artt�rd�k
	}
	}
	while(Y!=8){//Y e�it de�ilse 8 ko�ulu
	rasgeleSayi=rand()%(bardakBoyutu*3);
	//�stekilere ek olarak buraya birde Y yerle�tirece�imiz di�er ko�ulda e�er Y att�ktan sonra tekrar ayn� konuma Y gelirse d�ng�de Y artt�rmamas� i�in
	if(*(oyundizisi+rasgeleSayi)=='x' && *(oyundizisi+rasgeleSayi)!='K' && *(oyundizisi+rasgeleSayi)!='M' && *(oyundizisi+rasgeleSayi)!='Y'){
		*(oyundizisi+rasgeleSayi)='Y';
		Y++;//Y bir artt�rd�k
	}
	}
	

}

void oyun::ekranaYazdir(){//ekrana yazd�rma fonksiyonumuz

	cout<<"Atis tahtamiz:"<<endl<<endl;
	for(int i=0;i<3;i++){
	for(int j=0;j<bardakBoyutu;j++){
		cout<<*(oyundizisi+(i)*bardakBoyutu+j)<<" ";
	}
		cout<<endl;
	}
		cout<<endl;
}

void oyun::atisYap(){
		int kacinciAtis=0;//kullan�c�lar�n ka��nc� at��lar�n� geldi�ini ekranda g�stermek i�in
	    string atis_x,//kullan�c�dan al�ca��m�z raf ve sira 
			   atis_y;
		int rasgeleAtis;//ihtimallarimiz i�in randda 
		int kullanici=1;//1 kullan�cadan ba�lamak i�in
		while(1){//s�rekli d�nmesi i�in
			
			if(kullanici=1){
							ekranaYazdir();
		cout<<"------> Player1 atis sirasi <------"<<endl;
		cout<<"Atis yapmak icin raf ve sirayi seciniz:"<<endl;
		cout<<"!!Girislerimiz lutfen 1 2 3 raf seklinde olsun .\nSira icinde 1 den baslayarak girilen kucuk=15 orta=10 ve buyuk=8 araliginda bir sayi olsun!!"<<endl;
		cout<<"Oyundan cikmak isterseniz X veya x yaziniz. "<<endl;
	
		cout<<"raf yaziniz =>";
		
		cin>>atis_x;

	 	if(atis_x == "x" || atis_x == "X" ){//kullanici raf i�in x girerse ciksin
		     system("CLS");
			 cout<<"  x veya X basarak cikis yaptiniz"<<endl<<endl;
			 ekranaYazdir();
			 break;
			}
	
		
			 
		cout<<"sirayi yaziniz =>";
		cin>>atis_y;
		
			if(atis_y == "x"|| atis_y == "X"){//kullanici sira i�in x girerse ciksin
			 system("CLS");
			 cout<<"  x veya X basarak cikis yaptiniz"<<endl<<endl;
			 ekranaYazdir();
			 break;
			}
		int raf = atoi(atis_x.c_str());	//string int d�n�s�m� i�in
		int sira = atoi(atis_y.c_str())-1;//sira sayimiz -1 sekilde yapal�m ki  kullanicinin girdigi sirada dizimizdeki o elemana bakarken siradan 1 ��kartma yaparak dizimize bakalim
		
		if(sira == 0 ){	//kullanicin girdi�i sira 1 ise �stte ��kartma i�lemi yaparak yani 0 sirada se�im yap�l�rsa y�zde 50 ihtimal i�in			
			rasgeleAtis = rand()%2;			
		}	
		else if(sira == bardakBoyutu-1){//kullanicin girdigi sira bardakBoyutumuza e�itse solunla kendisi y�zde 50 sans yapt��� i�in
			rasgeleAtis = rand()%2 -1;
		}
		else{//sutunlar k��elerde de�ilse 1/3 �ans orani
			rasgeleAtis = rand()%3 -1 ;		
		}   //alttaki i�lem s�yle tek boyutlu dizimiz oldu�u i�in kullanici bardak boyunu b�y�k girsin yani sutun sayimiz bi nevi 8 oluyor
		//bunun �zerinden d���n�rsek raf�m�z� kullanici 1 girdi yani 0 satir alttaki i�lemde 0*8+kullanicin girdi�i sira-1 olur 125 satirda �unku + birde rasgele sayimiz
			if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis]== 'K'){//e�er kullanicinin sectigi raf ve sira sayisimiza ek   rasgeleatisimizi tutturduk mu diye 
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Kirmizi bardagi kirarak 3 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';	
			
				player1Puan += 3;		//puan ekledik
				cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;		//ekrana puan yazd�rd�k
		
				
		}
		//135-136 satirda a��klama bulunmakta
		else if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] == 'M'){	//dizimizde M ise kullanicin girdi�i raf ve sira ko�ula girer
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Mavi bardagi kirarak 2 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';		//burada vurdu�umuz bardakta yerine x yazar
			
			player1Puan += 2;		//player1 puan ekledik
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;//puanlar� ekrana yazdirdik	
						
		
		}
		else if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis]== 'Y'){//dizimizde Y ise kullanicin girdi�i raf ve sira ko�ula girer
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Yesil bardagi vurarak 1 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';	//vurdu�umuz yere x yazdik	
			
			player1Puan+=1;	//player 1 puan ekledik
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;				
			
		}
		else{//hi� biyeri vuramadiysa buradaki ko�ul
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasinda bardak olmadigi icin puan alamadiniz."<<endl;
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;
		}
		
			 
			
			}
	if(kullanici=2)	{//kullanici1 yani player1 de olan ayn� �eyler burada yapt�k ek olarak bi ka� bi�e ekledik burada
					ekranaYazdir();
		cout<<"------> Player2 atis sirasi <------"<<endl;
		cout<<"Atis yapmak icin raf ve sirayi seciniz:"<<endl;
		cout<<"!!Girislerimiz lutfen 1 2 3 raf seklinde olsun .\nSira icinde 1 den baslayarak girilen kucuk=15 orta=10 ve buyuk=8 araliginda bir sayi olsun!!"<<endl;
		cout<<"Oyundan cikmak isterseniz X veya x yaziniz. "<<endl;
		
		cout<<"raf yaziniz =>";
		
		cin>>atis_x;

	 	if(atis_x == "x" || atis_x == "X" ){
		     system("CLS");
			 cout<<"  x veya X basarak cikis yaptiniz"<<endl<<endl;
			 ekranaYazdir();
			 break;
			}
	
		
			 
		cout<<"sirayi yaziniz =>";
		cin>>atis_y;
		
			if(atis_y == "x"|| atis_y == "X"){
			 system("CLS");
			 cout<<"  x veya X basarak cikis yaptiniz"<<endl<<endl;
			 ekranaYazdir();
			 break;
			}
		int raf = atoi(atis_x.c_str());	//string int d�n�s�m�
		int sira = atoi(atis_y.c_str())-1;
		
		if(sira == 0 ){					
			rasgeleAtis = rand()%2;			
		}	
		else if(sira == bardakBoyutu-1){
			rasgeleAtis = rand()%2 -1;
		}
		else{
			rasgeleAtis = rand()%3 -1;		
		}
			if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis]== 'K'){
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Kirmizi bardagi kirarak 3 puan kazandiniz."<<endl;	
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';	
			
				player2Puan += 3;				
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;
				
		}
		else if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] == 'M'){	//e�er mavi bardak vurulduysa;
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Mavi bardagi kirarak 2 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';		//barda�� matristen kald�r
		
			player2Puan += 2;				
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;			
		
		}
		else if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis]== 'Y'){	//e�er ye�il bardak vurulduysa;
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Yesil bardagi  vurarak 1 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';		//barda�� matristen kald�r
			player2Puan+=1;					
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;
		}
		else{
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasinda bardak olmadigi icin puan alamadiniz."<<endl;
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;
		}
		
		
		kullanici=0;//kullanicimiz 0 e�itledik burada sebebi asa��da  258 satirda a��klama yaz�yor
		ekranaYazdir()
		;
	}
	int bittimi=0;//burada hi� bardak kalm�� m� diye kontrol
	for(int i=0;i<bardakBoyutu*3;i++){
		if(*(oyundizisi+i)=='x'){//teker teker bak�p x varsa bittimi de�i�kenimizde toplad�k
			bittimi++;//ko�ul sa�lan�yorsa artt�rd�k
		}
		
	}

	if(bittimi==bardakBoyutu*3){//bardakboyutu*3 e�it ise bittimi de�i�kenimiz  while d�ng�m�zden ��kal�m ve sonland�ral�m program�m�z�
		system("CLS");
		cout<<"Atis tahtasinda bardak kalmadi"<<endl;
		break;
	}
	
	kullanici++;//sebebi tekrar kullanici1 elde etmek i�in 
	kacinciAtis++;//at�� say�lar�m�z
	cout<<"Player1 ve Player2 nin "<<kacinciAtis<<". atislarina baktiysaniz bise basip diger atisa gecis yapin"<<endl;//at�� say�lar�m�z ekranda g�r�nt�s�
	system("Pause");//player 1 ve 2 incelemesi i�in sistemi beklettik
	system("CLS");	//ekrani sildik
	}
		
	
}	

void oyun::OyunSonlandir(){
	cout<<"   -----Oyun Sonlandirildi-----"<<endl;
	cout<<"--->Player1 ve Player2 skorlari<---"<<endl;
	printf("    player1 = %d    player2 = %d \n",player1Puan,player2Puan);
	if(player1Puan>player2Puan)
		cout<<"*****Player1 oyunu kazandi*****";

	if(player2Puan>player1Puan)
		cout<<"*****Player2 oyunu kazandi*****";

	

	
}
	
	

