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
void SListInit(SList* plist);
//销毁
SLNode * SLBuyNode(SLDataType value);
void  SListDestory(SList* plist);
//头插
void SListpushFront(SList* plist, SLDataType x);
//尾插
void SListpushAfter(SList* plist, SLDataType x);
//在pos后边插入
void SListIntsertAfter(SList* plist, SList* pos, SLDataType x);
//头删
void SListpopFront(SList* plist);
//尾删
void SListpopBack(SList* plist);
//将pos后面的加点删除
void SListEraseAfter(SList* plist, SList* pos);
//打印
void SListPrint(const SList* plist);
//查找
SLDataType* SListFind(SList* plist, SLDataType x);