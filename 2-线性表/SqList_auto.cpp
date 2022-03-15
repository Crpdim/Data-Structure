#include<stdio.h>
#define InitSize 10
typedef struct {
  int *data;
  int MaxSize;
  int length;
} SqList;

void InitList(SqList &L) {									//c语言没有引用,可以用指针实现
	L.data = (int *) malloc (InitSize * sizeof(int));		//申请一片连续的内存空间
  L.length = 0;
  L.MaxSize = InitSize;
}

void IncreaseSize(SqList &L, int len) {
  int *p = data;
  L.data = (int *)malloc((L.MaxSize+len) * sizeof(int));	//申请新的内存空间
  for (int i =0; i < L.length; ++i) {					    //将数据复制到新的区域
    L.data[i] = p[i];
  }
  L.MaxSize = L.MaxSize + len;								//增加顺序表的最大长度
  free(p); 												    //释放原来的内存空间
}
int main() {
  SqList L;
  InitList(L);
  IncreaseSize(L, 5);
 	//……
  return 0;
}
