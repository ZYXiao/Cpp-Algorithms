#include "BiTree.hpp"
#include <iostream>
#include <math.h>

using namespace std;

// https://blog.csdn.net/chixujohnny/article/details/50900804
BiTree::BiTree() {
    nodeCount = 0;
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
        nodeCount++;
        createBitTree(node->lchild);
        createBitTree(node->rchild);
    }
}

void BiTree::preOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node)) {
    if (node != NULL) {
        if (visit != NULL) {
            visit(node);
        }
        preOrderTraverse(node->lchild, visit);
        preOrderTraverse(node->rchild, visit);
    }
}

void BiTree::preOrderTraverseNonRecursion(void (*visit)(BiTNode *node)) {
    if (root != NULL) {
        BiTNode *stack[nodeCount]; // 初始化栈
        int top = -1; // 初始化栈
        stack[++top] = root; // 头结点入栈
        while (top != -1) { // 栈不为空才执行循环
            BiTNode *node = stack[top--]; // 元素出栈
            if (visit != NULL) {
                visit(node); // 访问结点
            }
            if (node->rchild != NULL) {
                stack[++top] = node->rchild; // 注意：这里右结点先入栈
            }
            if (node->lchild != NULL) {
                stack[++top] = node->lchild; // 注意：左结点后入栈
            }
        }
    }
}

void BiTree::inOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node)) {
    if (node != NULL) {
        inOrderTraverse(node->lchild, visit);
        if (visit != NULL) {
            visit(node);
        }
        inOrderTraverse(node->rchild, visit);
    }
}

void BiTree::inOrderTraverseNonRecursion(void (*visit)(BiTNode *node)) {
    BiTNode *stack[nodeCount];
    int top = -1;
    BiTNode *p = root;
    while (top != -1 || p != NULL) {
        while (p != NULL) {
            stack[++top] = p;
            p = p->lchild;
        }
        if (top != -1) { // 栈不为空的时候出栈
            p = stack[top--];
            if (visit != NULL) {
                visit(p);
            }
            p = p->rchild;
        }
    }
}

void BiTree::postOrderTraverse(BiTNode *node, void (*visit)(BiTNode *node)) {
    if (node != NULL) {
        postOrderTraverse(node->lchild, visit);
        postOrderTraverse(node->rchild, visit);
        if (visit != NULL) {
            visit(node);
        }
    }
}

