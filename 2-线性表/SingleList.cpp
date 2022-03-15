/**
 * @file SingleList.cpp
 * @author Crpdim (crpdim7@gmail.com)
 * @brief 单链表
 * @version 0.1
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include<iostream>
using namespace std;

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

//不带头节点链表初始化
// bool InitList(LinkList &L) {
//     L = NULL;
//     return true;
// }
//带头节点链表初始化
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) 
        return false;
    L->next = NULL;
    return true;
}

bool Empty(LinkList &L) {
    return !L;
}

bool ListInsert(LinkList &L, int i, int e) { //带头节点
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i-1) {
        p = p->next;
        ++j;
    }
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList &L, int i, int &e) { //e接收删除元素的值
    if(i < 1) return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i-1) {
        p = p->next;
        ++j;
    }
    if (p == NULL) return false;
    if (p->next == NULL) return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

bool DeleteNode(LNode *p) {
    if (p == NULL) return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}

int main() {
    return 0;
}