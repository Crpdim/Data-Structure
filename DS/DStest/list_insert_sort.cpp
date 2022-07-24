/*************************************************************************
> File Name:     list_insert_sort.cpp
> Author:        Crpdim
> mail:         crpdim7@gmail.com
> Created Time:  日  7/17 15:32:22 2022
> Description:   
 ************************************************************************/
#include"stdio.h"
#include"stdlib.h"


typedef struct Node {
    int data;
    Node*next;
}Node, *List;

Node* create_list(int a[], int len){
    List head = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < len; ++i) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = a[i];
        temp->next = head->next;
        head->next = temp;
    }
    return head;
}
void print_list(List a) {
    Node* p = a->next;
    while (p){
        printf("%d ,", p->data);
        p = p->next;
    }
}

void list_sort(List l){
    Node* p = l->next;
    while(p) {
        if (p->next->data < p->data){
            Node* temp = l->next;
            Node* targ = p->next;
            while(temp && temp->next > p->data) {
                
            }
        }
    }
}

int main() {

    int a[10] = {1,3,5,7,9,2,4,6,8,10};
    List l = create_list(a, 10);
    print_list(l);

}
