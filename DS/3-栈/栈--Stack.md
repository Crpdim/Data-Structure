# 栈

> 一种操作受限制的线性表,只允许栈顶进行插入删除操作(先进先出)!

栈顶: 允许插入和删除的一端

栈底: 不允许插入和删除的一端

空栈: 空的栈

## 基本操作

### 初始化栈

```c++
#define MaxSize 10
//顺序栈
typedef struct {
    int data[MaxSize];
    int top = -1;
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
```

### 销毁栈

### 添加元素

```c++
bool Push(SqStack& S, int num) {
    if (S.top == MaxSize) return false;
    // S.data[++S.top] = num;
    S.top++;
    S.data[S.top] = num;
    return true;
}
```

### 删除元素

```c++
bool Pop(SqStack& S, int& x) {
    if (S.top == -1) return false;
    // x = S.data[S.top--];
    x = S.top;
    --S.top;
    return true;
}
```

### 获取栈顶元素

```c++
bool GetTop(SqStack& S, int& x) {
    if (S.top == -1) return false;
    x = S.data[S.top];
    return true;
}
```



### 判空操作

```c++
bool IsEmpty(SqStack& S) {
    return S.top == -1;
}
```

