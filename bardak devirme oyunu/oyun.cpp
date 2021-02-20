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
	cin>>boyut;//bardak boyutumuzu aldýk
	while(1){//kullanýcý boyut doðru girene kadar çalýþtýr
	
	if(boyut=="kucuk"){// kullanýcýn girdiði bardak boyu kucukse bardak boyutu 15 atýp while çýktýk
		bardakBoyutu=15;
		system("CLS");
		break;
	}
	else if(boyut=="orta"){// kullanýcýn girdiði bardak boyu orta bardak boyutu 10 atýp while çýktýk
		bardakBoyutu=10;
		system("CLS");
		break;
	}
	
	else if(boyut=="buyuk"){// kullanýcýn girdiði bardak boyu buyukse bardak boyutu 8 atýp while çýktýk
		system("CLS");
		bardakBoyutu=8;
		break;
	}
	else{//kucuk-orta-buyuk bardak dýþýnda girerse döngü birdaha çalýþsýn 
		system("CLS");
		cout<<"Lutfen kucuk-orta-buyuk bardak boyu giriniz = ";
		cin>>boyut;
	}
	}
	for(int i=0;i<bardakBoyutu*3;i++){//tüm dizimize x attýk
	
		*(oyundizisi+i)='x';
		
	}
	int K=0,M=0,Y=0;//kýrmýzý mavi ve yeþil rasgele atýcaðýmýz için öncelikle dedik ki 0 yapalým yapalým hepsini
	while(K!=4){//K eþit deðilse 4 koþulu
	rasgeleSayi=rand()%(bardakBoyutu*3);//kullanýnýn girdiði boyuta göre 3 raf olduðu için 3 ile carpýp tek boyutlu dizimizde rasgele bir yer bulduk
	//dedik ki dizimizin içinde x varsa K'yazalým 2 olan koþul ise belki gene ayni yere K atma ihtimali için koþul koyduk
	if(*(oyundizisi+rasgeleSayi)=='x' && *(oyundizisi+rasgeleSayi)!='K'){
		*(oyundizisi+rasgeleSayi)='K';//K dizimize yazdýk
		K++;//K mýzý 1 arttýrdýk
	}
	}
	while(M!=5){//M eþit deðilse 5 koþulu
	rasgeleSayi=rand()%(bardakBoyutu*3);
	//burada da üstekinin aynýsý fakat bu sefer M eklediðimizde belki ayni yere M atýp M sayýmýzý arttýp 5 tane atmadan döngüden çýkmasýn diye
	if(*(oyundizisi+rasgeleSayi)=='x' && *(oyundizisi+rasgeleSayi)!='K' && *(oyundizisi+rasgeleSayi)!='M' ){
		*(oyundizisi+rasgeleSayi)='M';
		M++;//M 1 arttýrdýk
	}
	}
	while(Y!=8){//Y eþit deðilse 8 koþulu
	rasgeleSayi=rand()%(bardakBoyutu*3);
	//üstekilere ek olarak buraya birde Y yerleþtireceðimiz diðer koþulda eðer Y attýktan sonra tekrar ayný konuma Y gelirse döngüde Y arttýrmamasý için
	if(*(oyundizisi+rasgeleSayi)=='x' && *(oyundizisi+rasgeleSayi)!='K' && *(oyundizisi+rasgeleSayi)!='M' && *(oyundizisi+rasgeleSayi)!='Y'){
		*(oyundizisi+rasgeleSayi)='Y';
		Y++;//Y bir arttýrdýk
	}
	}
	

}

