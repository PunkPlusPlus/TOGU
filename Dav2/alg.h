#pragma once

int  GetRand();
int * GetArr(int size);
void Bubble(int size, int * arr);
void QuickS(int size, int * arr);
void heapify(int* arr, int n, int i);
void heapSort(int * arr, int n);
void PyrSort(int * arr, int n);
void SelectionS(int * arr, int n);
int FindGreater(int * arr, int size);
void ShellSort(int * arr, int size);
//void merge(int * a, int n);
void Merge(int *A, int first, int last);
void merge(int *A, int first, int last);