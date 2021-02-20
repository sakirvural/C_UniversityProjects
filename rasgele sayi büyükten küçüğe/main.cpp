#include <iostream>
#include <time.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	srand(time(NULL));
	int dizi[10],max;
	for(int i=0;i<10;i++){
		dizi[i]=rand()%1000;
	}
   	for(int i=0;i<10;i++){
		cout<<dizi[i]<<endl;
	}

	for(int i=0;i<10;i++){
	for(int j=0;j<10;j++){
		
		if(dizi[j]>dizi[i]){
			max=dizi[j];
			dizi[j]=dizi[i];
			dizi[i]=max;
		 // 123 
			
		}
		
	}
	}
	cout<<endl;
		for(int i=0;i<10;i++){
		cout<<dizi[i]<<endl;
	}
	
	return 0;
}
