# 二叉搜索树 && 二叉平衡树（C语言实现）

## 二叉搜索树

#### 性质：

1. 若它的左子树不空，则左子树上节点的值都小于根节点的值
2. 若它的右子树不空，则右子树上节点的值都大于根节点的值
3. 若左右子树都不空，则左右子树也是二叉搜索树

### 节点定义

```C
typedef struct BSNode {
    int data;
    struct BSNode *left;
    struct BSNode *right;
} BSNode, *BSTree;
```



### 查找操作

```c
BSNode *search(BSTree root, int d) {
    if (root != NULL) {
        BSNode *temp = root;
        if (d == temp->data) {
            printf("I Find %d \n", temp->data);
            return temp;
        } else if (d < temp->data) {
            search(temp->left, d);
        } else {
            search(temp->right, d);
        }
    } else {
        printf("no such data!");
        return NULL;
    }
}
```



### 插入操作

```C
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
```



### 删除节点操作

```C
void deleteNode(BSTree *root, int d) {
    if (*root == NULL) {
        printf("no such data\n");
    } else {
        if ((*root)->data == d) {
            if((*root)->left && (*root)->right) {
                BSNode *temp = (*root)->right;
                /// *********************************
                /// 另一种删除方式（把该节点左孩子接到后继节点的右孩子，并将该节点指针指向右孩子）
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
            deleteNode(&(*root)->left, d);
        } else {
            deleteNode(&(*root)->right, d);
        }
    }
}
```



## 平衡二叉树（AVL树）

#### 性质：

在二叉搜索树基础上左右子树高度差（平衡因子）小于等于1

#### 特殊处理：

在插入和删除节点时,会引起平衡因子的变化,若平衡被打破,则进行一系列操作(旋转最小不平衡子树),恢复树的平衡

### 节点定义

```C
typedef struct AVLNode {
    int data;
    int b_index;			//平衡因子
    struct AVLNode* left;
    struct AVLNode* right;
}AVLNode,* AVLTree;
```



### 计算平衡因子

```c
int get_hight(AVLNode *t) {                         //获取树高
    if (t == NULL) return 0;
    return max(get_hight(t->left), get_hight(t->right)) + 1;
}

int get_balance_index(AVLNode* t) {                 //获取平衡因子
    return get_hight(t->left) - get_hight(t->right);
}
```



### 旋转操作

```C
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
        if ((*root)->left->b_index < 0) {           //LR 先左旋后右旋
            l_rotate(&(*root)->left);
            r_rotate(&(*root));
        } else if ((*root)->left->b_index > 0) {    //LL 左旋
            r_rotate(&(*root));
        }
    } else if ((*root)->b_index < -1) {
        if ((*root)->right->b_index < 0) {          //RR 右旋
            l_rotate(&(*root));
        } else {
            r_rotate(&(*root)->right);          	//RL情况先右旋后左旋
            l_rotate(&(*root));
        }
    }
}
```



### 查找操作

```c
AVLTree *search(AVLTree root, int d) {
    if (root != NULL) {
        AVLTree *temp = root;
        if (d == temp->data) {
            printf("I Find %d \n", temp->data);
            return temp;
        } else if (d < temp->data) {
            search(temp->left, d);
        } else {
            search(temp->right, d);
        }
    } else {
        printf("no such data!");
    }
    return NULL;
}
```



### 插入操作

```C
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
```



### 删除操作

```C
int deleteNode(AVLTree* root, int d) {                              //删除节点
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
//                temp->left = (*root)->left;         //将该节点后继节点左指针指向该节点的左孩子
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
                AVLNode *p = (*root);     	//右孩子为空，直接用左孩子替换该节点
                (*root) = (*root)->left;
                free(p);
            } else {           	//左孩子为空，用右孩子替换该节点（右孩子可能也为空，则该节点指向NULL
                AVLNode *p = (*root);
                (*root) = p->right;
                free(p);
            }
        } else if (d > (*root)->data) {
            deleteNode(&(*root)->right, d);
        } else {
            deleteNode(&(*root)->left, d);
        }
        if ((*root) == NULL) return 1;
        (*root)->b_index = get_balance_index(*root);
        if ((*root)->b_index < -1 || (*root)->b_index > 1) {    //从该节点向上更新平衡因子
            rotate(&(*root));
        }
    }
}
```

