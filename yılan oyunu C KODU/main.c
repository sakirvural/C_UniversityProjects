#include <stdio.h>
#include <stdlib.h>
#include <time.h>//rasgele sayý üretirken kullandýk ayný kalmasýn diye 
#include  <locale.h>//türkçe karakterleri yazdýrabilmek için kütüphane


//öncelikle hocam oyun 120 sn çok fazlaydý 30 sn yaptým süreyi :)

int main(){
	
    setlocale(LC_ALL,"turkish");//türkçe karakterleri ekrana bastýrmak için
	char a[12][12];// 12 12 lik bi dizi
	char alfabe[5]="wasd";
	char harf;
    int can;//3 can hakký
	int i,x,sayi1,sayi2,z;
	time_t start,end;//zaman tutmak için
	int zaman;
	enbas://eðer yanarsa ,kazanýrsa veya zaman dolarsa herþeyi tekrar baþa almasý için
		time(&start);//zamaný baþlattýk
 can=3;//3 can hakkýmýz
      srand(time(NULL));//rasgele sayý üretirken tekrar oynadýðýmýzda sýfýrlama iþlemi için
      sayi1=rand()%9+1;//yemi rasgele yere attýk 12 12 lik dizi içinde
      sayi2=rand()%9+1;//yemi rasgele yere attýk
       yanma://eðer kullanýcý duvarlara çarparsa baþa alýp can deðerleri 0 ün üstünde mi diye  kontrol etmek için ve yýlanýmýzý 1 2 noktasýna koymak için tekrar
       	if(can>0){//can 0dan büyük mü diye
       		
       		int ileri=1,geri=2;//yýlanýn baþlangýç noktasý vee yandýðýmýzda sürekli ayný konuma alsýn diye
   dondur://kullanýcý eðer duvara deymediðinde veya zaman bitmediði sürece sürekli döndürmesi için
   	
       
	   
   	    if(sayi1==ileri && sayi2==geri ){//yýlanýmýz yemi yediðinde kontrol etmek için ayný konumdalar mý diye eper ayný konumda deðilse else ile devam ettþk
   	    	
   	    	for(i=0;i<12;i++){//satýr ve sütun için
		for(x=0;x<12;x++){
			if(i==0 || i==11 || x==0 || x==11){//eðer yemi yediðimizde duvar kenarlarýnda yakýn biyerdeyse duvarlarmýz deðiþmesin diye 
			a[ileri][geri+1]='|';
			a[ileri][geri-1]='|';
			a[ileri+1][geri]='-';
			a[ileri-1][geri]='_';
			a[ileri][geri]='X';	
		     }
			else {				
			a[ileri][geri+1]='.';//eðer yemi yediðimizde duvar kenarlarna yakýn biyerde deðilse yedikten sonraki yerimizi x çevirip her yeri . yapsýn diye
			a[ileri][geri-1]='.'; 
			a[ileri+1][geri]='.';
			a[ileri-1][geri]='.';
			a[ileri][geri]='X';
			}
				
		printf("%c",a[i][x]);// ekrana kazandýðýmýz konumu yazdýrdýk
		}
	      printf("\n");// satýr atlatmak için \n koyduk
	
	}
   	    	printf("\nTebrikler Kazandýnýz!\n\n");//oyunu kazandýk
   	    		scanf("%s",&harf);//kullanýcadan harf aldýk
   	 	if('Q'==harf ||'q'==harf){//eðer q ve Q ise girdðimiz harf oyunu bitirdik
		
		printf("\nQ-q bastýðýnýz için oyun bitmiþtir");
	}
	else{//eðer deðilse oyunu tekrar oynamak için ekraný sildik vee oyunu baþa aldýk enbas kýsmýmýza
			system("CLS");//ekraný sildik
   	      goto enbas;//en basa aldýk
	}
   	    
		   }
	  else {//eðer yemle yýlan ayný yerde deðilse burdan devam ettik
	  	//burdaki asýl yaptýðýmýz kýsým dizi içerisine duvarlarý yemi ve yýlaný koyduk
	  		for(i=0;i<12;i++){
		for(x=0;x<12;x++){
			//önceliðimiz yýlaný ve yemi koymak
		if(i==ileri && x==geri){// yýlanýmýz baþlangýç konumu
				
			a[ileri][geri]='X';//yýlanýmýz X yazdýrdýk ekrana
			
			
		}
		
		
		else{//sonra yemimizi koyduk
			if(i==sayi1 && x==sayi2){
				 a[sayi1][sayi2]='*';//yemi ekrana yazdýrdýk
			}
			else{	 
			if(i==0){//eðer satýr 0 ise duvar koy
		
			a[i][x]='_';
		}		
	
	
	    else if(x==0){//eðer sütun 0 ise duvar koy
	    a[i][x]='|';
		}
	   
	   else if(x==11){//eðer sütun 11 ise duvar koy
	    a[i][x]='|';	
		}
		else if(i==11){//eðer satýr 0 ise duvar koy
	    a[i][x]='_';
		}
		else{//eðer bunlardan biri deðile 10 10 lýk kýsýma nokta koyduk
		a[i][x]='.';		
		}
	
	} 
		}
			
	 
}
			}
			
			//yýlan  oyunumuz baþlattýk
	printf("Yýlan Oyununa Hoþ geldiniz, hareket için wasd tuþlarýný kullanýnýz.\n\n");

	for(i=0;i<12;i++){//koydupumuz konumlarý ekrana bastýk
		for(x=0;x<12;x++){
		printf("%c",a[i][x]);
		}
	printf("\n");
	
	}
	
	
	
	printf("\n");
	
	scanf("%s",&harf);//harf aldýk
	time(&end);//harf aldýktan sonra zamaný bitirdik ne kadar süre geçti saysýn diye
	zaman=end-start;//zaman deðiþkeni içine attýk zamaný

	if(zaman<30){//eðer zaman 30sn den küçükçe þu iþlemleri yapsýn 
		
			if('Q'==harf ||'q'==harf){//kullanýcý Q ve q harfini girerse oyunu bitirsin
		
		printf("\nQ-q bastýðýnýz için oyun bitmiþtir");
	}
	else 
	{
	
   if('w'==harf){//eðer kullanýcý w basarsa yýlaný yukarý konuma alsýn
   	ileri--;
	}
    
	if('a'==harf){//eðer kullanýcý a basarsa yýlaný sol konuma  alsýn
	geri--;	
	}
	
   if('s'==harf){//eðer kullanýcý s basarsa yýlaný asaðý konuma alsýn alsýn
		ileri++;
   }
	
   	if('d'==harf){//eðer kullanýcý d basarsa yýlaný sað konuma  alsýn
		geri++;	
	}
	
if(0==ileri|| 11==ileri || 0==geri || 11==geri){//kullanýcýnýn girdiði harflere göre yýlanýn alýnan konumlarý duvarlara çarpýyorsa candan düþsün
       	can--;//caný azalttýk duvarý çarptýðý için
   
      if('Q'==harf ||'q'==harf){//eðer kullanýcý Q q harfi girdiyse oyun bitti
		
		printf("\nQ-q bastýðýnýz için oyun bitmiþtir");
	}
	else{//ekraný silip can deðerimiz 0 dan büyük mü diye yanma konuma gönderdik yýlanýmýzý baþlangýç konumuna attýk
			system("CLS");
			 
   	      goto yanma;
	}
      	
      	
       	
      
	   }
	   else//eðer duvarlara çarpmadýysa yýlanýmýzýn konumunu götürdük ekraný sildik döndürdük
	   {
	   	system("CLS");
	   	goto dondur;
	   	
	   }
	  }
       		
		   }
		  
		  else{//verilen sürede tamamlamadýðýmýz için kaybettik
		  	

		  	printf("\nSize verilen sürede oyunu tamamlayamadýnýz!\n");
		  		  	scanf("%s",&harf);//kullanýcý tekrar oynamak istiyor mu diye kullanýca sorduk Q ve q harfi girerse oyun biter
   	 	if('Q'==harf ||'q'==harf){
		
		printf("\nQ-q bastýðýnýz için oyun bitmiþtir");
	}
	else{
			system("CLS");//ekraný sildik enbasa aldýk oyunu yemin yerini deðiþtirmesi için rasgele ve zamaný 0 lamak için
			 
   	      goto enbas;
	}
		  	
		  }
		
	}
		  
	}	   
     else {//can hakkýmýz bitti oyunu kaybettik
     	for(i=0;i<12;i++){
		for(x=0;x<12;x++){
		printf("%c",a[i][x]);
		}
	printf("\n");
	
	}
     	
     		printf("\nBaþarýsýz üç hakkýnýzý tamamladýnýz!\n\n");
     	  	scanf("%s",&harf);//kullanýcadan harf aldýk tekrar oynuyccak mý diye Q ve q harfi giderse oyun biter yoksa oyunu baþa alýrýz tekrar oynarýz
   	 	if('Q'==harf ||'q'==harf){
		
		printf("\nQ-q bastýðýnýz için oyun bitmiþtir");
	}
	else{
			system("CLS");//ekraný sildik oyunu en basa aldýk yemin yerini rasgele deðiþtirmek ve süreyide 0lamak için
			 
   	      goto enbas;
	}
     	
     	
		   }
    

return 0;
}



