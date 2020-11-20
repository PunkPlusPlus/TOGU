#include "alg.h"
#include <iostream>
using namespace std;
int GetRand()
{
	//���������� ��������� �����
	static unsigned seed = 1; // ����� �� ������ ���� 0
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
				int b = arr[j]; // ������� �������������� ����������
				arr[j] = arr[j + 1]; // ������ �������
				arr[j + 1] = b; // �������� ���������
			}
		}
	}
}
void QuickS(int size, int * arr)
{
	int i = 0; // ��������� �� ������ �������
	int j = size - 1; // �������� �� ����� �������
	int base = arr[size / 2]; //��������� ������� �������
	//����� ������
	do {
		//��������� �� ����� �������� ������ �������� � ����� �����
		while (arr[i] < base) { i++; }
		//� ������ ����� ��������� �������� ������ ��������
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
	//����������� ������, ���� ��������, ��� �����������
	if (j > 0) {
		//"����� �����"
		QuickS(j + 1, arr);
	}
	if (i < size) {
		//"����� �����"
		QuickS(size - i, &arr[i]);
	}
}

// ��������� ��� �������������� � �������� ���� ��������� � �������� ����� i, ��� ��������
// �������� � arr[]. n - ������ ����

void heapify(int* arr, int n, int i)
{
	int largest = i;
	// �������������� ���������� ������� ��� ������
	int l = 2 * i + 1; // ����� = 2*i + 1
	int r = 2 * i + 2; // ������ = 2*i + 2
 // ���� ����� �������� ������� ������ �����
	if (l < n && arr[l] > arr[largest])
		largest = l;
	// ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
	if (r < n && arr[r] > arr[largest])
		largest = r;
	// ���� ����� ������� ������� �� ������
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		// ���������� ����������� � �������� ���� ���������� ���������
		heapify(arr, n, largest);
	}
}

// �������� �������, ����������� ������������� ����������
void heapSort(int * arr, int n)
{	// ���������� ���� (�������������� ������)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	// ���� �� ������ ��������� �������� �� ����
	for (int i = n - 1; i >= 0; i--)
	{
		// ���������� ������� ������ � �����
		swap(arr[0], arr[i]);
		// �������� ��������� heapify �� ����������� ����
		heapify(arr, i, 0);
	}
}
// ����������� ���������
void PyrSort(int * arr, int n) // ������ ��� �� ������, � �� ������� ��� ��� ��� ���������
{
	heapSort(arr, n);	
}

void SelectionS(int * num, int size)
{
	int min, temp; // ��� ������ ������������ �������� � ��� ������
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // ���������� ������ �������� ��������
		// ���� ����������� ������� ����� ��������� �� ����� i-���
		for (int j = i + 1; j < size; j++)  // ��� ��������� ��������� ����� i-���
		{
			if (num[j] < num[min]) // ���� ������� ������ ������������,
				min = j;       // ���������� ��� ������ � min
		}
		temp = num[i];      // ������ ������� i-�� � ����������� ��������
		num[i] = num[min];
		num[min] = temp;
	}
}

void ShellSort(int *arr, int size)
{
	int step, i, j, tmp;

	// ����� ����
	for (step = size / 2; step > 0; step /= 2)
		// ������������ ���������, ������� ����������� �� ����������� ����
		for (i = step; i < size; i++)
			// ������������ ��������� ������ ���������, ���� i-��� �� ����� ������������
			for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
			{
				tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
			}
}

//void merge(int *a, int n)
//{
//	int mid = n / 2; // ������� �������� ����������� ������������������
//	if (n % 2 == 1)
//		mid++;
//	int h = 1; // ���
//	// �������� ������ ��� ����������� ������������������
//	int *c = (int*)malloc(n * sizeof(int));
//	int step;
//	while (h < n)
//	{
//		step = h;
//		int i = 0;   // ������ ������� ����
//		int j = mid; // ������ ������� ����
//		int k = 0;   // ������ �������� � �������������� ������������������
//		while (step <= mid)
//		{
//			while ((i < step) && (j < n) && (j < (mid + step)))
//			{ // ���� �� ����� �� ����� ����
//			  // ��������� ��������� ������� ����������� ������������������
//			  // ������� �� ���� ���������������
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
//			{ // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
//				c[k] = a[i];
//				i++; k++;
//			}
//			while ((j < (mid + step)) && (j < n))
//			{  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
//				c[k] = a[j];
//				j++; k++;
//			}
//			step = step + h; // ��������� � ���������� �����
//		}
//		h = h * 2;
//		// ��������� ������������� ������������������ (������������� �������) � �������� ������
//		for (i = 0; i < n; i++)
//			a[i] = c[i];
//	}
//}

void Merge(int *A, int first, int last) {
	int middle, start, final, j;
	int *mas = new int[100];
	middle = (first + last) / 2;  //���������� �������� ��������
	start = first;                //������ ����� �����
	final = middle + 1;           //������ ������ �����
	for (j = first; j <= last; j++)  //��������� �� ������ �� �����
		if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
			mas[j] = A[start];
			start++;
		}
		else {
			mas[j] = A[final];
			final++;
		}
	//����������� ���������� � ������
	for (j = first; j <= last; j++)
		A[j] = mas[j];
	delete[] mas;
};
//����������� ��������� ����������
void merge(int *A, int first, int last) {
	if (first < last) {
		merge(A, first, (first + last) / 2);  //���������� ����� �����
		merge(A, (first + last) / 2 + 1, last);  //���������� ������ �����
		Merge(A, first, last);  //������� ���� ������
	}
}
