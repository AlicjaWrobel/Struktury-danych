#include "Kopiec.h"
#include <iostream>
using namespace std;

int Kopiec::size() {
	return rozmiarKopiec;
}

Kopiec::Kopiec()
{
	rozmiarKopiec = 0;
}


Kopiec::~Kopiec()
{
	rozmiarKopiec = 0;
}

void Kopiec::showKopiec(string sp, string sn, int v)
{
	string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218;	cr[1] = 196;
	cl[0] = 192;	cl[1] = 196;
	cp[0] = 179;
	string s;
	if (v < rozmiarKopiec) {
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		showKopiec(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << kopiec[v] << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		showKopiec(s + cp, cl, 2 * v + 1 );
	}

}

void Kopiec::dodajElement(int wartosc)
{
	kopiec.dodajElement(wartosc, rozmiarKopiec);
	uporz퉐kujKopiecGora(rozmiarKopiec);
	rozmiarKopiec++;

}

void Kopiec::uporz퉐kujKopiecGora(int indeks)
{

	int i = indeks;											//przyjmujemy za i podana przez uzytkownika wartosc
	int j = (i-1) / 2;										//za j przyjmujemy indeks rodzica
	while (( i > 0) && (kopiec[j] < kopiec[i])) {			//dopoki nie dojedziemy do poczatku kopca lub dopoki rodzic nie bedzie wiekszy
		if (kopiec[i] > kopiec[j]) {						//zamieniamy miejscami rodzica z synem
			int buffer = *(kopiec.wskaznikPoczatku + i);
			*(kopiec.wskaznikPoczatku + i) = *(kopiec.wskaznikPoczatku + j);
			*(kopiec.wskaznikPoczatku + j) = buffer;
			i = j;											//przechodzimy poziom wyzej
			j = (i-1) / 2;
		}
		else
			break;
	}
}

void Kopiec::uporz퉐kujKopiecDol(int indeks) {
	int i = indeks;														//przyjmujemy za i podana przez uzytkownika wartosc
	int j = i * 2 + 1;													//za j przyjmujemy 2i
	while (j < rozmiarKopiec) {											//dopoki j jest mniejsze od wielkosci kopca
		if (kopiec[i] < kopiec[j] || kopiec[i] < kopiec[j + 1]) {		//czy element jest mniejszy od lewego lub prawego syna; jesli nie algorytm sie konczy
			if (kopiec[j] >= kopiec[j + 1] && kopiec[i] < kopiec[j]) {	//jesli lewy syn jest wiekszy od prawego, lub nie ma prawego
				int buffer = *(kopiec.wskaznikPoczatku + i);
				*(kopiec.wskaznikPoczatku + i) = *(kopiec.wskaznikPoczatku + j);
				*(kopiec.wskaznikPoczatku + j) = buffer;				//zamieniamy go z naszym mniejszym elementem; w ten sposob mamy pewnosc ze wiekszy obiekt sie stanie ojcem
				i = j;													//przechodzimy poziom kopca nizej
				j = i * 2+1;
			}
			else if (kopiec[j] < kopiec[j + 1] && kopiec[i] < kopiec[j + 1]) {	//jesli to prawy syn jest wiekszy
				int buffer = *(kopiec.wskaznikPoczatku + i);
				*(kopiec.wskaznikPoczatku + i) = *(kopiec.wskaznikPoczatku + j + 1);
				*(kopiec.wskaznikPoczatku + j + 1) = buffer;					//to zamienieamy go z naszym elementem
				i = j + 1;														//przechodzimy poziom nizej
				j = i * 2 + 1;
			}
		}
		else
			break;
	}
}

void Kopiec::usunElement(int indeks)
{
	if (indeks >= rozmiarKopiec) {
		std::cout << "Nie odnaleziono elementu";
	}

	else {
		kopiec.setElement(indeks, kopiec[rozmiarKopiec-1]);
		kopiec.usunElement(rozmiarKopiec-1);
		rozmiarKopiec--;

	}
	uporz퉐kujKopiecDol(indeks);
}

void Kopiec::wyszukajElement(int wartosc)
{
	int pozycja = 0;
	int szukana = 0;

	for (int i = 0; i <= rozmiarKopiec; i++){
		if (wartosc != (kopiec[i]))
			pozycja++;
		else {
			szukana++;
			std::cout << pozycja;
			break;
		}
	}

	if (szukana == 0) std::cout << "Nie odnaleziono elementu";
}
