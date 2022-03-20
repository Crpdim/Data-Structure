# 线性表 --Linear List

[TOC]



## 定义 (逻辑结构)

既有相同的数据类型的n个数据元素的**有限 序 列**, 其中n为**表长**, n = 0是,该线性表是一个**空表**

用L 表示线性表, 则一般表示为: L = (a1, a2, a3,…ai, ai+1,…, an)  *脚标从1开始* a1为**表头**元素,an为**表尾**元素,除表头元素以外,其余元素都**有且只有一个**前驱元素,除表尾元素以外,其余元素都有且只有一个后继元素.**数据元素的位序从1开始**.

## 基本操作

对数据的操作无非是 **创建销毁** and **增删改查**

1. 初始化表  InitList(&L) : 构造一个空的线性表L, 并分配内存空间

2. 销毁操作 DestroyList(&L) : 销毁线性表,并释放线性表L所占用的内存空间

3. 插入操作 ListInsert(&L,i, e)  : 在表中第i个位置插入指定元素e
4. 删除操作 ListDelete(&L,i, &e)  : 删除表中第i个位置的元素,并用e返回删除元素的值
5. 按值查找 LocateElem(L, e)  : 在表L中查找具有指定关键字值的元素
6. 按位查找 GetElem(L, i)  : 获取表L中第i个位置元素的值
7. 其他操作
   * 求表长 Length(L)
   * 打印表 PrintList(L)
   * 判空操作 Empty(L)

### 为什么要实现数据结构基本操作?

* 团队合作编程,你定义的数据结构要让别人可以很方便的使用(封装)

* 将常用操作/运算封装成函数,避免重复工作,降低出错风险

 ## 存储/物理结构

## 顺序表 : 用顺序存储的方式实现的线性表

*顺序存储: 把逻辑上相邻的元素存储在物理位置也相邻的存储单元中* 

#### 顺序表特点:

1. 随机访问,可以在O(1)时间内找到第i个元素

   因为存放位置是连续的,只需要知道第一个地址,其余地址都可以直接算出.

2. 存储密度高

   顺序存储每个节点只存储数据, 链式存储还需要存储指针

3. 拓展容量不方便

   即使使用动态分配,拓展长度复杂度高

4. 插入 删除元素不方便 复杂度高

#### 顺序表实现--静态分配

```c
#define MaxSize 10
typedef struct {
  ElemType data[MaxSize];	//使用静态数组存放数据元素
  int length;							//顺序表当前长度
}SqList;									//顺序表类型定义
```

##### 具体实现

```c
#include<stdio.h>
#define MaxSize 10
typedef struct {
  int data[MaxSize];
  int length;
} SqList;

void InitList(SqList &L) {						//c语言没有引用,可以用指针实现
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
```

##### 局限性

静态分配顺序表长刚开始确定后就无法更改!!! (存储空间是静态的)

#### 顺序表实现--动态分配

```c
#define InitSize 10				//顺序表的初始长度
typedef struct {
  ElemTppe *data;					//只是动态分配数组的指针
  int MaxSize;						//顺序表的最大容量
  int length;							//顺序表当前长度
} SqList;									//顺序表类型定义
```

##### 具体实现

*c语言中 malloc()函数可以实现动态申请内存并返回该内存空间的起始地址, free() 函数可以释放内存空间 c++可以使用new 和 delete关键字*

```c
#include<stdio.h>
#define InitSize 10
typedef struct {
  int *data;
  int MaxSize;
  int length;
} SqList;

void InitList(SqList &L) {																//c语言没有引用,可以用指针实现
	L.data = (int *) malloc (InitSize * sizeof(int));				//申请一片连续的内存空间
  L.length = 0;
  L.MaxSize = InitSize;
}

void IncreaseSize(SqList &L, int len) {
  int *p = data;
  L.data = (int *)malloc((L.MaxSize+len) * sizeof(int));	//申请新的内存空间
  for (int i =0; i < L.length; ++i) {											//将数据复制到新的区域
    L.data[i] = p[i];
  }
  L.MaxSize = L.MaxSize + len;														//增加顺序表的最大长度
  free(p); 																								//释放原来的内存空间
}
int main() {
  SqList L;
  InitList(L);
  IncreaseSize(L, 5);
 	//……
  return 0;
}
```

#### 顺序表插入删除

```c++
bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1 || L.length >= L.MaxSize) {
		return false;
	}
	for (int j = L.length; j >= i; --i) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	++L.length;
	return true;
}
```

##### 复杂度分析:

* 最好情况:新元素加到表尾, 不需要移动元素, 循环0次

  最好时间复杂度O(1)

* 最坏情况:新元素加到表头,需要将原来所有元素都往后移动, 循环n次 

  最坏时间复杂度O(n)

* 平均复杂度: 假设新元素插入到任何位置概率相同, 平均循环次数: n/2

  平均时间复杂度O(n)

#### 顺序表删除操作

