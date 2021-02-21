#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int Prefix(char dizi[],int a){
	
     vector<int> vi;
     int islem=0;
     
	for(a;a>=0;a--){

	if(dizi[a]=='+'){
	
		
		
		islem=vi.back();
		vi.pop_back();
		islem+=vi.back();
		vi.pop_back();
		vi.push_back(islem);
		
	}

	else if(dizi[a]=='-'){
		islem=vi.back();
		vi.pop_back();
		islem-=vi.back();
		vi.pop_back();
		vi.push_back(islem);
	}
	else if(dizi[a]=='*'){
		islem=vi.back();
		vi.pop_back();
		islem*=vi.back();
		vi.pop_back();
		vi.push_back(islem);
	}
	else if(dizi[a]=='/'){
		islem=vi.back();
		vi.pop_back();
		islem/=vi.back();
		vi.pop_back();
		vi.push_back(islem);
  		
	}
	else if(dizi[a]=='^'){
		islem=vi.back();
		vi.pop_back();
		islem^=vi.back();
		vi.pop_back();
		vi.push_back(islem);
}
	else {
		
	int sayi;
	
	if(dizi[a]=='0')
	sayi=0;
	if(dizi[a]=='1')
	sayi=1;
	if(dizi[a]=='2')
	sayi=2;
	if(dizi[a]=='3')
	sayi=3;
	if(dizi[a]=='4')
	sayi=4;
	if(dizi[a]=='5')
	sayi=5;
	if(dizi[a]=='6')
	sayi=6;
	if(dizi[a]=='7')
	sayi=7;
	if(dizi[a]=='8')
	sayi=8;
	if(dizi[a]=='9')
	sayi=9;
	
	
		 vi.push_back(sayi);
	}
	
		}
						
	cout<<islem;
	

}

void Postfix(char dizi[],int a ){
		
	vector<int> vi;
     int islem=0;
     
	for(int i=0;i<a;i++){

	if(dizi[i]=='+'){
		
		
		islem=vi.back();
		vi.pop_back();
		islem+=vi.back();
		vi.pop_back();
		vi.push_back(islem);
		
	}

	else if(dizi[i]=='-'){
		islem=vi.back();
		vi.pop_back();
		islem-=vi.back();
		vi.pop_back();
		vi.push_back(islem);
	}
	else if(dizi[i]=='*'){
		islem=vi.back();
		vi.pop_back();
		islem*=vi.back();
		vi.pop_back();
		vi.push_back(islem);
	}
	else if(dizi[i]=='/'){
		islem=vi.back();
		vi.pop_back();
		islem/=vi.back();
		vi.pop_back();
		vi.push_back(islem);
  		
	}
	else if(dizi[i]=='^'){
		islem=vi.back();
		vi.pop_back();
		islem^=vi.back();
		vi.pop_back();
		vi.push_back(islem);
}
	else {
		
	int sayi;
	
	if(dizi[i]=='0')
	sayi=0;
	if(dizi[i]=='1')
	sayi=1;
	if(dizi[i]=='2')
	sayi=2;
	if(dizi[i]=='3')
	sayi=3;
	if(dizi[i]=='4')
	sayi=4;
	if(dizi[i]=='5')
	sayi=5;
	if(dizi[i]=='6')
	sayi=6;
	if(dizi[i]=='7')
	sayi=7;
	if(dizi[i]=='8')
	sayi=8;
	if(dizi[i]=='9')
	sayi=9;
	
	
		 vi.push_back(sayi);
	}
	
		}
						
	cout<<vi.back();
	
}

int main(int argc, char** argv) {
	setlocale(LC_ALL,"Turkish");
	string kelime;
	
	cout<<"Hesaplanacak islem giriniz : ";
	
	cin>>kelime;
	
	int a=kelime.length();
   	char dizi[a];//kelimemizin char dizisindeki boyut için
   	
    strcpy(dizi,kelime.c_str());//kopyalama iþlemimiz
    
  
     
   vector<char> vc;
   
   vector <char> islem; 
	
    int  islemSayaci=0;
    int  sayiSayaci=0;
	for(int i=0;i<a;i++){

	if(dizi[i]=='+'){
		
	islem.push_back('+');
	islemSayaci++;	
	}

	else if(dizi[i]=='-'){
	
	islem.push_back('-');
	islemSayaci++;
	}
	else if(dizi[i]=='*'){
	islem.push_back('*');
	islemSayaci++;
	}
	else if(dizi[i]=='/'){
	
  	islem.push_back('/');
	islemSayaci++;	
	}
	else if(dizi[i]=='^'){
		
	islem.push_back('^');
	islemSayaci++;
	}
	else if(dizi[i]=='('){
		
	islem.push_back('(');
	islemSayaci=-1;
	
	}
	else if(dizi[i]==')'){
	char a;
	a=islem.back();
	vc.push_back(a);
	
	islem.pop_back();
	
	if(islem.back()=='(')
	islem.pop_back();
	islemSayaci=0;
	}
	
	else {
		sayiSayaci++;
		if(islemSayaci==1 || sayiSayaci==2){
			islemSayaci=0;
		    sayiSayaci=0;
			if(islem.back()=='*' || islem.back()=='/' || islem.back() =='^'  ){
				
			vc.push_back(dizi[i]);
			vc.push_back(islem.back());
			islem.pop_back();
			}
			else{
				vc.push_back(dizi[i]);
			}
			}
		else{
			vc.push_back(dizi[i]);
		}
	

	}
    

}
	while(!islem.empty()){
		if(islem.back()=='(')
		islem.pop_back();
		else{
		vc.push_back(islem.back());
		islem.pop_back();	
		}
		
		
	}
	char yenidizi1[vc.size()];
	
	for(int x=0;x<vc.size();x++){
	yenidizi1[x]=vc[x];
	}
	
	char yenidizi2[vc.size()];
	int sayacim=0;
	for(int x=vc.size();x>=0;x--){
	yenidizi2[sayacim]=vc[x];
	sayacim++;
	}
	
	cout<<endl<<"--------------------------------";
	cout<<endl<<"Postfix gösterim = ";
	for(int x=0;x<vc.size();x++)
	cout<<vc[x];
	
	
	if(vc[0]=='0' || vc[0]=='1' || vc[0]=='2' || vc[0]=='3' || vc[0]=='4' || vc[0]=='5' || vc[0]=='6' || vc[0]=='7' || vc[0]=='8' || vc[0]=='9'){
	
	cout<<endl<<"Postfix islemi sonucu = ";
	Postfix(yenidizi1,vc.size());

	}
	cout<<endl<<"--------------------------------";
	cout<<endl<<"Prefix gösterim = ";
	
	for(int i=vc.size();i>=0;i--)
	cout<<vc[i];
	
	if(vc[0]=='0' || vc[0]=='1' || vc[0]=='2' || vc[0]=='3' || vc[0]=='4' || vc[0]=='5' || vc[0]=='6' || vc[0]=='7' || vc[0]=='8' || vc[0]=='9'){
		
	cout<<endl<<"Prefix islemi sonucu = ";
	
    Prefix(yenidizi2,vc.size());
	}

	

    
	

		
	
	
	return 0;
}
