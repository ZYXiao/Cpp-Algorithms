/*
 循环队列-队列的顺序表示和实现
 */
#ifndef SqQueue_hpp
#define SqQueue_hpp

#include <stdio.h>
#include <iostream>

class SqQueue {
public:
    SqQueue(int size); // 构造函数，用于执行initQueue操作
    ~SqQueue(); // 析构函数，就是dealloc函数
    int queueLength(void); // 返回队列长度
    bool enQueue(int e); // 元素入队
    bool deQueue(int &e); // 元素出队
    void traveQueue(void); // 遍历循环队列，从队首开始
private:
    int *_base; // 初始化的动态分配存储空间
    int _front; // 头指针，若队列不空，指向队列头元素
    int _rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
    int _storageSize; // 循环队列总的内存空间大小
};

#endif /* SqQueue_hpp */
