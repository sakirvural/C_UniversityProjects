# include<fstream>
# include<iostream>

using namespace std;

void MatrisOku(char[],int[][100],int&,int&);
void SonucYaz(char[],int[][2],int);
int Arama(const int [][100],const int[][100],int[][2],int,int,int,int); 

int main()
{
  char dosyaAdi1[]="AnaMatris.txt";//ana matrisimizin dosya ismini tutan dizi
  char dosyaAdi2[]="ArananMatris.txt";//aranan matrisimizin dosya ismini tutan dizi
  char dosyaAdi3[]="Sonuc.txt";//sonuc matrismizin dosya ismini tutan dizi
  int anaMatris[100][100]; // maksimum 100*100 boyutunda bir dizi
  int arananMatris[100][100]; //// maksimum 100*100 boyutunda aranan matris
  int sonuclar[100][2]={{11,2},{2,3}}; // aranan matrisin maksimum 100 defa bulunabilecegini varsayd�k
  
  int satir,sutun; //ana matrisin satir ve sutun degerleri
  int arananSatir, arananSutun; // aranan matrisin satir ve sutun degerleri
  int sonucSayisi;//ka� tane buldu�unu belirlemek i�in 
  
  cout<<"ANA MATRIS"<<endl<<"_______________________"<<endl;//ana matrisimiz
  MatrisOku(dosyaAdi1,anaMatris,satir,sutun); // Dosyadan Ana matrisimizi okumas� i�in void fonksiyonuna g�nderdik
  cout<<endl<<"ARANAN MATRIS"<<endl<<"_______________________"<<endl;//aranan matris
  MatrisOku(dosyaAdi2,arananMatris,arananSatir,arananSutun); // Dosyadan Ara matrisimizi okumasi i�in 1 fonksiyonda 2 dosyam�z�da okuduk ana ve ara matris i�in
  cout<<endl;
  sonucSayisi=Arama(anaMatris,arananMatris,sonuclar,satir,sutun,arananSatir,arananSutun); // Arama Islemi yap�p ka� tane buldu�unu sonuc sayisini return ile int fonksiyonuyla d�nderdik ve e�itledik
  SonucYaz(dosyaAdi3,sonuclar,sonucSayisi);//sonuc de�erimizi ve sol �st k��ede bulundurduklar� konumu txt dosyas�na yazmas� i�in void fonksiyon g�derdik
}


void MatrisOku(char dosyaAdi[],int matris[][100],int satir,int sutun)
{   

ifstream oku;
oku.open(dosyaAdi);//void fonksiyonu ile gelen dosyaadi char dizisi i�ersindeki txt dosya ismini ald�k vee txt dosyam�z� a�t�k
oku>>satir>>sutun;//a��ld���nda ilk 2 de�eri satir ve sutunumuzu ald�k ve de�i�kenlere kaydettik

for(int i=0;i<satir;i++){//satir ve sutun de�erlerimizi ald���m�z txt dosyas� i�ersindeki diziyi okumaya ba�lad�k ve matrisimize att�k
	for(int j=0;j<sutun;j++){
		oku>>matris[i][j];
	}

}

oku.close();//dosya okumay� sonland�rd�k
cout<<"satir sayisi ="<<satir<<endl<<"sutun sayisi="<<sutun<<endl;//ekrana satir sayisi ile sutun say�s�n� bast�k txt dosyas�ndan ald���m�z
for(int i=0;i<satir;i++){//dizimizi ekrana bast�rd�k
	for(int j=0;j<sutun;j++){
		cout<<matris[i][j]<<" ";
	}
cout<<endl;
}

}

