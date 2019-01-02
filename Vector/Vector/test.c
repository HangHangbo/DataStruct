
//顺序表的头插
struct Vector{
	int array[100];
	int size;
};
void VectorPushFront(struct vector *vector, int val);
{
	assert(vector);
	assert(vector->arrary);
	for (int i = vector->size, i > 0; i--)
	{
		vector->array[i] = vector->[i - 1];
	}
	vector->array[0] = val;
	vector->size++;
}
//单向+无头+不循环 链表的尾删
struct ListNode {
	int val;
	struct ListNode *next;
};

struct List {
	struct ListNode *head;
};

void ListPopBack(struct List*list, int size)
{
	if (list->head== NULL)
	{
		return;
	}
	struct ListNode *cur =list-> head;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

//删除链表的所有val的值

void ListRemoveAll(struct List*list, int value)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = list->head;
	while (cur != NULL)
	{
		if (cur->val == value)
		{
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
//冒泡排序
void swap(int  a, int b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[i]>array[i + 1])
			{
				swap(array[i], array[i + 1]);
			}
		}
	}
}
//复杂链表的复制
struct RListNode{
	int val;
	struct RListNode *random;
	struct RListNode *next;
};
struct RListNode *RListCopy(struct RListNode *head);
{

}