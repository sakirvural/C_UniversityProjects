#ifndef OYUN_H
#define OYUN_H

class oyun
{
	private:
	int player1Puan=0,//kullan�c�lar�n ilk puanlari
		player2Puan=0,	
	    bardakBoyutu,//degisecek olan bardak boyumuz 
	    rasgeleSayi;//rasgele bardaklar�n�n yerini koymak i�in

	char *oyundizisi=new char[bardakBoyutu*3];//tek boyutlu dizimizde oyundizimizi olusturma i�in gelen kucuk-orta-buyuk boyutlar�ndan
		//herhangi biri 3 raf oldu�u i�in �arpt�k 
	public://aray�z�m�z
	void oyunTuret();
	void ekranaYazdir();
	void atisYap();
	void OyunSonlandir();
	
		
};

#endif
