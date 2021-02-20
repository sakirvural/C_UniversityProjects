#include <iostream>

using namespace std;

int main(){
	int m,n,toplam1=0,toplam2=0;
	cout<<"M ve N sayisini giriniz : ";
	cin>>m;
	cin>>n;
	for(int i=1;i<m;i++){
		if(m%i==0){
			toplam1=toplam1+i;
		}
	}
	for(int y=1;y<n;y++){
		if(n%y==0){
			toplam2=toplam2+y;
		}
	}
	
	if(toplam1==n && toplam2==m){
		cout<<"dost sayi";
	}
	else 
	cout <<"dost sayi degildir";
	
	return 0;
	
	
}
