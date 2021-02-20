#include <iostream>
#include "oyun.h"
#include <time.h>//srand için
#include <cstdlib> 	// rand için
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	srand(time(0));//sürekli rasgele üretmesi için
	oyun o;
	o.oyunTuret();//oyun türetme
	o.ekranaYazdir();//oyun ekrana yazdirma
	system("CLS");
	o.atisYap();//atislarýýz
	o.OyunSonlandir();//oyun sonlandirip skorlarý yazma
	return 0;
}
