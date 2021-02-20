#include <iostream>

using namespace std;

int main(){
	int x ;
	cout<<"sayi giriniz : ";
	cin>>x;
	int z=1;
int l =x;

	for(int i=0;i<x;i++){
		
		for(int c=1;c<l;c++){
			cout<<" ";
		}
		
		for(int b=0;b<z;b++){
				cout<<"*";
		}
		z=z+2;
		l--;
	cout<<endl;
		
	}
	
	return 0;
}
