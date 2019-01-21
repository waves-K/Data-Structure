#pragma once	// 这句话的目的是为了防止头文件被重复包含
				// 防止头文件被重复包含的另一种方式：#defin  (条件编译)
				// 这两种方式的区别？

// SeqList---连续的空间中--->数组

/*

typedef int DataType;	// 使用类型定义 typedef 关键字，给顺序表类型取一个别名
#define MAXSIZE 100		// 使用宏定义来实现更方便的控制顺序表中有效元素的个数
// 静态顺序表：
struct SeqList {	//	封装成一个结构体
	DataType array[MAXSIZE];	// 用来存储顺序表中的有效元素
	int size;	// 记录当前顺序表中有效元素的个数
};

*/

// 动态顺序表

//注意： 对于动态顺序表，他会开辟动态空间，动态空间使用完必须释放，否则会造成内存泄漏

typedef int DataType;

typedef struct SeqList {
	DataType* _array;	// 保存顺序表中的有效元素
	int _capacity;		// 空间大小 capacity(容量)
	int _size;			// 记录顺序表中有效元素的个数
}SeqList, *PSeqList;

// typedef struct SeqList SeqList;   一般情况不这样写，而是直接再封装结构体时就起别名

// 要使用结构体定义变量/指针时，需要再类型前加上一个 struct

void SeqListInit(PSeqList ps); // 初始化顺序表

void SeqListDestroy(PSeqList ps);  // 销毁顺序表

// data 尾插
void SeqListPushBack(PSeqList ps, DataType data);
// 尾删
void SeqListPopBack(PSeqList ps);

// data 头插
void SeqListPushFront(PSeqList ps, DataType data);
// 头删
void SeqListPopFront(PSeqList ps);

// 在顺序表中的任意位置进行插入
void SeqListInsert(PSeqList ps, int pos, DataType data);	

// 任意位置的删除，即把 pos 这个位置的元素删除掉
void SeqListErase(PSeqList ps, int pos);	

// 在顺序表中查找某个元素，如果找到，就返回该元素所在的位置
int SeqListFind(PSeqList ps, DataType data);

// 移除，先给一个 data ，然后把顺序表中第一个成为 data 的元素移除掉
void SeqListRemove(PSeqList ps, DataType data);

// 把顺序表中所有设置为 data 的元素全部移除掉
void SeqListRemoveAll(PSeqList ps, DataType data);

// 返回顺序表中有效元素的个数
int SeqListSize(PSeqList ps);

// 返回顺序表容量的大小
int SeqListCapacity(PSeqList ps);

// 检测顺序表是否不为空
int SeqListEmpty(PSeqList ps);

// 获取顺序表中的第一个元素
DataType SeqListFront(PSeqList ps);

// 获取顺序表中的最后一个元素
DataType SeqListBack(PSeqList ps);

void PrintSeqList(PSeqList ps);  // 打印函数