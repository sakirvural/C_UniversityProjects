#ifndef OYUN_H
#define OYUN_H

class oyun
{
	private:
	int player1Puan=0,//kullanýcýlarýn ilk puanlari
		player2Puan=0,	
	    bardakBoyutu,//degisecek olan bardak boyumuz 
	    rasgeleSayi;//rasgele bardaklarýnýn yerini koymak için

	char *oyundizisi=new char[bardakBoyutu*3];//tek boyutlu dizimizde oyundizimizi olusturma için gelen kucuk-orta-buyuk boyutlarýndan
		//herhangi biri 3 raf olduðu için çarptýk 
	public://arayüzümüz
	void oyunTuret();
	void ekranaYazdir();
	void atisYap();
	void OyunSonlandir();
	
		
};

#endif
