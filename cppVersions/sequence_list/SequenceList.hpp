#ifndef _SEQUENCELIST_H_
#define _SEQUENCELIST_H_ 

#include <iostream>
#include <cassert>
using namespace std;


#if 0
// 静态顺序表模板类
#define MAXSIZE 100

template<typename T>
class Static{
public:
    Static()
        : _size(0)
    {}

    Static(const T data[], size_t size) {
        if (size > MAXSIZE) 
            return;

        for (size_t i = 0; i < size; ++i) {
            array[i] = data[i];
        }

        _size = size;
    }
private:
    T array[MAXSIZE];
    size_t _size;
};
#endif


// 动态顺序表模板类的实现
template<typename T>
class SeqList {
public:
    // 构造函数
    SeqList(size_t capacity = 10);
    // 拷贝构造函数
    SeqList(const SeqList <T>& s);
    // 赋值运算符的重载
    SeqList<T>& operator=(SeqList<T> s);
    // 小标运算符重载
    T& operator[](size_t pos) {
        assert(pos < _size);
        return _pData[pos];
    }
    // 析构函数
    ~SeqList(); 
    // 检查容量是否已满，若已满则扩容，否则不操作
    void _CheckCapacity();
    // 尾插
    void PushBack(const T& val);
    // 尾删
    void PopBack();
    // 头插
    void PushFront(const T& val);
    // 头删
    void PopFront();
    // 任意位置插入
    void Insert(size_t pos, const T& val);
    // 任意位置删除
    void Erase(size_t pos);
    // 查找值为 val 的元素，找到返回元素的下标，否则返回 -1
    int Find(const T& val);
    // 将下标为 pos 的元素的值修改为 val
    void Modify(size_t pos, const T& val);
    // 移除第一个值为 val 的元素
    void Remove(const T& val);
    // 移除所有值为 val 的元素
    void RemoveAll(const T& val);
    // 冒泡排序
    void BubbleSort();
    // 二分查找
    int Binaryfind(const T& val);
    // 打印顺序表内容
    void Print();
private:
    T* _pData;        // 指向动态开辟数组的指针
    size_t _size;      // 顺序表有效元素个数
    size_t _capacity;  // 顺序表容量大小 
};

/////////////////////////  注意  ///////////////////////////
// 1. 若成员函数中有类型参数存在，则:
//    (1)在成员函数定义之前进行模板声明
//    (2)在成员函数名前加上: 类名<类型参数>::
//


// 构造函数的作用: 初始化对象
// 定义构造函数
template<typename T>
SeqList<T>::SeqList(size_t capacity)
    : _pData(new T[capacity])
      , _size(0)
      , _capacity(capacity)
{}

// 定义拷贝构造函数
template<typename T>
SeqList<T>::SeqList(const SeqList <T>& s) {
    _pData = new T[s._size];
    for (size_t i = 0; i < s.size; ++i) {
        _pData[i] = s._pData[i];
    }

    _size = s._size;
    _capacity = s._capacity;
}    

// 定义下标运算符重载
//template<typename T>
//T& SeqList<T>::operator[](size_t pos) {
//    assert(pos < _size);
//    //if (pos >= _size)
//    //    return -1;
//
//    return _pData[pos];
//}

// 定义赋值运算符重载
template<typename T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T> s) {
    if (&s != this) {
        swap(_pData, s._pData);
        swap(_size, s._size);
        swap(_capacity, s._capacity);
    }

    return *this;
}

// 定义析构函数
// 析构函数作用: 清理对象
template<typename T>
SeqList<T>::~SeqList() {
    if (_pData) {
        delete[] _pData;
    }
}

