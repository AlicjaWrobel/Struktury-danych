#include "Tablica.h"
#include <iostream>

int Tablica::size() {
	return rozmiarTablica;
}

void Tablica::setElement(int indeksElementu, int wartosc)
{
	*(wskaznikPoczatku + indeksElementu) = wartosc; //przypisujemy danemu miejscu w pamieci wartosc
}

int &Tablica::getElement(int indeksElementu)
{
	return *(wskaznikPoczatku + indeksElementu);
}

void Tablica::showTablica()
{
	if (rozmiarTablica == 0) std::cout << "Tablica jest pusta";
	else {
		for (int i = 0; i < rozmiarTablica; i++) {
			std::cout << "[" << *(wskaznikPoczatku + i) << "]";
		}
	}
}

void Tablica::dodajPoczatek(int wartosc)
{
	//if (rozmiarTablica == 0) {
	//	wskaznikPoczatku = (int*)malloc(1 * sizeof(int)); //rezerwacja miejsca w pamieci
	//	setElement(0, wartosc);
	//	rozmiarTablica++;
	//}
	//else {
		int *wskaznik = (int*)malloc((rozmiarTablica + 1) * sizeof(int)); //+1 aby zarezerowac miejsce dla nowego
		memcpy(wskaznik + 1, wskaznikPoczatku, rozmiarTablica * sizeof(int)); //to co bylo kopiujemy do pozycji od +1
		free(wskaznikPoczatku);
		wskaznikPoczatku = wskaznik;
		setElement(0, wartosc);
		rozmiarTablica++;
	//}
}

void Tablica::dodajKoniec(int wartosc)
{
	//if (rozmiarTablica == 0) {
	//	wskaznikPoczatku = (int*)malloc(1 * sizeof(int)); //rezerwacja miejsca w pamieci
	//	setElement(0, wartosc);
	//	rozmiarTablica++;
	//}
	//else {
		int *wskaznik = (int*)malloc((rozmiarTablica + 1) * sizeof(int)); //+1 aby zarezerowac miejsce dla nowego
		memcpy(wskaznik, wskaznikPoczatku, rozmiarTablica * sizeof(int)); //to co bylo kopiujemy do pozycji od 0
		free(wskaznikPoczatku);
		wskaznikPoczatku = wskaznik;
		setElement(rozmiarTablica, wartosc); //dodanie na ostatniej pozycji
		rozmiarTablica++;
	//}
}

void Tablica::dodajElement(int wartosc, int indeks)
{
	if (rozmiarTablica == 0) {
		wskaznikPoczatku = (int*)malloc(1 * sizeof(int)); //rezerwacja miejsca w pamieci
		setElement(0, wartosc);
		rozmiarTablica++;
	}

	else if (indeks == 0) dodajPoczatek(wartosc);
	else if (indeks >= rozmiarTablica) dodajKoniec(wartosc);
	
	else
	{
		int *wskaznik = (int*)malloc((rozmiarTablica + 1) * sizeof(int));
		memcpy(wskaznik, wskaznikPoczatku, indeks * sizeof(int));
		memcpy(wskaznik + indeks + 1, wskaznikPoczatku + indeks, (rozmiarTablica-indeks) * sizeof(int));
		free(wskaznikPoczatku);
		wskaznikPoczatku = wskaznik;
		setElement(indeks,wartosc);
		rozmiarTablica++;
	}

}

void Tablica::usunPoczatek()
{
	int *wskaznik = (int*)malloc((rozmiarTablica - 1) * sizeof(int));
	memcpy(wskaznik, wskaznikPoczatku+1, (rozmiarTablica - 1) * sizeof(int));
	free(wskaznikPoczatku);
	wskaznikPoczatku = wskaznik;
	rozmiarTablica--;
}

void Tablica::usunKoniec()
{
	int *wskaznik = (int*)malloc((rozmiarTablica - 1) * sizeof(int));
	memcpy(wskaznik, wskaznikPoczatku, (rozmiarTablica-1) * sizeof(int));
	free(wskaznikPoczatku);
	wskaznikPoczatku = wskaznik;
	rozmiarTablica--;
}

void Tablica::usunElement(int indeks)
{
	if (indeks == 0) usunPoczatek();
	else if (indeks >= rozmiarTablica) usunKoniec();

	else
	{
		int *wskaznik = (int*)malloc((rozmiarTablica - 1) * sizeof(int));
		memcpy(wskaznik, wskaznikPoczatku, indeks * sizeof(int));
		memcpy(wskaznik + indeks, wskaznikPoczatku + indeks + 1, (rozmiarTablica - indeks) * sizeof(int));
		free(wskaznikPoczatku);
		wskaznikPoczatku = wskaznik;
		rozmiarTablica--;
	}
}

void Tablica::wyszukajElement(int wartosc)
{
	int pozycja = 0;
	int szukana = 0;

	for (int i = 0; i <= rozmiarTablica; i++) {
		if (wartosc != *(wskaznikPoczatku + i))
			pozycja++;
		else {
			szukana++;
			std::cout << pozycja;
			break;
		}
	}
	if (szukana == 0) std::cout << " Nie odnaleziono elementu ";
}

int &Tablica::operator[](int element) {
	return getElement(element);
}



Tablica::Tablica()
{
	rozmiarTablica = 0;
}

Tablica::~Tablica()
{
	free(wskaznikPoczatku);
}
