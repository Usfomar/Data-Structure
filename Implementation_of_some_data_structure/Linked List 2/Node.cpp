//
// Created by Omar Youssif on 8/15/2023.
//

#include<iostream>
#include "Node.h"
using namespace std;
template<class t>
Node<t>::Node() {
    next = nullptr;
}
template<class t>
Node<t>::Node(t data, Node<t> *next) {
    this->data = data;
    this->next = next;
}

template<class t>
t Node<t>::getData() const {
    return data;
}

template<class t>
Node<t> *Node<t>::getNext() const {
    return next;
}

template<class t>
void Node<t>::setData(t data) {
    Node::data = data;
}

template<class t>
void Node<t>::setNext(Node<t> *next) {
    Node::next = next;
}


template class Node<int>;
template class Node<float>;
template class Node<double>;
template class Node<string>;
template class Node<char>;
