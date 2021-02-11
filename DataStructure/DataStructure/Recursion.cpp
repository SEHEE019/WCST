#include <stdio.h>
#include <iostream>

//이진탐색 재귀 이용(선형)

int _BinSearch(int arr[], int left, int right, int data) {
	if (left <= right) {
		int middle = (left + right) / 2;
		if (data < arr[middle]) {
			return _BinSearch(arr, left, right - 1, data);
		}
		else if (data > arr[middle]) {
			return _BinSearch(arr, left, right - 1, data);
		}
		else {
			return middle;
		}
	}
}
int BinSearch(int arr[], int size, int data) {
	return _BinSearch(arr, 0,size-1, data);
}
int main() {
	int arr[10] = { 10,35,45,48,50,57,69,72,83,96 };
	int size = 10;

	int idx = BinSearch(arr, size, 48);
	if (idx != -1)
		printf("[%d]: %d\n", idx, arr[idx]);
	return 0;
}

//Fibonacci(비선형)

//int Fibonacci(int n) {
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 2;
//	else
//		return Fibonacci(n - 1) + Fibonacci(n - 2); 
//}
//
//int main() {
//	int result = Fibonacci(5);
//	printf("%d\n", result);
//	return 0;
//}

//factorial(선형)

//int Factorial(int n){
//	if (n == 1)
//		return 1;
//	else
//		return Factorial(n-1)*n;
//}
//int main()
//{
//	int result = Factorial(5);
//	return 0;
//}

//선형 재귀함수

//void Print(int n) {
//	printf("+%d\n", n);
//	if (n > 0)
//		Print(n - 1);
//	printf("-%d\n", n);
//}
//int main()
//{
//	Print(3);
//	return 0;
//} 