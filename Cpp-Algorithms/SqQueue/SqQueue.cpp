#include "SqQueue.hpp"
#include <stdlib.h>

using namespace std;

SqQueue::SqQueue(int size) {
    // 也可以用C语言中的malloc方法实现，如下
    // base = (int *)malloc(size * sizeof(int));
    _base = new int[size];
    _front = 0;
    _rear = 0;
    _storageSize = size;
}

int SqQueue::queueLength(void) {
    return (_rear - _front + _storageSize) % _storageSize;
}

bool SqQueue::enQueue(int e) {
    if ((_rear + 1) % _storageSize == _front) {
        cout << "队列已满，不能入队" << endl; // 队列满的时候会有一个空置的元素，件教材；
        return false;
    }
    _base[_rear] = e;
    _rear = (_rear + 1) % _storageSize; // 入队的时候_rear++;
    return true;
}

bool SqQueue::deQueue(int &e) {
    if (_rear == _front) {
        cout << "队列为空，不能出队" << endl;
        return false;
    }
    e = _base[_front];
    _front = (_front + 1) % _storageSize; // 出队的时候_front++;
    return true;
}

void SqQueue::traveQueue() {
    cout << "遍历队列：";
    int _frontRef = _front;
    while (1) {
        cout << _base[_frontRef] << " ";
        _frontRef++;
        if (_frontRef == _rear) {
            break;
        }
    }
}

SqQueue::~SqQueue() {
}


