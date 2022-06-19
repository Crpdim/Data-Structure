//
// Created by 王业同 on 2022/6/19.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H
#endif //SORT_SORT_H
#define SIZE 100000

void InsertSort(int a[], int n) {                    //将待排序的记录按关键字大小插入到前面已经排好序的序列中
    int i, j, temp;

    for (i = 1; i < n; ++i) {
        if (a[i] < a[i-1]) {
            temp = a[i];
            for (j = i-1; j >=0 && temp < a[j]; --j) {  //将a[i]前面所有大于它的都右移一位
                a[j+1] = a[j];
            }
            a[j+1] = temp;                              //插入相应位置
        }
    }

}/**插入排序
 * 最好时间复杂度O(n)   (正序)
 * 最坏时间复杂度O(n^2) (逆序)
 * 平均时间复杂度O(n^2)
 * 空间复杂度O(1)
 * 算法稳定性： 稳定
 * **/

void HS_InsertSort(int a[], int n) {
    int mid, high, low, temp;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i-1]) {
            low = 0, high = i-1, temp = a[i];
            while (high >= low) {                    //折半查找寻找插入位置
                mid = (low + high) / 2;
                if (a[mid] > temp) high = mid-1;
                else low = mid+1;
            }
            for (int j = i-1; j >= high+1; --j) {
                a[j+1] = a[j];
            }
            a[high+1] = temp;
        }
    }
}   //折半查找优化的插入排序 先通过折半查找查找插入位置，再调整位置

void ShellSort(int a[], int n) {                //将若干排序表分割成若干表内元素相隔增量d的子表，对各个子表进行直接插入排序，缩小增量d，重复这个过程，直到d=1
    int temp, j;
    for (int d = n/2; d >= 1; d/=2) {           //缩小增量d的过程，这里每次缩小，d都变为原来的一半
        for (int i = d; i < n; ++i) {           //对各个子表进行插入排序
            if (a[i] < a[i-d]) {
                temp = a[i], j = i-d;
                for (; j >= 0 && a[j] > temp; j-=d) {
                    a[j+d] = a[j];
                }
                a[j+d] = temp;
            }
        }
    }
}/**
  * 希尔排序
  * 最坏时间复杂度O(n^2)
  * 空间复杂度O(1)
  * 稳定性： 不稳定
  * 适用于顺序表，不能基于线性表
  * **/

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; ++i) {
        int is_sorted = 0;                  //有序标志位，若一次冒泡过程未发生交换，已经有序，可以直接return
        for (int j = n-1; j > i; --j) {
            if (a[j-1] > a[j]) {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                is_sorted = 1;
            }
        }
        if (is_sorted) return;
    }
}/** 冒泡排序
 * 最坏时间复杂度O(n^2)
 * 空间复杂度O(1);
 * 算法稳定性： 稳定
 * 适用于链表
 * **/

void QuickSort(int a[], int low, int high) {
    if (low >= high) return;                            //子数组只有一个元素时跳出循环
    int LOW = low, HIGH = high;                         //复制一份low和high，用于确定子表范围
    int pivot = a[low];
    while (low < high) {
        while (high > low && a[high] >= pivot) --high;  //high指针左移，找到第一个小于枢轴的元素
        a[low] = a[high];
        while (low < high && a[low] <= pivot) ++low;    //low指针右移，找到第一个大于枢轴的元素
        a[high] = a[low];
    }
    a[low] = pivot;                                     //将枢轴元素固定在它应该在的地方
    QuickSort(a, LOW, low-1);                 //递归处理左右子表
    QuickSort(a, low+1, HIGH);
}/**
 * 快速排序
 * 递归层数可以类比 n个节点的二叉树，最小高度（log2 n)+1， 最大高度n
 * 时间复杂度：O(n*递归层数) (每一层递归处理的元素都小于n)
 * 空间复杂度: O(递归层数)
 * 算法稳定性： 不稳定
 * 优化方法： 递归层数与枢轴的选择有直接关系，尽量选取将数据中分的枢轴元素
 * **/

void SelectSort(int a[], int n) {
    int min_elem = 0;
    int temp;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            min_elem = a[j] < a[min_elem]? j: min_elem;
        }
        if (min_elem != i) {            //swap
            temp = a[min_elem];
            a[min_elem] = a[i];
            a[i] = temp;
        }
    }
}/**
 * 简单选择排序
 * 时间复杂度O(n^2) (与序列初始状态无关)
 * 空间复杂度O(1)
 * 算法稳定性：不稳定
 * 顺序表和链表都适用
 */
