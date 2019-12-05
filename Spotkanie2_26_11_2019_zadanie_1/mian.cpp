#include <iostream>
#include <fstream>
#define Size 256
bool sprawdzenie(char* temp);
bool kontkatenacja(char* nameFile, char* path);
void przypisanie(char* path, char* fileName);
int main() {
	char *nameFile = new char[Size];
	char stop;
	char *path = new char[Size];
	std::cout << "Prosze podac nazwe pliku\n";
	std::cin >> nameFile;
	std::cout << "Prosze podac sciezke do pliku:\nJezeli plik zajduje sie w aktualnym folderze prosze wprowadzic '*'\n";
	std::cin >> path;
	std::cout << "Prosze podac znak po ktorym zostanie zakonczony proces wpisywania do pliku:\n";
	std::cin >> stop;
	std::ofstream file;
	if (*path != '*') {
		if (sprawdzenie(path)) {
			if (!kontkatenacja(path, nameFile)) {
				return 0;
			}
		}
		else {
			char* temp = new char[Size];
			temp[0] = '\\';
			temp[1] = '\0';
			if (!kontkatenacja(path, temp)) {
				return 0;
			}
			if (!kontkatenacja(path, nameFile)) {
				return 0;
			}
			delete[] temp;
		}
	}
	else {
		przypisanie(path, nameFile);
	}
	char *line = new char[Size];
	file.open(path);
	if (file.good()) {
		std::cin.getline(line, Size);
		do {
			system("cls");
			std::cout << "Pisanie do pliku: \nAby przerwaæ uzyj znaku: " << stop << "\n";
			std::cin.getline(line, Size);
			if (line[0] == stop) {
				break;
			}
			file << line << "\n";
		} while (true);
		file.close();
	}
	std::ifstream odczyt(path);
	int i = 1;
	if (odczyt.good()) {
		while (!odczyt.eof()) {
			odczyt.getline(line, Size);
			std::cout << i++ << "\t" << line << "\n";
		}
		odczyt.close();
	}
	system("pause");
	delete[] line;
	delete[] path;
	delete[] nameFile;
	return 0;
}
bool sprawdzenie(char* temp) {
	for (int i = 0; i < Size; i++) {
		if (temp[i] == '\0') {
			if (temp[i - 1] == '\\') return true;
		}
	}
	return false;
}
bool kontkatenacja(char* nameFile, char* path) {
	int i_path;
	int i_namefile;
	for (int i = 0; i < Size; i++) {
		if (nameFile[i] == '\0') {
			i_namefile = i;
		}
	}
	for (int i = 0; i < Size; i++) {
		if (path[i] == '\0') {
			i_path = i;
		}
	}
	if ((i_path + i_namefile + 2) > Size) {
		std::cout << "za dluga nazwa sciezki lub pliku!\n"; 
		return false;
	}
	else {
		for (int i = 0; i <= i_path; i++) {
			nameFile[i_namefile+i] = path[i];
		}
	}
	return true;
}
void przypisanie(char* path, char* fileName) {
	for (int i = 0; i < Size; i++)
		path[i] = fileName[i];
}