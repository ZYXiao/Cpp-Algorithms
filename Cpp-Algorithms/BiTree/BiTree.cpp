#include "BiTree.hpp"
#include <iostream>

using namespace std;

// https://blog.csdn.net/chixujohnny/article/details/50900804
BiTree::BiTree() {
    createBitTree(root);
}

void BiTree::createBitTree(BiTNode *&node) {
    cout << "请输入节点:"; // 输入节点的data
    char ch;
    cin >> ch;
    if (ch == '#') { // 输入空格符号
        node = NULL;
    } else {
        node = new BiTNode;
        node->data = ch;
        createBitTree(node->lchild);
        createBitTree(node->rchild);
    }
}

void BiTree::preOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node)) {
    if (node != NULL) {
        visit(node);
        preOrderTraverse(node->lchild, visit);
        preOrderTraverse(node->rchild, visit);
    }
}

void BiTree::inOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node)) {
    if (node != NULL) {
        inOrderTraverse(node->lchild, visit);
        visit(node);
        inOrderTraverse(node->rchild, visit);
    }
}

void BiTree::postOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node)) {
    if (node != NULL) {
        postOrderTraverse(node->lchild, visit);
        postOrderTraverse(node->rchild, visit);
        visit(node);
    }
}

void BiTree::levelOrderTraverse(void (*visit)(BiTNode *node)) {
    // 这里直接从根节点开始进行遍历
    if (root != NULL) {
        int maxSize = 50;
        BiTNode *queue = new BiTNode[maxSize]; // 这里定义的是存放BiTNode结构体的数组
        int front = 0;
        int rear = 0;
        queue[rear] = *root;
        rear = (rear + 1) % maxSize;
        while (rear != front) { // 这里很关键：当队列不空时再进行循环
            BiTNode node = queue[front];
            front = (front + 1) % maxSize;
            visit(&node);
            if (node.lchild != NULL) {
                queue[rear] = *node.lchild;
                rear = (rear + 1) % maxSize;
            }
            if (node.rchild != NULL) {
                queue[rear] = *node.rchild;
                rear = (rear + 1) % maxSize;
            }
        }
    }
}

int BiTree::getDepth(void) {
    return 1;
}

void BiTree::search(BiTNode *p, BiTNode *&q, char key) {
    if (p != NULL) {
        if (p->data == key) {
            q = p;
        } else {
            search(p->lchild, q, key);
            if (q == NULL) {
                search(p->rchild, q, key);
            }
        }
    }
}

BiTree::~BiTree() {
}
