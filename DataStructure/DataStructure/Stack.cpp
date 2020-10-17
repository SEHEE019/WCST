#include <stdio.h>
#include <stdlib.h>

//stack 동적 메모리 할당, stack 초기화 함수

//server
struct Stack
{
	//int stack[10];
	int* stack; //정적 메모리에서 동적 메모리 사용할 수 있도록 변경
	int top = 0;
};
void Push(Stack* st,int data) {
	//주소를 알고 있으면 멤버를 접근할 때는 화살표 연산자  
	st->stack[st->top] = data;
	++st->top;
}
int Pop(Stack* st) {
	--st->top;
	return st->stack[st->top];
}
//void InitStack(Stack* st) {
//	st->top = 0;
//}
void InitStack(Stack* st, int cap){//cap: 할당 용량
	st->stack = (int*)malloc(sizeof(int)*cap);
	st->top = 0;
}
//void UninitStack(Stack* st) {
//	st->top = 0;
//}
void UninitStack(Stack* st,int cap) {
	free(st->stack);
	st->top = 0;
}
//client  
int main() {
	
	Stack st; //Stack st={0}; initStack으로 초기화하여 선언 때 초기화 필요 x
	Stack st2;

	//InitStack(&st); //Stack 초기화 인터페이스
	InitStack(&st,500); //heap 메모리 500byte 할당
	Push(&st, 10); 
	Push(&st, 20);
	Push(&st, 30);
	printf("%d\n", Pop(&st)); //30
	printf("%d\n", Pop(&st)); //20
	printf("%d\n", Pop(&st)); //10 
	//UninitStack(&st);
	UninitStack(&st, 500); 

	//InitStack(&st2);
	InitStack(&st2, 10);
	Push(&st2, 100);
	Push(&st2, 200);
	Push(&st2, 300);
	printf("%d\n", Pop(&st2)); //300 
	printf("%d\n", Pop(&st2)); //200 
	printf("%d\n", Pop(&st2)); //10 
	//UninitStack(&st2);
	UninitStack(&st2, 10);

	return 0;
}

//구조체를 이용한 stack

////server
//struct Stack
//{
//	int stack[10];
//	int top = 0;
//};
//void Push(Stack* st,int data) { //void Push(int Stack[],int *top ,int data) {
//	//주소를 알고 있으면 멤버를 접근할 때는 화살표 연산자  
//	st->stack[st->top] = data;  //Stack[*top] = data;
//
//	//함수 내 top 증감 내용이 client top 변수에도 적용되어야 하기 때문에 
//	//call by reference로 int형 포인터 사용
//	++st->top; //++*top;
//}
//int Pop(Stack* st) {
//	--st->top;
//	return st->stack[st->top];
//}
////client  
//int main() {
//	
//	Stack st; //Stack st={0}; 쌤은 0으로 초기화해야 되던데 나는 초기화하면 안됨...
//	Stack st2;
//	Push(&st, 10);
//	Push(&st, 20);
//	Push(&st, 30);
//
//	printf("%d\n", Pop(&st)); //30
//	printf("%d\n", Pop(&st)); //20
//	printf("%d\n", Pop(&st)); //10 
//
//	Push(&st2, 100);
//	Push(&st2, 200);
//	Push(&st2, 300);
//
//	printf("%d\n", Pop(&st2)); //300 
//	printf("%d\n", Pop(&st2)); //200 
//	printf("%d\n", Pop(&st2)); //10 
//
//	return 0;
//}

//stack basel(printf("%d\n", Pop()))

////server
//int stack[10];
//int top = 0;
//void Push(int data) {
//	stack[top] = data;
//	++top;
//}
//int Pop() {
//	--top;
//	return stack[top];
//}
////client  
//int main() {
//	Push(10);
//	Push(20);
//	Push(30);
//
//	printf("%d\n", Pop()); //30
//	Push(40);
//	Push(50);
//	printf("%d\n", Pop()); //50
//	printf("%d\n", Pop()); //40
//	printf("%d\n", Pop()); //20
//	printf("%d\n", Pop()); //10 
//	return 0;
//}

//stack basel(data=pop())

////server
//int stack[10];
//int top = 0;
//void Push(int data) {
//	stack[top] = data;
//	++top;
//}
//int Pop() {
//	--top;
//	return stack[top];
//}
////client 
//int main() {
//	Push(10);
//	Push(20);
//	Push(30);
//	
//	int data;
//	data = Pop();
//	printf("%d\n", data);
//	data = Pop();
//	printf("%d\n", data);
//	data = Pop();
//	printf("%d\n", data);
//	return 0;
//}