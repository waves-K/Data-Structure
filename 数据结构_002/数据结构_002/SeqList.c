#include "SeqList.h"
#include<malloc.h> // malloc �İ���ͷ�ļ���ʹ�� malloc ʱ��һ��Ҫ��������ͷ�ļ�
#include<assert.h>
#include<stdio.h>

void SeqListInit(PSeqList ps) // ��ʼ��˳����������Ա����
{
	// �ȼ������ĺϷ��ԣ�����ָ�룬һ��Ҫ�����пմ���
	// ���ַ�ʽ

	//if (NULL == ps)	// ��ʽ1��ֻҪ NULL == ps ��������ֱ�ӷ��� 
	//	return;

	assert(ps);	// ��ʽ2��assert ���������Ƿ�����ģ��������Ƿ���assert �ͻᴥ��
				//		  assert ���������ֵĳ������ǳ����ж�

	// �㷨����
	// Ĭ�������˳����п��Դ��3��Ԫ��
	ps->_array = (DataType*)malloc(sizeof(DataType) * 3); // ��ʼ��˳����е�ָ��
	// ���� malloc ����Ŀռ䣺
	//		1. �������ɹ����ͷ��ؿռ���׵�ַ
	//		2. �������ʧ�ܣ��ͷ���һ����
	// ������ʹ�� malloc ����ռ�ʱ����ö�������һ����⣬�����Ƿ�����ռ�ɹ���
	//�������ռ�ʧ�ܣ��� NULL == ps->_array
	if (NULL == ps->_array) {
		assert(0);		// ���ԣ����� assert ����һ�����Ժ꣬��ֻ�� debug �汾�²�������
						// ��һ��������Ƿ��������õ��� Release �汾

	    //return;   ��ʵ��������� return ֱ�ӷ��������� assert ����
		// ���ǣ�ֱ�ӷ�����һ�����õĵط������ֱ�ӷ��صĻ������Ͳ�֪�����˳�������û�д�����
	}

	// �����ߵ�����˵������ռ�ɹ�������������Ҫ���� ���� �� ʵ����ЧԪ�� �ĸ�����
	ps->_capacity = 3; // ����������С
	ps->_size = 0; // ��ʾʵ��˳�����û����ЧԪ��
}


