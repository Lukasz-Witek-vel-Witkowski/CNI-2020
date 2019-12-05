#include <iostream>
#include <fstream>
#define Size 256
bool fileExists(char* nameFile);
void fileRead(char* nameFile);
int fileSize(char* nameFile);
void fileOverwrite(char* nameFile);
void fileWrite(std::ofstream& file);
void fileCreative(char* nameFile);
void appendingToFile(char* nameFile);
int mainmenu();
int main() {
	bool loop=true;
	bool loopTemp = false;
	int wybor;
	char* file = new char[Size];
	enum program {
		menuglowne,
		odczyt,
		nadpisanie,
		nowy,
		dopisac,
		zamknac
	};
	program p=menuglowne;
	do {
		switch (p)
		{
		case menuglowne:
			p = (program)mainmenu();
			system("cls");
			std::cout << "Prosze wprowadzic nazwe pliku wraz ze sciezka: \n";
			std::cin >> file;
			system("cls");
			break;
		case odczyt: fileRead(file); p = menuglowne;  break;
		case nadpisanie: fileOverwrite(file); p = menuglowne; break;
		case nowy: fileCreative(file); p = menuglowne; break;
		case dopisac: appendingToFile(file); p = menuglowne; break;
		case zamknac:
			loop = false;
			break;
		default:
			break;
		}
	} while (loop);
	fileRead(file);
	delete[] file;
	return 0;
}
bool fileExists(char* nameFile) {
	std::ifstream file(nameFile);
	if (file.good()) {
		file.close();
		return true;
	}
	return false;
}
void fileRead(char* nameFile) {
	int SizeFile=fileSize(nameFile);
	if (SizeFile > 32000) {
		std::cout << "Zbyt duzy plik!\n"; return;
	}
	char** TAB = new char*[SizeFile];
	for (int i = 0; i < SizeFile; i++) {
		TAB[i] = new char[Size];
	}
	std::ifstream file(nameFile);
	int i = 0;
	char buf;
	int max;
	bool loop = true;
	int iterator=0;
	max = SizeFile / 10;
	if (file.good()) {
		while (!file.eof()) {
			file.getline(TAB[i++], Size);
		}
		file.close();
		do {
			system("cls");
			for (i = iterator * 10; i < (iterator + 1) * 10; i++) {
				if (i < SizeFile) {
					std::cout << i + 1 << "\t" << TAB[i] << "\n";
				}
			}
			std::cout << "\t\tSterowanie:\n\tw - przesuniecie do tylu\n\ts - przesuniecie do przodu\n\tk - zamkniecie pliku\n";
			std::cin >> buf;
			switch (buf) {
			case 'w':
			case 'W':
					if (iterator > 0) iterator--;
				break;
			case 's':
			case 'S':
				if (iterator < max) iterator++;
				break;
			case 'k':
			case 'K':
				loop = false;
				system("cls");
				break;
			}
		} while (loop);
		for (int i = 0; i < SizeFile; i++) {
			delete[] TAB[i];
		}
		delete[] TAB;
	}
	else {
		std::cout << "\tNie udalo sie odczytac pliku " << nameFile << "\n\n";
	}
}
int fileSize(char* nameFile) {
	int i = 0;
	std::ifstream file(nameFile);
	if (file.good()) {
		char* line = new char[Size];
		while (!file.eof()) {
			i++;
			file.getline(line, Size);
		}
		file.close();
		delete[] line;
	}
	return i;
}
void fileOverwrite(char* nameFile) {
	if (fileExists(nameFile)) {
		std::ofstream file(nameFile);
		fileWrite(file);
		file.close();
	}
	else {
		std::cout << "\tPlik o nazwie " << nameFile << " nie istnieje\n\n";
	}
}
void fileWrite(std::ofstream& file) {
	char stop;
	char* line = new char[Size];
	std::cout << "Prosze podac znak po ktorym zostanie zakonczony proces wpisywania do pliku:\n";
	std::cin >> stop;
	while (true) {
		system("cls");
		std::cout << "Pisanie do pliku: \nAby przerwaæ uzyj znaku: " << stop << "\n";
		std::cin.getline(line, Size);
		if (line[0] == stop) {
			break;
		}
		file << line << "\n";
	}
	system("cls");
}
void fileCreative(char* nameFile) {
	if (!fileExists(nameFile)) {
		std::ofstream file(nameFile);
		fileWrite(file);
		file.close();
	}
	else {
		std::cout << "\tPlik o nazwie " << nameFile << " juz istnieje\n\n";
	}
}
void appendingToFile(char* nameFile) {
	if (fileExists(nameFile)) {
		std::ofstream file(nameFile, std::ios::app);
		fileWrite(file);
		file.close();
	}
	else {
		std::cout << "\tPlik o nazwie " << nameFile << " nie istnieje\n\n";
	}
}
int mainmenu() {
	bool loop;
	int wybor;
	do {
		std::cout << "\t\t\tMenuGlowne\n" <<
			"\tCo chcesz zrobic z plikiem?\n" <<
			"\t1.\tOdczytanie\n" <<
			"\t2.\tNadpisac\n" <<
			"\t3.\tStworzyc Nowy\n" <<
			"\t4.\tDopisac do pliku\n" <<
			"\t5.\tWyjscie z programu\n";
		std::cin >> wybor;
		if (wybor < 0 || wybor > 5) {
			system("cls");
			std::cout << "Wprowadzono zla wartosc!\n";
			loop = true;
		}
		else
			loop = false;
	} while (loop);
	return wybor;
}