#include"SList.h"
#include<stdio.h>
#include<assert.h>
void SListTest()
{

	SList plist;
	SListInit(&plist);
	assert(plist.first == NULL);

	SListpushFront(&plist, 1);
	SListpushFront(&plist, 2);
	SListpushFront(&plist, 3);
	//3 2 1
	SListpushAfter(&plist, 13);
	SListpushAfter(&plist, 12);
	SListpushAfter(&plist, 11);
	// 3 2 1 13 12 11
	SListpopFront(&plist);
	SListpopFront(&plist);
	SListpopFront(&plist);
	//13 12 11
	SListpopBack(&plist);
	SListpopBack(&plist);
//13
	SListPrint(&plist);
}

void main()
{
	SList plist;
	 SListTest();

}