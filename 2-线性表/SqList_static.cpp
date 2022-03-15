/**
 * @file SqList_static.cpp
 * @author Crpdim (crpdim7@gmail.com)
 * @brief 顺序表静态分配实现
 * @version 0.1
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include<stdio.h>
#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int length;
} SqList;

void InitList(SqList& L) {
	for (int i = 0; i < MaxSize; ++i) {
		L.data[i] = 0;
	}
	L.length = 0;
}

int main() {
	SqList L;
	InitList(L);
	//……
	return 0;
}
