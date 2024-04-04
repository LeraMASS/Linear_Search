#include <iostream>
#include <ctime>
#include <cstdlib>

//Вывод массива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
//Функция линейного поиска, первого вхождения значения key в массив arr начиная с позиции бегин.
template <typename T>
int search_index(T arr[], const int length, T key, int begin = 0) {//значение begin поиск от определенного индекса массива
	for (int i = begin; i < length; i++)
		if (arr[i] == key)
			return i;
	return -1;
}

// Функция линейного поиска последнего вхождения 
template <typename T>
int search_last_index(T arr[], const int length, T key) { //begin воспользовать не возможно, если будет обращение к одной из переменных функции
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == key)
			return i;
	return -1;
}
// Функция линейного поиска последнего вхождения с позиции begin
template <typename T>
int search_last_index(T arr[], const int length, T key, int begin) { //begin пустая переменная
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == key)
			return i;
	return -1;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Вывод массива 
	const int size = 10;
	int arr[size]{ 5, 20, 10, 8, 5, 20, 7, 8, 20, 1 };

	std::cout << "Массив:\n";
	print_arr(arr, size);

	//Линейный поиск в массиве
	std::cout << "Введите число для поиска -> ";
	std::cin >> n;
	// От начала массива
	int index = search_index(arr, size, n); //записываем доп. число, откуда будет поиск по массиву

	if (index != -1)
		std::cout << "Позиция числа: " << index << std::endl;
	else
		std::cout << "Числа нет в массиве.\n";

	// От конца массива
	int last_index = search_last_index(arr, size, n, 6);//можно добавить четвертый аргумент
	if (last_index != -1)
		std::cout << "Позиция числа:\n" << last_index << std::endl;
	else
		std::cout << "Числа нет в массиве!\n";

	return 0;
}