void SonucYaz(char dosyaAdi[],int sonuclar[][2],int sonucSayisi)
{
ofstream yazdir(dosyaAdi,ios::app); 
yazdir<<sonucSayisi;//sonuc sayisini txt dosyas�na yazd�
yazdir<<endl;
	for(int i=0;i<sonucSayisi;i++){//sonuc dizi de�erlerimizi txt dosyalar� i�ine yazd�rd�k
	for(int j=0;j<2;j++){
		yazdir<<sonuclar[i][j]<<" ";
	}
    yazdir<<endl;
}
yazdir.close();// dosyaya yazma i�lemi sonlandirilir
}
int Arama(const int anaMatris[][100],const int arananMatris[][100],int sonuclar[][2],int satir,int sutun,int arananSatir,int arananSutun)
{
   int s=0,d=0;//sonuclar dizimizdeki satir ve sutun ayarlamak i�in
  int toplam=0;//saya� gibi e�le�me oldu�unda artt�rmas� i�in  carpima e�it mi diye 
  int carpim=arananSatir*arananSutun;//arananmatrisimizin satir sutunlar�n� alarak �arp�m�n� ald�k ve e�le�me say�m�z� bununla bulaca��z
  int bulundu=0;//
  	int i=0,j=0,x=0,y=0;//while d�ng�lerindeki ba�lama de�eri satir sutunlar�
    // forla yapmak yerine while yapt�m
     	while(i<satir){//ana matrisimizin satiri
	    	j=0;//alttaki while ��kt���nda i artt���nda alttaki while tekrar 0 dan ba�lat�p i�ine girip taratmak i�in
	    while(j<sutun){//ana matrismizin sutunu
		toplam=0;//konumuzu de�i�tirdi�imizde ana matrisin ara matris �zerinde e�le�meleri 0lamas� i�in ��nk� konum de�i�ikli�i oldu�u i�in ana matristen tekrar 0dan e�le�tirmelere ba�lad�k
	    	x=0;//alttaki whilemizi j 1 artt���nda konum de�i�ece�i i�in x mizi aranan matriste satir sayimizi 0dan ba�latt�k yeniden 
		
		while(x<arananSatir){//aranan matristeki satir sayisi
			y=0;//x 1 artt���nda y m�z� 0 lamak i�in ��nk� aranan matriste satir sayimizi artt���m�zda 0dan sutunlar� artt�rmak i�in 
		while(y<arananSutun){//aranan matriteki satir sayisi
			if(anaMatris[i+x][j+y]==arananMatris[x][y]){//ana matriste aranan matris sayisi e�le�irse if i�ine girsin
					
    toplam++;//toplam 1 artt�kt�k ��nk� aranan matris dizisi i�indeki sayilar ana matriste e�le�ti
	if(toplam==carpim){//toplam de�eri e�er ana matristeki sayilar aranan matristeki t�m say�larla e�le�irse 
		bulundu++;//e�le�me buldu�u i�in 1 e�le�tirme artt�rm�� olduk 
	    sonuclar[s][d]=i;//ana matris dizisi i�inde sol �st k��edeki konumu zaten ana matrisin satiri ve sutunu aramaya ba�lad���m�z noktay� verir ilk 2 while ba�lad��� yerler
	    sonuclar[s][d+1]=j;//burayada sol �st k��edeki konumun sutun de�erini att�k 
	        s++;//s 1 artt�rt�k �unku her e�letirme bitti�inde bulundu say�s� artt���nda  sonuclar dizisinde yeni konuma atmak i�in satir i�in 
	    
            }
			}
			y++;//while sonuna geldi�inde tekrar ba�a d�nd���m�zde aranan sutun sayisi bitene kadar d�nmesi i�in 1 artt�kt�k while ��kana kadar 
			
	    	}
	     	x++;//while sonuna geldi�inde tekrar ba�a d�nd���m�zde aranan satir  sayisi bitene kadar d�nmesi i�in 1 artt�kt�k while ��kana kadar 
         	}
			j++;//while sonuna geldi�inde tekrar ba�a d�nd���m�zde ana matristei sutun sayisi bitene kadar d�nmesi i�in 1 artt�kt�k while ��kana kadar 
	    	}
	
            i++;//while sonuna geldi�inde tekrar ba�a d�nd���m�zde ana matristeki satir  sayisi bitene kadar d�nmesi i�in 1 artt�kt�k while ��kana kadar 
        	}
 
	cout<<"SONUCLAR"<<endl;//ekrana sonuclar� yazd�rd�k 110-119 aras� alt k�s�m 
	cout<<"_______________________";
	cout<<endl;
	cout<<bulundu<<endl;
	for(int i=0;i<bulundu;i++){
	for(int j=0;j<2;j++){
		cout<<sonuclar[i][j]<<" ";
	}
cout<<endl;
}
return bulundu;//return ile int main fonksiyonunda sonucsayisi de�erine g�nderdik
}
