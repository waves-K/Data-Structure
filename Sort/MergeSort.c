#include <stdio.h>
#include <malloc.h>

void Swap(int array[], int i, int j) {
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}

// 归并排序

// 时间复杂度   O(n * log(n))
//
// 空间复杂度   O(n)
//
// 稳定性：稳定
//
// 外部排序   首选
void Merge(int array[], int left, int mid, int right, int extra[]) {
    int i = left;     // 左边区间的下标
    int j = mid;      // 右边区间的下标
    int k = left;        // extra 的下标

    while (i < mid && j < right) {
        if (array[i] <= array[j]) {
            extra[k++] = array[i++];
        } else {
            extra[k++] = array[j++];
        }
    }

    while (i < mid) {
        extra[k++] = array[i++];
    }

    while (j < right) {
        extra[k++] = array[j++];
    }

    // 把 extra 的数据搬移回来
    for (int x = left; x < right; ++x) {
        array[x] = extra[x];
    }
}

// [left, right)
void __MergeSort(int array[], int left, int right, int extra[]) {
    // 直到
    // size == 1    
    if (right == left + 1) {
        return;
    }
    // size == 0
    if (right <= left) {
        return;
    }

    
    // 1. 把数组平均分成两部分
    int mid = left + (right - left) / 2;
    // [left, mid)
    // [mid, right)
    // 2. 分治算法，排序左右两部分
    __MergeSort(array, left, mid, extra);
    __MergeSort(array, mid, right, extra);

    // 3. 合并两个有序数组
    // [left, mid)  [mid, right)
    Merge(array, left, mid, right, extra);
}

void MergeSort(int array[], int size) {
    int *extra = (int *)malloc(sizeof(int) * size);
    __MergeSort(array, 0, size, extra);
    free(extra);
}

void MergeSortNoR(int array[], int size) {
    int *extra = (int *)malloc(sizeof(int) * size);

    // i 的含义：i 个有序的数组 和另一个 i 个有序的数组进行合并
    for (int i = 1; i < size; i = 2 * i) {
        // 一层里需要多少次归并
        // j 表示的是要合并的两个有序数组的左边数组的左边界
        // i 是有序数组的长度
        for (int j = 0; j < size; j = j + 2 * i) {
            int left = j;
            int mid = j + 1;
            if (mid >= size) {
                // mid 越界，说明没有右边一个有序数组，不需要归并
                continue;
            }
            int right = mid + 1;
            if (right > size) {
                right = size;
            }

            Merge(array, left, mid, right, extra);
        }
    }

    free(extra);
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
    MergeSort(array, size);
    PrintArray(array, size);
}

int main() {
    Test();
    return 0;
}
