#include <stdio.h>
#include <stdlib.h>
#include <time.h>//rasgele say� �retirken kulland�k ayn� kalmas�n diye 
#include  <locale.h>//t�rk�e karakterleri yazd�rabilmek i�in k�t�phane


//�ncelikle hocam oyun 120 sn �ok fazlayd� 30 sn yapt�m s�reyi :)

int main(){
	
    setlocale(LC_ALL,"turkish");//t�rk�e karakterleri ekrana bast�rmak i�in
	char a[12][12];// 12 12 lik bi dizi
	char alfabe[5]="wasd";
	char harf;
    int can;//3 can hakk�
	int i,x,sayi1,sayi2,z;
	time_t start,end;//zaman tutmak i�in
	int zaman;
	enbas://e�er yanarsa ,kazan�rsa veya zaman dolarsa her�eyi tekrar ba�a almas� i�in
		time(&start);//zaman� ba�latt�k
 can=3;//3 can hakk�m�z
      srand(time(NULL));//rasgele say� �retirken tekrar oynad���m�zda s�f�rlama i�lemi i�in
      sayi1=rand()%9+1;//yemi rasgele yere att�k 12 12 lik dizi i�inde
      sayi2=rand()%9+1;//yemi rasgele yere att�k
       yanma://e�er kullan�c� duvarlara �arparsa ba�a al�p can de�erleri 0 �n �st�nde mi diye  kontrol etmek i�in ve y�lan�m�z� 1 2 noktas�na koymak i�in tekrar
       	if(can>0){//can 0dan b�y�k m� diye
       		
       		int ileri=1,geri=2;//y�lan�n ba�lang�� noktas� vee yand���m�zda s�rekli ayn� konuma als�n diye
   dondur://kullan�c� e�er duvara deymedi�inde veya zaman bitmedi�i s�rece s�rekli d�nd�rmesi i�in
   	
       
	   
   	    if(sayi1==ileri && sayi2==geri ){//y�lan�m�z yemi yedi�inde kontrol etmek i�in ayn� konumdalar m� diye eper ayn� konumda de�ilse else ile devam ett�k
   	    	
   	    	for(i=0;i<12;i++){//sat�r ve s�tun i�in
		for(x=0;x<12;x++){
			if(i==0 || i==11 || x==0 || x==11){//e�er yemi yedi�imizde duvar kenarlar�nda yak�n biyerdeyse duvarlarm�z de�i�mesin diye 
			a[ileri][geri+1]='|';
			a[ileri][geri-1]='|';
			a[ileri+1][geri]='-';
			a[ileri-1][geri]='_';
			a[ileri][geri]='X';	
		     }
			else {				
			a[ileri][geri+1]='.';//e�er yemi yedi�imizde duvar kenarlarna yak�n biyerde de�ilse yedikten sonraki yerimizi x �evirip her yeri . yaps�n diye
			a[ileri][geri-1]='.'; 
			a[ileri+1][geri]='.';
			a[ileri-1][geri]='.';
			a[ileri][geri]='X';
			}
				
		printf("%c",a[i][x]);// ekrana kazand���m�z konumu yazd�rd�k
		}
	      printf("\n");// sat�r atlatmak i�in \n koyduk
	
	}
   	    	printf("\nTebrikler Kazand�n�z!\n\n");//oyunu kazand�k
   	    		scanf("%s",&harf);//kullan�cadan harf ald�k
   	 	if('Q'==harf ||'q'==harf){//e�er q ve Q ise gird�imiz harf oyunu bitirdik
		
		printf("\nQ-q bast���n�z i�in oyun bitmi�tir");
	}
	else{//e�er de�ilse oyunu tekrar oynamak i�in ekran� sildik vee oyunu ba�a ald�k enbas k�sm�m�za
			system("CLS");//ekran� sildik
   	      goto enbas;//en basa ald�k
	}
   	    
		   }
	  else {//e�er yemle y�lan ayn� yerde de�ilse burdan devam ettik
	  	//burdaki as�l yapt���m�z k�s�m dizi i�erisine duvarlar� yemi ve y�lan� koyduk
	  		for(i=0;i<12;i++){
		for(x=0;x<12;x++){
			//�nceli�imiz y�lan� ve yemi koymak
		if(i==ileri && x==geri){// y�lan�m�z ba�lang�� konumu
				
			a[ileri][geri]='X';//y�lan�m�z X yazd�rd�k ekrana
			
			
		}
		
		
		else{//sonra yemimizi koyduk
			if(i==sayi1 && x==sayi2){
				 a[sayi1][sayi2]='*';//yemi ekrana yazd�rd�k
			}
			else{	 
			if(i==0){//e�er sat�r 0 ise duvar koy
		
			a[i][x]='_';
		}		
	
	
	    else if(x==0){//e�er s�tun 0 ise duvar koy
	    a[i][x]='|';
		}
	   
	   else if(x==11){//e�er s�tun 11 ise duvar koy
	    a[i][x]='|';	
		}
		else if(i==11){//e�er sat�r 0 ise duvar koy
	    a[i][x]='_';
		}
		else{//e�er bunlardan biri de�ile 10 10 l�k k�s�ma nokta koyduk
		a[i][x]='.';		
		}
	
	} 
		}
			
	 
}
			}
			
			//y�lan  oyunumuz ba�latt�k
	printf("Y�lan Oyununa Ho� geldiniz, hareket i�in wasd tu�lar�n� kullan�n�z.\n\n");

	for(i=0;i<12;i++){//koydupumuz konumlar� ekrana bast�k
		for(x=0;x<12;x++){
		printf("%c",a[i][x]);
		}
	printf("\n");
	
	}
	
	
	
	printf("\n");
	
	scanf("%s",&harf);//harf ald�k
	time(&end);//harf ald�ktan sonra zaman� bitirdik ne kadar s�re ge�ti says�n diye
	zaman=end-start;//zaman de�i�keni i�ine att�k zaman�

	if(zaman<30){//e�er zaman 30sn den k���k�e �u i�lemleri yaps�n 
		
			if('Q'==harf ||'q'==harf){//kullan�c� Q ve q harfini girerse oyunu bitirsin
		
		printf("\nQ-q bast���n�z i�in oyun bitmi�tir");
	}
	else 
	{
	
   if('w'==harf){//e�er kullan�c� w basarsa y�lan� yukar� konuma als�n
   	ileri--;
	}
    
	if('a'==harf){//e�er kullan�c� a basarsa y�lan� sol konuma  als�n
	geri--;	
	}
	
   if('s'==harf){//e�er kullan�c� s basarsa y�lan� asa�� konuma als�n als�n
		ileri++;
   }
	
   	if('d'==harf){//e�er kullan�c� d basarsa y�lan� sa� konuma  als�n
		geri++;	
	}
	
if(0==ileri|| 11==ileri || 0==geri || 11==geri){//kullan�c�n�n girdi�i harflere g�re y�lan�n al�nan konumlar� duvarlara �arp�yorsa candan d��s�n
       	can--;//can� azaltt�k duvar� �arpt��� i�in
   
      if('Q'==harf ||'q'==harf){//e�er kullan�c� Q q harfi girdiyse oyun bitti
		
		printf("\nQ-q bast���n�z i�in oyun bitmi�tir");
	}
	else{//ekran� silip can de�erimiz 0 dan b�y�k m� diye yanma konuma g�nderdik y�lan�m�z� ba�lang�� konumuna att�k
			system("CLS");
			 
   	      goto yanma;
	}
      	
      	
       	
      
	   }
	   else//e�er duvarlara �arpmad�ysa y�lan�m�z�n konumunu g�t�rd�k ekran� sildik d�nd�rd�k
	   {
	   	system("CLS");
	   	goto dondur;
	   	
	   }
	  }
       		
		   }
		  
		  else{//verilen s�rede tamamlamad���m�z i�in kaybettik
		  	

		  	printf("\nSize verilen s�rede oyunu tamamlayamad�n�z!\n");
		  		  	scanf("%s",&harf);//kullan�c� tekrar oynamak istiyor mu diye kullan�ca sorduk Q ve q harfi girerse oyun biter
   	 	if('Q'==harf ||'q'==harf){
		
		printf("\nQ-q bast���n�z i�in oyun bitmi�tir");
	}
	else{
			system("CLS");//ekran� sildik enbasa ald�k oyunu yemin yerini de�i�tirmesi i�in rasgele ve zaman� 0 lamak i�in
			 
   	      goto enbas;
	}
		  	
		  }
		
	}
		  
	}	   
     else {//can hakk�m�z bitti oyunu kaybettik
     	for(i=0;i<12;i++){
		for(x=0;x<12;x++){
		printf("%c",a[i][x]);
		}
	printf("\n");
	
	}
     	
     		printf("\nBa�ar�s�z �� hakk�n�z� tamamlad�n�z!\n\n");
     	  	scanf("%s",&harf);//kullan�cadan harf ald�k tekrar oynuyccak m� diye Q ve q harfi giderse oyun biter yoksa oyunu ba�a al�r�z tekrar oynar�z
   	 	if('Q'==harf ||'q'==harf){
		
		printf("\nQ-q bast���n�z i�in oyun bitmi�tir");
	}
	else{
			system("CLS");//ekran� sildik oyunu en basa ald�k yemin yerini rasgele de�i�tirmek ve s�reyide 0lamak i�in
			 
   	      goto enbas;
	}
     	
     	
		   }
    

return 0;
}



