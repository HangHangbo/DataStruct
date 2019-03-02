#pragma once

typedef struct Stack{

	int array[100];
	int top;
} stack;

//��ʼ��
void StackInit(Stack *stack){
	stack->top = 0;
}

//ѹջ
void StackPush(Stack*stack,int value){
	stack->array[stack->top] = value;
	stack->top++;
}

//��ջ����ջ��βɾ��
void StackPop(Stack*stack){
	stack->top--;
}

//����ջ��Ԫ��
int StackTop(const Stack *stack){
	return stack->array[stack->top - 1];
}

//�ж��Ƿ�Ϊ��
int StackEmpty(const Stack*stack){
	return stack->top == 0 ? 1 : 0;
}
//��ȡsize
int StackSize(const Stack*stack){
	return stack->top;
}