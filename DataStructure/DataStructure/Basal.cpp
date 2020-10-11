#include <stdio.h>
#include <stdlib.h>

//이진검색

//void PrintList(int list[], int size) {
//	for (int i = 0; i < size; i++)
//		printf("%5d", list[i]);
//	printf("\n");
//}
//int BSearch(int data, int list[], int size, int(*cmp)(int,int)) {
//	int left = 0;
//	int right = size - 1;
//	while (left <=right){
//		int middle = (left + right) / 2;
//		switch (cmp(data, list[middle])) {
//		case 1:
//			right = middle - 1;
//			break;
//		case -1:
//			left = middle + 1;
//			break;
//		case 0:
//			return middle;
//		}
//		//if (data < list[middle]) {
//		//	right = middle - 1;
//		//}
//		//else if (data > list[middle]) {
//		//	left = middle + 1;
//		//}
//		//else
//		//	return middle;
//	}
//	
//	return -1;
//}
////비교하는 정책을 클라이언트에서 할 수 있도록 해주는 함수
//int cmp(int data1, int data2) {
//	if (data2 < data1)
//		return -1;
//	else if (data2 > data1)
//		return 1;
//	else
//		return 0;
//}
//int main() {
//	int list[10] = { 20,23,25,35,42,51,56,65,70,89 };
//	PrintList(list, 10);
//	int idx = BSearch(51,list, 10, cmp);
//	if (idx != -1) {
//		printf("list[%d]:%d\n", idx, list[idx]); 
//	}
//}

// 함수 포인터(NOTE 있음!!)

//int Add(int a, int b) {
//	return a + b;
//}
//void Print(int n){}
//int main() {
//	//함수의 주소를 저장할 포인터 변수 생성
//	int (*pf)(int, int);
//	void(*pf2)(int);
//
//	// main 내 함수 이름은 함수의 시작 주소를 나타낸다.
//	// 즉, 함수의 시작 주소만 가지고 있으면 함수를 호출시킬 수 있다.
//	pf = Add; 
//	pf2 = Print;
//
//	// NOTE: 주소값을 직접 넣어서 함수를 호출시킬 수 있을까?
//
//	//int result = Add(10, 20);
//	// 함수 포인터를 사용하여 호출 가능
//	int result = pf(10, 20); 
//
//	printf("result:%d\n", result);
//	//함수의 주소 출력
//	printf("%p\n", Add);
//	return 0;
//}

//callback

////server
//void PrintList(int list[], int size) {
//	for (int i = 0; i < size; i++)
//		printf("%5d", list[i]);
//	printf("\n");
//}
//int Search(int list[], int size, int (*cmp)(int)) {
//	for (int i = 0; i < size; i++) {
//		//if (list[i] == data)
//		if(cmp(list[i]))//callback
//			return i;
//	}
//	return -1;
//}
////client
//int cmp(int data) {// callback function
//	//return data == 42;
//	return data > 50 && data % 2 == 0;
//}
//int main() {
//	int list[10] = { 20,23,56,70,35,42,65,51,89,25 };
//
//	PrintList(list, 10);
//	int idx = Search(list, 10, cmp);
//	if (idx != -1) {
//		printf("list[%d]:%d\n", idx, list[idx]);
//	}
//	return 0;
//}

//node

//struct Node {
//	int data;
//	Node* link;
//};
//int main() {
//	Node n1 = { 20 ,NULL };
//	Node n2 = { 30 ,NULL };
//	Node n3 = { 40 ,NULL };
//
//	n1.link = &n2;
//	n2.link = &n3;
//
//	// n1.data;
//	printf("%d\n", n1.data);
//	// n2.data;
//	printf("%d\n", n1.link->data);
//	// n3.data;
//	printf("%d\n", n1.link->link->data);
//}

//struct

//struct Point
//{
//	int x;
//	int y;
//};
//
//int main() {
//	Point p1 = { 1,2 };
//	Point p2;
//	Point* pp = &p1;
//	Point* p = (Point*)malloc(sizeof (Point));
//
//	p2.x = 4;
//	p2.y = 5;
//
//	printf("(%d,%d)\n", p1.x, p1.y);
//	printf("(%d,%d)\n", pp->x, pp->y);
//
//	return 0;
//
//}

//malloc

//int main() {
//	//heap 영역에 메모리 할당
//	//malloc return value : 해당 메모리 시작 주소값(void형) -> 포인터 변수에 담아야 함.
//	int* p;
//	p = (int*)malloc(4);
//	*p = 10;
//	printf("%d\n", *p);
//	free(p);
//
//	//정적 배열은 상수 값으로만 크기를 정할 수 있다.
//	int arr[5];
//	int size = 0;
//
//	printf("최대 원소의 개수 입력: ");
//	scanf_s("%d", &size);
//	int* pa = (int*)malloc(sizeof(int) * size);
//	
//	for (int i = 0; i < 5; ++i) {
//		arr[i] = 10 * i;
//	}
//	for (int i = 0; i < size; ++i) {
//		pa[i] = 10 * i;
//	}
//
//	for (int i = 0; i < 5; i++) {
//		printf("%d\n", arr[i]);
//	}
//	for (int i = 0; i < size; i++) {
//		printf("%d\n", pa[i]);
//	}
//	free(pa);
//	return 0;
//}