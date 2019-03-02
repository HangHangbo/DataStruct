#pragma once

typedef struct Stack{

	int array[100];
	int top;
} stack;

//³õÊ¼»¯
void StackInit(Stack *stack){
	stack->top = 0;
}

//Ñ¹Õ»
void StackPush(Stack*stack,int value){
	stack->array[stack->top] = value;
	stack->top++;
}

//³öÕ»£¬µ¯Õ»£¨Î²É¾£©
void StackPop(Stack*stack){
	stack->top--;
}

//·µ»ØÕ»¶¥ÔªËØ
int StackTop(const Stack *stack){
	return stack->array[stack->top - 1];
}

//ÅÐ¶ÏÊÇ·ñÎª¿Õ
int StackEmpty(const Stack*stack){
	return stack->top == 0 ? 1 : 0;
}
//»ñÈ¡size
int StackSize(const Stack*stack){
	return stack->top;
}