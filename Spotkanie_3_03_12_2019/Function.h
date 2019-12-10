#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
template<class T>
void sort(T* tab, int size, bool(*f)(T& l, T& r)) {
	int i;
	T temp;
	bool b;
	do {
		b = false;
		for (i = 0; i < size - 1; i++) {
			if (f(tab[i], tab[i + 1])) {
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				b = true;
			}
		}
		size--;
	} while (b);
}
template<class T>
bool wyszukaj(T* tab, int size, T find) {
	int left = 0;
	int right = size;
	int n;
	if (find < tab[0] || tab[size - 1] < find)
		return false;
	while (left < right)
	{
		n = (left + right) / 2;
		if (tab[n] < find) left = n + 1;
		else if (tab[n] > find) right = n;
		else if (tab[n] == find)
			return true;
	}
	return false;
}
template<class T>
bool wieksze(T& l, T&r) {
	return l < r;
}
template<class D>
bool mniejsze(D& l, D& r) {
	return l > r;
}
#endif // !FUNCTION_H
















