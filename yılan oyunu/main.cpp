#include <iostream>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	  
	  int rasgele1,rasgele2;
	  char kelime;
	  
	  srand(time(NULL));
	  rasgele1=rand()%10+1;
	  rasgele2=rand()%10+1;
	  int oynat1=1,oynat2=2;
	  do{
	  	 for(int x=0;x<11;x++){
    	for(int y=0;y<11;y++){
    		if(x==0)
    		cout<<"-";
    		else if(x==10){
    			cout<<"-";
    		}
    			else if(y==0){
    				cout<<"|";
				
			}
			else if(y==10){
				cout<<"|";
			}
			else if(x==rasgele1 && y==rasgele2){
				cout<<".";
			}
			else if(x==oynat1 && y==oynat2){
				cout<<"X";
			}
    		else{
    			cout<<"*";
			}
		}
		cout<<endl;
		
		
	}
	cin>>kelime;
	if(kelime=='w'){
		oynat1--;
		system("CLS");
	}
		if(kelime=='s'){
		oynat1++;
				system("CLS");
	}
		if(kelime=='a'){
		oynat2--;
				system("CLS");
	}
		if(kelime=='d'){
		oynat2++;
				system("CLS");
	}
	
	if(oynat1==0 || oynat1==10){
		cout<<"duvara vurdun"<<endl;
		oynat1=1;
		oynat2=2;
				system("CLS");	
	}
		if(oynat2==0 || oynat2==10){
	  cout<<"duvara vurdun"<<endl;
	  oynat1=1;
	  oynat2=2;	
	  		system("CLS");
	}
	if(oynat1==rasgele1 && oynat2==rasgele2){
		
		system("CLS");
		cout<<"oyunu kazandin";
		break;
		
	}
		  	
	  }while(kelime!='e');
	
   
	return 0;
}
