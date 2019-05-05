#include <stdio.h>


/* 数据越有序，速度越快
 * 时间复杂度
 * 最快：O(n)     已经有序
 * 平均: O(n^2)
 * 最慢：O(n^2)   逆序
 *
 * 空间复杂度：   O(1)
 * 稳定性：稳定 
 */

void InsertSort(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        int key = array[i];
        int j;
        // [i - 1, 0]
        for (j = i - 1; j >= 0; j--) {
            if (array[j] <= key) {
                break;
            }

            array[j + 1] = array[j];
        }

        array[j + 1] = key;
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
    InsertSort(array, size);
    PrintArray(array, size);
}

int main() {
    Test();
    return 0;
}
