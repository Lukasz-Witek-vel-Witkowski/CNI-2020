#include <string>
#include <iostream>
#include <fstream>
#include <vector>
void find(std::ifstream *file, std::string find, int& i);
void load(std::ifstream* file, std::vector<std::string>& vector);
void zamien(std::vector<std::string>& vector, std::string find, std::string text);
void save(std::vector<std::string>& vector, std::string data);
int main(int size, char* tab[]) {
	if (size >= 4) {
		std::ifstream file(tab[2]);
		std::string find_str;
		std::string text_str;
		int i;
		std::vector<std::string> vector;
		if (file.good()) {

			switch (tab[1][0]) {
			case '1':
				find_str = tab[3];
				find(&file, find_str, i);
				std::cout << i << "\n";
				break;
			case '2':
				load(&file, vector);
				find_str = tab[3];
				text_str = tab[4];
				zamien(vector, find_str, text_str);
				break;
			case '3':
				load(&file, vector);

				break;
			}

			file.close();
			std::string data = tab[2];
			save(vector, data);
		}
	}
	return 0;
}
void find(std::ifstream *file, std::string find, int& i) {
	std::string data;
	int i_find;
	bool what = false;
	i = 0;
		while (!file->eof())
		{
			std::getline(*file, data);
			do {
				what = false;
				i_find = data.find(find);
				if (i_find != std::string::npos) {
					i++;
					what = true;
					data = data.substr(0, i_find + find.size());
				}

			} while (what);

		}
}
void load(std::ifstream* file, std::vector<std::string>& vector) {
	std::string data;
	int i_find;
	bool what = false;
	int i = 0;
	while (!file->eof())
	{
		std::getline(*file, data);
		vector.push_back(data);
	}
}
void zamien(std::vector<std::string>& vector, std::string find, std::string text) {
	std::cout << find << "\t" << text << "\n";
	std::string data;
	std::string temp;
	int i_find;
	int i_temp;
	bool what;
	int iter = 0;
	for (int i = 0; i < vector.size(); i++) {
		data = vector[i];
		i_find = data.find(find);
		if (i_find != std::string::npos) {
			iter++;
			data.erase(i_find, find.size());
			data.insert(i_find, text);
			if (i_find + text.size() < data.size()) {
				temp = data.substr(i_find + text.size(), data.size());
				do {
					what = false;
					i_temp = temp.find(find);
					if (i_temp != std::string::npos) {
						temp.erase(i_temp, find.size());
						temp.insert(i_temp, text);
						data = data.substr(0, i_find + text.size()) + temp;
						if (i_temp + text.size() < data.size()) {
							temp = data.substr(i_temp + text.size(), data.size());
							what = true;
						}
					}
			} while (what);
		}
		}
		vector[i] = data;
	}
	std::cout << iter;
}
void save(std::vector<std::string>& vector, std::string data) {
	if (vector.size() > 0) {
		std::ofstream file(data.c_str());
		if (file.good()) {
			for (int i = 0; i < vector.size(); i++) {
				file << vector[i] <<"\n";
			}
			file.close();
		}
	}
}