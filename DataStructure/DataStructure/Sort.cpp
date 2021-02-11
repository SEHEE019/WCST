#include <stdio.h>
#include <iostream>

int Search(int list[], int size, int data) {
	for (int i = 0; i < size; i++) {
		if (list[i] == data)
			return i;
		else
			return -1;
	}
}
int main() {
	int list[10] = { 20,23,56,70,35,42,65,51,89,25 };
	int idx = Search(list, 10, 70);
	printf("%d\n", idx);
	return 0;
}

//버블 정렬

//void Swap(int* pa, int* pb)
//{
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//void PrintList(int list[], int size)
//{
//	for (int i = 0; i < size; ++i)
//		printf("%5d", list[i]);
//	printf("\n");
//}
//int Min(int list[], int sIndex, int eIndex)
//{
//	int min = sIndex;
//	for (int i = sIndex + 1; i <= eIndex; ++i)
//		if (list[min] > list[i])
//			min = i;
//	return min;
//}
//void BubbleSort(int list[], int size)
//{
//	for (int i = 0; i < size - 1; ++i)
//	{
//		for (int j = 0; j < (size - 1) - i; ++j)
//		{
//			if (list[j] > list[j + 1])
//				Swap(&list[j], &list[j + 1]);
//		}
//	}
//}
//int main()
//{
//	int list[10] = { 80,20,70,50,60,90,40,30 };
//	int size = 8;
//
//	PrintList(list, size);
//	BubbleSort(list, size);
//	PrintList(list, size);
//	return 0;
//}

//삽입 정렬

//#include<stdio.h>
//
//void Swap(int* pa, int* pb)
//{
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//void PrintList(int list[], int size)
//{
//	for (int i = 0; i < size; ++i)
//		printf("%5d", list[i]);
//	printf("\n");
//}
//int Min(int list[], int sIndex, int eIndex)
//{
//	int min = sIndex;
//	for (int i = sIndex + 1; i <= eIndex; ++i)
//		if (list[min] > list[i])
//			min = i;
//	return min;
//}
//void InsertionSort(int list[], int size)
//{
//	int value, j;
//	for (int i = 1; i < size; ++i)
//	{
//		value = list[i];
//		for (j = i - 1; j >= 0; --j)
//		{
//			if (list[j] > value)
//				list[j + 1] = list[j];
//			else
//				break;
//		}
//		list[j + 1] = value;
//	}
//}
//int main()
//{
//	int list[10] = { 80,20,70,50,60,90,40,30 };
//	//int list[10] = { 20,50,70,80,10,90,40,30 };
//	int size = 8;
//
//	PrintList(list, size);
//	InsertionSort(list, size);
//	PrintList(list, size);
//	return 0;
//}

//선택 정렬

//void Swap(int* pa, int * pb) {
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//void PrintList(int list[], int size) {
//	for (int i = 0; i < size; i++)
//		printf("%5d", list[i]);
//	printf("\n");
//}
//int Min(int list[],int sIndex, int eIndex) {
//	int min = sIndex;
//	for (int i = sIndex+1; i <=eIndex; i++) {
//		if (list[min] > list[i])
//			min = i;
//	}
//	return min;
//}
//void SelectionSort(int list[],int size) {
//	for (int i = 0; i < size - 1; i++) {
//		int min = Min(list, i, size - 1);
//		Swap(&list[i], &list[min]);
//	}
//}
//int main() {
//	int list[10] = { 80,20,70,50,60,90,40,30 };
//	int size = 8;
//
//	PrintList(list, size);
//	SelectionSort(list,size);
//	PrintList(list, size);
//	return 0;
//}

//void Swap(int* pa, int * pb) {
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//void PrintList(int list[], int size) {
//	for (int i = 0; i < size; i++)
//		printf("%5d", list[i]);
//	printf("\n");
//}
//int main() {
//	int list[10] = { 80,20,70,50,60,90,40,30 };
//	int size = 8;
//
//	PrintList(list, size);
//	Swap(&list[0], &list[1]);
//	PrintList(list, size);
//	return 0;
//}