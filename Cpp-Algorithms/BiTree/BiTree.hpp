/*
 二叉链表
 */
#ifndef BiTree_hpp
#define BiTree_hpp

#include <stdio.h>

// 二叉链表节点结构体
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode;

// 这个结构体用于计算二叉树宽度
typedef struct LevelNode {
    BiTNode *node;
    int level;
}LevelNode;

typedef enum {
    TraverseTypePreOrder = 0,
    TraverseTypeInOrder,
    TraverseTypePostOrder
}TraverseType;

class BiTree {
private:
    // 二叉链表总结点个数
    int nodeCount;
    
public:
    // 二叉链表根节点，因为要递归调用所以才设置为public；
    BiTNode *root;
    
    // 构造函数
    BiTree();
    // 析构函数
    ~BiTree();
    
    // 用先序递归的方式创建二叉树
    void createBitTree(BiTNode *&node);
    
    /* 二叉树遍历 */
    // 前序遍历，如果递归调用则参数中需要有node字段
    void preOrderTraverse(BiTNode *node ,void (*visit)(BiTNode *node));
    void preOrderTraverseNonRecursion(void (*visit)(BiTNode *node));
    // 中序遍历，如果递归调用则参数中需要有node字段
    void inOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node));
    void inOrderTraverseNonRecursion(void (*visit)(BiTNode *node));
    // 后序遍历，如果递归调用则参数中需要有node字段
    void postOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node));
    void postOrderTraverseNonRecursion(void (*visit)(BiTNode *node));
    // 层次遍历，非递归调用所以参数中不带node字段
    void levelOrderTraverse(void (*visit)(BiTNode *node));
    
    // 获取二叉树深度
    int getDepth(BiTNode *node);
    // 获取二叉树宽度（定义宽度为结点数最多的那一层的节点数）
    // 参数：nodeCount-总结点个数；
    int getWidth(void);
    
    // 查找data域值为key的第一个节点
    void search(BiTNode *p, BiTNode *&q, char key);
    
    // 获取总结点个数
    int getNodeCount(void);
};

#endif /* BiTree_hpp */
