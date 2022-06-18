#include <stdio.h>
#include <stdlib.h>

typedef struct BSNode {
    int data;
    struct BSNode *left;
    struct BSNode *right;
} BSNode, *BSTree;

int search(BSTree root, int d) {
    if (root != NULL) {
        BSNode *temp = root;
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

void insert(BSTree *root, int d) {
    if (*root == NULL) {                                   //初始化新节点
        (*root) = (BSNode *) malloc(sizeof(BSNode));
        (*root)->data = d;
        (*root)->right = (*root)->left = NULL;
    } else {
        if (d == (*root)->data) {
            printf("data [%d] is already exist\n", d);
            return;
        } else if (d > (*root)->data) {
            insert(&(*root)->right, d);
        } else {
            insert(&(*root)->left, d);
        }
    }
}

void delete(BSTree *root, int d) {
    if (*root == NULL) {
        printf("no such data\n");
    } else {
        if ((*root)->data == d) {
            if((*root)->left && (*root)->right) {
                BSNode *temp = (*root)->right;
                /// *********************************
                /// 另一种删除方式
//                BSNode *Target = (*root);
//                while (temp->left) {
//                    temp = temp->left;
//                }
//                temp->left = (*root)->left;
//                *root = (*root)->right;
//                free(Target);
                /// **********************************
                /// 将后继节点数据复制到该节点，并删除后继节点
                while (temp->left && temp->left->left) {
                    temp = temp->left;
                }
                BSNode *p = temp;
                if (temp->left) {
                    p = temp->left;
                    temp->left = p->right;
                } else {
                    (*root)->right = temp->right;
                }
                (*root)->data = p->data;
                free(p);

            } else if (!(*root)->left) {
                BSNode *p = (*root);
                (*root) = p->right;
                free(p);
            } else {
                BSNode *p = (*root);
                (*root) = p->left;
                free(p);
            }
        } else if ((*root)->data > d) {
            delete(&(*root)->left, d);
        } else {
            delete(&(*root)->right, d);
        }
    }
}

void PreOrder(BSTree root) {
    if (!root) return;
    PreOrder(root->left);
    printf("%d ", root->data);
    PreOrder(root->right);
}

int main() {
    BSTree root = NULL;
    int arr[10] = {53, 17, 78, 9, 45,  65, 94, 23, 81, 88};
    for (int i = 0; i < 100; ++i) {
        int d = rand()%100;
        insert(&root, d);
    }
    for (int i = 0; i < 100; ++i) {
        int x = rand()%100;
        delete(&root, x);
        printf("delete %d\n", x);
        PreOrder(root);
        printf("\n");
    }

    return 0;
}
