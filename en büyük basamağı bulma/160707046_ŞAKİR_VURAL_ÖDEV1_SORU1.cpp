#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;


int main(int argc, char** argv) {
	setlocale(LC_ALL,"turkish");
	
	int sayi,max=0,kalan,x=1,y=0,z;
	
	cout<<"say� giriniz=";
	
	cin>>sayi;
	max=sayi%10;
	while(sayi>0){
		y++;
		kalan=sayi%10;
		
		if(kalan>=max){
						
		if(kalan>max){
			
			max=kalan;
		x=y;
		}
		
		}	
	sayi=sayi/10;
	}
	z=y-x;
	z=y-z;
	cout<<"en b�y�k say�="<<max<<endl;
	switch(z){
		
	case 1:
		
	cout<<"birler basama��\a"<<endl;
		break;
		
	case 2:
				
	cout<<"onlar basama��\a"<<endl;
		break;
		
	case 3:
		
	cout<<"y�zler basama��\a"<<endl;
		break;
			
	case 4:
		
	cout<<"binler basama��\a"<<endl;
		break;
		
	case 5:
		
	cout<<"onbinler basama��\a"<<endl;
		break;
		
	case 6:
		
	cout<<"y�zbinler basama��\a"<<endl;
	
		break;
		
	case 7:
	
	cout<<"milyonlar basama��\a"<<endl;
	
	    break;
	    
	case 8:
		
	cout<<"onmilyonlar basama��\a"<<endl;
	
	    break;
	    
    case 9:
    
    cout<<"y�zmilyonlar basama��\a"<<endl;
    
        break;
		
		
	
	}
	
	return 0;
}

