#include"SList.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

//c��ʼ�� 
void SListInit(SList* plist)
{
	assert(plist != NULL);
	plist->first = NULL;
}
//����
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
//�����½ڵ�
SLNode * SLBuyNode(SLDataType value)
{
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	node->value = value;
	node->next = NULL;
	return node;
}
//ͷ��
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
//β��
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
//��pos��߲���
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
//ͷɾ
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
//βɾ
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
//��pos����ļӵ�ɾ��
void SListEraseAfter(SList* plist, SList* pos)
{

}
////����
//SLDataType* SListFind(SList* plist, SLDataType x)
//��ӡ
void SListPrint(const SList* plist)
{
	for (SLNode *cur = plist->first; cur != NULL; cur = cur->next)
	{
		printf("%d->", cur->value);
		system("pause");
	}
	printf("NULL");
}