#include "polinom.h"
#include <iostream>
#include <math.h>

using namespace std;

polinom::polinom():A(1),B(2){} // A = 1 B = 2 default deðer atar . 

void polinom::KatsayilaraDegerAta(int gelenA ,int gelenB, int gelenC)//degerlerimizi nesnemizdeki
{
	if(gelenA==0 && gelenB==0)
		{
			cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout<<"Uyari girdiginiz A=0 B=0 degerlerine gore kok yoktur. Fakat default olarak constructor  A = 1 B = 2 kabul etmistir"<<endl;
			cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			C=gelenC;
		}
	
	else
		{
		A=gelenA;
		B=gelenB;
		C=gelenC;
		}	

}

int polinom::DegerHesapla(int x)//y degerini döndürür
{
	return A*x*x+B*x+C;
}

void polinom::KokleriHesapla()//köklerin kontrolu
{
	cout<<"DELTA : "<<B*B-4*A*C<< " buna gore "<<endl;
	
	if(B*B-4*A*C>0)
		{
		cout<<"2 farkli kok vardir"<<endl;
		cout<<"1. kok degeri : "<<(-B+sqrt(B*B-4*A*C))/2*A<<endl;
		cout<<"2. kok degeri : "<<(-B-sqrt(B*B-4*A*C))/2*A;
		
		}
	
	else if(B*B-4*A*C==0)
		{
		cout<<"Birbirine esit 2 kok vardir"<<endl;
		cout<<"2 kokun degeri : "<<(-B+sqrt(B*B-4*A*C))/2*A;
		}	
	
	else
		{
		cout<<"Sanal kok vardir"<<endl;
		cout<<"1. sanal kok degeri : "<<-B/2*A<<"+"<<sqrt(-1*(B*B-4*A*C))<<"i"<<"/"<<2*A<<endl;
		cout<<"2. sanal kok degeri : "<<-B/2*A<<"-"<<sqrt(-1*(B*B-4*A*C))<<"i"<<"/"<<2*A;
		}
	
}