void SeqListDestroy(PSeqList ps) {  // ����˳���
	assert(ps);
	if (ps->_array) {
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

void _CheckCapacity(PSeqList ps) {
	assert(ps);
	if (ps->_size == ps->_capacity) {

		// �����¿ռ�
		int newCapacity = ps->_capacity * 2;
		DataType* pTemp = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (NULL == pTemp) {
			assert(0);
			return;
		}

		// ����Ԫ��
		memcpy(pTemp, ps->_array, ps->_size * sizeof(DataType));	
		// memcpy ����ʱ��������ֽ���������Ԫ�ء��������¿ռ���Ҫ����ÿ��Ԫ�صĴ�С

		// �ͷžɿռ�
		free(ps->_array);
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

// data β��
void SeqListPushBack(PSeqList ps, DataType data) {
	/*
	assert(ps);
	// ˳�����������
	_CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
	*/

	assert(ps);
	SeqListInsert(ps, ps->_size, data);
}
// βɾ
void SeqListPopBack(PSeqList ps) {
	/*
	assert(ps);
	if (0 == ps->_size)
		return;

	ps->_size--;
	*/

	assert(ps);
	SeqListErase(ps, ps->_size - 1);
}

// data ͷ��
void SeqListPushFront(PSeqList ps, DataType data) {
	assert(ps);

	// ���ռ��Ƿ����
	_CheckCapacity(ps);

	// ��˳����е���ЧԪ������������һ��λ�ã��Ӻ���ǰ��
	// ��ʽһ��i ����ĺ�����Ҫ����Ԫ�ص��±�
	for (int i = ps->_size - 1; i >= 0; --i) {
		ps->_array[i + 1] = ps->_array[i];
	}

	/*
	//��ʽ����i ����ĺ�����Ҫ���Ƶ�λ�õ��±�
	for (int i = ps->_size - 1; i > 0; --i) {
		ps->_array[i] = ps->_array[i - 1];
	}
	*/

	// ����Ԫ��
	ps->_array[0] = data;
	ps->_size++;
}

// ͷɾ
void SeqListPopFront(PSeqList ps) {
	assert(ps);
	if (0 == ps->_size)
		return;

	// ��ʽһ��
	// i��Ԫ�ر����Ƶ�λ�õ��±�
	for (int i = 0; i < ps->_size - 1; ++i) {
		ps->_array[i] = ps->_array[i + 1];
	}

	ps->_size--;
}

// ��˳����е�����λ�ý��в���
void SeqListInsert(PSeqList ps, int pos, DataType data) {
	assert(ps);
	if (pos < 0 || pos > ps->_size) {
		printf("����Ԫ��λ�÷Ƿ�\n");
		return;
	}

	// �������
	_CheckCapacity(ps);
	
	for (int i = ps->_size - 1; i >= pos; --i) {
		ps->_array[i + 1] = ps->_array[i];
	}

	ps->_array[pos] = data;
	ps->_size++;
}

// ����λ�õ�ɾ��
void SeqListErase(PSeqList ps, int pos) {
	assert(ps);
	if (pos < 0 || pos >= ps->_size) {
		printf("ɾ����λ��ֵ�Ƿ�\n");
		return;
	}

	for (int i = pos; i < ps->_size - 1; ++i) {
		ps->_array[i] = ps->_array[i + 1];
	}

	ps->_size--;
}


// ��˳����в���ĳ��Ԫ�أ�����ҵ����ͷ��ظ�Ԫ�����ڵ�λ��
int SeqListFind(PSeqList ps, DataType data) {
	assert(ps);
	for (int i = 0; i < ps->_size; ++i) {
		if (ps->_array[i] == data)
			return i;
	}

	return -1;
}


// �Ƴ����ȸ�һ�� data ��Ȼ���˳����е�һ��ֵΪ data ��Ԫ���Ƴ���
void SeqListRemove(PSeqList ps, DataType data) {
	SeqListErase(ps, SeqListFind(ps, data));
}

// ��˳���������ֵΪ data ��Ԫ��ȫ���Ƴ���
void SeqListRemoveAll(PSeqList ps, DataType data) {
	/*
	// 1. 
	// ʱ�临�Ӷ� O(n*m)
	int pos = -1;
	while (-1 != (pos = SeqListFind(ps, data))) {
		SeqListErase(ps, pos);
	}
	*/

	/*
	// 2. 
	int i = 0;
	for (; i < ps->_size; ++i) {
		if (ps->_array[i] == data) {
			SeqListErase(ps, i);
		}
	}
	*/

	// 3. ���������ռ䣬��˳��������в����� data ��Ԫ��ȫ�������������ռ���
	//	  ���� data ��Ԫ�ز����а��ƣ�Ȼ���ٽ������ռ��е�����Ԫ�ذ����ԭ�ռ䣬�ٽ� _size �ı�
	// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)

	// 4.
	// ʱ�临�Ӷ� O(n), �ռ临�Ӷ� O(1)
	int count = 0;	// ��¼��ɾ��Ԫ�صĸ���
	for (int i = 0; i < ps->_size; ++i) {
		if (ps->_array[i] == data) {
			count++;
		}
		else {
			ps->_array[i - count] = ps->_array[i];
		}
	}
	ps->_size -= count;
}

// ����˳�������ЧԪ�صĸ���
int SeqListSize(PSeqList ps) {
	assert(ps);
	return ps->_size;
}

// ����˳��������Ĵ�С
int SeqListCapacity(PSeqList ps) {
	assert(ps);
	return ps->_capacity;
}

// ���˳����Ƿ�Ϊ��
int SeqListEmpty(PSeqList ps) {
	assert(ps);
	return 0 == ps->_size;
}

// ��ȡ˳����еĵ�һ��Ԫ��
DataType SeqListFront(PSeqList ps) {
	assert(ps);
	return ps->_array[0];
}

// ��ȡ˳����е����һ��Ԫ��
DataType SeqListBack(PSeqList ps) {
	assert(ps);
	return ps->_array[ps->_size - 1];
}


/////////////////////////////////////////////////////
// test
void PrintSeqList(PSeqList ps) {
	assert(ps);
	for (int i = 0; i < ps->_size; ++i) {
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}