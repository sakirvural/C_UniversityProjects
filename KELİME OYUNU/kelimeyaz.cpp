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
	 //17-32 satirlar arasi kullan�c�n girdi�i kelimeleri diziye att�k v
	 while(kelimeler != "son"){
	 	  karakterdizisi:
	 	 cout<<"Lutfen kelime girininiz |------>";
	 	 cin>>kelimeler;
	 	if(kelimeler!= "son"){
	 			  if(kelimeler.length()<12){//kullan�c�n�n girdi�i kelimenin harf sayisi 12 den k���k olmas�n� kontrol ettik
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
	 


	//39-50 satir aras� hem oyun dizisimizin t�m karakterlerini null yapt�k hemde string dizimizden char dizimize d�n��t�rece�imiz dizimizde null yapcak
    for(int i=0;i<12;i++){
    	 for(int j=0;j<12;j++){
    	oyundizisi[i][j]='\0';
	}
	}
	
	
	char dizikelimeleri[144]; 

	for(int i=0;i<144;i++){
		dizikelimeleri[i]='\0';
	}
	
	

	//54-74 satir arasinda string dizimizi char dizimize kopyalama i�lemi yapt�k
    int diziboyutu=0;
    int dizisayac=0;
	
	
	for(int i=0;i<=kelimesayisi;i++){
	 	
	int a=(kelimedizisi[i].length()+1);//+ 1 olma sebebi string karakterimizin sonuna \0 yani null gelece�i i�in
	  
   	char dizi2[a];//kelimemizin char dizisindeki boyut i�in
   	
    strcpy(dizi2,kelimedizisi[i].c_str());//kopyalama i�lemimiz
     
    diziboyutu=diziboyutu+a;//buda char dizimize t�m kelimelerimizi att���m�zda dizimizin boyutunu belirtmek i�in
     
      
     for(int j=0;j<a;j++){//kelimelerimizi dizikelimelerine tek tek kopyalamak i�in
	 dizikelimeleri[dizisayac]=dizi2[j];
	 dizisayac++;//artt�rma sebeimiz dizimize kopyala i�leme yapt���nda harflerimizin tek hangi konumlara geldi�ini ve kaydetme i�lemi i�in
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
     //86-115 satir aras�nda kullan�c�m�z�n girdi�i kelimeleri rasgele konumlar belirterek yana m� asa�� yazd�ra��m�z� belirleme ve oyundizime kaydetmek i�in
     for(int i=0;i<kelimesayisi;i++){ //girdi�imiz kelime sayisi kadar d�ng�
	 rasgelekonum:	
     konum1=rand()%12;//rasgele konumlar�m�z 0ile 12 arasinda konum i�in
     konum2=rand()%12;
     yanaasagi=rand()%2+1;//yana m� yukar� m� olsun diye 
     if(konum1+kelimedizisi[i].length()<12 && konum2+kelimedizisi[i].length()<12)	{//rasgele gelen sayilarimiz ve girdi�imiz kelimelerin uzunlu�u toplam� 12 den k���k olmal�
     	
     	rasgelesayilar[i][x]= konum1;//ilerde laz�m olaca�� i�in konumlar�m�z� kaydettik
     	rasgelesayilar[i][x+1]=konum2;
       if(i>0){
        	arttir=arttir+(kelimedizisi[i-1].length()+1);//char dizisi i�ine kaydetti�imiz kelimeleri konumlar�n� i>0 olduktan sonra artt�rmam�z gerekir 1 �nceki kelime boyutumuzdan ��nk� yeni kelimeler okumak i�in
		}
    for(int j=0;j<(kelimedizisi[i].length()+1);j++){//kelime boyutumuz kadar for d�ns�n ��nk� dizimizi i�indeki kelimeleri oyun dizimize tek tek kaydetmek i�in
    	if(yanaasagi==1){//yana dogru yazd�rmak i�in
    		yukariasagidizisi[i]=yanaasagi;
    	oyundizisi[konum1][konum2+j]=dizikelimeleri[j+arttir];
		}
       if(yanaasagi==2){//asag� do�ru yazd�rmak i�in
        yukariasagidizisi[i]=yanaasagi;
       	oyundizisi[konum1+j][konum2]=dizikelimeleri[j+arttir];
	   }
    
	}
	 }
	 else{
	 		goto rasgelekonum;//e�er s��mazsa kelimeler tekrar tekrar denemesi i�in 
	 }

}

  
   
   int rasgele=0;
    char c;
    //122-132 arasi oyun dizimizeki \0 karakterlerimize rasgele harf girmesi icin
    for(int i=0;i<12;i++){
    for(int j=0;j<12;j++){
  
	if(oyundizisi[i][j]=='\0'){
	rasgele=rand()%26+65;
	c=char(rasgele);//ascii tablomuzdan yararlanarak sayi degerinin harfe kar��l���
	oyundizisi[i][j]=c;
	}
  
		}
	}
	
	tekrarla:
	char secim;
	//136-278 ARAS� SECENEKLER�M�Z� BEL�RLED�K 
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
		//159-240 aras� aramak istedi�imiz kelime ve konumlar�m�z� yazdik ve arad�k
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
		//241-265 arasi aramak istedi�imizi kelimeyi yazip konumlar� ald�k
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
		//oyundan ��kmak i�in
		if(secim=='C'){
			cout<<"OYUNDAN CIKTINIZ";
		}
	
	}
	//yanl�� harf girdi�imiz i�in
		else{
		cout<<"yanlis giris yaptiniz.lutfen tekrar deneyin."<<endl;
		 goto tekrarla;
	}
	
		}
		
		
	
	}

   	
   	
   	
   
	

  


