#include "DList.h"

int main()
{
	TestDList();
	system("pause");
	return 0;
}


/*
void Swap(int* pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void SwapPtr(int** ppa, int** ppb) {
	int* pTemp = *ppa;
	*ppa = *ppb;
	*ppb = pTemp;
}


int main()
{
	int a = 10;
	int b = 20;

	printf("%d, %d\n", a, b);
	// 如果想要通过形参改变实参的内容，必须传递实参的地址
	// 实参：值
	// 传参：值得地址
	Swap(&a, &b);

	int* pa = &a;
	int* pb = &b;
	Swap(pa, pb);
	printf("%d, %d\n", a, b);

	// 实参：指针
	// 传参：指针的地址---> (二级)
	// 在函数体中，想要通过形参改变外部指针的指向，必须传递二级指针
	SwapPtr(&pa, &pb);
	printf("%d, %d\n", a, b);
	//TestDList();
	system("pause");
	return 0;
}
*/