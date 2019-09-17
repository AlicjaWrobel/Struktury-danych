#include <iostream>
#include <conio.h>
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include <string>
#include <fstream>
#include "Time.h"


using namespace std;

int tablica() {
	int wartosc;
	int indeks;
	int wybor;

	static Tablica* tablica;

	cout << "\n\n Operacje na tablicy:\n"
		<< "\n 1 - Zbuduj z pliku"
		<< "\n 2 - Dodaj"
		<< "\n 3 - Usun"
		<< "\n 4 - Znajdz"
		<< "\n 5 - Wyswietl"
		<< "\n 0 - Powrot \n";

	cin >> wybor;
	switch (wybor) {
	case 0:
		return 0;
	case 1: {
		ifstream plik;
		string nazwa;
		cout << "\n Podaj nazwe pliku z ktorego chcesz wczytac dane: ";
		cin >> nazwa;
		plik.open(nazwa, std::ios::in);
		if (plik.good()) {

			plik.seekg(0);
			plik >> indeks;

			if (tablica == nullptr) tablica = new Tablica();
			else {
				delete tablica;
				tablica = new Tablica();
			}

			for (int i = 0; i < indeks; ++i) {
				plik >> wartosc;
				tablica->dodajKoniec(wartosc);
			}
		}
		plik.close();
		cout << "\nZawartosc tablicy: \n";
		tablica->showTablica();

	}
		break;
	case 2:
		if (tablica == nullptr) tablica = new Tablica();
		cout << "\n Podaj wartosc elementu:\n";
		cin >> wartosc;
		cout << "\n Podaj indeks elementu:\n";
		cin >> indeks;
		tablica->dodajElement(wartosc, indeks);
		cout << "\n Aktualna tablica: \n";
		tablica->showTablica();
		break;
	case 3:
		if (tablica == nullptr) tablica = new Tablica();
		if (tablica->rozmiarTablica == 0) {
			std::cout << "Tablica jest pusta. \n";
		}
		else {
			cout << "\n Podaj indeks elementu z podanej tablicy:\n";
			tablica->showTablica();
			cout << "\n";
			cin >> indeks;
			tablica->usunElement(indeks);
			cout << "\n Aktualna Tablica: \n";
			tablica->showTablica();
		}
		break;
	case 4:
		if (tablica == nullptr) tablica = new Tablica();
		cout << "\n Podaj szukana wartosc: \n";
		cin >> wartosc;
		cout << "\n Szukany element znajduje sie na pozycji: ";
		tablica->wyszukajElement(wartosc);
		break;
	case 5:
		cout << "\n Aktualna Tablica: \n";
		tablica->showTablica();
		break;
	default:
		cout << "\n Wybierz opcje od 0 do 5";
		return 1;
	}
}
int lista() {
	int wartosc;
	int indeks;
	int wybor;

	static Lista* lista;

	cout << "\n\n Operacje na liscie:\n"
		<< "\n 1 - Zbuduj z pliku"
		<< "\n 2 - Dodaj"
		<< "\n 3 - Usun"
		<< "\n 4 - Znajdz"
		<< "\n 5 - Wyswietl"
		<< "\n 0 - Powrot \n";

	cin >> wybor;
	switch (wybor) {
	case 0:
		return 0;
	case 1: {
		ifstream plik;
		string nazwa;
		cout << "\n Podaj nazwe pliku z ktorego chcesz wczytac dane: ";
		cin >> nazwa;
		plik.open(nazwa, std::ios::in);
		if (plik.good()) {

			plik.seekg(0);
			plik >> indeks;

			if (lista == nullptr) lista = new Lista();
			else {
				delete lista;
				lista = new Lista();
			}

			for (int i = 0; i < indeks; ++i) {
				plik >> wartosc;
				lista->dodajElement(wartosc,i);
			}
		}
		plik.close();
		cout << "\nZawartosc tablicy: \n";
		lista->showLista();

	}
	break;
		break;
	case 2:
		if (lista == nullptr) lista = new Lista();
		cout << "\n Podaj wartosc elementu:\n";
		cin >> wartosc;
		cout << "\n Podaj indeks elementu:\n";
		cin >> indeks;
		lista->dodajElement(wartosc, indeks);
		cout << "\n Aktualna lista: \n";
		lista->showLista();
		break;
	case 3:
		if (lista == nullptr) lista = new Lista();
		if (lista->rozmiarLista == 0) {
			std::cout << "Lista jest pusta. \n";
		}
		else {
			cout << "\n Podaj indeks elementu z podanej listy:\n";
			lista->showLista();
			cout << "\n";
			cin >> indeks;
			lista->usunElement(indeks);
			cout << "\n Aktualna Lista: \n";
			lista->showLista();
		}
		break;
	case 4:
		if (lista == nullptr) lista = new Lista();
		cout << "\n Podaj szukana wartosc: \n";
		cin >> wartosc;
		cout << "\n Szukany element znajduje sie na pozycji: ";
		lista->wyszukajElement(wartosc);
		break;
	case 5:
		cout << "\n Aktualna Lista: \n";
		lista->showLista();
		break;
	default:
		cout << "\n Wybierz opcje od 0 do 5";
		return 1;
	}
}


