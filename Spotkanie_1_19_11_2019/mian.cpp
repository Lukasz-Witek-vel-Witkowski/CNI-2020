#include <iostream>
#define e_value 2.718281828458
#define pi_value 3.14159265359
double f_diamond(double f);
double f_rectagle(double a, double b);
double f_trapeze(double a, double b, double h);
double f_triangle(double a, double h);
double f_triagle2(double a);
double f_wheel(double r);
int main() {
	bool what = true;
	bool good;
	int value;
	int program = 1;
	double a, h, x;
	do {
		switch (program) {
		case 1:
			do {
				good = true;
				std::cout << "Wybierz pole jakie chcesz obliczyc: \n";
				std::cout << " 1.\t Prostakat\n 2.\t Trapez\n 3.\t Trojkat\n 4.\t Trojkat rownolegloboczny\n 5.\t Kolo\n 6.\t Romb\n";
				std::cin >> value;
				if (value >= 1 && value <= 6) good = false;
				else {
					system("cls"); // system windows
					// system("clear"); // system linux
					std::cout << "Zostala wprowadzona niepoprawna wartosc\n";
				}
			} while (good);
			program = 2;
			system("cls"); // system windows
			// system("clear"); // system linux
			break;
		case 2:
			switch (value) {
			case 1:
				std::cout << "Podaj wartosc a:\n";
				std::cin >> a;
				std::cout << "Podaj wartosc h:\n";
				std::cin >> h;
				if (a > 0 && h > 0) {
					std::cout <<"Wynik: "<< f_rectagle(a, h)<<"\n";
					program = 3;
				}
				else {
					system("cls"); // system windows
					// system("clear"); // system linux
					std::cout << "Zostala wprowadzona zla wartosc a lub h\n";
				}
				break;
			case 2:
				std::cout << "Podaj wartosc a:\n";
				std::cin >> a;
				std::cout << "Podaj wartosc b:\n";
				std::cin >> x;
				std::cout << "Podaj wartosc h:\n";
				std::cin >> h;
				if (a > 0 && x >0 && h > 0) {
					std::cout <<"Wynik: "<< f_trapeze(a, x, h) << "\n";
					program = 3;
				}
				else {
					system("cls"); // system windows
					// system("clear"); // system linux
					std::cout << "Zostala wprowadzona zla wartosc a, b lub h\n";
				}
				break;
			case 3:
				std::cout << "Podaj wartosc a:\n";
				std::cin >> a;
				std::cout << "Podaj wartosc h:\n";
				std::cin >> h;
				if (a > 0 && h > 0) {
					std::cout << "Wynik: " << f_triangle(a, h) << "\n";
					program = 3;
				}
				else {
					system("cls"); // system windows
					// system("clear"); // system linux
					std::cout << "Zostala wprowadzona zla wartosc a lub h\n";
				}
				break;
			case 4:
				std::cout << "Podaj wartosc a:\n";
				std::cin >> a;
				if (a > 0) {
					std::cout << "Wynik: " << f_triagle2(a) << "\n";
					program = 3;
				}
				else {
					system("cls"); // system windows
					// system("clear"); // system linux
					std::cout << "Zostala wprowadzona zla wartosc a\n";
				}
				break;
			case 5:
				std::cout << "Podaj wartosc r:\n";
				std::cin >> a;
				if (a > 0) {
					std::cout << "Wynik: " << f_wheel(a) << "\n";
					program = 3;
				}
				else {
					system("cls"); // system windows
					// system("clear"); // system linux
					std::cout << "Zostala wprowadzona zla wartosc r\n";
				}
				break;
			case 6:
				std::cout << "Podaj wartosc f:\n";
				std::cin >> a;
				if (a > 0) {
					std::cout << "Wynik: " << f_diamond(a) << "\n";
					program = 3;
				}
				else {
					system("cls"); // system windows
					// system("clear"); // system linux
					std::cout << "Zostala wprowadzona zla wartosc f\n";
				}
				break;
			}
			good = false;
			break;
		case 3:
			do {
				what = false;
				if (good) {
					std::cout << "Zostala wprowadzona niepoprawna wartosc\n";
				}
				std::cout << "Czy chcesz kontynulowac?\n";
				std::cout << " 1.\t Tak \n";
				std::cout << " 2.\t Nie \n";
				std::cin >> value;
				system("cls"); // system windows
				// system("clear"); // system linux
				if (value == 1) {
					what = true;
					program = 1;
				}
				else if (value != 2) good = true;
			} while (!(value == 1 || value == 2));
			break;
		}

		} while (what);
	return 0;
}
double f_diamond(double f) {
	return (e_value * f) / 2;
}
double f_rectagle(double a, double b) {
	return a * b;
}
double f_trapeze(double a, double b, double h) {
	return ((a + b)*h) / 2;
}
double f_triangle(double a, double h) {
	return a * h / 2;
}
double f_triagle2(double a) {
	return (a*a*sqrt(3)) / 4;
}
double f_wheel(double r) {
	return pi_value * r*r;
}
