#include <iostream>
#include "oyun.h"
#include <time.h>//srand i�in
#include <cstdlib> 	// rand i�in
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	srand(time(0));//s�rekli rasgele �retmesi i�in
	oyun o;
	o.oyunTuret();//oyun t�retme
	o.ekranaYazdir();//oyun ekrana yazdirma
	system("CLS");
	o.atisYap();//atislar��z
	o.OyunSonlandir();//oyun sonlandirip skorlar� yazma
	return 0;
}
