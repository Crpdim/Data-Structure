# 线性表 --Linear List

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

### 顺序表 : 用顺序存储的方式实现的线性表

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





