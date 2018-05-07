//
// Created by hpf on 18-5-7.
//

#ifndef DATASTRUCTURE_WITH_C_LINKLISTSTACK_H
#define DATASTRUCTURE_WITH_C_LINKLISTSTACK_H

#include "Stack.h"
#include "LinkList.h"

template<class T>
class LinkListStack : public Stack<T> {
public:
    LinkListStack() {
        linklist = new LinkList<T>();
    }

    int getSize() {
        return linklist->getSize();
    }

    void push(T e) {
        linklist->addFirst(e);
    }

    T pop() {
        linklist->removeFirst();
    }

    T peek() {
        linklist->getFirst();
    }

    bool isEmpty() {
        return linklist->isEmpty();
    }

    void print() {
        std::cout << "Stack: size = " << linklist->getSize() << std::endl;
        std::cout << "bottom ";
        linklist->toPrint();
        std::cout << " top" << std::endl;
    }

private:
    LinkList<T> *linklist;
};

#endif //DATASTRUCTURE_WITH_C_LINKLISTSTACK_H
