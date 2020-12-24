#include "alg.h"

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

int linear(int * arr, int key)
{
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}		
	}
	return -1;
}

void sort(int size, int * arr)
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
			sort(j + 1, arr);
		}
		if (i < size) {
			//"Првый кусок"
			sort(size - i, &arr[i]);
		}
	
}

//Бинарный поиск
//можно отсортировать массив для всех методов поиска сразу.
int birnary(int * arr, int key)
{
	int left = 0;
	int right = 99;	
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (key == arr[mid])
		{
			return mid;
		}
		else if (key < arr[mid])
		{
			right = mid-1;
			
		}
		else if (key > arr[mid])
		{
			left = mid+1;
			
		}		
	}
	return -1;
}

int KnMrPr(std::string key, std::string str)
{
	for (int i = 0; str[i]; ++i) {
		for (int j = 0;; ++j) {
			if (!key[j]) return i; 
			if (str[i + j] != key[j]) break;
		}
		
	}
	
	return -1;
}

int BMSearch(std::string txt, std::string srch) {
	int  sl, ssl;
	int res = -1;

	sl = txt.length();
	ssl = srch.length();

	int  i, pos;
	int BMT[256];

	for (i = 0; i < 256; i++)
		BMT[i] = ssl;

	for (i = ssl - 1; i >= 0; i--)
		if (BMT[(short)(srch[i])] == ssl)
			BMT[(short)(srch[i])] = ssl - i - 1;

	pos = ssl - 1;
	while (pos < sl)
		if (srch[ssl - 1] != txt[pos])
			pos = pos + BMT[(short)(txt[pos])];
		else
			for (i = ssl - 2; i >= 0; i--) {
				if (srch[i] != txt[pos - ssl + i + 1]) {
					pos += BMT[(short)(txt[pos - ssl + i + 1])] - 1;
					break;
				}
				else
					if (i == 0)
						return pos - ssl + 1;
			}

	return res;
}

int LinStr(std::string txt, std::string srch) {
	for (int i = 0; i <= (txt.length() - srch.length()); i++)
	{ 
		for (int j = 0; txt[j + i] == srch[j]; j++)
		{ 
			if ((j + 1) == srch.length())
			{
				return i;
			}
		}
	}
	return -1;
}



