#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	//1 1 2 3 5 8 13 21
	int sayi=1,belirt;
	cout<<"sayi giriniz :";
	cin>>belirt;
	int dizi[belirt];
    sayi=1;
	for(int i=0;i<belirt;i++){
		if(i==0 || i==1)
		dizi[i]=sayi;
	    else 
	    dizi[i]=dizi[i-1]+dizi[i-2];
		
		
	}
		for(int i=0;i<belirt;i++){
	  cout<<dizi[i]<<" ";
	}
	return 0;
}
