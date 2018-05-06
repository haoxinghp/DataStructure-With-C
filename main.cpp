#include <iostream>
#include "Array.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"

template<typename T>
static double testQueue(Queue<T> *queue, T rangeL, T rangeR, int opCount) {
    clock_t startTime = clock();
    srand(66);
    for (int i = 0; i < opCount; ++i) {
        queue->enqueue(INT32_MAX);
    }
    for (int j = 0; j < opCount; ++j) {
        queue->dequeue();
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
    ArrayStack<int> *stack = new ArrayStack<int>(5);
    for (int i = 0; i < 5; ++i) {
        stack->push(i);
        stack->print();
    }
    stack->push(300);
    stack->push(500);
    stack->print();
    stack->pop();
    stack->print();
    std::cout << stack->peek() << std::endl;

    ArrayQueue<int> *queue = new ArrayQueue<int>(5);
    for (int j = 0; j < 5; ++j) {
        queue->enqueue(j);
        queue->print();
    }
    queue->enqueue(20);
    queue->enqueue(33);
    queue->print();
    queue->dequeue();
    queue->print();
    std::cout << queue->getFront() << std::endl;

    LoopQueue<int> *loopQueue1 = new LoopQueue<int>(5);
    for (int j = 0; j < 5; ++j) {
        loopQueue1->enqueue(j);
        loopQueue1->print();
    }
    loopQueue1->enqueue(20);
    loopQueue1->enqueue(33);
    loopQueue1->print();
    loopQueue1->dequeue();
    loopQueue1->print();
    std::cout << loopQueue1->getFront() << std::endl;

    int opCount = 100000;
    ArrayQueue<int> *arrayQueue = new ArrayQueue<int>();
    clock_t startTime = clock();
    srand(66);
    for (int i = 0; i < opCount; ++i) {
        arrayQueue->enqueue(rand());
    }
    for (int j = 0; j < opCount; ++j) {
        arrayQueue->dequeue();
    }
    clock_t endTime = clock();
    std::cout << "ArrayQueue time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<< std::endl;
    LoopQueue<int> *loopQueue = new LoopQueue<int>();
    startTime = clock();
    srand(66);
    for (int i = 0; i < opCount; ++i) {
        loopQueue->enqueue(rand());
    }
    for (int j = 0; j < opCount; ++j) {
        loopQueue->dequeue();
    }
    endTime = clock();
    std::cout << "LoopQueue time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<< std::endl;
    return 0;
}