```c++
bool ListDelete(SqList &L, int i, int &e) {		//i为删除位置, e接收删除元素的内容
	if (i < 1 || i > L.length) 
		return false;
	e = L.data[i-1];														//注意!顺序表位序从1开始,数组下标从0开始
	for (int j = i; i < L.length; ++j) {
		L.data[j-1] = L.data[j];
	}
	--L.length;
  return true;
}
```

##### 复杂度分析:

* 最好情况:删除表尾元素, 不需要移动元素, 循环0次

  最好时间复杂度O(1)

* 最坏情况:删除表头,需要将原来所有元素都往前移动, 循环n-1次 

  最坏时间复杂度O(n)

* 平均复杂度: 假设新元素插入到任何位置概率相同, 平均循环次数: (n-1)/2

  平均时间复杂度O(n)

#### 顺序表元素查找

* 按位查找

  ```c++
  int GetElem(SqList &L, int i) {
  	if (i > L.length || i < 1) {
  		return -1;
  	}
  	return L.data[i-1];
  }
  ```

  复杂度分析:

  时间复杂度为O(1)

* 按值查找

  ```c++
  int LocateElem(SqList &L, int e) {
  	for (int i = 0; i < L.length; ++i) {
  		if (L.data[i] == e) 
  			return i+1;
  	}
  	return 0;
  }
  ```

  复杂度分析:

  * 最好情况:目标元素在表头

    最好时间复杂度O(1)

  * 最坏情况:目标元素在表尾或不存在 

    最坏时间复杂度O(n)

  * 平均复杂度: 设目标元素在任何位置概率相同

    平均时间复杂度O(n)

## 单链表

表中每个节点除存放数据以外还要存储指向下一节点的指针

### 单链表特点:

1. 不支持随机存取,需要耗费一定空间存放指针
2. 不要求大片的连续空间,改变容量很方便

### 定义单链表

```c++
typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode, *LinkList;
//LNode强调节点,LinkList强调链表
//使用LinkList声明头指针,代码可读性强

//不带头节点链表初始化
bool InitList(LinkList &L) {	//判断不带头节点的链表为空,只需要判断头节点next指向是否为空
    L = NULL;
    return true;
}
//带头节点链表初始化
bool InitList(LinkList &L) {	//判断带头节点链表为空,则只需要判断头节点是否为空
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) 
        return false;
    L->next = NULL;
    return true;
}

```

### 基本操作实现

#### 单链表插入(带头节点), 不带头节点需要特殊处理第一个元素

```c++

bool ListInsert(LinkList &L, int i, int e) { //带头节点
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i-1) {
        p = p->next;
        ++j;
    }
  	//-------------------------以下可以用return InsertNextNode(p, e); 后插操作代替
    if (p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
  	//-------------------------
}
```

#### 指定节点后插操作

```c++
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
```

#### 指定节点前插操作

```c++
//将新节点放到p节点之后,将p中元素复制到新节点,在给p节点重新赋值e
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
```

#### 按位序删除(带头节点) 

```c++
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
```

#### 删除指定节点p

```c++
//找到指定节点的后继节点,将其元素赋给指定节点,之后删除指定节点的后继节点并释放空间.
bool DeleteNode(LNode *p) {
    if (p == NULL) return false;
    LNode *q = p->next;					
    p->data = p->next->data;		
    p->next = q->next;
    free(q);
    return true;
}
```

#### 单链表建立-尾插法

​	建立一个尾指针,将新数据节点接到尾指针之后并更新尾指针

```c++
//尾插法建立单链表
LinkList List_TailInsert(LinkList &L) {         //正向建立单链表
    int x;
    L = (LinkList)malloc(sizeof(LNode));        //头节点
    LNode* s, * r = L;                          //r为表尾指针
    L->next = NULL;                             //初始化头节点(建立指针时应该养成初始化指针的习惯,防止无法预料的情况发生)
    scanf("%d", &x);                            //输入节点值
    while (x != 9999) {                         //不断向尾节点插入新数据,并更新尾节点,输入x = 9999时,插入操作结
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;                             //尾节点置空
    return L;
}
```

#### 单链表建立-头插法

在头节点和头节点next之间不断插入节点,得到逆序链表(头插法应用:链表逆置),得到的链表位序与尾插法相反

```c++
//头插法建立单链表
LinkList List_HeadInsert(LinkList& L) {     //逆序插入链表,得到的链表与尾插法相反
    LNode* s;
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;                         //!!初始化
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;								
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
```

## 双链表实现 

每个节点都有一个前向指针和一个后向指针

```c++
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;   
}DNode, *DLinkList;

//双链表初始化
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//双链表插入
bool InsertNextDNode(DNode *p, DNode *s) {  //在p节点之后插入s
    if (p == NULL || s == NULL) return false;
    s->next = p->next;
    if (p->next != NULL)										//边界情况特殊处理
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
```

## 静态链表

```c++
#define MaxSize 10
//定义一个节点
struct Node{
    int data;
    int next;
};
//定义一个静态链表
typedef struct
{
    int data;
    int next;
}SLinkList [MaxSize];

```

