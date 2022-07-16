/* ************************************************************************
> File Name:     2_2_4.cpp
> Author:        Crpdim
> mail:         crpdim7@gmail.com
> Created Time:  五  7/15 15:14:41 2022
> Description:   
 ************************************************************************/

#include <stdio.h>
int a[10] = {1,2,3,4,5,6,7,8,9,10};


int half_find(int target,int len, int a[]) {
    int start = 0, end = len-1;
    while (start <= end) {
        int mid = (start + end) /  2;
        if (target == a[mid]) {
            return mid;
        } else if (target < a[mid]) {
            end = mid-1;
        } else {
            start = mid +1;;
        }
    }
    return end;
}


int main() {
    int ans = half_find(3, 10, a);
    printf("hello world \n");
    printf("a[%d] = %d \n", ans, a[ans]);
    return 0;
}
