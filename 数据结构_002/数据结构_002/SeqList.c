#include "SeqList.h"
#include<malloc.h> // malloc 的包含头文件，使用 malloc 时就一定要包含它的头文件
#include<assert.h>
#include<stdio.h>

void SeqListInit(PSeqList ps) // 初始化顺序表的三个成员变量
{
	// 先检测参数的合法性：对于指针，一定要进行判空处理
	// 两种方式

	//if (NULL == ps)	// 方式1：只要 NULL == ps 成立，就直接返回 
	//	return;

	assert(ps);	// 方式2：assert 是用来检测非法情况的，如果代码非法，assert 就会触发
				//		  assert 触发所表现的场景就是程序中断

	// 算法功能
	// 默认情况：顺序表中可以存放3个元素
	ps->_array = (DataType*)malloc(sizeof(DataType) * 3); // 初始化顺序表中的指针
	// 对于 malloc 申请的空间：
	//		1. 如果申请成功，就返回空间的首地址
	//		2. 如果申请失败，就返回一个宏
	// 所以在使用 malloc 申请空间时，最好对他进行一个检测，看看是否申请空间成功。
	//如果申请空间失败，则 NULL == ps->_array
	if (NULL == ps->_array) {
		assert(0);		// 断言，对于 assert 他是一个调试宏，他只在 debug 版本下才起作用
						// 而一般情况我们发布工程用的是 Release 版本

	    //return;   其实这里可以用 return 直接返回来代替 assert 断言
		// 但是，直接返回有一个不好的地方：如果直接返回的话将来就不知道这个顺序表到底有没有创建好
	}

	// 代码走到这里说明申请空间成功，接下来就需要更改 容量 和 实际有效元素 的个数了
	ps->_capacity = 3; // 更改容量大小
	ps->_size = 0; // 表示实际顺序表中没有有效元素
}


void SeqListDestroy(PSeqList ps) {  // 销毁顺序表
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

		// 申请新空间
		int newCapacity = ps->_capacity * 2;
		DataType* pTemp = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (NULL == pTemp) {
			assert(0);
			return;
		}

		// 拷贝元素
		memcpy(pTemp, ps->_array, ps->_size * sizeof(DataType));	
		// memcpy 拷贝时，搬的是字节数，不是元素。所以再新空间后边要乘以每个元素的大小

		// 释放旧空间
		free(ps->_array);
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

// data 尾插
void SeqListPushBack(PSeqList ps, DataType data) {
	/*
	assert(ps);
	// 顺序表满，扩容
	_CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
	*/

	assert(ps);
	SeqListInsert(ps, ps->_size, data);
}
// 尾删
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

// data 头插
void SeqListPushFront(PSeqList ps, DataType data) {
	assert(ps);

	// 检测空间是否充足
	_CheckCapacity(ps);

	// 将顺序表中的有效元素整体向后搬移一个位置：从后往前搬
	// 方式一：i 代表的含义是要搬移元素的下标
	for (int i = ps->_size - 1; i >= 0; --i) {
		ps->_array[i + 1] = ps->_array[i];
	}

	/*
	//方式二：i 代表的含义是要搬移到位置的下标
	for (int i = ps->_size - 1; i > 0; --i) {
		ps->_array[i] = ps->_array[i - 1];
	}
	*/

	// 插入元素
	ps->_array[0] = data;
	ps->_size++;
}

// 头删
void SeqListPopFront(PSeqList ps) {
	assert(ps);
	if (0 == ps->_size)
		return;

	// 方式一：
	// i：元素被搬移到位置的下标
	for (int i = 0; i < ps->_size - 1; ++i) {
		ps->_array[i] = ps->_array[i + 1];
	}

	ps->_size--;
}

// 在顺序表中的任意位置进行插入
void SeqListInsert(PSeqList ps, int pos, DataType data) {
	assert(ps);
	if (pos < 0 || pos > ps->_size) {
		printf("插入元素位置非法\n");
		return;
	}

	// 检测容量
	_CheckCapacity(ps);
	
	for (int i = ps->_size - 1; i >= pos; --i) {
		ps->_array[i + 1] = ps->_array[i];
	}

	ps->_array[pos] = data;
	ps->_size++;
}

// 任意位置的删除
void SeqListErase(PSeqList ps, int pos) {
	assert(ps);
	if (pos < 0 || pos >= ps->_size) {
		printf("删除的位置值非法\n");
		return;
	}

	for (int i = pos; i < ps->_size - 1; ++i) {
		ps->_array[i] = ps->_array[i + 1];
	}

	ps->_size--;
}


// 在顺序表中查找某个元素，如果找到，就返回该元素所在的位置
int SeqListFind(PSeqList ps, DataType data) {
	assert(ps);
	for (int i = 0; i < ps->_size; ++i) {
		if (ps->_array[i] == data)
			return i;
	}

	return -1;
}


// 移除，先给一个 data ，然后把顺序表中第一个值为 data 的元素移除掉
void SeqListRemove(PSeqList ps, DataType data) {
	SeqListErase(ps, SeqListFind(ps, data));
}

// 把顺序表中所有值为 data 的元素全部移除掉
void SeqListRemoveAll(PSeqList ps, DataType data) {
	/*
	// 1. 
	// 时间复杂度 O(n*m)
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

	// 3. 借助辅助空间，将顺序表中所有不等于 data 的元素全部搬移至辅助空间中
	//	  等于 data 的元素不进行搬移，然后再将辅助空间中的所有元素搬回至原空间，再将 _size 改变
	// 时间复杂度 O(n)，空间复杂度 O(n)

	// 4.
	// 时间复杂度 O(n), 空间复杂度 O(1)
	int count = 0;	// 记录待删除元素的个数
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

// 返回顺序表中有效元素的个数
int SeqListSize(PSeqList ps) {
	assert(ps);
	return ps->_size;
}

// 返回顺序表容量的大小
int SeqListCapacity(PSeqList ps) {
	assert(ps);
	return ps->_capacity;
}

// 检测顺序表是否不为空
int SeqListEmpty(PSeqList ps) {
	assert(ps);
	return 0 == ps->_size;
}

// 获取顺序表中的第一个元素
DataType SeqListFront(PSeqList ps) {
	assert(ps);
	return ps->_array[0];
}

// 获取顺序表中的最后一个元素
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