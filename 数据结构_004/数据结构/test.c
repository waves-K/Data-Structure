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
	// �����Ҫͨ���βθı�ʵ�ε����ݣ����봫��ʵ�εĵ�ַ
	// ʵ�Σ�ֵ
	// ���Σ�ֵ�õ�ַ
	Swap(&a, &b);

	int* pa = &a;
	int* pb = &b;
	Swap(pa, pb);
	printf("%d, %d\n", a, b);

	// ʵ�Σ�ָ��
	// ���Σ�ָ��ĵ�ַ---> (����)
	// �ں������У���Ҫͨ���βθı��ⲿָ���ָ�򣬱��봫�ݶ���ָ��
	SwapPtr(&pa, &pb);
	printf("%d, %d\n", a, b);
	//TestDList();
	system("pause");
	return 0;
}
*/