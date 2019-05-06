#include <stdio.h>

void Swap(int array[], int i, int j) {
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}

/* 冒泡排序
 *
 * 时间复杂度
 * 最坏： O(n^2)
 * 平均： O(n^2)
 * 最好： O(n)
 *
 * 空间复杂度   O(1)
 *
 * 稳定性：稳定
 */

void BubbleSort(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        int isSorted = 1;
        for (int j = 0; j < size - 1 - i; ++j) {
            if (array[j] > array[j + 1]) {
                Swap(array, j ,j + 1);
                isSorted = 0;
            }
        }
        if (isSorted == 1) {
            break;
        }
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
    BubbleSort(array, size);
    PrintArray(array, size);
}

int main() {
    Test();
    return 0;
}
