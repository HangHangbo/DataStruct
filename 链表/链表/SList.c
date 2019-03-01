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
void SListDestory(SList* plist)
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
void SListInsertAfter(SList* plist, SLNode* pos, SLDataType x)
{
	SLNode *node = SLBuyNode(x);
	node->next = pos->next;
	pos->next = node;
	/*assert(plist);
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
	cur->next = tmp;*/
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
void SListEraseAfter(SList* plist, SLNode* pos)
{
	SLNode*next = pos->next;
	pos->next = next->next;
	free(next);
	/*assert(plist);
	for (SLNode*cur = plist->first; cur->next != NULL; cur = cur->next){
		if (cur == pos){
			SLNode*tmp = cur->next;
			cur->next = cur->next->next;
			free(tmp);
		}
	}
*/
}
////����
SLNode* SListFind(const SList *plist, SLDataType value)
{

	for (SLNode *cur = plist->first; cur->next != NULL; cur = cur->next){
		if (cur->value == value)
			return cur;
	}
	return NULL;
}
//��ӡ
void SListPrint(const SList* plist)
{
	for (SLNode *cur = plist->first; cur != NULL; cur = cur->next)
	{
		printf("%d->", cur->value);
	}
	printf("NULL");
	system("pause");
}
//��
void SLUpdate(SLNode *node, SLDataType value){
	node->value = value;
}

//��posǰ����
void SLInsertBefore(SList*plist, SLNode*pos, SLDataType value){
	assert(plist);
	assert(plist->first->next);
	SLNode*tmp = plist->first;
	while (tmp->next != pos){
		tmp = tmp->next;
	}
	SLNode*cur = SLBuyNode(value);
	tmp->next = cur;
	cur->next = pos;
	//SLNode*cur=SLBuyNode(value);
	//for (SLNode*tmp = plist->first; tmp->next != NULL; tmp = tmp->next){
	//	if (tmp->next == pos){
	//		tmp->next = cur;
	//		cur->next = pos;
	//		return;
	//	}
	//}
}