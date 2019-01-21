#pragma once	// ��仰��Ŀ����Ϊ�˷�ֹͷ�ļ����ظ�����
				// ��ֹͷ�ļ����ظ���������һ�ַ�ʽ��#defin  (��������)
				// �����ַ�ʽ������

// SeqList---�����Ŀռ���--->����

/*

typedef int DataType;	// ʹ�����Ͷ��� typedef �ؼ��֣���˳�������ȡһ������
#define MAXSIZE 100		// ʹ�ú궨����ʵ�ָ�����Ŀ���˳�������ЧԪ�صĸ���
// ��̬˳���
struct SeqList {	//	��װ��һ���ṹ��
	DataType array[MAXSIZE];	// �����洢˳����е���ЧԪ��
	int size;	// ��¼��ǰ˳�������ЧԪ�صĸ���
};

*/

// ��̬˳���

//ע�⣺ ���ڶ�̬˳������Ὺ�ٶ�̬�ռ䣬��̬�ռ�ʹ��������ͷţ����������ڴ�й©

typedef int DataType;

typedef struct SeqList {
	DataType* _array;	// ����˳����е���ЧԪ��
	int _capacity;		// �ռ��С capacity(����)
	int _size;			// ��¼˳�������ЧԪ�صĸ���
}SeqList, *PSeqList;

// typedef struct SeqList SeqList;   һ�����������д������ֱ���ٷ�װ�ṹ��ʱ�������

// Ҫʹ�ýṹ�嶨�����/ָ��ʱ����Ҫ������ǰ����һ�� struct

void SeqListInit(PSeqList ps); // ��ʼ��˳���

void SeqListDestroy(PSeqList ps);  // ����˳���

// data β��
void SeqListPushBack(PSeqList ps, DataType data);
// βɾ
void SeqListPopBack(PSeqList ps);

// data ͷ��
void SeqListPushFront(PSeqList ps, DataType data);
// ͷɾ
void SeqListPopFront(PSeqList ps);

// ��˳����е�����λ�ý��в���
void SeqListInsert(PSeqList ps, int pos, DataType data);	

// ����λ�õ�ɾ�������� pos ���λ�õ�Ԫ��ɾ����
void SeqListErase(PSeqList ps, int pos);	

// ��˳����в���ĳ��Ԫ�أ�����ҵ����ͷ��ظ�Ԫ�����ڵ�λ��
int SeqListFind(PSeqList ps, DataType data);

// �Ƴ����ȸ�һ�� data ��Ȼ���˳����е�һ����Ϊ data ��Ԫ���Ƴ���
void SeqListRemove(PSeqList ps, DataType data);

// ��˳�������������Ϊ data ��Ԫ��ȫ���Ƴ���
void SeqListRemoveAll(PSeqList ps, DataType data);

// ����˳�������ЧԪ�صĸ���
int SeqListSize(PSeqList ps);

// ����˳��������Ĵ�С
int SeqListCapacity(PSeqList ps);

// ���˳����Ƿ�Ϊ��
int SeqListEmpty(PSeqList ps);

// ��ȡ˳����еĵ�һ��Ԫ��
DataType SeqListFront(PSeqList ps);

// ��ȡ˳����е����һ��Ԫ��
DataType SeqListBack(PSeqList ps);

void PrintSeqList(PSeqList ps);  // ��ӡ����