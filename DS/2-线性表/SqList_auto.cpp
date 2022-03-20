/**
 * @file SqList_auto.cpp
 * @author Crpdim (crpdim7@gmail.com)
 * @brief 顺序表--动态分配 实现
 * @version 0.1
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include<iostream>
using namespace std;
#define InitSize 10
typedef struct {
	int* data;
	int MaxSize;
	int length;
} SqList;

void InitList(SqList& L) {									//c语言没有引用,可以用指针实现
	L.data = new int[InitSize];								//申请一片连续的内存空间
	L.length = 0;
	L.MaxSize = InitSize;
}

void IncreaseSize(SqList& L, int len) {
	int* p = L.data;
	L.data = new int[L.length + len];							
	for (int i = 0; i < L.length; ++i) {					    //将数据复制到新的区域
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;								//增加顺序表的最大长度
	delete(p); 												    //释放原来的内存空间
}

bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1 || L.length >= L.MaxSize) {
		cout << "error\n";
		return false;
	}
	for (int j = L.length; j >= i; --i) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	++L.length;
	return true;
}

bool ListDelete(SqList &L, int i, int &e) {		//i为删除位置, e接收删除元素的内容
	if (i < 1 || i > L.length) {
		cout << "error\n";
		return false;
	}
	e = L.data[i-1];
	for (int j = i; i < L.length; ++j) {
		L.data[j-1] = L.data[j];
	}
	--L.length;
	return true;
}

int GetElem(SqList &L, int i) {
	if (i > L.length || i < 1) {
		cout << "error\n";
		return -1;
	}
	return L.data[i-1];
}

int LocateElem(SqList &L, int e) {
	for (int i = 0; i < L.length; ++i) {
		if (L.data[i] == e) 
			return i+1;
	}
	return 0;
}

int main() {
	SqList L;
	InitList(L);
	IncreaseSize(L, 5);
	ListInsert(L,1,1);
	int x;
	ListDelete(L,1,x);
	cout << x << endl;
	return 0;
}
