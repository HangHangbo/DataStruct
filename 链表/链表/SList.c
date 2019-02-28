#include"SList.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

//c初始化 
void SListInit(SList* plist)
{
	assert(plist != NULL);
	plist->first = NULL;
}
//销毁
void SListInit(SList* plist)
{
	SLNode*next;
	SLNode *cur = plist->first;
	while (cur != NULL){
		next = cur->next;
		free(cur);
		cur = next;
	}
	plist->first = NULL;
}
//申请新节点
SLNode * SLBuyNode(SLDataType value)
{
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	node->value = value;
	node->next = NULL;
	return node;
}
//头插
void SListpushFront(SList* plist, SLDataType x)
{
	assert(plist != NULL);
	SLNode *node=SLBuyNode(x);
	node->next = plist->first;
	plist->first = node;
	//if (plist->first == NULL)
	//{
	//	plist->first = newhead;
	//	newhead->next = NULL;
	//}
	//else{
	//	newhead->next = plist->first;
	//	plist->first = newhead;
	//}
	//node->next = plist->first;
	//plist->first = node;
}
//尾插
void SListpushAfter(SList* plist, SLDataType x)
{
	assert(plist != NULL);
	if (plist->first == NULL){
		SListpushFront(plist, x);
		return;
	}
	SLNode *cur;
	for (cur = plist->first; cur->next != NULL; cur = cur->next){
	}
	SLNode *node = SLBuyNode(x);
	cur->next = node;
	/*SLNode* cur = (SLNode*)malloc(sizeof(SLNode));
	SLNode* tmp;
	if (plist->first == NULL)
	{
		plist->first = cur;
		return;
	}
	tmp = plist->first;
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = cur;
	cur->next = NULL;*/

}
//在pos后边插入
void SListIntsertAfter(SList* plist, SLNode* pos, SLDataType x)
{
	assert(plist);
	SLNode*cur;
	SLNode*tmp;
	cur = plist->first;
	tmp = (SLNode*)malloc(sizeof(SLNode));
	if (cur==pos)
	{
		cur->next = tmp;
		tmp->next = NULL;
		return;
	}
	while (cur != pos){
		cur = cur->next;
	}
	tmp->next = cur->next;
	cur->next = tmp;
}
//头删
void SListpopFront(SList* plist)
{
	assert(plist);
	assert(plist->first);
	/*if (plist->first->next == NULL);
	{
		plist->first = NULL;
		return;
	}
		SLNode* cur=plist->first;
		plist->first = cur->next;
		free(cur);*/
	SLNode* cur = plist->first;
	plist->first = cur->next;
	free(cur);
}
//尾删
void SListpopBack(SList* plist)
{
	assert(plist);
	SLNode* cur = plist->first;
	if (cur->next == NULL)
	{
		SListpopFront(plist);
		return;
	}
	while (cur->next->next != NULL){
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
	/*assert(plist);
	SLNode* cur = plist->first;
	SLNode* tmp;
	if (cur->next == NULL)
	{
		cur = NULL;
		free(cur);
		return;
	}
	while (cur->next->next != NULL){
		cur = cur->next;
	}
	tmp = cur->next;
	tmp = NULL;
	free(tmp);
	cur->next = NULL;*/

}
//将pos后面的加点删除
void SListEraseAfter(SList* plist, SList* pos)
{

}
////查找
//SLDataType* SListFind(SList* plist, SLDataType x)
//打印
void SListPrint(const SList* plist)
{
	for (SLNode *cur = plist->first; cur != NULL; cur = cur->next)
	{
		printf("%d->", cur->value);
		system("pause");
	}
	printf("NULL");
}