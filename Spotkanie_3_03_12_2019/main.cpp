#include <iostream>
#include <fstream>
#include "Function.h"
#define _size 10

int main() {
	int size;
	int* tab = nullptr;
	int find;
	std::ifstream file;
	file.open("plik.txt");
	if (file.good()) {
		file >> size;
		if (size > 0);
		tab = new int[size];
		for (int i = 0; i < size; i++) {
			file >> tab[i];
		}
		file.close();
	}
	else {
		std::cout<<"Plik nie istnieje\n";
		system("pause");
		return 0;
	}
	std::cout << "Podaj wartosc szukana: \n";
	std::cin >> find;
	system("cls");
	sort<int>(tab, _size,mniejsze);
	if (wyszukaj<int>(tab, _size, find)) {
		std::cout << "Udalo sie znalesc " << find << "\n";
	}
	else {
		std::cout << "Nie udalo sie znalesc " << find << "\n";
	}
	std::cout << "Zawartosc pliku po sortowaniu:\n";
	for (int i = 0; i < _size; i++) {
		std::cout << tab[i] << "\n";
	}
	delete[] tab;
	system("pause");
	return 0;
}



