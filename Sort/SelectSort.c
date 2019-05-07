/* 选择排序 */

#include <stdio.h>

void Swap(int array[], int i, int j) {
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}

/* 直接选择
 * 时间复杂度： O(n^2)   数据不敏感
 * 空间复杂度： O(1)
 * 稳定性： 不稳定
 */

void SelectSort(int array[], int size){
    for (int i = 0; i < size; ++i) {
        int maxIdx = 0;
        for (int j = 0; j < size - i; ++j) {
            if (array[j] > array[maxIdx]) {
                maxIdx = j;
            }
        }
        Swap(array, maxIdx, size - 1 - i);
    }
}

/* 堆排序
 *
 * 时间复杂度 O(n * log(n))    不敏感
 * 空间复杂度 O(1)
 * 稳定性: 不稳定
 *
 *
 * 向下调整
 *
 * 0. 如果我是叶子，可以停了
 * 1. 左右孩子中值比较大的一个
 *    1）没有右孩子     左孩子
 *    2）有右孩子 
 *        i. 左孩子大   左孩子
 *        ii.右孩子大   右孩子
 * 2. 大孩子的值和根的值进行比较
 * 3. 如果根的值 >= 大孩子的值了，可以停
 * 4. 交换，继续向下调整
 */

void Heapify(int array[], int size, int rIdx) {
    while (1) {
        int leftIdx = 2 * rIdx + 1;
        int rightIdx = 2 * rIdx + 2;
        if (leftIdx >= size) {
            return;
        }

        int maxIdx;
        if (rightIdx >= size) {
            maxIdx = leftIdx;
        } else if (array[leftIdx] >= array[rightIdx]) {
            maxIdx = leftIdx;
        } else {
            maxIdx = rightIdx;
        } 

        if (array[maxIdx] <= array[rIdx]) {
            return;
        }

        Swap(array, maxIdx, rIdx);

        rIdx = maxIdx;
    }
}

void CreateHeap(int array[], int size) {
    for (int i = (size - 1 - 1) / 2; i >= 0; --i) {
        Heapify(array, size, i);
    }
}

void HeapSort(int array[], int size) {
    CreateHeap(array, size);

    for (int i = 0; i < size; ++i) {
        Swap(array, 0, size - 1 - i);
        Heapify(array, size - 1 - i, 0);
    }
}

void PrintArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void Test() {
    int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 10, 9 };
    int size = sizeof(array) / sizeof(int);

    PrintArray(array, size);
    // SelectSort(array, size);
    HeapSort(array, size);
    PrintArray(array, size);
}

int main() {
    Test();
    return 0;
}
