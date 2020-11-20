#include "alg.h"
#include <iostream>
using namespace std;
int GetRand()
{
	//генерируем рандомное число
	static unsigned seed = 1; // зерно не должно быть 0
	seed = (seed * 73129 + 95121) % 100000;
	return seed;
	return 0;
}
int * GetArr(int size)
{
	int * arr = new int[size];
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = GetRand();
	}
	return arr;
}
void Bubble(int size, int * arr)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int b = arr[j]; // создали дополнительную переменную
				arr[j] = arr[j + 1]; // меняем местами
				arr[j + 1] = b; // значения элементов
			}
		}
	}
}
void QuickS(int size, int * arr)
{
	int i = 0; // указываем на начало массива
	int j = size - 1; // указывем на конец массива
	int base = arr[size / 2]; //назначаем опорный элемент
	//делим массив
	do {
		//оставляем на месте элементы меньше опорного в левой части
		while (arr[i] < base) { i++; }
		//в правой части оставляем элементы больше опорного
		while (arr[j] > base) { j--; }
		if (i <= j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);
	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		QuickS(j + 1, arr);
	}
	if (i < size) {
		//"Првый кусок"
		QuickS(size - i, &arr[i]);
	}
}

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(int* arr, int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2
 // Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;
	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;
	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int * arr, int n)
{	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);
		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}
// Управляющая программа
void PyrSort(int * arr, int n) // вообще это не нужжно, я не понимаю как оно тут оказалось
{
	heapSort(arr, n);	
}

void SelectionS(int * num, int size)
{
	int min, temp; // для поиска минимального элемента и для обмена
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // запоминаем индекс текущего элемента
		// ищем минимальный элемент чтобы поместить на место i-ого
		for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
		{
			if (num[j] < num[min]) // если элемент меньше минимального,
				min = j;       // запоминаем его индекс в min
		}
		temp = num[i];      // меняем местами i-ый и минимальный элементы
		num[i] = num[min];
		num[min] = temp;
	}
}

void ShellSort(int *arr, int size)
{
	int step, i, j, tmp;

	// Выбор шага
	for (step = size / 2; step > 0; step /= 2)
		// Перечисление элементов, которые сортируются на определённом шаге
		for (i = step; i < size; i++)
			// Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
			{
				tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
			}
}

//void merge(int *a, int n)
//{
//	int mid = n / 2; // находим середину сортируемой последовательности
//	if (n % 2 == 1)
//		mid++;
//	int h = 1; // шаг
//	// выделяем память под формируемую последовательность
//	int *c = (int*)malloc(n * sizeof(int));
//	int step;
//	while (h < n)
//	{
//		step = h;
//		int i = 0;   // индекс первого пути
//		int j = mid; // индекс второго пути
//		int k = 0;   // индекс элемента в результирующей последовательности
//		while (step <= mid)
//		{
//			while ((i < step) && (j < n) && (j < (mid + step)))
//			{ // пока не дошли до конца пути
//			  // заполняем следующий элемент формируемой последовательности
//			  // меньшим из двух просматриваемых
//				if (a[i] < a[j])
//				{
//					c[k] = a[i];
//					i++; k++;
//				}
//				else {
//					c[k] = a[j];
//					j++; k++;
//				}
//			}
//			while (i < step)
//			{ // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
//				c[k] = a[i];
//				i++; k++;
//			}
//			while ((j < (mid + step)) && (j < n))
//			{  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
//				c[k] = a[j];
//				j++; k++;
//			}
//			step = step + h; // переходим к следующему этапу
//		}
//		h = h * 2;
//		// Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
//		for (i = 0; i < n; i++)
//			a[i] = c[i];
//	}
//}

void Merge(int *A, int first, int last) {
	int middle, start, final, j;
	int *mas = new int[100];
	middle = (first + last) / 2;  //вычисление среднего элемента
	start = first;                //начало левой части
	final = middle + 1;           //начало правой части
	for (j = first; j <= last; j++)  //выполнять от начала до конца
		if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
			mas[j] = A[start];
			start++;
		}
		else {
			mas[j] = A[final];
			final++;
		}
	//возвращение результата в список
	for (j = first; j <= last; j++)
		A[j] = mas[j];
	delete[] mas;
};
//рекурсивная процедура сортировки
void merge(int *A, int first, int last) {
	if (first < last) {
		merge(A, first, (first + last) / 2);  //сортировка левой части
		merge(A, (first + last) / 2 + 1, last);  //сортировка правой части
		Merge(A, first, last);  //слияние двух частей
	}
}
