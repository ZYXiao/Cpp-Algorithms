/*
 链队列-队列的链式表示和实现
 */
#ifndef LinkQueue_hpp
#define LinkQueue_hpp

#include <stdio.h>

typedef struct QNode {
    int data;
    struct QNode *next;
}QNode;

class LinkQueue {
private:
    QNode *front; // 队头指针
    QNode *rear; // 队尾指针
public:
    LinkQueue();
    ~LinkQueue();
    bool isQueueEmpty(void); // 判断队列是否为空
    bool enQueue(int e); // 入队
    bool deQueue(int &e); // 出队
};

#endif /* LinkQueue_hpp */
