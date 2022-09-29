//
// Created by 50683 on 9/29/2022.
//

#ifndef PRUBITALISTTA_NODE_H
#define PRUBITALISTTA_NODE_H


#include<iostream>
#include "GenericMyVector.h"
using namespace std;

template<typename T>class Node{
private:
    GenericMyVector<T> data;
    Node<T>* next;
    template<typename U>friend class LinkedList;
public:
    Node();
};

template<typename T>
Node<T>::Node() {
    this->next = NULL;

}


#endif //PRUBITALISTTA_NODE_H