// 定义检查容量函数 ==> 即扩容操作
// 注意:
//    1. 不能使用 relloc 函数进行扩容,因为 relloc 函数进行扩容时不会调用构造函数,
//       所以对于自定义类型 relloc 不会调用构造函数初始化自定义类型对象,随机值会导致崩溃 
//    2. 不能使用 memcpy 进行内存拷贝,因为对于长字符串重新开辟空间拷贝析构两次崩溃
template<typename T>
void SeqList<T>::_CheckCapacity() {
    if (this == nullptr) 
        return;

    if(_size < _capacity) {
        return;
    }

    T* new_pData= new T[_capacity * 2];
    if (_size == _capacity) {
        for (size_t i = 0; i < _size; ++i) {
            new_pData[i] = _pData[i];
        }
    }

    delete[] _pData;
    _pData = new_pData;
    _capacity *= 2;
}

// 尾插
template<typename T>
void SeqList<T>::PushBack(const T& val) {
    // if (this == nullptr)
    //     return;

    _CheckCapacity();
    _pData[_size++] = val;
}

// 尾删
template<typename T>
void SeqList<T>::PopBack() {
    if (this == nullptr || 0 == _size)
        return;

    --_size;
}

// 头插
template<typename T>
void SeqList<T>::PushFront(const T& val) {
    if(this == nullptr)
        return;

    _CheckCapacity();
    ++_size;
    for (int i = _size - 2; i >= 0; --i) {
        _pData[i + 1] = _pData[i];
    }
    _pData[0] = val;
}

// 头删
template<typename T>
void SeqList<T>::PopFront() {
    if (this == nullptr)
        return;

    for (size_t i = 0; i < _size; ++i) {
        _pData[i] = _pData[i + 1];
    }

    --_size;
}

// 任意位置插入
template<typename T>
void SeqList<T>::Insert(size_t pos, const T& val) {
    if (nullptr == this || pos > _size)
        return;

    ++_size;
    _CheckCapacity();
    for(size_t i = _size - 1; i >= pos; --i) {
        _pData[i + 1] = _pData[i];
    }

    _pData[pos] = val;
}

// 任意位置删除
template<typename T>
void SeqList<T>::Erase(size_t pos) {
    if (nullptr == this || pos >= _size) 
        return;

    for (size_t i = pos; i < _size; ++i) {
        _pData[i] = _pData[i + 1];
    }

    --_size;
}

// 查找
template<typename T>
int SeqList<T>::Find(const T& val) {
    if (nullptr == this || 0 == _size)
        return -1;

    for (size_t i = 0; i < _size; ++i) {
        if(val == _pData[i])
            return i;
    }

    return -1;
}

template<typename T>
void SeqList<T>::Modify(size_t pos, const T& val) {
    if (pos >= _size) 
        return;

    _pData[pos] = val;
}

// 移除第一个值为 val 的元素
template<typename T>
void SeqList<T>::Remove(const T& val) {
    int pos = Find(val);

    if (pos >= 0) {
        for (size_t i = pos; i < _size; ++i) {
            _pData[i] = _pData[i + 1];
        } 
    }
    --_size;
}

// 移除所有值为 val 的元素
template<typename T>
void SeqList<T>::RemoveAll(const T& val) {
    while (Find(val) >= 0) {
        Erase(Find(val));
    }
}

// 冒泡排序
template<typename T>
void SeqList<T>::BubbleSort() {
    if (nullptr == this)
        return;

    T tmp;
    for (size_t i = 0; i < _size - 1; ++i) {
        for (size_t j = 0; j < _size - 1 -i; ++j) {
            if (_pData[j] > _pData[j + 1]) {
                tmp = _pData[j];
                _pData[j] = _pData[j + 1];
                _pData[j + 1] = tmp;
            }
        }
    }
}

// 二分查找
template<typename T>
int SeqList<T>::Binaryfind(const T& val) {
    BubbleSort();

    size_t left = 0;
    size_t right = _size - 1;
    size_t mid;
    
    while (left < right) {
        mid = (left + right) / 2;
        if (_pData[mid] > val) {
            right = mid - 1;
        } else if (_pData[mid] < val) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

// 打印函数
template<typename T>
void SeqList<T>::Print() {
    if (nullptr == this || 0 == _size)
        return;

    for (size_t i = 0; i < _size; ++i) {
        cout << _pData[i] << " ";
    }

    cout << endl;
}

#endif // _SEQUENCELIST_H_
