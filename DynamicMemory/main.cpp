#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int index, int value);  //  ��������� ������� � ������ �� ���������� �������
int* insert1(int arr[], int index, int value);  //  �������� ������� � ������� �� ���������� �������
int* pop_back(int arr[], int& n);	//������� �������� � ����� �������
int* pop_front(int arr[], int& n);	//������� �������� � ������ �������
int* erase(int arr[], int& n, int index);   //  ������� �������� �� ������� �� ���������� �������

//#define DEBUG_ASSERTION_FAILED
//#define DEBUG_ASSERTION_FAILED_2

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;  // ������ �������
#ifdef DEBUG_ASSERTION_FAILED
	int* pn = &n;
	delete[] pn;
#endif // DEBUG_ASSERTION_FAILED

	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};  // �������� ������ ��� ������
	FillRand(arr, n);
	Print(arr, n);

	int value;  //  ����������� ��������
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value); //  �����  
	Print(arr, n);
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;  //  ���������� �������
	cout << "������� ������ ��������, ��� ���������� � ������ (�� 0 �� ������ ������� - 1): "; cin >> index;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);
	cout << "������� ������ ��������, ������� ���������� �������� (�� 0 �� ������ ������� - 1): "; cin >> index;
	cout << "������� ���������� ��������: "; cin >> value;
	arr = insert1(arr, index, value);
	Print(arr, n);
	cout << "������� ������ �������� ��� �������� �� ������� (�� 0 �� ������ ������� - 1): "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	cout << "�������� ���������� � ������� �������� �������!" << endl;
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
	//1)������� ��������  ������� ������� (�� 1 ������� ������)
	int* buffer = new int[n + 1]{};

	//2)�������� ��� �������� � ����� ������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3)������� �������� ������
	delete[] arr;

	//4)��������� �������� ������ ��������
	arr = buffer;

	//5)��������� �������� � ����� �������:
	arr[n] = value;

	//6)����� ���� ��� � ������� ��������� �������, 
	//���������� ��� ��������� ������������� �� 1:
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
	//����� ������� �������� ��������������:
	int i = 0;
	for (; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//���������� ����� ������� �������� �� ���������:
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