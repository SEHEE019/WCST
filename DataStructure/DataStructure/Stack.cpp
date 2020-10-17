#include <stdio.h>
#include <stdlib.h>

//stack ���� �޸� �Ҵ�, stack �ʱ�ȭ �Լ�

//server
struct Stack
{
	//int stack[10];
	int* stack; //���� �޸𸮿��� ���� �޸� ����� �� �ֵ��� ����
	int top = 0;
};
void Push(Stack* st,int data) {
	//�ּҸ� �˰� ������ ����� ������ ���� ȭ��ǥ ������  
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
void InitStack(Stack* st, int cap){//cap: �Ҵ� �뷮
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
	
	Stack st; //Stack st={0}; initStack���� �ʱ�ȭ�Ͽ� ���� �� �ʱ�ȭ �ʿ� x
	Stack st2;

	//InitStack(&st); //Stack �ʱ�ȭ �������̽�
	InitStack(&st,500); //heap �޸� 500byte �Ҵ�
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

//����ü�� �̿��� stack

////server
//struct Stack
//{
//	int stack[10];
//	int top = 0;
//};
//void Push(Stack* st,int data) { //void Push(int Stack[],int *top ,int data) {
//	//�ּҸ� �˰� ������ ����� ������ ���� ȭ��ǥ ������  
//	st->stack[st->top] = data;  //Stack[*top] = data;
//
//	//�Լ� �� top ���� ������ client top �������� ����Ǿ�� �ϱ� ������ 
//	//call by reference�� int�� ������ ���
//	++st->top; //++*top;
//}
//int Pop(Stack* st) {
//	--st->top;
//	return st->stack[st->top];
//}
////client  
//int main() {
//	
//	Stack st; //Stack st={0}; ���� 0���� �ʱ�ȭ�ؾ� �Ǵ��� ���� �ʱ�ȭ�ϸ� �ȵ�...
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