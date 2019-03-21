#pragma once 
 
#include <string.h>
// 静态顺序表：顺序表中数组的空间大小是固定的
// #define MAXSIZE 100      // 宏定义，顺序表中数组的空间大小
// typedef int DataType;   // typedef 类型定义关键字，也是相当于重命名
// 
// struct SeqList{
//    int array[10];    // 保存顺序表中有效元素
//    int size;         // 记录顺序表中有效元素的个数
// }
// 
// 
// 动态顺序表---重点考察

typedef int DataType;

typedef struct SeqList{
    DataType* _array;
    int _capacity;
    int _size;
}SeqList, *PSeqList;

// 初始化顺序表
void SeqListInit(PSeqList ps);

// 销毁顺序表
void SeqListDestory(PSeqList ps);

// 扩容
void _CheckCapacity(PSeqList ps);

// 尾插
void SeqListPushBack(PSeqList ps, DataType data);

// 尾删
void SeqListPopBack(PSeqList ps);

// 头插
void SeqListPushFront(PSeqList ps, DataType data);

// 头删
void SeqListPopFront(PSeqList ps);

// 任意位置插入
void SeqListInsert(PSeqList ps, int pos, DataType data);

// 任意位置删除
void SeqListErase(PSeqList ps, int pos);

// 查找
int SeqListFind(PSeqList ps, DataType data);

// 把顺序表中第一个值位 data 的元素移除
void SeqListRemove(PSeqList ps, DataType data);

// 把顺序表中值为 data 的元素全部移除
void SeqListRemoveAll(PSeqList ps, DataType data);

// 返回顺序表中所有元素的个数
int SeqListSize(PSeqList ps);

// 返回顺序表的容量
int SeqListCapacity(PSeqList ps);

// 判断顺序表是否为空
int SeqListEmpty(PSeqList ps);

// 获取顺序表第一个元素
DataType SeqListFront(PSeqList ps);

// 获取顺序表最后一个元素
DataType SeqListBack(PSeqList ps);

//////////////////////////////////////
// 这是一个测试专用的打印函数
void PrintSeqList(PSeqList ps);
