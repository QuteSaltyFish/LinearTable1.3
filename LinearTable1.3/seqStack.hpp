//
// Created by Mingke Wang on 2018/10/27.
//

#ifndef LINETABLE1_3_SEQSTACK_H
#define LINETABLE1_3_SEQSTACK_H

#include <iostream>
using namespace std;

template <class T>
class seqStack{
private:
    T **elem;   //[][0]是时间 [][1]是车牌号
    int top_p;      //指针下标
    int maxsize;
    void doublespace();
    
public:
    seqStack(int initsize = 0);
    ~seqStack();
    bool isEmpty();
    void push(const T &x, T n);
    T pop();
    int top() const;
    bool isFull();
};

template <class T>
bool seqStack<T>::isFull() {
    return top_p == (maxsize -1);
}

template <class T>
seqStack<T>::seqStack(int initsize) {
    elem = new T*[initsize];
    for (int i=0; i<initsize; ++i)
        elem[i] = new T[2];
    maxsize = initsize;
    top_p = -1;
}

template <class T>
seqStack<T>::~seqStack() {
    delete [] elem;
}


template <class T>
bool seqStack<T>::isEmpty() {
    return top_p == -1;
}

template <class T>
void seqStack<T>::push(const T &x, T n) {
    if (top_p == maxsize-1)
        return;
    elem[++top_p][0] = x;
    elem[top_p][1] = n;
}

template <class T>
T seqStack<T>::pop() {
    return elem[top_p--][0];
}

template <class T>
int seqStack<T>::top() const {
    return elem[top_p][1];
}

template <class T>
void seqStack<T>::doublespace() {
    T *tmp = elem;
    elem = new T[2 * maxsize];
    for (int i=0; i<maxsize; ++i)
        elem[i] = tmp[i];
    maxsize *= 2;
    delete [] tmp;
}
#endif //LINETABLE1_3_SEQSTACK_H
