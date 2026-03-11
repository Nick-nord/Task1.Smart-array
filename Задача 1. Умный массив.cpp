// Задача 1. Умный массив.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <exception>

class smart_array
{
	int* arr;
	int size;
	int capacity;   // Максимальное количество элементов
public:
	smart_array(int initial_capacity)
	{
		arr = new int[initial_capacity];
		capacity = initial_capacity;
		size = 0;

	}
	// Функция добавления элемента в конец массива
	void add_element(int value) {
		if (size >= capacity) {
			// Если места недостаточно, увеличиваем емкость вдвое
			resize(capacity * 2);
		}
		arr[size++] = value;
	}

	// Изменение размера массива
	void resize(int new_capacity) {
		int* temp_data = new int[new_capacity];

		for (int i = 0; i < size; ++i) {
			temp_data[i] = arr[i];
		}

		delete[] arr;
		arr = temp_data;
		capacity = new_capacity;
	}


	// Получение элемента по индексу с проверкой границ
	int& get_element(int index) {
		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}
		return arr[index];
	}

	~ smart_array() { delete[] arr; };
};





int main()
{
	
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

