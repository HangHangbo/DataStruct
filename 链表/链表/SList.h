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
//创建新的节点
SLNode * SLBuyNode(SLDataType value);
//销毁
void  SListDestory(SList* plist);
//头插
void SListpushFront(SList* plist, SLDataType x);
//尾插
void SListpushAfter(SList* plist, SLDataType x);
//在pos后边插入
void SListInsertAfter(SList* plist, SLNode* pos, SLDataType x);
//头删
void SListpopFront(SList* plist);
//尾删
void SListpopBack(SList* plist);
//将pos后面的加点删除
void SListEraseAfter(SList* plist, SLNode* pos);
//打印
void SListPrint(const SList* plist);
//查找
SLNode* SListFind(const SList* plist, SLDataType x);
//改
void SLUpdate(SLNode *node, SLDataType value);
//在pos前插入
void SLInserBefore(SList*plist, SLNode*pos, SLDataType value);
