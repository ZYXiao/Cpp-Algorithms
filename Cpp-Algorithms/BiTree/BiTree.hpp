/*
 二叉链表
 */
#ifndef BiTree_hpp
#define BiTree_hpp

#include <stdio.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode;

typedef enum {
    TraverseTypePreOrder = 0,
    TraverseTypeInOrder,
    TraverseTypePostOrder
}TraverseType;

class BiTree {
public:
    BiTNode *root;
    BiTree();
    ~BiTree();
    void createBitTree(BiTNode *&node); //  用先序递归的方式创建二叉树
    void preOrderTraverse(BiTNode *node ,void (*visit)(BiTNode *node)); // 前序遍历，递归调用所以参数中需要有node字段
    void inOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node)); // 中序遍历，递归调用所以参数中需要有node字段
    void postOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node)); // 后序遍历，递归调用所以参数中需要有node字段
    void levelOrderTraverse(void (*visit)(BiTNode *node)); // 层次遍历，非递归调用所以参数中不带node字段
    int getDepth(void); // 获取二叉树深度
    void search(BiTNode *p, BiTNode *&q, char key); // 查找data域值为key的第一个节点
};

#endif /* BiTree_hpp */
