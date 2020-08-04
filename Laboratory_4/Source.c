/* Лабораторная работа № 5. Задание № 1.
   "Сортировка  вставками,  место  помещения очередного элемента в
	отсортированную часть производить с помощью двоичного поиска.
	Двоичный поиск  оформить  в  виде  отдельной функции."
*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define SIZE 10

void insert(int A[], int size);
void showArray(int A[], int size);
int binSearch(int A[], int size, int val);
void binInsert(int A[], int size);


void main()
{
	setlocale(LC_ALL, "Rus");

	int myArray[SIZE] = { 5,7,3,8,9,1,6,2,1,4 };

	printf("Исходный массив: ");
	showArray(myArray, SIZE);

	//	insert(myArray,SIZE);
	binInsert(myArray, SIZE);

	printf("Отсортированный массив: ");
	showArray(myArray, SIZE);

	_getch();
}

void binInsert(int A[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int pos = binSearch(A, i, A[i]);
		int save = A[i];
		int j;

		for (j = i; j > pos; j--)
		{
			A[j] = A[j - 1];
		}
		A[j] = save;

	}
}
int binSearch(int A[], int size, int val)
{
	int mid, left, right;
	for (left = 0, right = size - 1; left < right;)
	{
		mid = (left + right) / 2;


		if (A[mid] == val)
		{
			return mid;
		}

		if (A[mid] > val)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}

	}

	if (A[left] < val)
	{
		return left + 1;
	}
	else
	{
		return left;
	}
}

// Классическая вставка
void insert(int A[], int size)
{
	for (int i = 1; i < size; i++)
	{

		for (int j = i, tmp; j != 0 && A[j] < A[j - 1]; j--) //поиск места для очередного элемента
		{
			tmp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = tmp;
		}
	}
}
// Вывод массива на экран
void showArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n\n");
}