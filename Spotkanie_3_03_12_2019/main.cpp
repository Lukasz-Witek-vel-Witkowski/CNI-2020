#include <iostream>
#include <fstream>
#define _size 10
void sort(int* tab, int size, bool(*f)(int& l, int& r));
bool wyszukaj(int* tab, int size, int find);
bool wieksze(int& l, int&r);
bool mniejsze(int& l, int& r);
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
	/*tab[0] = 1;
	tab[1] = 7;
	tab[2] = 123;
	tab[3] = 54;
	tab[4] = 16;
	tab[5] = 17;
	tab[6] = 90;
	tab[7] = 100;
	tab[8] = 54;
	tab[9] = 5;*/
	sort(tab, _size,mniejsze);
	if (wyszukaj(tab, _size, find)) {
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
void sort(int* tab, int size, bool(*f)(int& l, int& r)) {
	int i; 
	int temp;
	bool b;
	do {
		b = false;
		for (i = 0; i < size - 1; i++) {
			if (f(tab[i],tab[i+1])) {
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i+1] = temp;
				b = true;
			}
		}
		size--;
	} while (b);
}
bool wieksze(int& l, int&r) {
	return l < r;
}
bool mniejsze(int& l, int& r) {
	return l > r;
}
bool wyszukaj(int* tab, int size, int find) {
	int left = 0;
	int right = size;
	int n;
	if (find < tab[0] || tab[size - 1] < find) 
		return false;
	while (left<right)
	{
		n = (left + right) / 2;
		if (tab[n] < find) left = n+1;
		else if (tab[n] > find) right = n;
		else if(tab[n] == find)
			return true;
	}
	return false;
}