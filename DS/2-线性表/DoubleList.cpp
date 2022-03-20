/**
 * @file DoubleList.cpp
 * @author Crpdim (crpdim7@gmail.com)
 * @brief 双链表带初始化,带头节点 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;   
}DNode, *DLinkList;


bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//双链表插入
bool InsertNextDNode(DNode *p, DNode *s) { //在p节点之后插入s
    if (p == NULL || s == NULL) return false;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
}

//删除p节点的后继节点
bool DeleteNextDNode(DNode *p) {
    if (p == NULL) return false;
    DNode *q = p->next;
    if (q == NULL) return false;
    p->next = q->next->next;
    if (q->next != NULL) 
        q->next->prior = p;
    free(q);
    return true;
}

//销毁双链表
void DestoryList(DLinkList &L) {
    while (L->next != NULL) {
        DeleteNextDNode(L);
    }
    free(L);
    L = NULL;
}
