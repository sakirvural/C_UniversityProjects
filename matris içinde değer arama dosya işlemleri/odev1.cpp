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
  int sonuclar[100][2]={{11,2},{2,3}}; // aranan matrisin maksimum 100 defa bulunabilecegini varsaydýk
  
  int satir,sutun; //ana matrisin satir ve sutun degerleri
  int arananSatir, arananSutun; // aranan matrisin satir ve sutun degerleri
  int sonucSayisi;//kaç tane bulduðunu belirlemek için 
  
  cout<<"ANA MATRIS"<<endl<<"_______________________"<<endl;//ana matrisimiz
  MatrisOku(dosyaAdi1,anaMatris,satir,sutun); // Dosyadan Ana matrisimizi okumasý için void fonksiyonuna gönderdik
  cout<<endl<<"ARANAN MATRIS"<<endl<<"_______________________"<<endl;//aranan matris
  MatrisOku(dosyaAdi2,arananMatris,arananSatir,arananSutun); // Dosyadan Ara matrisimizi okumasi için 1 fonksiyonda 2 dosyamýzýda okuduk ana ve ara matris için
  cout<<endl;
  sonucSayisi=Arama(anaMatris,arananMatris,sonuclar,satir,sutun,arananSatir,arananSutun); // Arama Islemi yapýp kaç tane bulduðunu sonuc sayisini return ile int fonksiyonuyla dönderdik ve eþitledik
  SonucYaz(dosyaAdi3,sonuclar,sonucSayisi);//sonuc deðerimizi ve sol üst köþede bulundurduklarý konumu txt dosyasýna yazmasý için void fonksiyon göderdik
}


void MatrisOku(char dosyaAdi[],int matris[][100],int satir,int sutun)
{   

ifstream oku;
oku.open(dosyaAdi);//void fonksiyonu ile gelen dosyaadi char dizisi içersindeki txt dosya ismini aldýk vee txt dosyamýzý açtýk
oku>>satir>>sutun;//açýldýðýnda ilk 2 deðeri satir ve sutunumuzu aldýk ve deðiþkenlere kaydettik

for(int i=0;i<satir;i++){//satir ve sutun deðerlerimizi aldýðýmýz txt dosyasý içersindeki diziyi okumaya baþladýk ve matrisimize attýk
	for(int j=0;j<sutun;j++){
		oku>>matris[i][j];
	}

}

oku.close();//dosya okumayý sonlandýrdýk
cout<<"satir sayisi ="<<satir<<endl<<"sutun sayisi="<<sutun<<endl;//ekrana satir sayisi ile sutun sayýsýný bastýk txt dosyasýndan aldýðýmýz
for(int i=0;i<satir;i++){//dizimizi ekrana bastýrdýk
	for(int j=0;j<sutun;j++){
		cout<<matris[i][j]<<" ";
	}
cout<<endl;
}

}

void SonucYaz(char dosyaAdi[],int sonuclar[][2],int sonucSayisi)
{
ofstream yazdir(dosyaAdi,ios::app); 
yazdir<<sonucSayisi;//sonuc sayisini txt dosyasýna yazdý
yazdir<<endl;
	for(int i=0;i<sonucSayisi;i++){//sonuc dizi deðerlerimizi txt dosyalarý içine yazdýrdýk
	for(int j=0;j<2;j++){
		yazdir<<sonuclar[i][j]<<" ";
	}
    yazdir<<endl;
}
yazdir.close();// dosyaya yazma iþlemi sonlandirilir
}
int Arama(const int anaMatris[][100],const int arananMatris[][100],int sonuclar[][2],int satir,int sutun,int arananSatir,int arananSutun)
{
   int s=0,d=0;//sonuclar dizimizdeki satir ve sutun ayarlamak için
  int toplam=0;//sayaç gibi eþleþme olduðunda arttýrmasý için  carpima eþit mi diye 
  int carpim=arananSatir*arananSutun;//arananmatrisimizin satir sutunlarýný alarak çarpýmýný aldýk ve eþleþme sayýmýzý bununla bulacaðýz
  int bulundu=0;//
  	int i=0,j=0,x=0,y=0;//while döngülerindeki baþlama deðeri satir sutunlarý
    // forla yapmak yerine while yaptým
     	while(i<satir){//ana matrisimizin satiri
	    	j=0;//alttaki while çýktýðýnda i arttýðýnda alttaki while tekrar 0 dan baþlatýp içine girip taratmak için
	    while(j<sutun){//ana matrismizin sutunu
		toplam=0;//konumuzu deðiþtirdiðimizde ana matrisin ara matris üzerinde eþleþmeleri 0lamasý için çünkü konum deðiþikliði olduðu için ana matristen tekrar 0dan eþleþtirmelere baþladýk
	    	x=0;//alttaki whilemizi j 1 arttýðýnda konum deðiþeceði için x mizi aranan matriste satir sayimizi 0dan baþlattýk yeniden 
		
		while(x<arananSatir){//aranan matristeki satir sayisi
			y=0;//x 1 arttýðýnda y mýzý 0 lamak için çünkü aranan matriste satir sayimizi arttýðýmýzda 0dan sutunlarý arttýrmak için 
		while(y<arananSutun){//aranan matriteki satir sayisi
			if(anaMatris[i+x][j+y]==arananMatris[x][y]){//ana matriste aranan matris sayisi eþleþirse if içine girsin
					
    toplam++;//toplam 1 arttýktýk çünkü aranan matris dizisi içindeki sayilar ana matriste eþleþti
	if(toplam==carpim){//toplam deðeri eðer ana matristeki sayilar aranan matristeki tüm sayýlarla eþleþirse 
		bulundu++;//eþleþme bulduðu için 1 eþleþtirme arttýrmýþ olduk 
	    sonuclar[s][d]=i;//ana matris dizisi içinde sol üst köþedeki konumu zaten ana matrisin satiri ve sutunu aramaya baþladýðýmýz noktayý verir ilk 2 while baþladýðý yerler
	    sonuclar[s][d+1]=j;//burayada sol üst köþedeki konumun sutun deðerini attýk 
	        s++;//s 1 arttýrtýk çunku her eþletirme bittiðinde bulundu sayýsý arttýðýnda  sonuclar dizisinde yeni konuma atmak için satir için 
	    
            }
			}
			y++;//while sonuna geldiðinde tekrar baþa döndüðümüzde aranan sutun sayisi bitene kadar dönmesi için 1 arttýktýk while çýkana kadar 
			
	    	}
	     	x++;//while sonuna geldiðinde tekrar baþa döndüðümüzde aranan satir  sayisi bitene kadar dönmesi için 1 arttýktýk while çýkana kadar 
         	}
			j++;//while sonuna geldiðinde tekrar baþa döndüðümüzde ana matristei sutun sayisi bitene kadar dönmesi için 1 arttýktýk while çýkana kadar 
	    	}
	
            i++;//while sonuna geldiðinde tekrar baþa döndüðümüzde ana matristeki satir  sayisi bitene kadar dönmesi için 1 arttýktýk while çýkana kadar 
        	}
 
	cout<<"SONUCLAR"<<endl;//ekrana sonuclarý yazdýrdýk 110-119 arasý alt kýsým 
	cout<<"_______________________";
	cout<<endl;
	cout<<bulundu<<endl;
	for(int i=0;i<bulundu;i++){
	for(int j=0;j<2;j++){
		cout<<sonuclar[i][j]<<" ";
	}
cout<<endl;
}
return bulundu;//return ile int main fonksiyonunda sonucsayisi deðerine gönderdik
}
