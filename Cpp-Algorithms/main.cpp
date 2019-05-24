//
//  main.cpp
//  Cpp-Algorithms
//
//  Created by baihui on 2019/5/23.
//  Copyright © 2019年 zyxiao. All rights reserved.
//

#include <iostream>
#include "SqQueue.hpp"
#include "BiTree.hpp"

using namespace std;

void visit(BiTNode *node) {
    cout << node->data;
}

int main(int argc, const char * argv[]) {
    /*
     SqQueue queue(5); // 初始化一个最大存储空间为5的循环队列
     queue.enQueue(2);
     queue.enQueue(7);
     queue.enQueue(8);
     queue.enQueue(9);
     int e;
     if (queue.deQueue(e)) {
     cout << e << ":成功出队" << endl;
     }
     if (queue.deQueue(e)) {
     cout << e << ":成功出队" << endl;
     }
     */
    
    BiTree tree;
    int width = tree.getWidth();
    cout << "该二叉树的宽度为：" << width << endl;
    
    return 0;
}
