#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int index, int value);  //  Добавляет элемент в массив по указанному индексу
int* insert1(int arr[], int index, int value);  //  Изменяет элемент в массиве по указанному индексу
int* pop_back(int arr[], int& n);	//Удаляет значение с конца массива
int* pop_front(int arr[], int& n);	//Удаляет значение с начала массива
int* erase(int arr[], int& n, int index);   //  Удаляет значение из массива по указанному индексу

//#define DEBUG_ASSERTION_FAILED
//#define DEBUG_ASSERTION_FAILED_2

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;  // Размер массива
#ifdef DEBUG_ASSERTION_FAILED
	int* pn = &n;
	delete[] pn;
#endif // DEBUG_ASSERTION_FAILED

	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};  // Выделяем память под массив
	FillRand(arr, n);
	Print(arr, n);

	int value;  //  Добавляемое значение
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value); //  ВЫЗОВ  
	Print(arr, n);
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;  //  Изменяемый элемент
	cout << "Укажите индекс элемента, для добавления в массив (от 0 до размер массива - 1): "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);
	cout << "Укажите индекс элемента, который необходимо заменить (от 0 до размер массива - 1): "; cin >> index;
	cout << "Введите изменяемое значение: "; cin >> value;
	arr = insert1(arr, index, value);
	Print(arr, n);
	cout << "Укажите индекс элемента для удаления из массива (от 0 до размер массива - 1): "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	cout << "Удаление последнего и первого элемента массива!" << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);

#ifdef DEBUG_ASSERTION_FAILED_2	
	delete[] buffer;
#endif // DEBUG_ASSERTION_FAILED_2	

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* push_back(int arr[], int& n, int value)
{
	//1)Создаем буферный  нужного размера (на 1 элемент больше)
	int* buffer = new int[n + 1]{};

	//2)Копируем все значения в новый массив:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3)Удаляем исходный массив
	delete[] arr;

	//4)Подменяем исходный массив буферным
	arr = buffer;

	//5)Добавляем значение в конец массива:
	arr[n] = value;

	//6)После того как в массиве добавился элемент, 
	//количество его элементов увеличивается на 1:
	n++;

	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int arr[], int& n, int index, int value)
{
	if (index >= n)return arr;
	int* buffer = new int[n + 1];
	//Часть массива копируем соответственно:
	int i = 0;
	for (; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//Оставшуюся часть массива копируем со смещением:
	for (; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* insert1(int arr[], int index, int value)
{
	arr[index] = value;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	//int* buffer = new int[n - 1];
	int* buffer = new int[--n];
	//for (int i = 0; i < n - 1; i++)
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	//arr = buffer;
	//n--;
	//return arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	//int* buffer = new int[n - 1];
	int* buffer = new int[--n];
	//for (int i = 0; i < n - 1; i++)
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	//arr = buffer;
	//n--;
	//return arr;
	return buffer;
}
int* erase(int arr[], int& n, int index)
{
	if (index < 0 || index >= n)return arr;
	//int* buffer = new int[n - 1];
	int* buffer = new int[--n];
	int i = 0;
	for (; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	//arr = buffer;
	//n--;
	//return arr;
	return buffer;
}