#include <iostream>
#include <stdlib.h>
#include "kelimeyaz.h"
#include <time.h>
using namespace std;

//TEK SINIF ÝÇERÝSÝNDE HEPSÝNÝ YAPTIM HOCAM TÜM ÝÞLEMLERÝ UMARIM DEDÝÐÝNÝZ ÞEKÝLDE YAPMIÞIMDIR

void OyunProfil();

int main(int argc, char** argv) {
	cout<<"Kelime bulma oyununa hos geldiniz!\n\n\n";
	kelimeyaz k;
   
    	char secim;
    
     tekrar:
     	 OyunProfil();
     	cin>>secim;
    	if(secim=='Y'||secim=='O'||secim=='K'||secim=='A'||secim=='C'){
		if(secim=='Y'){
			k.kelimeler();
		}
		  if(secim=='O'){
		cout<<"!!! ONCELIKLE OYUN OLUSTUR !!!"<<endl;
		goto tekrar;
		}
		 if(secim=='K'){
			cout<<"!!! ONCELIKLE OYUN OLUSTUR !!!"<<endl;
			goto tekrar;
		}
		 if(secim=='A'){
		cout<<"!!! ONCELIKLE OYUN OLUSTUR !!!"<<endl;
		goto tekrar;
		}
		if(secim=='C'){
			cout<<"OYUNDAN CIKTINIZ";
		}
	
	}
		else{
		cout<<"yanlis giris yaptiniz.lutfen tekrar deneyin."<<endl;
		 goto tekrar;
	}

   
	
    return 0;
}

void OyunProfil(){
	cout<<"\tYeni oyun olusturmak icin |<- Y ->| harfine basiniz\n";
	cout<<"\tOyunu goruntulemek icin |<- O ->| harfine  basiniz\n";
	cout<<"\tKelime bulmak icin |<- K ->| harfine basiniz\n";
	cout<<"\tKelime Aramasi icin |<- A ->| harfine basiniz\n";
	cout<<"\tCikmak icin |<- C ->| harfine basiniz"<<endl;
	cout<<"\tKelimeleriniz bittiyse |<- son ->| yaziniz\n"<<endl;
	cout<<"Lutfen bir secenek girin\n";
	
}