int kopiec() {
	int wartosc;
	int indeks;
	static Kopiec* kopiec;

	cout << "\n\n Operacje na kopcu:\n"
		<< "\n 1 - Zbuduj z pliku"
		<< "\n 2 - Dodaj"
		<< "\n 3 - Usun"
		<< "\n 4 - Znajdz"
		<< "\n 5 - Wyswietl"
		<< "\n 0 - Powrot \n";

	int wybor;
	cin >> wybor;
	switch (wybor) {
	case 0:
		return 0;
	case 1: {
		ifstream plik;
		string nazwa;
		cout << "\n Podaj nazwe pliku z ktorego chcesz wczytac dane: ";
		cin >> nazwa;
		plik.open(nazwa, std::ios::in);
		if (plik.good()) {

			plik.seekg(0);
			plik >> indeks;

			if (kopiec == nullptr) kopiec = new Kopiec();
			else {
				delete kopiec;
				kopiec = new Kopiec();
			}

			for (int i = 0; i < indeks; ++i) {
				plik >> wartosc;
				kopiec->dodajElement(wartosc);
			}
		}
		plik.close();
		cout << "\nZawartosc tablicy: \n";
		kopiec->showKopiec("", "", 0);

	}
			break;
	case 2:
		if (kopiec == nullptr) kopiec = new Kopiec();
		cout << "\nPodaj wartosc ktora chcesz dodac: ";
		cin >> wartosc;
		kopiec->dodajElement(wartosc);
		cout << "\nZawartosc kopca: \n";
		kopiec->showKopiec("", "", 0);
		break;
	case 3:
		if (kopiec == nullptr) kopiec = new Kopiec();
		if (kopiec->rozmiarKopiec == 0) {
			std::cout << "Kopiec jest pusty. \n";
		}
		else {
			cout << "\n Podaj indeks elementu z podanego kopca:\n";
			kopiec->showKopiec("", "", 0);
			cout << "\n";
			cin >> indeks;
			kopiec->usunElement(indeks);
			cout << "\n Aktualna kopiec: \n";
			kopiec->showKopiec("", "", 0);
		}
		break;
	case 4:
		if (kopiec == nullptr) kopiec = new Kopiec();
		cout << "\n Podaj szukana wartosc: \n";
		cin >> wartosc;
		cout << "\n Szukany element znajduje sie na pozycji: ";
		kopiec->wyszukajElement(wartosc);
		break;
	case 5:
		if (kopiec == nullptr) kopiec = new Kopiec();
		cout << "\nZawartosc kopca: \n";
		kopiec->showKopiec("", "", 0);
		_getch();
		break;
	default:
		cout << "\n Wybierz opcje od 0 do 5";
		_getch();
		return 1;
	}
}

