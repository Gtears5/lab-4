#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

string text;

void SpaceAnnihilator() {
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ' && text[i + 1] == ' ')
			while (text[i + 1] == ' ')
				text.erase((i + 1), 1);
	}
}

void SignAnnihilator() {
	for (int i = 0; i < text.size(); i++)
		if ((text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == '!' || text[i] == ';' || text[i] == ':') && (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == '?' || text[i + 1] == '!' || text[i + 1] == ';' || text[i + 1] == ':')) {
			if (text[i] == '.' && text[i + 1] == '.' && text[i + 2] == '.' && text[i + 3] == ' ')
				i += 3;
			else
				while (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == '?' || text[i + 1] == '!' || text[i + 1] == ';' || text[i + 1] == ':')
					text.erase((i + 1), 1);
		}
}

void Big2() {
	for (int i = 1; i < text.size(); i++) {
		if (text[i] == ' ')
			i += 2;
		text[i] = tolower(text[i]);
	}
}

void DigitalRacist(string txt) {
	txt += ' ';
	for (int i = 0, k = 0, a = 0; i < txt.size(); i++) {
		if (txt[i] == '0' || txt[i] == '1' || txt[i] == '2' || txt[i] == '3' || txt[i] == '4' || txt[i] == '5' || txt[i] == '6' || txt[i] == '7' || txt[i] == '8' || txt[i] == '9')
			k++;
		if (txt[i] == ' ') {
			if (k != 0) {
				while (txt[a] != ' ')
					txt.erase(a, 1);
				txt.erase(a, 1);
				i = a;
			}
			else
				a = i + 1;
			k = 0;
		}
	}
	cout << txt << "\n";
}

void NotStraight() {
	for (int i = 0; i < text.size(); i++) {
		if (text[i] != ' ')
			cout << text[i];
		else
			cout << endl;

	}
}

void Search(string txt) {
	string under;
	int k = 0;
	int count = 0;

	cin >> under;

	for (int i = 0; i < txt.size(); i++) {
		if (txt[i] == under[0]) {
			k = 1;
			for (int j = 1; j < under.size(); j++) {
				if (txt[i + j] != under[j]) {
					k = 0;
					break;
				}
			}
			if (k == 1) {
				count++;
			}
		}
	}
	cout << "Количество совпадений: " << count;
}

int main()
{
	setlocale(0, "");
	int choice;
	cout << "Задание 1\n\n";
	cout << "Выберите (1), чтобы вести строку" << "\n" << "Выберите (2), чтобы открыть файл" << "\n";
	cin >> choice;
	switch (choice) {
	case 1:
		cin.ignore();
		getline(cin, text);
		break;
	case 2:
		ifstream file("C:\\Users\\79802\\Desktop\\sus.txt");
		if (file.is_open())
			getline(file, text);
		file.close();
		break;
	}
	cout << "Входной текст: " << text << "\n\n";

	cout << "Задание 2\n\n";
	SpaceAnnihilator();
	SignAnnihilator();
	Big2();
	cout << "Отредактированный текст: " << text << "\n\n";

	cout << "Задание 3\n\n";
	cout << "Выведены слова без цифр: \n\n";
	DigitalRacist(text);

	cout << "\n\n" << "Задание 4\n\n";
	cout << "Выведены все слова исходной последовательности на экран вертикально: \n";
	NotStraight();

	cout << "\n\n" << "Задание 5";
	cout << "\n\nЛинейный поиск: \nВведите подстроку, которую хотите найти: \n";
	Search(text);

}

