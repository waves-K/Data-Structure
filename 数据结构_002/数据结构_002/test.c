#include "SeqList.h"
#include<stdlib.h>
#include<stdio.h>

/*
int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4); 
	PrintSeqList(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	PrintSeqList(&s);

	SeqListPushFront(&s, 0);
	PrintSeqList(&s);

	SeqListPopFront(&s);
	PrintSeqList(&s);

	SeqListDestroy(&s);

	system("pause");
	return 0;
}
*/

/*
int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	PrintSeqList(&s);

	SeqListInsert(&s, 3, 8);
	PrintSeqList(&s);

	SeqListErase(&s, 3);
	PrintSeqList(&s);

	SeqListDestroy(&s);

	system("pause");
	return 0;
}
*/

//#include<stdio.h>

//void Swap(int a, int b) {
//	printf("&a = %p, &b = %p\n", &a, &b);
//	int temp = a;
//	a = b;
//	b = temp;
//}




//void Swap(int* pa, int* pb) {
//	printf("&a = %p, &b = %p\n", pa, pb);
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//
//
//int main()
//{
//	int a = 20;
//	int b = 10;
//
//	printf("&a = %p, &b = %p\n", &a, &b);
//	Swap(&a, &b);
//	printf("%d %d\n", a, b);
//
//	system("pause");
//	return 0;
//}


int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 2);
	PrintSeqList(&s);

	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	printf("%d\n", SeqListFront(&s));
	printf("%d\n", SeqListBack(&s));

	SeqListRemove(&s, 5);
	PrintSeqList(&s);

	SeqListRemoveAll(&s, 2);
	PrintSeqList(&s);

	SeqListDestroy(&s);

	system("pause");
	return 0;
}