void oyun::ekranaYazdir(){//ekrana yazdýrma fonksiyonumuz

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
		int kacinciAtis=0;//kullanýcýlarýn kaçýncý atýþlarýný geldiðini ekranda göstermek için
	    string atis_x,//kullanýcýdan alýcaðýmýz raf ve sira 
			   atis_y;
		int rasgeleAtis;//ihtimallarimiz için randda 
		int kullanici=1;//1 kullanýcadan baþlamak için
		while(1){//sürekli dönmesi için
			
			if(kullanici=1){
							ekranaYazdir();
		cout<<"------> Player1 atis sirasi <------"<<endl;
		cout<<"Atis yapmak icin raf ve sirayi seciniz:"<<endl;
		cout<<"!!Girislerimiz lutfen 1 2 3 raf seklinde olsun .\nSira icinde 1 den baslayarak girilen kucuk=15 orta=10 ve buyuk=8 araliginda bir sayi olsun!!"<<endl;
		cout<<"Oyundan cikmak isterseniz X veya x yaziniz. "<<endl;
	
		cout<<"raf yaziniz =>";
		
		cin>>atis_x;

	 	if(atis_x == "x" || atis_x == "X" ){//kullanici raf için x girerse ciksin
		     system("CLS");
			 cout<<"  x veya X basarak cikis yaptiniz"<<endl<<endl;
			 ekranaYazdir();
			 break;
			}
	
		
			 
		cout<<"sirayi yaziniz =>";
		cin>>atis_y;
		
			if(atis_y == "x"|| atis_y == "X"){//kullanici sira için x girerse ciksin
			 system("CLS");
			 cout<<"  x veya X basarak cikis yaptiniz"<<endl<<endl;
			 ekranaYazdir();
			 break;
			}
		int raf = atoi(atis_x.c_str());	//string int dönüsümü için
		int sira = atoi(atis_y.c_str())-1;//sira sayimiz -1 sekilde yapalým ki  kullanicinin girdigi sirada dizimizdeki o elemana bakarken siradan 1 çýkartma yaparak dizimize bakalim
		
		if(sira == 0 ){	//kullanicin girdiði sira 1 ise üstte çýkartma iþlemi yaparak yani 0 sirada seçim yapýlýrsa yüzde 50 ihtimal için			
			rasgeleAtis = rand()%2;			
		}	
		else if(sira == bardakBoyutu-1){//kullanicin girdigi sira bardakBoyutumuza eþitse solunla kendisi yüzde 50 sans yaptýðý için
			rasgeleAtis = rand()%2 -1;
		}
		else{//sutunlar köþelerde deðilse 1/3 þans orani
			rasgeleAtis = rand()%3 -1 ;		
		}   //alttaki iþlem söyle tek boyutlu dizimiz olduðu için kullanici bardak boyunu büyük girsin yani sutun sayimiz bi nevi 8 oluyor
		//bunun üzerinden düþünürsek rafýmýzý kullanici 1 girdi yani 0 satir alttaki iþlemde 0*8+kullanicin girdiði sira-1 olur 125 satirda çunku + birde rasgele sayimiz
			if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis]== 'K'){//eðer kullanicinin sectigi raf ve sira sayisimiza ek   rasgeleatisimizi tutturduk mu diye 
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Kirmizi bardagi kirarak 3 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';	
			
				player1Puan += 3;		//puan ekledik
				cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;		//ekrana puan yazdýrdýk
		
				
		}
		//135-136 satirda açýklama bulunmakta
		else if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] == 'M'){	//dizimizde M ise kullanicin girdiði raf ve sira koþula girer
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Mavi bardagi kirarak 2 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';		//burada vurduðumuz bardakta yerine x yazar
			
			player1Puan += 2;		//player1 puan ekledik
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;//puanlarý ekrana yazdirdik	
						
		
		}
		else if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis]== 'Y'){//dizimizde Y ise kullanicin girdiði raf ve sira koþula girer
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Yesil bardagi vurarak 1 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';	//vurduðumuz yere x yazdik	
			
			player1Puan+=1;	//player 1 puan ekledik
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;				
			
		}
		else{//hiç biyeri vuramadiysa buradaki koþul
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasinda bardak olmadigi icin puan alamadiniz."<<endl;
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;
		}
		
			 
			
			}
	if(kullanici=2)	{//kullanici1 yani player1 de olan ayný þeyler burada yaptýk ek olarak bi kaç biþe ekledik burada
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
		int raf = atoi(atis_x.c_str());	//string int dönüsümü
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
		else if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] == 'M'){	//eðer mavi bardak vurulduysa;
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Mavi bardagi kirarak 2 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';		//bardaðý matristen kaldýr
		
			player2Puan += 2;				
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;			
		
		}
		else if(oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis]== 'Y'){	//eðer yeþil bardak vurulduysa;
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasindaki Yesil bardagi  vurarak 1 puan kazandiniz."<<endl;
			oyundizisi[(raf-1)*bardakBoyutu+sira+rasgeleAtis] = 'x';		//bardaðý matristen kaldýr
			player2Puan+=1;					
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;
		}
		else{
			cout<<raf<<".rafin "<<sira+rasgeleAtis+1<<". sirasinda bardak olmadigi icin puan alamadiniz."<<endl;
			cout<<"Player1 Puani = "<<player1Puan<<"  <-> "<<" Player2 Puani = "<<player2Puan<<endl<<endl;
		}
		
		
		kullanici=0;//kullanicimiz 0 eþitledik burada sebebi asaðýda  258 satirda açýklama yazýyor
		ekranaYazdir()
		;
	}
	int bittimi=0;//burada hiç bardak kalmýþ mý diye kontrol
	for(int i=0;i<bardakBoyutu*3;i++){
		if(*(oyundizisi+i)=='x'){//teker teker bakýp x varsa bittimi deðiþkenimizde topladýk
			bittimi++;//koþul saðlanýyorsa arttýrdýk
		}
		
	}

	if(bittimi==bardakBoyutu*3){//bardakboyutu*3 eþit ise bittimi deðiþkenimiz  while döngümüzden çýkalým ve sonlandýralým programýmýzý
		system("CLS");
		cout<<"Atis tahtasinda bardak kalmadi"<<endl;
		break;
	}
	
	kullanici++;//sebebi tekrar kullanici1 elde etmek için 
	kacinciAtis++;//atýþ sayýlarýmýz
	cout<<"Player1 ve Player2 nin "<<kacinciAtis<<". atislarina baktiysaniz bise basip diger atisa gecis yapin"<<endl;//atýþ sayýlarýmýz ekranda görüntüsü
	system("Pause");//player 1 ve 2 incelemesi için sistemi beklettik
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
	
	

