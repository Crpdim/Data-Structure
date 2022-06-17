#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct BitNode {
    int data;
    struct BitNode* left;
    struct BitNode* right;
}BitNode, *BitTree;

int search(BitTree root, int d) {
    if (root != NULL) {
        BitNode *temp = root;
        if (d == temp->data) {
            printf("I Find %d \n", temp->data);
            return 1;
        } else if (d < temp->data) {
            search(temp->left, d);
        } else {
            search(temp->right, d);
        }
    } else {
        printf("no such data!");
        return 0;
    }
}

void insert(BitTree *root, int d) {
    if (*root == NULL) {                                   //初始化新节点
        (*root) = (BitNode*)malloc(sizeof(BitNode));
        (*root)->data = d;
        (*root)->right = (*root)->left = NULL;
    } else {
        if (d > (*root)->data) {
            insert(&(*root)->right, d);
        } else {
            insert(&(*root)->left, d);
        }
    }
}

void delete(BitTree *root, int d) {
    if (*root == NULL) {
        printf("no such node");
    } else {
        if ((*root)->data == d) {
            if (!(*root)->left) {       //左子树为空
                BitNode *p = (*root);
                (*root) = p->right;
                free(p);
            } else if (!(*root)->right){
                BitNode *p = (*root);
                (*root) = p->left;
                free(p);
            } else {
                BitNode *Target = (*root);
                BitNode *temp = (*root)->right;
                while (temp->left) {
                    temp = temp->left;
                }
                temp->left = (*root)->left;
                *root = (*root)->right;
                free(Target);
            }
        } else if ((*root)->data > d) {
            delete(&(*root)->left, d);
        } else {
            delete(&(*root)->right, d);
        }
    }
}

void PreOrder(BitTree root) {
    if (!root) return;
    BitNode *temp = root;
    PreOrder(root->left);
    printf("%d ", root->data);
    PreOrder(root->right);
}

int main() {
    printf("Hello, World!\n");
    BitTree root = NULL;
    int a[10] = {25, 12, 20,35,46,24,31,22,55,87};
    for (int i = 0; i < 10; ++i) {
        insert(&root, a[i]);
    }
    for (int i = 9; i >=0; i--) {
        int x = rand() % 10;
        delete(&root, a[x]);
        printf("delete %d, x = %d \n", a[x], x);
        PreOrder(root);
    }
    PreOrder(root);
    return 0;
}
