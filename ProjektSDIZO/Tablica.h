#pragma once
class Tablica {
public:
	int *wskaznikPoczatku; //wskaznik na poczatek
	int rozmiarTablica; //rozmiar tablicy

	void setElement(int indeksElementu, int wartosc); //wstawienie w okreslone miejsce element o okreslonej wartosci
	int& getElement(int indeksElementu); //referencja do elementu get element
	void showTablica(); //wyswietla wartosc tablicy
	int size(); //zwraca rozmiar tablicy

	void dodajPoczatek(int wartosc); //dodaje okreslony element na indeks 0
	void dodajKoniec(int wartosc); //dodaje okreslony element na indeks=rozmiarListy
	void dodajElement(int wartosc, int indeks); //dodaje okreslony element na dowolnej pozycji
	void usunPoczatek(); //usuwa element o indeksie 0
	void usunKoniec(); //usuwa element o indeksie=rozmiar listy
	void usunElement(int indeks); //usuwa element o dowolnym indeksie
	void wyszukajElement(int wartosc); //wyszukuje element o okreslonej wartosci i zwraca jego pozycje
	int &operator[](int element); //przeciazenie opertaora []

	Tablica(); //konstruktor
	~Tablica(); //destruktor, dla zwolnienia pamieci
};