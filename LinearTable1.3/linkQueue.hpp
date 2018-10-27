//
// Created by Mingke Wang on 2018/10/27.
//

#ifndef LINETABLE1_3_LINKQUEUE_H
#define LINETABLE1_3_LINKQUEUE_H

template  <class T>
class linkQueue {
private:
    struct node
    {
        T data; //代表着车的编号
        node * next;
        node(const T &x,node *N = nullptr)
        {
            data = x;
            next = N;
        }
        node():next(nullptr){}
        ~node(){};
    };
    
    node *front, *rear;
    
public:
    linkQueue();
    ~linkQueue();
    bool isEmpty() const;
    void enQueue(const T &x);
    T dequeue();
    T getHead() const;
};


template <class T>
linkQueue<T>::linkQueue() {
    front = rear = nullptr;
}

template <class T>
linkQueue<T>::~linkQueue() {
    node *tmp;
    while (front != nullptr)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template <class T>
bool linkQueue<T>::isEmpty() const {
    return front == nullptr;
}


template <class T>
T linkQueue<T>::getHead() const {
    return front->data;
}

template <class T>
void linkQueue<T>::enQueue(const T &x) {
    if (rear == nullptr)       //入队前为空队列
        front = rear = new node(x);
    else
        rear = rear->next = new node(x);
}

template <class T>
T linkQueue<T>::dequeue() {
    node *tmp = front;
    T value = tmp->data;
    front = front->next;
    if (front == nullptr)
        rear = nullptr;
    delete tmp;
    return value;
}
#endif //LINETABLE1_3_LINKQUEUE_H
