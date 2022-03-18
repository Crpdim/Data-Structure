/**
 * @file StaticList.cpp
 * @author Crpdim (crpdim7@gmail.com)
 * @brief 静态链表
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

#define MaxSize 10

struct Node{
    int data;
    int next;
};

typedef struct
{
    int data;
    int next;
}SLinkList [MaxSize];


