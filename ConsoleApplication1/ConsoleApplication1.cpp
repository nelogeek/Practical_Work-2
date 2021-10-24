#include <iostream>
#include <string>

using namespace std;

struct ZNAK
{
	string NAME[2];// фамилия имя
	string ZODIAK;
	int BDAY[3];//dd mm yyyy
	double AV_SCORE;//средний балл
};

double average_score(double* arr, int size) //функция нахождения среднего арифметического
{
	double average;
	double temp = 0;
	for (int i = 0; i < size; i++)
	{
		temp += arr[i];
	}
	average = temp / size;
	return average;
}

void bubbleSort(ZNAK temp[], size_t size) {
	long i, j;
	ZNAK x;

	for (i = 0; i < size; i++) {
		for (j = size - 1; j > i; j--) {
			if (temp[j - 1].BDAY[0] > temp[j].BDAY[0]) {
				x = temp[j - 1]; temp[j - 1] = temp[j]; temp[j] = x;
			}
		}
	}
	for (i = 0; i < size; i++) {
		for (j = size - 1; j > i; j--) {
			if (temp[j - 1].BDAY[1] > temp[j].BDAY[1]) {
				x = temp[j - 1]; temp[j - 1] = temp[j]; temp[j] = x;
			}
		}
	}
	for (i = 0; i < size; i++) {           
		for (j = size - 1; j > i; j--) {   
			if (temp[j - 1].BDAY[2] > temp[j].BDAY[2]) {
				x = temp[j - 1]; temp[j - 1] = temp[j]; temp[j] = x;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 2; // количество человек
	ZNAK BOOK[size];
	for (int i = 0; i < size; i++)  // ввод информации
	{
		cout << "Введите фамилию и имя" << endl;
		for (int j = 0; j < 2; j++)
			cin >> BOOK[i].NAME[j];
		cout << "Введите знак зодиака" << endl;
		cin >> BOOK[i].ZODIAK;
		cout << "Введите ДЕНЬ рождения" << endl;
		cin >> BOOK[i].BDAY[0];
		cout << "Введите МЕСЯЦ рождения" << endl;
		cin >> BOOK[i].BDAY[1];
		cout << "Введите ГОД рождения" << endl;
		cin >> BOOK[i].BDAY[2];

	}

	bubbleSort(BOOK, size);//сортировка
	for (auto SOMEONE : BOOK) {
		cout << SOMEONE.NAME[0] << " " << SOMEONE.NAME[1] << endl;
		cout << SOMEONE.BDAY[0] << "." << SOMEONE.BDAY[1] << "." << SOMEONE.BDAY[2] <<endl;
	}

	cout << "Введите фамилию человека, которого нужно найти" << endl;
	string surname;
	cin >> surname;
	bool check = true;
	for (auto SOMEONE : BOOK) {
		if (SOMEONE.NAME[0] == surname) {
			cout << "Фамилия: " << SOMEONE.NAME[0] << endl;
			cout << "Имя: " << SOMEONE.NAME[1] << endl;
			cout << "Знак зодиака: " << SOMEONE.ZODIAK << endl;
			cout << "Дата рождения: " << SOMEONE.BDAY[0] << "." << SOMEONE.BDAY[1] << "." << SOMEONE.BDAY[2] << endl;

			check = false;
		}
		
	}
	if (check)
		cout << "Такая фамилия не найдена";
}