#pragma once

typedef int SLDataType;


typedef struct SLNode{
	SLDataType value;
	struct SLNode *next;
}SLNode;

typedef struct SList{
	SLNode *first;  //��һ���ڵ�ĵ�ַ����ͷ���
}SList;
//c��ʼ�� 
void SListInit(SList* plist);
//�����µĽڵ�
SLNode * SLBuyNode(SLDataType value);
//����
void  SListDestory(SList* plist);
//ͷ��
void SListpushFront(SList* plist, SLDataType x);
//β��
void SListpushAfter(SList* plist, SLDataType x);
//��pos��߲���
void SListInsertAfter(SList* plist, SLNode* pos, SLDataType x);
//ͷɾ
void SListpopFront(SList* plist);
//βɾ
void SListpopBack(SList* plist);
//��pos����ļӵ�ɾ��
void SListEraseAfter(SList* plist, SLNode* pos);
//��ӡ
void SListPrint(const SList* plist);
//����
SLNode* SListFind(const SList* plist, SLDataType x);
//��
void SLUpdate(SLNode *node, SLDataType value);
//��posǰ����
void SLInserBefore(SList*plist, SLNode*pos, SLDataType value);
