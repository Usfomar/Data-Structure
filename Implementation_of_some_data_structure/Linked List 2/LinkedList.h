//
// Created by Omar Youssif on 8/15/2023.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H
#include "Node.h"
using namespace std;
template<class t>
class LinkedList {
private:
    Node<t>*head , *tail;
    int size;
public:
    LinkedList();
    void AddToHead(t value);
    void AddToTail(t value);
    t RemoveFromHead();
    t RemoveFromTail();
    t GetValueAtHead();
    void PairwiseSwap();
    void RemoveDuplicates();
    void clear();
    bool isEmpty();
    int getSize();


    ~LinkedList();








    friend ostream& operator<<(ostream&out , LinkedList<t>& list)
    {
        if(list.isEmpty())
        {
            cout<<"The list has no elements to print"<<endl;
        }
        auto *current = list.head;
        while(current != nullptr)
        {
            out<<current->getData();
            if(current->getNext() != nullptr)
            {
                out<<" <- ";
            }
            current = current->getNext();
        }
        out<<endl;
        return out;
    }
};


#endif //LINKED_LIST_LINKEDLIST_H
