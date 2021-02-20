#include <iostream>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {

	 char dizi[100];
	 int sayi,sayi1,c=-1;
	 cout<<"10luktan 16 la "<<endl;
	 cin>>sayi;
	 
	 
	  while(sayi>0){
	  		c++;
	  	sayi1=sayi%16;
	  	sayi=sayi/16;
	  	

	   	   if(sayi1==0)
	   	   dizi[c]='0';
	   	    if(sayi1==1) 
	   	      dizi[c]='1';
		   if(sayi1==2)
				   dizi[c]='2';  
		 if(sayi1==3)   
					dizi[c]='3';
		if(sayi1==4) 
		dizi[c]='4';
		  if(sayi1==5) 
		  dizi[c]='5';
		    if(sayi1==6) 
			dizi[c]='6';
			  if(sayi1==7)  
			  dizi[c]='7';
			   if(sayi1==8) 
			   dizi[c]='8';
			     if(sayi1==9)
		  	dizi[c]='9';

	  		if(sayi1==10)
	  		dizi[c]='A';
	  		if(sayi1==11)
	  		dizi[c]='B';
	  		if(sayi1==12)
	  		dizi[c]='C';
	  		if(sayi1==13)
	  		dizi[c]='D';
	  		if(sayi1==14)
	  		dizi[c]='E';
	  		if(sayi1==15)
	  		dizi[c]='F';
	  		
		
		  }
	  for(c;c>=0;c--){
	  	cout<<dizi[c];
	  }
	  	  	

    cout<<endl;
    cout<<"16liktan 10luga"<<endl;
	 string kelimedizisi[1];
	 string kelime;
	 int toplasayi=0;
	 cin>>kelime;
	 int i=0;
	 kelimedizisi[0]=kelime;
	 int a=(kelimedizisi[0].length()+1);
   	char dizi2[a];
    strcpy(dizi2,kelimedizisi[0].c_str());
    a=a-2;
    for(a;a>=0;a--){
    
     if(dizi2[a]=='0')
    toplasayi=toplasayi+pow(16,i)*0;
     if(dizi2[a]=='1')
     toplasayi=toplasayi+pow(16,i)*1;
     if(dizi2[a]=='2')
     toplasayi=toplasayi+pow(16,i)*2;
      if(dizi2[a]=='3')
      toplasayi=toplasayi+pow(16,i)*3;
       if(dizi2[a]=='4')
       toplasayi=toplasayi+pow(16,i)*4;
        if(dizi2[a]=='5')
        toplasayi=toplasayi+pow(16,i)*5;
         if(dizi2[a]=='6')
         toplasayi=toplasayi+pow(16,i)*6;
          if(dizi2[a]=='7')
          toplasayi=toplasayi+pow(16,i)*7;
           if(dizi2[a]=='8')
           toplasayi=toplasayi+pow(16,i)*8;
            if(dizi2[a]=='9')
            toplasayi=toplasayi+pow(16,i)*9;
             if(dizi2[a]=='A')
             toplasayi=toplasayi+pow(16,i)*10;
              if(dizi2[a]=='B')
              toplasayi=toplasayi+pow(16,i)*11;
               if(dizi2[a]=='C')
               toplasayi=toplasayi+pow(16,i)*12;
                if(dizi2[a]=='D')
                toplasayi=toplasayi+pow(16,i)*13;
                 if(dizi2[a]=='E')
                 toplasayi=toplasayi+pow(16,i)*14;
                  if(dizi2[a]=='F')
                  toplasayi=toplasayi+pow(16,i)*15;
                 
             
	  			i++;
		
	}
     cout<<toplasayi;
   
	
	
	 
	return 0;
}
