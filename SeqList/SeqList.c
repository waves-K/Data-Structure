#include"SeqList.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

// 顺序表初始化
void SeqListInit(PSeqList ps){
    assert(ps);
    ps->_array = (DataType*)malloc(sizeof(DataType) * 10);

    if(NULL == ps->_array){
        assert(0);
        return;
    }

    ps->_capacity = 10;
    ps->_size = 0;
}

// 扩容
void _ChackCapacity(PSeqList ps){
    // 1. 开辟新空间
    // 2. 拷贝元素
    // 3. 释放旧空间
    assert(ps);

    // 检测容量,相等则满，进行扩容
    if(ps->_size == ps->_capacity){
        // 扩容规则：翻倍
        int newcapacity = ps->_capacity * 2;
        DataType* PTemp = (DataType*)malloc(sizeof(DataType)*newcapacity);
        if(NULL == PTemp){
            assert(0);
            return;
        }
        // 拷贝元素
        memcpy(PTemp, ps->_array, ps->_size*sizeof(DataType));
        // 释放旧空间
        free(ps->_array);
        ps->_array = PTemp;
        ps->_capacity = newcapacity;
    }
}

// 尾插
void SeqListPushBack(PSeqList ps, DataType data){
    assert(ps);
    ps->_array[ps->_size] = data;
    ps->_size++;

    // 顺序表满，扩容
    // _CheckCapacity(ps);
}

// 尾删
void SeqListPopBack(PSeqList ps){
    assert(ps);
    if(0 == ps->_size)
        return;
    ps->_size--;
}

// 头插
void SeqListPushFront(PSeqList ps, DataType data){
    assert(ps);
    
    // 检测容量
    // _CheckCapacity(ps);
    
    // 1. 将顺序表中所有元素向后搬移
    // 这里 i 代表要搬移到的位置
    for(int i = ps->_size; i > 0 ; --i){
        ps->_array[i] = ps->_array[i - 1];
    }
    // 2. 在头部插入 data 元素
    ps->_array[0] = data;
    ps->_size++;
}

// 头删
void SeqListPopFront(PSeqList ps){
    assert(ps);
    
    // 将顺序表中的所有元素向前搬移一个位置
    // 这里的 i 代表被搬移元素的位置
    for(int i = 1; i <= ps->_size - 1; ++i){
        ps->_array[i - 1] = ps->_array[i];
    }
    ps->_size--;
}

// 任意位置插入
void SeqListInsert(PSeqList ps, int pos, DataType data){
    assert(ps);

    // 判断插入位置是否合法
    if(pos < 0 | pos > ps->_size){
        printf("插入元素位置非法\n");
        return ;
    }

    // 插入元素
    // 检测容量
   //  _CheckCapacity(ps);
    
    for(int i = ps->_size; i > pos; --i){
        ps->_array[i] = ps->_array[i - 1];
    }
    ps->_array[pos] = data;
    ps->_size++;
}

// 任意位置删除
void SeqListErase(PSeqList ps, int pos){
    assert(ps);

    // 检测删除位置是否合法
    if(pos < 0 | pos >= ps->_size){
        printf("删除元素位置非法\n");
        return;
    }
    
    // 这里 i 代表被搬移到元素的位置
    for(int i = pos; i < ps->_size - 1; ++i){
        ps->_array[i] = ps->_array[i + 1];
    }
    ps->_size--;
}

// 查找
int SeqListFind(PSeqList ps, DataType data){
    assert(ps);
    
    for(int i = 0; i < ps->_size; ++i){
        if(ps->_array[i] == data){
            return i;
        }   
    }
    return -1;
}

// 移除顺序表中第一个值为 data 的元素
void SeqListRemove(PSeqList ps, DataType data){
    assert(ps);

    int i = 0;
    for(i = 0; i < ps->_size; ++i){
        if(ps->_array[i] == data){
            break;
        }
    }
    SeqListErase(ps, i);
}
// 顺序表销毁
void SeqListDestory(PSeqList ps){
    assert(ps);
    if(ps->_array){
        free(ps->_array);
        ps->_array = NULL;
        ps->_capacity = 0;
        ps->_size--;
    }
}

// 移除顺序表中所有值为 data 的元素
void SeqListRomoveAll(PSeqList ps, DataType data){
    // 时间复杂度: O(n^2)
    int pos;
    while((pos = SeqListFind(ps,data)) != -1){
        SeqListErase(ps, pos);
    }
}

// 返回顺序表中所有元素的个数
int SeqListSize(PSeqList ps){
    assert(ps);
    return ps->_size;
}

// 返回顺序表的容量
int SeqListCapacity(PSeqList ps){
    assert(ps);
    return ps->_capacity;
}

// 判断顺序表是否为空
int SeqListEmpty(PSeqList ps){
    assert(ps);
    return 0 == ps->_size;
}

// 获取顺序表中的第一个元素
DataType SeqListFront(PSeqList ps){
    return ps->_array[0];
}

// 获取顺序表中最后一个元素
DataType SeqListBack(PSeqList ps){
    return ps->_array[ps->_size-1];
}




//////////////////////////////////////
// 这是一个纯测试函数
void PrintSeqList(PSeqList ps){
    assert(ps);
    // 这里的 i 代表的是有效元素的下标
    for(int i = 0; i <= ps->_size - 1;++i){
        printf("%d ", ps->_array[i]);
    }
    printf("\n");
}
