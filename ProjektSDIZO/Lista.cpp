#include "Lista.h"
#include <iostream>

int Lista::size() {
	return rozmiarLista;
}

int Lista::Element::getWartosc()
{
	return wartosc;
}

Lista::Lista()
{
	rozmiarLista = 0;
	head = nullptr;
	tail = nullptr;
	selected = nullptr;
}


Lista::~Lista()
{
	Element* remove = head;
	for (rozmiarLista; rozmiarLista > 0; rozmiarLista--) {
		selected = remove->nextElement;
		delete remove;
		remove = selected;
	}
	selected = nullptr;
	head= nullptr;
	tail= nullptr;
	rozmiarLista = 0;
}

Lista::Element::~Element() {
	nextElement = nullptr;
	previousElement = nullptr;
	wartosc = 0;
}

Lista::Element::Element(int wartosc) {
	this->wartosc = wartosc;
}


Lista::Element & Lista::getElement(int indeksElementu)
{
	Element* selected;
	if (rozmiarLista / 2 >= indeksElementu) {
		selected = head;
		for (int i = 0; i < indeksElementu; i++) {
			selected = selected->nextElement;
		}
	}
	else {
		selected = tail;
		for (int i = rozmiarLista; i > indeksElementu; i--) {
			selected = selected->previousElement;
		}
	}
	return *selected;
}

void Lista::showLista()
{
	selected = head;
	for (int i = 0; i < rozmiarLista; i++) {
		std::cout << selected->getWartosc() << " ";
		selected = selected->nextElement;
	}
}

void Lista::dodajPoczatek(int wartosc)
{
	if (rozmiarLista == 0) {
		head = new Element(wartosc);
		head->previousElement = nullptr;
		head->nextElement = nullptr;
		tail = head;
		selected = head;
		this->indeks = 0;
		rozmiarLista++;
	}
	Element *nowyElement = new Element(wartosc);
	nowyElement->nextElement = head;
	nowyElement->previousElement = nullptr;
	head->previousElement = nowyElement;
	head = nowyElement;
	selected = head;
	indeks = 0;
	rozmiarLista++;

}

void Lista::dodajKoniec(int wartosc)
{
	if (rozmiarLista == 0) {
		head = new Element(wartosc);
		head->previousElement = nullptr;
		head->nextElement = nullptr;
		tail = head;
		selected = head;
		this->indeks = 0;
		rozmiarLista++;
	}
	Element *nowyElement = new Element(wartosc);
	nowyElement->previousElement = tail;
	nowyElement->nextElement = nullptr;
	tail->nextElement = nowyElement;
	tail = nowyElement;
	selected = tail;
	indeks = rozmiarLista;
	rozmiarLista++;
}

void Lista::dodajElement(int wartosc, int indeks)
{
	if (rozmiarLista == 0) {
		head = new Element(wartosc);
		head->previousElement = nullptr;
		head->nextElement = nullptr;
		tail = head;
		selected = head;
		this->indeks = 0;
		rozmiarLista++;
	}

	else if (indeks == 0) dodajPoczatek(wartosc);
	else if (indeks >= rozmiarLista) dodajKoniec(wartosc);
	else {
	
		selected = &getElement(indeks);

		Element *nowyElement = new Element(wartosc);
		nowyElement->nextElement = selected;
		nowyElement->previousElement = selected->previousElement;
		selected->previousElement->nextElement = nowyElement;
		selected->previousElement = nowyElement;
		this->indeks = indeks;

		rozmiarLista++;

	}
}

void Lista::usunPoczatek()
{
	selected = head;
	selected = selected->nextElement;
	selected->previousElement = nullptr;
	delete head;
	head = selected;
	//head->indeks = 0;
	rozmiarLista--;

}

void Lista::usunKoniec()
{
	selected = tail;
	selected = selected->previousElement;
	selected->nextElement = nullptr;
	delete tail;
	tail = selected;
	//tail->indeks = rozmiarLista-2;
	rozmiarLista--;
}

void Lista::usunElement(int indeks)
{
	if (indeks >= rozmiarLista) {
		std::cout << "Nie odnaleziono elementu";
	}
	else if (rozmiarLista == 1) {
		delete tail;
		selected = nullptr;
		tail = selected;
		head = selected;
		rozmiarLista--;
	}
	else if (rozmiarLista == 0) return;
	else if (indeks == 0) usunPoczatek();
	else if (indeks == rozmiarLista - 1) usunKoniec();
	else {
		
		selected = &getElement(indeks);
		selected->nextElement->previousElement = selected->previousElement;
		selected->previousElement->nextElement = selected->nextElement;
		
		delete selected;
		selected = head;
		rozmiarLista--;
	}
}

void Lista::wyszukajElement(int wartosc)
{
	int pozycja = 0;
	int szukana = 0;
	selected = head;
	for (int i = 0; i < rozmiarLista; i++) {
		if (wartosc != (selected->getWartosc()))
			pozycja++;
		else {
			szukana++;
			std::cout << pozycja;
			break;
		}
		selected = selected->nextElement;
	}

	if (szukana == 0) std::cout << "Nie odnaleziono elementu";
}


