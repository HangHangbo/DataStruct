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


//����