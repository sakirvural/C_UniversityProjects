#include <iostream>
#include "polinom.h"
#include <math.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv) 
{
	polinom polinom;
	int a,b,c,x;
	
	cout<<"2. dereceden 1 bilinmeyenli denklemde kok bulma programi\n";
	cout<<"***********************************************\n\n";
	cout<<"x karenin kat sayisini giriniz : ";
	cin>>a;
	cout<<"x'in kat sayisini giriniz : ";
	cin>>b;
	cout<<"Sabit sayiyi giriniz : ";
	cin>>c;
	
	cout<<"x degerini giriniz : ";
	cin>>x;
	
	

	polinom.KatsayilaraDegerAta(a,b,c);
	
	cout<<"x'e gore y degerimiz = "<<polinom.DegerHesapla(x)<<endl;
	
	cout<<endl<<"***********************************************\n\n";
	
	polinom.KokleriHesapla();
	
	return 0;
}
