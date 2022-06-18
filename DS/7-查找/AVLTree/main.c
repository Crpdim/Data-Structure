#include <stdio.h>
//#include <malloc.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    int b_index;
    struct AVLNode* left;
    struct AVLNode* right;
}AVLNode,* AVLTree;

int max(int d1, int d2) {
    return d1 > d2? d1: d2;
}

int get_hight(AVLNode *t) {                         //获取树高
    if (t == NULL) return 0;
    return max(get_hight(t->left), get_hight(t->right)) + 1;
}

int get_balance_index(AVLNode* t) {                 //获取平衡因子
    return get_hight(t->left) - get_hight(t->right);
}

void l_rotate(AVLTree* root) {                      //左旋操作
    AVLNode *temp = (*root)->right;
    (*root)->right = temp->left;
    temp->left = (*root);
    (*root) = temp;
    (*root)->b_index = get_balance_index((*root));
    (*root)->left->b_index = get_balance_index((*root)->left);
}

void r_rotate(AVLTree* root) {                      //右旋操作
    AVLNode *temp = (*root)->left;
    (*root)->left = temp->right;
    temp->right = (*root);
    (*root) = temp;
    (*root)->b_index = get_balance_index((*root));
    (*root)->right->b_index = get_balance_index((*root)->right);
}

void rotate(AVLTree *root) {                        //平衡被打破进行旋转操作
    if ((*root)->b_index > 1) {
        if ((*root)->left->b_index < 0) {           //LR
            l_rotate(&(*root)->left);
            r_rotate(&(*root));
        } else if ((*root)->left->b_index > 0) {    //LL
            r_rotate(&(*root));
        }
    } else if ((*root)->b_index < -1) {
        if ((*root)->right->b_index < 0) {          //RR
            l_rotate(&(*root));
        } else {
            r_rotate(&(*root)->right);          //RL
            l_rotate(&(*root));
        }
    }
}

void insert(AVLTree* root, int d) {                             //插入新节点
    if ((*root) == NULL) {
        (*root) = (AVLNode*)malloc(sizeof(AVLNode));
        (*root)->data = d;
        (*root)->b_index = 0;
        (*root)->left = (*root)->right = NULL;
    } else {
        if (d == (*root)->data) {
            printf("data is already exist\n");
            return;
        } else if (d < (*root)->data) {
            insert(&(*root)->left, d);
        } else {
            insert(&(*root)->right, d);
        }
        (*root)->b_index = get_balance_index(*root);         //更新平衡因子
        if ((*root)->b_index < -1 || (*root)->b_index > 1) {    //判断平衡是否被打破
            rotate(&(*root));
        }
    }
}

int delete(AVLTree* root, int d) {                              //删除节点
    if ((*root) == NULL) {
        printf("no such data");
        return 0;
    } else {
        if (d == (*root)->data) {
            if ((*root)->left && (*root)->right) {               //被删除节点左右儿子都存在时
                AVLNode *temp = (*root)->right;
                /// **************************************
                /// 另一种删除方式（把该节点左孩子接到后继节点的右孩子，并将该节点指针指向右孩子）
//                AVLNode *target = (*root);
//                while (temp->left) {                              //寻找后继节点
//                    temp = temp->left;
//                }
//                temp->left = (*root)->left;                      //将该节点后继节点左指针指向该节点的左孩子
//                (*root) = (*root)->right;                        //将指针指向右孩子
//                free(target);
                /// **************************************
                /// 将后继节点数据复制到该节点，并删除后继节点
                while (temp->left && temp->left->left) {
                    temp = temp->left;
                }
                AVLNode *p = temp;
                if (temp->left) {
                    p = temp->left;
                    temp->left = p->right;
                } else {
                    (*root)->right = temp->right;
                }
                (*root)->data = p->data;
                free(p);

            } else if ((*root)->left) {
                AVLNode *p = (*root);                            //右孩子为空，直接用左孩子替换该节点
                (*root) = (*root)->left;
                free(p);
            } else {                                             //左孩子为空，用右孩子替换该节点（右孩子可能也为空，则该节点指向NULL）
                AVLNode *p = (*root);
                (*root) = p->right;
                free(p);
            }
        } else if (d > (*root)->data) {
            delete(&(*root)->right, d);
        } else {
            delete(&(*root)->left, d);
        }
        if ((*root) == NULL) return 1;
        (*root)->b_index = get_balance_index(*root);
        if ((*root)->b_index < -1 || (*root)->b_index > 1) {    //从该节点向上更新平衡因子
            rotate(&(*root));
        }
    }
}


void PreOrder(AVLTree root) {
    if (root == NULL) return;
    PreOrder(root->left);
    printf("%d , balance index = %d \n", root->data, root->b_index);
    PreOrder(root->right);
}

int main() {
    AVLTree root = NULL;
    int b[10] = {53, 17, 78, 9, 45,  65, 94, 23, 81, 88};
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
