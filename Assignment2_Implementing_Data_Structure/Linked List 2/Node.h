//
// Created by Omar Youssif on 8/15/2023.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template<class t>
class Node {
private:
    t data;
    Node<t> *next;
public:
    Node();
    Node(t data , Node<t> *next = nullptr);

    t getData() const;

    Node<t> *getNext() const;

    void setData(t data);

    void setNext(Node<t> *next);
};

#endif //LINKED_LIST_NODE_H
