#ifndef POLINOM_H
#define POLINOM_H

class polinom
{
	private:
		int A,
			B,
			C;
			
	public:
		polinom();
		void KatsayilaraDegerAta(int,int,int);
		int DegerHesapla(int);
		void KokleriHesapla();
	
	
};

#endif
