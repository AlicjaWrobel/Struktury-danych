#pragma once
#include "Tablica.h"
#include <String>

class Kopiec
{
public:
	Kopiec(); //konstruktor kopca
	~Kopiec(); //destruktor kopca

	int rozmiarKopiec; //rozmiar kopca
	int size(); //zwraca rozmiar kopca
	Tablica kopiec = Tablica(); //utworzenie tablicy bedacej podstawa kopca
	void showKopiec(std::string sp, std::string sn, int v); //wyswietlenie kopca
	void dodajElement(int wartosc); //dodanie elementu do kopca
	void uporz¹dkujKopiecGora(int indeks); //przadkownie kopca po dodaniu elementu
	void uporz¹dkujKopiecDol(int indeks); //porzadkowanie kopca po usunieciu elementu
	void usunElement(int indeks); //usuniecie elemenetu o zadanym indeksie
	void wyszukajElement(int wartosc); //wyszukanie elementu o zdanym indeksie
};