void BiTree::postOrderTraverseNonRecursion(void (*visit)(BiTNode *node)) {
    
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
            if (visit != NULL) {
                visit(&node);
            }
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

// 计算二叉树深度的思想是max(左子树深度，右子树深度)+1；
// 采用后续遍历计算深度；
int BiTree::getDepth(BiTNode *node) {
    if (node == NULL) {
        return 0; // 空树的深度为0
    }
    int ld = getDepth(node->lchild);
    int rd = getDepth(node->rchild);
    return ld > rd ? ld + 1 : rd + 1;
}

int BiTree::getWidth(void) {
    if (root != NULL) {
        LevelNode *queue[nodeCount]; // 这里定义了一个非循环但空间足够大的队列
        int front = 0;
        int rear = 0;
        LevelNode *node = new LevelNode;
        node->level = 1;
        node->node = root;
        queue[rear] = node;
        rear++; // 非循环但空间足够大的队列这里只要++
        while (front != rear) {
            LevelNode *levelNode = queue[front];
            front++;
            BiTNode *biTNode = levelNode->node;
            if (biTNode->lchild != NULL) {
                node = new LevelNode;
                node->level = (levelNode->level + 1);
                node->node = biTNode->lchild;
                queue[rear] = node;
                rear++;
            }
            if (biTNode->rchild != NULL) {
                node = new LevelNode;
                node->level = (levelNode->level + 1);
                node->node = biTNode->rchild;
                queue[rear] = node;
                rear++;
            }
        }
        // 到这一步，queue中已存满了所有的结点信息，接下来遍历去获取二叉树的宽度
        int max = 0;
        int levelCount = 0;
        int curLevel = 1;
        for (int i = 0; i < nodeCount; i ++) {
            LevelNode *levelNode = queue[i];
            if (levelNode->level == curLevel) {
                levelCount ++;
            } else {
                if (max < levelCount) {
                    max = levelCount;
                }
                curLevel = levelNode->level;
                levelCount = 1;
            }
        }
        return max < levelCount ? levelCount : max;
    }
    return 0;
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

// 注意：这个算法没有考虑到内存的释放
void BiTree::getLevelNodeInfo(LevelNode ***&info, int &depth) {
    if (root != NULL) {
        LevelNode **queue = new LevelNode *[nodeCount]; // 这里定义了一个非循环但空间足够大的队列
        int front = 0;
        int rear = 0;
        LevelNode *node = new LevelNode;
        node->level = 1;
        node->node = root;
        queue[rear] = node;
        rear++; // 非循环但空间足够大的队列这里只要++
        while (front != rear) {
            LevelNode *levelNode = queue[front];
            front++;
            BiTNode *biTNode = levelNode->node;
            if (biTNode->lchild != NULL) {
                node = new LevelNode;
                node->level = (levelNode->level + 1);
                node->node = biTNode->lchild;
                queue[rear] = node;
                rear++;
            }
            if (biTNode->rchild != NULL) {
                node = new LevelNode;
                node->level = (levelNode->level + 1);
                node->node = biTNode->rchild;
                queue[rear] = node;
                rear++;
            }
        }
        // 到这一步一维数组queue里面存储了所有的结点信息
        // 下面去分解一维数组queue得到二维数组info
        LevelNode *lastNode = queue[nodeCount - 1];
        depth = lastNode->level; // 获取二叉树的深度
        int maxWidth = pow(2, depth - 1); // 层上结点的最大个数
        info = new LevelNode **[depth];
        int row = 0;
        int column = 0;
        info[row] = new LevelNode *[maxWidth](); // 加()可统一全部初始化，参考https://blog.csdn.net/sinat_32427167/article/details/52901883
        for (int i = 0; i < nodeCount; i ++) {
            LevelNode *levelNode = queue[i];
            if (levelNode->level == row + 1) { // 层次号是从1开始的
                info[row][column++] = levelNode;
            } else {
                info[++row] = new LevelNode *[maxWidth]();
                column = 0;
                info[row][column++] = levelNode;
            }
        }
    } else {
        info = NULL;
        depth = 0;
    }
}

BiTNode *BiTree::getRoot(void) {
    return root;
}

int BiTree::getNodeCount() {
    return nodeCount;
}

// 算法思想：
// 1、完全二叉树第depth-1层上面结点数一定是满的；
// 2、遍历第depth-1层上的结点的左右孩子，如果出现过Null之后又出现了非Null的孩子则为非完全二叉树；
bool BiTree::isCompletely(void) {
    LevelNode ***info;
    int depth;
    getLevelNodeInfo(info, depth);
    if (!depth) { // 空树为非完全二叉树；
        return false;
    }
    if (depth == 1) { // 只有一个结点的树为完全二叉树；
        return true;
    }
    LevelNode **arr = info[depth - 2];
    int max = pow(2, depth - 2);
    bool meetNull = false;
    for (int i = 0; i < max; i++) {
        LevelNode *ln = arr[i];
        if (ln == NULL) {
            return false; // 第(depth-1)层上结点不满的话为非完全二叉树；
        }
        if (meetNull && (ln->node->lchild || ln->node->rchild)) {
            return false;
        }
        if (!ln->node->lchild && ln->node->rchild) {
            return false;
        }
        if (!ln->node->lchild || !ln->node->rchild) {
            meetNull = true;
        }
    }
    return true;
}

bool BiTree::isFull(void) {
    int depth;
    LevelNode ***info;
    getLevelNodeInfo(info, depth);
    LevelNode **arr = info[depth - 1];
    int maxCount = pow(2, depth - 1);
    // 遍历计算数组中有效的元素个数，用sizeOf只可以计算出数组所占有的空间大小；
    int count = 0;
    for (int i = 0; i < maxCount; i++) {
        LevelNode *node = arr[i];
        if (node != NULL) {
            count++;
        } else {
            break;
        }
    }
    if (maxCount == count) {
        return true;
    }
    return false;
}

BiTree::~BiTree() {
}
