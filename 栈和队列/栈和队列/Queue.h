#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Node{
	int value;
	struct Node*next;
}Node;
//头删+尾插
typedef struct Queue{
	Node *front;   //链表的第一个节点
	Node*rear;     //链表的最后一个节点
	int size;      //数据个数
}Queue;

//初始化
void QueueInit(Queue*queue){
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}
//销毁
void QueueDestory(Queue*queue){
	Node *node, *next;
	for (node = queue->front; node != NULL; node = next){
		next = node->next;
		free(node);
	}
	queue->front = queue->rear = NULL;
	queue -> size = 0;
}

//Push,队尾插入，即链表尾插
void QueuePush(Queue*queue, int val){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = val;
	node->next = NULL;
	if (queue->rear!=NULL){
		queue->rear->next = node;
		queue->rear = node;
	}
	else{
		queue->front = queue->rear = node;
	}
}
//Pop,队首队列，链表的头删
void QueuePop(Queue*queue){
	assert(queue->size > 0);
	queue->size--;
	Node*cur = queue->front;
	queue->front = queue->front->next;
	free(cur);
	if (queue->front == NULL){
		queue->rear = NULL;
	}
}
//Front  返回队首元素
int QueueFront(Queue*queue){
	return queue->front->value;

}
//Rear 返回队尾元素
int QueueRear(Queue*queue){
	return queue->rear->value;
}
//Empty 是否为空
int QueueEmpty(Queue*queue){
	return queue->size == 0 ? 1 : 0;
}
//Size
int QueueSize(Queue*queue){
	return queue->size;
}