int pomiary() {
	int mnoznik;
	int skok;
	int ilosc;
	vector<double> pomiarytablicy;
	static Time time;

	cout << "Podaj ile elementow ma wynosic skok pomiarowy: ";
	cin >> skok;
	cout << "Podaj ile punktow pomiarowych chcesz uzyskac: ";
	cin >> mnoznik;
	cout << "Podaj z ilu pomiarow chcesz uzyskac srednia: ";
	cin >> ilosc;
	system("cls");
	cout << "Wartosci generowane losowo maja wartosc od -1000 do 1000\n";
	int x, y, i;
	//TABLICA
	{
		Tablica* tablica = new Tablica();
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete tablica;
				tablica = new Tablica();
				for (i = 0; i < skok * y; i++) {
					tablica->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = (rand() % 2001) - 1000;
				time.StartCounter();
				tablica->dodajPoczatek(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla dodania losowej wartosci\n"
				<< " na poczatek tablicy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete tablica;
				tablica = new Tablica();
				for (i = 0; i < skok * y; i++) {
					tablica->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = (rand() % 2001) - 1000;
				time.StartCounter();
				tablica->dodajKoniec(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla dodania losowej wartosci\n"
				<< " na koniec tablicy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete tablica;
				tablica = new Tablica();
				for (i = 0; i < skok * y; i++) {
					tablica->dodajKoniec((rand() % 2001) - 1000);
				}
				time.StartCounter();
				tablica->usunElement(0);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla usuniecia wartosci\n"
				<< " z poczatku tablicy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete tablica;
				tablica = new Tablica();
				for (i = 0; i < skok * y; i++) {
					tablica->dodajKoniec((rand() % 2001) - 1000);
				}
				time.StartCounter();
				tablica->usunElement(tablica->size() - 1);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla usuniecia wartosci\n"
				<< " z konca tablicy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete tablica;
				tablica = new Tablica();
				for (i = 0; i < skok * y; i++) {
					tablica->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = rand() % (tablica->size() - 1);
				time.StartCounter();
				tablica->dodajElement(generate, generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla dodania losowej wartosci\n"
				<< " na losowym miejscu tablicy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete tablica;
				tablica = new Tablica();
				for (i = 0; i < skok * y; i++) {
					tablica->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = rand() % (tablica->size() - 1);
				time.StartCounter();
				tablica->usunElement(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla usuniecia wartosci\n"
				<< " z losowego miejsca tablicy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete tablica;
				tablica = new Tablica();
				for (i = 0; i < skok * y; i++) {
					tablica->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = (rand() % 2001) - 1000;
				time.StartCounter();
				tablica->wyszukajElement(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla wyszukania losowej wartosci\n"
				<< " w tablicy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		delete tablica;
	}
	
	//LISTA
	{
		Lista* lista = new Lista();
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete lista;
				lista = new Lista();
				for (i = 0; i < skok * y; i++) {
					lista->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = (rand() % 2001) - 1000;
				time.StartCounter();
				lista->dodajPoczatek(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla dodania losowej wartosci\n"
				<< " na poczatek listy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete lista;
				lista = new Lista();
				for (i = 0; i < skok * y; i++) {
					lista->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = (rand() % 2001) - 1000;
				time.StartCounter();
				lista->dodajKoniec(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla dodania losowej wartosci\n"
				<< " na koniec listy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete lista;
				lista = new Lista();
				for (i = 0; i < skok * y; i++) {
					lista->dodajKoniec((rand() % 2001) - 1000);
				}
				time.StartCounter();
				lista->usunElement(0);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla usuniecia pierwszego elementu\n"
				<< " z listy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete lista;
				lista = new Lista();
				for (i = 0; i < skok * y; i++) {
					lista->dodajKoniec((rand() % 2001) - 1000);
				}
				//int generate = (rand() % lista->size()) - 1;
				time.StartCounter();
				lista->usunElement(lista->size() - 1);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla usuniecia ostatniego elementu\n"
				<< " z listy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete lista;
				lista = new Lista();
				for (i = 0; i < skok * y; i++) {
					lista->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = (rand() % (lista->size() - 1));
				time.StartCounter();
				lista->dodajElement(generate, generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla dodania losowego elementu\n"
				<< " na losowa pozycje listy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete lista;
				lista = new Lista();
				for (i = 0; i < skok * y; i++) {
					lista->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = (rand() % (lista->size() - 1));
				time.StartCounter();
				lista->usunElement(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla usuniecia losowego elementu\n"
				<< " z listy " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete lista;
				lista = new Lista();
				for (i = 0; i < skok * y; i++) {
					lista->dodajKoniec((rand() % 2001) - 1000);
				}
				int generate = ((rand() % 2001) - 1000);
				time.StartCounter();
				lista->wyszukajElement(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla wyszukania losowego elementu\n"
				<< " na liscie " << i << " elementowej wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		delete lista;
	}
	//KOPIEC
	{
		Kopiec* kopiec = new Kopiec();
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete kopiec;
				kopiec = new Kopiec();
				for (i = 0; i < skok * y; i++) {
					kopiec->dodajElement((rand() % 2001) - 1000);
				}
				int generate = (rand() % 2001) - 1000;
				time.StartCounter();
				kopiec->dodajElement(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla dodania losowej wartosci\n"
				<< " do kopca " << i << " elementowego wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete kopiec;
				kopiec = new Kopiec();
				for (i = 0; i < skok * y; i++) {
					kopiec->dodajElement((rand() % 2001) - 1000);
				}
				time.StartCounter();
				kopiec->usunElement(0);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla usuniecia korzenia\n"
				<< " z kopca " << i << " elementowego wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete kopiec;
				kopiec = new Kopiec();
				for (i = 0; i < skok * y; i++) {
					kopiec->dodajElement((rand() % 2001) - 1000);
				}
				int generate = (rand() % kopiec->size() + 1);
				time.StartCounter();
				kopiec->usunElement(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla usuniecia losowego elementu\n"
				<< " z kopca " << i << " elementowego wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		for (y = 1; y <= mnoznik; y++) {
			for (x = 0; x < ilosc; x++) {
				delete kopiec;
				kopiec = new Kopiec();
				for (i = 0; i < skok * y; i++) {
					kopiec->dodajElement((rand() % 2001) - 1000);
				}
				int generate = ((rand() % 2001) - 1000);
				time.StartCounter();
				kopiec->wyszukajElement(generate);
				time.GetCounter();
			}
			cout << "\nSrednia z " << ilosc << " pomiarow dla wyszukania losowego elementu\n"
				<< " w kopca " << i << " elementowym wyniosla " << time.printAverage() << " us";
			time.reset();
		}
		delete kopiec;
	}
	return 0;
}

int menu() {
	cout << "Wybierz strukture:\n"
		<< "\n 1 - tablica"
		<< "\n 2 - lista dwukierunkowa"
		<< "\n 3 - kopiec binarny"
		<< "\n 4 - wykonaj pomiary"
		<< "\n 0 - wyjscie \n";
	int wybor;
	cin >> wybor;
	switch (wybor) {
	case 0:
		return 0;
	case 1:
		while (tablica());
		break;
	case 2:
		while (lista());
		break;
	case 3:
		while (kopiec());
		break;
	case 4:
		while (pomiary());
		break;
	default:
		cout << "\n Podaj wartosc od 0 do 4";
		_getch();
		return 1;
	}
	return 1;
}

int main() {
	while(menu());
	return 0;
}
