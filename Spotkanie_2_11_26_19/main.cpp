#include <iostream>
#include <fstream>
void dodawanie(int** tab, int size); //funkacja sumowania macierzy
void odejmowanie(int** tab, int size); //funkcja odejmowania macierzy
void zapis(std::ofstream& file, char** nazwy, int** tab, int size, bool& b, int size_base, int value); //funkcja zapisu danych wynikowych do pliku
int main() {

	//deklaracja zmiennych
	int** sek = nullptr;
	char znak; // 1 - dodawanie / 2 - odejmowanie
	char** nazwy = nullptr;
	char* name = nullptr;
	bool one = true;
	int size;
	int i;
	name = new char[100];
	std::ifstream file;
	std::ofstream file_output;


	//pobranie informacji od u¿ytkownika o nazwie pliku z danymi
	do {
		std::cout << "Podaj nazwe pliku do przetworzenia: \n";
		std::cin >> name;
		file.open(name);
		if (file.good()) {
			file >> size;
			nazwy = new char*[size];
			for (i = 0; i < size; i++)
				nazwy[i] = new char[20];
			for (i = 0; i < size; i++)
				file >> nazwy[i];
			file.close();
			one = false;
		}
		else {


			// w prypadku gdy bledna nazwa
			system("cls");
			std::cout << "Podany plik: " << name << " nie istnieje!\n";
		}
	} while (one);
	one = true;
	int size_sek;
	int size_matrix;


	//otwieranie plikow z macierzamia
	for (int j = 0; j < size - 1; j++) {
		file.open(nazwy[j]);
		if (file.good()) {


			//pobranie danych o ilosci segmentow w pliku
			file >> size_sek;


			//pobranie danych o ilosci wierszy (liczba kolum stala = 10)
			file >> size_matrix;


			//tworzenie tablicy na macierze
			sek = new int*[2];
			for (i = 0; i < 2; i++) {
				sek[i] = new int[10 * size_matrix];
			}


			//wczytywanie pierwszej macierzy
			for (int k = 0; k < 10 * size_matrix; k++) {
				file >> sek[0][k];
			}
			for (i = 1; i < size_sek; i++) {


				//wczytanie znaku odpowiedzialnego za typ operacji
				file >> znak;


				//wczytanie kolejnej macierzy
				for (int k = 0; k < 10 * size_matrix; k++) {
					file >> sek[1][k];
				}


				// dodawania macierzy
				if (znak == '1') dodawanie(sek, 10 * size_matrix);
				
				
				//odejmowanie macierzy
				else odejmowanie(sek, 10 * size_matrix);
			}
			
			
			//zapis do pliku
			zapis(file_output, nazwy, sek, 10 * size_matrix, one, size,j);
			
			
			//usuwanie macierzy
			for (i = 0; i < 2; i++) {
				delete[] sek[i];
			}
			delete sek;
			
			
			//zamkniecie pliku z nacierzami
			file.close();
		}
	}
	
	
	//otworzenie pliku w notatniku
	system(nazwy[size - 1]);
	
	
	//usuniecie tablicy z nazwami plikow
	delete[] nazwy;
	delete[] name;
	return 0;
}
void dodawanie(int** tab, int size) {
	for (int i = 0; i < size; i++) {
		tab[0][i] = tab[0][i] + tab[1][i];
	}
}
void odejmowanie(int** tab, int size) {
	for (int i = 0; i < size; i++) {
		tab[0][i] = tab[0][i] - tab[1][i];
	}
}
void zapis(std::ofstream& file, char** nazwy, int** tab, int size, bool& b, int size_base, int value) {
	if (b) {
	
		
		// gdy pierwsza operacja utworz plik operacja potrzebna bo po kolejnym wywolaniu dopisze do juz istniejacego
		b = false;
		file.open(nazwy[size_base - 1]);
	}
	else 
		
		
		// dopisz do pliku dane
		file.open(nazwy[size_base - 1], std::ios::app);
	if (file.good()) {
		
		
		//zapisz nazwe do pliku z zabezpieczeniem przed przedostaniem sie poza macierz
		if(value<size_base)
		file << nazwy[value] << "\n";
		
		
		//wypisanie macierzy wynikowej do pliku
		for (int i = 0; i < size; i++) {
			file << tab[0][i];
			if ((i+1) % 10 == 0 && i>0) {
				file << "\n";
			}
			else
				file << " ";
		}
		
		
		//oddzielenie macierzy pusta linia
		file << "\n";
		file.close();
	}
}

