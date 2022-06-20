//
// Created by 王业同 on 2022/6/20.
//

#ifndef SORT_HEAP_H
#define SORT_HEAP_H

#endif //SORT_HEAP_H

///堆排序

void HeadAdjust(int a[], int k, int length) {   ///大根堆
    int temp = a[k];
    for (int i = 2*(k+1)-1; i <= length; i =i*2+1) {
        if (i < length-1 && a[i] < a[i+1])
            ++i;
        if (temp >= a[i]) break;
        else {                  //继续向下筛选
            int s = a[i];
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = temp;
}

void buildHeap(int a[], int length) {   //关键字对比次数<4n 时间复杂度O(n)
    int last = (length)/2;
    for (int i = last; i >=0; --i) {
        HeadAdjust(a, i, length);
    }
}

void HeapSort(int a[], int n) {
    buildHeap(a, n-1);
    for (int i = n-1; i >= 1; --i) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        HeadAdjust(a, 0, i-1);
    }
}/** 大根堆排序 （递增）
 * 时间复杂度 O(nlog2n)
 * 空间复杂度 O(1)
 * 稳定性： 不稳定
 * */


void SmallHeadAdjust(int a[], int k, int length) {  //小跟堆
    int temp = a[k];
    for (int i = 2*(k+1)-1; i <= length; i=i*2+1) {    //大元素不断下坠
        if (i <= length-1 && a[i] > a[i+1]) {
            ++i;
        }
        if (temp <= a[i]) break;
        else {
            a[k] = a[i];                            //小元素换上去，继续向下探索
            k = i;
        }
    }
    a[k] = temp;
}

void buildSmallHeap(int a[], int length) {          //构建小顶堆
    int last = length/2;                            //最后一个非叶节点
    for (int i = last; i >=0; --i) {                //从中间元素向前，不断向下调整
        SmallHeadAdjust(a, i, length);
    }
}

void SmallHeapSort(int a[], int n) {                //小顶堆排序
    buildSmallHeap(a, n-1);
    for (int i = n-1; i >= 1; --i) {                //将最小的元素放到最后并将最后的元素换到a[0]并下坠
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        SmallHeadAdjust(a, 0, i-1);
    }
}

/**
 * 堆的插入操作：
 * 将元素放入堆的末尾（堆底），与父节点进行对比，并不断上升，上升一次对比关键字一次
 * 堆的删除操作：
 * 用末尾元素填补删除位置，并不断下降，下降一次需先对比两子节点数据大小，后与最大的进行对比（大顶堆）
 * */
