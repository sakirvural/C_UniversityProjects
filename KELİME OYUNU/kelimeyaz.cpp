#include "kelimeyaz.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

 void kelimeyaz::kelimeler(){
 	cout<<"\tKelimeleriniz bittiyse |<- son ->| yaziniz\n"<<endl;
 		tekrar:
	srand(time(NULL));
	 string kelimeler;
	 string kelimedizisi[12];
	 char oyundizisi[12][12];
	 int kelimesayisi=0;
	 //17-32 satirlar arasi kullanýcýn girdiði kelimeleri diziye attýk v
	 while(kelimeler != "son"){
	 	  karakterdizisi:
	 	 cout<<"Lutfen kelime girininiz |------>";
	 	 cin>>kelimeler;
	 	if(kelimeler!= "son"){
	 			  if(kelimeler.length()<12){//kullanýcýnýn girdiði kelimenin harf sayisi 12 den küçük olmasýný kontrol ettik
	 			  	kelimedizisi[kelimesayisi]=kelimeler;
	 			  	kelimesayisi++;
				   }
				   else{
				   	cout<<"!!! Lutfen 12 harften kucuk olan kelime yaziniz !!!"<<endl;
				   	goto karakterdizisi;
				   }
	 			 
		 }
	 }
	 
	 cout<<endl<<"Kelime oyunu hazir"<<endl<<endl;
	 


	//39-50 satir arasý hem oyun dizisimizin tüm karakterlerini null yaptýk hemde string dizimizden char dizimize dönüþtüreceðimiz dizimizde null yapcak
    for(int i=0;i<12;i++){
    	 for(int j=0;j<12;j++){
    	oyundizisi[i][j]='\0';
	}
	}
	
	
	char dizikelimeleri[144]; 

	for(int i=0;i<144;i++){
		dizikelimeleri[i]='\0';
	}
	
	

	//54-74 satir arasinda string dizimizi char dizimize kopyalama iþlemi yaptýk
    int diziboyutu=0;
    int dizisayac=0;
	
	
	for(int i=0;i<=kelimesayisi;i++){
	 	
	int a=(kelimedizisi[i].length()+1);//+ 1 olma sebebi string karakterimizin sonuna \0 yani null geleceði için
	  
   	char dizi2[a];//kelimemizin char dizisindeki boyut için
   	
    strcpy(dizi2,kelimedizisi[i].c_str());//kopyalama iþlemimiz
     
    diziboyutu=diziboyutu+a;//buda char dizimize tüm kelimelerimizi attýðýmýzda dizimizin boyutunu belirtmek için
     
      
     for(int j=0;j<a;j++){//kelimelerimizi dizikelimelerine tek tek kopyalamak için
	 dizikelimeleri[dizisayac]=dizi2[j];
	 dizisayac++;//arttýrma sebeimiz dizimize kopyala iþleme yaptýðýnda harflerimizin tek hangi konumlara geldiðini ve kaydetme iþlemi için
	 }
	 }
	
	
	
     int arttir=0;
     int x=0;
     int toplam=0;
     int konum1=0;
     int konum2=0;
     int yanaasagi=0;
     int yukariasagidizisi[kelimesayisi];
     int rasgelesayilar[kelimesayisi][2];
     //86-115 satir arasýnda kullanýcýmýzýn girdiði kelimeleri rasgele konumlar belirterek yana mý asaðý yazdýraðýmýzý belirleme ve oyundizime kaydetmek için
     for(int i=0;i<kelimesayisi;i++){ //girdiðimiz kelime sayisi kadar döngü
	 rasgelekonum:	
     konum1=rand()%12;//rasgele konumlarýmýz 0ile 12 arasinda konum için
     konum2=rand()%12;
     yanaasagi=rand()%2+1;//yana mý yukarý mý olsun diye 
     if(konum1+kelimedizisi[i].length()<12 && konum2+kelimedizisi[i].length()<12)	{//rasgele gelen sayilarimiz ve girdiðimiz kelimelerin uzunluðu toplamý 12 den küçük olmalý
     	
     	rasgelesayilar[i][x]= konum1;//ilerde lazým olacaðý için konumlarýmýzý kaydettik
     	rasgelesayilar[i][x+1]=konum2;
       if(i>0){
        	arttir=arttir+(kelimedizisi[i-1].length()+1);//char dizisi içine kaydettiðimiz kelimeleri konumlarýný i>0 olduktan sonra arttýrmamýz gerekir 1 önceki kelime boyutumuzdan çünkü yeni kelimeler okumak için
		}
    for(int j=0;j<(kelimedizisi[i].length()+1);j++){//kelime boyutumuz kadar for dönsün çünkü dizimizi içindeki kelimeleri oyun dizimize tek tek kaydetmek için
    	if(yanaasagi==1){//yana dogru yazdýrmak için
    		yukariasagidizisi[i]=yanaasagi;
    	oyundizisi[konum1][konum2+j]=dizikelimeleri[j+arttir];
		}
       if(yanaasagi==2){//asagý doðru yazdýrmak için
        yukariasagidizisi[i]=yanaasagi;
       	oyundizisi[konum1+j][konum2]=dizikelimeleri[j+arttir];
	   }
    
	}
	 }
	 else{
	 		goto rasgelekonum;//eðer sýðmazsa kelimeler tekrar tekrar denemesi için 
	 }

}

  
   
   int rasgele=0;
    char c;
    //122-132 arasi oyun dizimizeki \0 karakterlerimize rasgele harf girmesi icin
    for(int i=0;i<12;i++){
    for(int j=0;j<12;j++){
  
	if(oyundizisi[i][j]=='\0'){
	rasgele=rand()%26+65;
	c=char(rasgele);//ascii tablomuzdan yararlanarak sayi degerinin harfe karþýlýðý
	oyundizisi[i][j]=c;
	}
  
		}
	}
	
	tekrarla:
	char secim;
	//136-278 ARASÝ SECENEKLERÝMÝZÝ BELÝRLEDÝK 
	while(secim!='C'){
	cout<<"\tYeni oyun olusturmak icin |<- Y ->| harfine basiniz\n";
	cout<<"\tOyunu goruntulemek icin |<- O ->| harfine  basiniz\n";
	cout<<"\tKelime bulmak icin |<- K ->| harfine basiniz\n";
	cout<<"\tKelime Aramasi icin |<- A ->| harfine basiniz\n";
	cout<<"\tCikmak icin |<- C ->| harfine basiniz\n"<<endl;
	cout<<"Lutfen bir secenek girin\n";
		cin>>secim;
		if(secim=='Y'||secim=='O'||secim=='K'||secim=='A'||secim=='C'){
			if(secim=='Y'){
			goto tekrar;
		}
		  if(secim=='O'){
	   for(int i=0;i<12;i++){
    for(int j=0;j<12;j++){
     cout<<oyundizisi[i][j]<<" ";
		}
		cout<<endl;
	}
	 cout<<endl;
		
		}
		//159-240 arasý aramak istediðimiz kelime ve konumlarýmýzý yazdik ve aradýk
	 if(secim=='K'){
	
	 for(int i=0;i<12;i++){
    for(int j=0;j<12;j++){
     cout<<oyundizisi[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	for(int i=0;i<kelimesayisi;i++){
		cout<<i<<".kelime=>"<<kelimedizisi[i]<<endl;
	}
     cout<<"Bulmak istediginiz kelimeyi ve basladigi ilk harfin konumunu yaziniz"<<endl;
	 string kelimeiste;
	 cin>>kelimeiste;
	 int kelimekonum1;
	 int kelimekonum2;
	 int sayacimiz=0;
			while(kelimeiste!="son"){
			 
				for(int i=0;i<kelimesayisi;i++){
				if(kelimedizisi[i]==kelimeiste){
				tekrarkonum:
				cout<<"x konum=";
				cin>>kelimekonum1;
				cout<<"y konum=";
				cin>>kelimekonum2;
					
							if(rasgelesayilar[i][x]==kelimekonum1&&rasgelesayilar[i][x+1]==kelimekonum2){
							cout<<endl;
							cout<<"Dogru bildiniz"<<endl<<endl;
							sayacimiz++;
							if(sayacimiz==kelimesayisi){
								cout<<"Tebrikler tum kelimeler bulundunuz"<<endl<<endl;
								goto tekrarla;
							}
							else{
								 for(int j=0;j<(kelimedizisi[i].length()+1);j++){
					         	int rasgeleharfimiz=rand()%26+65;
					         	if(yukariasagidizisi[i]==1){
					         	oyundizisi[kelimekonum1][kelimekonum2+j]=char(rasgeleharfimiz);
								 }
					         	if(yukariasagidizisi[i]==2){
					         	oyundizisi[kelimekonum1+j][kelimekonum2]=char(rasgeleharfimiz);
								 }
	
							 }
							 	 for(int i=0;i<12;i++){
                                 for(int j=0;j<12;j++){
                                 cout<<oyundizisi[i][j]<<" ";
	                           	}
	                        	cout<<endl;
                               	}
                         	cout<<endl;
							cout<<"Oncelikle bulmak istediginiz kelimeyi ve sonrasinda basladigi ilk harfin konumunu yaziniz"<<endl;
							goto kelimegir;
							}
					    
						}
						else{
							cout<<"kelimenin basladigi ilk harfin konumu hatali tekrar konum giriniz"<<endl;
							goto tekrarkonum;
						}
						
					
					}
					
					if(i==kelimesayisi-1){
						cout<<"Oyunda ole bir kelime yok"<<endl<<"Tekrar kelime giriniz"<<endl;
					}
					
	}
				
				
				kelimegir:
				cin>>kelimeiste;
			}
		
			
		}
		//241-265 arasi aramak istediðimizi kelimeyi yazip konumlarý aldýk
	 if(secim=='A'){
    for(int i=0;i<12;i++){
    for(int j=0;j<12;j++){
     cout<<oyundizisi[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	 cout<<"arananacak kelime giriniz=> ";
	 string kelimetaramasi;
	 kelimealalim:
	 cin>>kelimetaramasi;
	 	for(int i=0;i<kelimesayisi;i++){
	 		if(kelimedizisi[i]==kelimetaramasi){
	 			cout<<"aramak istediginiz kelimenin bas harfi konumu= > "<<rasgelesayilar[i][x]<<" "<<rasgelesayilar[i][x+1]<<endl<<endl;
	 			goto tekrarla;
			 }
			 if(i==kelimesayisi-1){
			 	cout<<"kelime bulamadiniz tekrar kelime giriniz"<<endl;
			 	goto kelimealalim;
			 }
		 }
	
		}
		//oyundan çýkmak için
		if(secim=='C'){
			cout<<"OYUNDAN CIKTINIZ";
		}
	
	}
	//yanlýþ harf girdiðimiz için
		else{
		cout<<"yanlis giris yaptiniz.lutfen tekrar deneyin."<<endl;
		 goto tekrarla;
	}
	
		}
		
		
	
	}

   	
   	
   	
   
	

  


