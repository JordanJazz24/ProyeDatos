//
// Created by 50683 on 9/29/2022.
//

#ifndef PRUBITALISTTA_LINKEDLIST_H
#define PRUBITALISTTA_LINKEDLIST_H


#include "Node.h"
#include "Integer.h"

template<typename T>class LinkedList{
private:
    Node<T>* head;
public:
    LinkedList();

    void add(Integer number);

    void addFront(GenericMyVector<T> item);

    void add(int index, GenericMyVector<T> item);

    int length();

    void displayAll();

    void remove();

    void remove(int index);

    void removeFront();

    T get(int index);

};

template<typename T>
LinkedList<T>::LinkedList() {
    this->head = NULL;

}

template<typename T>
void LinkedList<T>::add(Integer number) {


    string numberAux = number.toString();
    GenericMyVector<int> vecAux;

    while (numberAux.size() != 0) {

        string aux;

        if (numberAux.size() > 5) {
            for (int i = 0; i < 5; i++) {

                aux = aux + numberAux[i];
            }

            numberAux.erase(0, 5);
        }else {
            for (int i = 0; i < numberAux.size(); i++) {

                aux = aux + numberAux[i];
            }
            numberAux.erase(0, numberAux.size());
        }
        int num = stoi(aux);
        vecAux.push_back(num);
       // cout << "\n" << num;
    }

    Node<T>* node = new Node<T>[1];
    node->data = vecAux;
    if(head == NULL){
        head = node;
        cout<<"new node added(firstnode) !"<<endl;
        return;
    }
    Node<T>* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    cout<<"new node added at back!"<<endl;
}

template<typename T>
void LinkedList<T>::addFront(GenericMyVector<T> item) {
    Node<T>* node = new Node<T>[1];
    node->data = item;
    if(head == NULL){
        head = node;
        cout<<"new node added(firstnode) !"<<endl;
        return;
    }
    node->next = head;
    head = node;
    cout<<"new node added at front !"<<endl;
}

template<typename T>
void LinkedList<T>::add(int index, GenericMyVector<T> item) {
    if(index > length() || index < 0){
        cout<<"index out of bound !"<<endl;
        return;
    }
    Node<T>* node = new Node<T>[1];
    node->data = item;
    int count = 0;
    Node<T>* temp = head;
    while(temp != NULL && count < index){
        if(count == index-1){
            if(temp->next != NULL){
                node->next = temp->next;
            }
            temp->next = node;
            cout<<"new node added at index "<<index<<" !"<<endl;
            break;
        }
        count++;
        temp = temp->next;
    }

}

template<typename T>
int LinkedList<T>::length() {
    int len = 0;
    Node<int>* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

template<typename T>
void LinkedList<T>::displayAll() {
    if(head == NULL){
        cout<<"linked list is empty"<<endl;
        return;
    }
    cout<<endl<<"----link list items------"<<endl;
    Node<T>* temp = head;
    int numeroNodo=0;
    while(temp != NULL){
        cout<<"Nodo# " + std::to_string(numeroNodo) <<endl;

        for(int i=0; i<temp->data.size(); i++) {
            cout << temp->data[i] << " | ";
        }
        cout<<endl;
        numeroNodo++;
        temp = temp->next;
    }
    cout<<endl<<"--------------------------"<<endl;
}

template<typename T>
void LinkedList<T>::remove() {
    if(head == NULL){
        cout<<"linked list is empty !"<<endl;
        return;
    }
    if(head->next == NULL){
        head = NULL;
        cout<<"last item removed"<<endl;
        return;
    }

    Node<T>* temp = head;
    while(temp != NULL){
        if(temp->next->next == NULL){
            temp->next = NULL;
            cout<<"last item removed"<<endl;
            break;
        }
        temp = temp->next;
    }
}

template<typename T>
void LinkedList<T>::remove(int index) {
    if(head == NULL){
        cout<<"linked list is empty !"<<endl;
        return;
    }
    if(index >= length() || index < 0){
        cout<<"index out of bound !"<<endl;
        return;
    }
    if(index == 0){
        removeFront();
        cout<<"item removed at index "<<index<<endl;
        return;
    }

    int count = 0;
    Node<T>* temp = head;
    while(temp != NULL){
        if(count == index - 1){
            temp->next = temp->next->next;
            cout<<"item removed at index "<<index<<endl;
            break;
        }
        count++;
        temp = temp->next;
    }
}

template<typename T>
void LinkedList<T>::removeFront() {
    if(head == NULL){
        cout<<"linked list is empty !"<<endl;
        return;
    }
    head = head->next;
    cout<<"front item removed"<<endl;
}

template<typename T>
T LinkedList<T>::get(int index) {
    if(head == NULL){
        cout<<"linked list is empty !"<<endl;
        return -9999;
    }
    if(index >= length() || index < 0){
        cout<<"index out of bound !"<<endl;
        return -9999;
    }
    if(index == 0){
        return head->data;
    }
    int count = 0;
    T res;
    Node<T>* temp = head;
    while(temp != NULL){
        if(count++ == index){
            res = temp->data;
            break;
        }
        temp = temp->next;
    }
    return res;
}


#endif //PRUBITALISTTA_LINKEDLIST_H
