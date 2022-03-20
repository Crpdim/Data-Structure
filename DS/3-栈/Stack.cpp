/**
 * @file Stack.cpp
 * @author Crpdim (crpdim7@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-03-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include<iostream>
#include<stdio.h>

using namespace std;
#define MaxSize 10

//顺序栈
typedef struct {
    int data[MaxSize];
    int top;
} SqStack;//顺序栈

//共享栈: 两栈共用一片存储空间,一个从上往下,一个从下往上
typedef struct {
    int data[MaxSize];
    int top1 = MaxSize;
    int top0 = -1;
} ShStack;




void InitStack(SqStack& S) {
    S.top = -1;
}

bool Push(SqStack& S, int num) {
    if (S.top == MaxSize) return false;
    // S.data[++S.top] = num;
    S.top++;
    S.data[S.top] = num;
    return true;
}

bool Pop(SqStack& S, int& x) {
    if (S.top == -1) return false;
    // x = S.data[S.top--];
    x = S.top;
    --S.top;
    return true;
}

bool GetTop(SqStack& S, int& x) {
    if (S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

bool IsEmpty(SqStack& S) {
    return S.top == -1;
}




int main()
{
    SqStack S;

    ;
    return 0;
}