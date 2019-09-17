#pragma once
class Lista
{
public:

	class Element {			
		friend class Lista;
	private:
		int wartosc; //wartosc elementu
		Element* nextElement; //wskaznik na nastepnika elementu	
		Element* previousElement; //wskaznik na poprzednika elementu
	public:
		int getWartosc(); //zwraca wartosc elementu
		Element(int wartosc); //konstruktor elementu
		~Element();//destruktor elementu
	};
	int size();
	int rozmiarLista; //rozmiar listy
	int indeks;	//indeks elementu
	Element* head; //wskaznik na poczatek
	Element* tail; //wskaznik na koniec
	Element* selected; //glowny wskaznik na dany element listy
	
	Element & getElement(int indeksElementu);
	void showLista(); //wyswietla aktualna liste

	void dodajPoczatek(int wartosc); //dodaje okreslony element na indeks 0
	void dodajKoniec(int wartosc); //dodaje okreslony element na indeks=rozmiarListy
	void dodajElement(int wartosc, int indeks); //dodaje okreslony element na dowolnej pozycji
	void usunPoczatek(); //usuwa element o indeksie 0
	void usunKoniec(); //usuwa element o indeksie=rozmiar listy
	void usunElement(int indeks); //usuwa element o dowolnym indeksie
	void wyszukajElement(int wartosc); //wyszukuje element o okreslonej wartosci i zwraca jego pozycje
	Lista(); //konstruktor listy
	~Lista(); //destruktor listy
};

