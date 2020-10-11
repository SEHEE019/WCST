#include <stdio.h>
#include <stdlib.h>

//server
int stack[10];
int top = 0;
void Push(int data) {
	stack[top] = data;
	++top;
}
int Pop() {
	--top;
	return stack[top];
}
//client 
int main() {
	Push(10);
	Push(20);
	Push(30);
	
	int data;
	data = Pop();
	printf("%d\n", data);
	data = Pop();
	printf("%d\n", data);
	data = Pop();
	printf("%d\n", data);
	return 0;
}