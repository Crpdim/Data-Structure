/**
 * @file LiStack.cpp
 * @author Crpdim (crpdim7@gmail.com)
 * @brief 链栈
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */



// #include <bits/stdc++.h>
#include<stdio.h>
typedef struct LinkNode{ 
    int data;
    struct LinkNode *next;
} *LiStack;

void InitStack(LiStack &S) {
    S = (LinkNode *)malloc(sizeof(LinkNode));
    S->data = -9999;
    S->next = NULL;
}

bool StackPush(LiStack &S, int num) {
    if (S->data == -9999) {
        S->data = num;
        return true;
    }
    struct LinkNode *p;
    p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = num;
    p->next = S;
    S = p;
    return true;
}

bool StackIsEmpty(LiStack &S) {
    if (S->data == -9999) return true;
    return false;
}

bool StackPop(LiStack &S, int &num) {
    if (StackIsEmpty(S)) return false;
    num = S->data;
    if (S->next) {
        S = S->next;
    } else {
        S->data = -9999;
    }
    return true;
}

bool StackGetElem(LiStack &S, int &num) {
    if (S->data == -9999) return false;
    num = S->data;
    return true;
}


int main()
{
    LiStack s;
    InitStack(s);
    int a = 10;
    StackPush(s, a);
    StackPush(s, 20);
    StackPush(s, 30);
    int b = 0;
    int c = 0;
    StackPop(s, b);
    StackGetElem(s, c);
    printf("%d,%d",b,c);
    return 0;
}