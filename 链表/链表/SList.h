#pragma once

typedef int SLDataType;


typedef struct SLNode{
	SLDataType value;
	struct SLNode *next;
}SLNode;

typedef struct SList{
	SLNode *first;  //第一个节点的地址不是头结点
}SList;
//c初始化 


//销毁