/* 希尔排序(分组排序)
 * 组的跨度大和小之间有个矛盾
 * 动态分组
 *
 * 时间复杂度：
 * 最好： O(n)
 * 平均： O(n^1.3-1.4)
 * 最坏： O(n^2)
 *
 * 空间复杂度：  O(1)
 * 稳定性： 不稳定
 */ 

#include <stdio.h>

void InsertSortWithGap(int array[], int size, int gap) {
    for (int i = 0; i < size; ++i) {
        int key = array[i];
        int j;

        for (j = i - gap; j >= 0; j -= gap) {
            if (array[j] <= key) {
                break;
            }

            array[j + gap] = array[j];
        }
        
        array[j + gap] = key;
    }
}

void ShellSort(int array[], int size) {
    int gap = size;
    while (1) {
        gap = gap / 3 + 1;
        // gap = gap / 2
        
        InsertSortWithGap(array, size, gap);

        if (gap == 1) {
            return;
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
    ShellSort(array, size);
    PrintArray(array, size);
}

int main() {
    Test();
    return 0;
}
