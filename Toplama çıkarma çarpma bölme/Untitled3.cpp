#include <iostream>

using namespace std;

int main(){

cout<<"lutfen '+','-','*','/' birini giriniz"<<endl;
	char a;
while('q'!=a){
	
	cin>>a;
	int sayi1,sayi2;
	
	switch(a){
	case '+':
		cout<<"sayi 1 ve sayi 2 giriniz : ";
cin>>sayi1>>sayi2;
		cout<<sayi1+sayi2<<endl;
		break;
	case '-':
		cin>>sayi1>>sayi2;
	cout<<sayi1-sayi2<<endl;
		break;
			
	case '*':
     cin>>sayi1>>sayi2;
     	cout<<sayi1*sayi2<<endl;
		break;
	case '/':
	cin>>sayi1>>sayi2;
		cout<<sayi1/sayi2<<endl;
		break;
		case 'q':
			cout<<"islem sonlandi";
			break;
		default:
			cout<<"lütfen '+','-','*','/' birini giriniz";
				break;
}
}

	return 0;
	
	
}
