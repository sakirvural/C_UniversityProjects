#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;


int main(int argc, char** argv) {
	setlocale(LC_ALL,"turkish");
	
	int sayi,max=0,kalan,x=1,y=0,z;
	
	cout<<"sayý giriniz=";
	
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
	cout<<"en büyük sayý="<<max<<endl;
	switch(z){
		
	case 1:
		
	cout<<"birler basamaðý\a"<<endl;
		break;
		
	case 2:
				
	cout<<"onlar basamaðý\a"<<endl;
		break;
		
	case 3:
		
	cout<<"yüzler basamaðý\a"<<endl;
		break;
			
	case 4:
		
	cout<<"binler basamaðý\a"<<endl;
		break;
		
	case 5:
		
	cout<<"onbinler basamaðý\a"<<endl;
		break;
		
	case 6:
		
	cout<<"yüzbinler basamaðý\a"<<endl;
	
		break;
		
	case 7:
	
	cout<<"milyonlar basamaðý\a"<<endl;
	
	    break;
	    
	case 8:
		
	cout<<"onmilyonlar basamaðý\a"<<endl;
	
	    break;
	    
    case 9:
    
    cout<<"yüzmilyonlar basamaðý\a"<<endl;
    
        break;
		
		
	
	}
	
	return 0;
}

