//
// Created by Omar Youssif on 8/15/2023.
//
#include<iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

//Default constructor
template<class t>
LinkedList<t>::LinkedList(): head(nullptr) , tail(nullptr) , size(0) {}
//Returns the number of nodes in the linked list
template<class t>
int LinkedList<t>::getSize()  {
    return size;
}

//Check if the list is empty or not
template<class t>
bool LinkedList<t>::isEmpty() {return(head== nullptr);}

//Add items in the list on the front
template<class t>
void LinkedList<t>::AddToHead(t value) {
    auto *new_node = new Node<t>(value);
    if(isEmpty())
    {
        head = tail = new_node;
        new_node->setNext(nullptr);
    }
    else
    {
        new_node->setNext(head);
        head = new_node;
    }
    size++;
}

//Add items but at the end of the list
template<class t>
void LinkedList<t>::AddToTail(t value) {
    auto *new_node = new Node<t>(value);
    if(isEmpty())
    {
        AddToHead(value);
    }
    else if(head == tail)
    {
        head = tail = new_node;
    }
    else
    {
        tail->setNext(new_node);
        tail = new_node;
        new_node->setNext(nullptr);
    }
    size++;
}

//Remove items from the head
template<class t>
t LinkedList<t>::RemoveFromHead()
{
    t n;
    auto *temp = head;
    if(isEmpty())
    {
        throw runtime_error ("The list is empty");
    }
    else if(head == tail)
    {
        head = tail = nullptr;
        n = temp->getData();
        delete temp;
        size--;
        return n;
    }
    else
    {
        head = head->getNext();
        temp ->setNext(nullptr);
        n = temp->getData();
        delete temp;
        size--;
        return n;
    }
}

//Removes items from the tail
template<class t>
t LinkedList<t>::RemoveFromTail() {
    t n;
    auto *temp = head;
    if(isEmpty())
    {
        throw runtime_error ("The list has no element to delete");
    }
    else if(head == tail)
    {
        head = tail = nullptr;
        n = temp->getData();
        delete temp;
        size--;
        return n;
    }
    else
    {
        while(temp->getNext() != tail)
        {
            temp = temp ->getNext();
        }
        tail = temp;
        temp = temp ->getNext();
        tail->setNext(nullptr);
        n = temp->getData();
        delete temp;
        size--;
        return n;
    }
}
//Delete all Nodes in the List
template<class t>
void LinkedList<t>::clear()
{
    if(isEmpty())
    {
    }
    else
    {
        while (head != nullptr)
        {
            auto *temp = head;
            head = head->getNext();
            delete temp;
        }
        size = 0;
    }
}

//Return the value which at the head
template<class t>
t LinkedList<t>::GetValueAtHead() {
    if(isEmpty())
    {
        throw runtime_error ("The list is empty");
    }
    return head->getData();
}

//Swap elements pairwise
template<class t>
void LinkedList<t>::PairwiseSwap() {
    auto *temp = head;
    while(temp != nullptr && temp->getNext() != nullptr)
    {
        //Swap the data between each node and the node after it
        t x = temp->getData();
        temp->setData(temp->getNext()->getData());
        temp ->getNext()->setData(x);

        //Moves 2 nodes
        temp = temp->getNext()->getNext();
    }
}

//Removes the duplicates in the list
template<class t>
void LinkedList<t>::RemoveDuplicates() {
    auto *temp = head;
    while(temp != nullptr && temp->getNext() != nullptr)
    {
        auto *temp2 = temp;
        while(temp2->getNext() != nullptr)
        {
            if(temp->getData() == temp2->getNext()->getData())
            {

                auto *c = temp2->getNext();
                if(c == tail)
                {
                    tail = temp2;
                    tail->setNext(nullptr);
                    temp2->setNext(c->getNext());
                    delete c;
                    size--;

                }
                else
                {
                    temp2->setNext(c->getNext());
                    delete c;
                    size--;
                }
            }
            else
            {
                temp2 = temp2 -> getNext();
            }

        }
        temp = temp->getNext();
    }
}


//To delete the list after use it
template<class t>
LinkedList<t>::~LinkedList<t>()
{
    cout<<"The list is deleted"<<endl;
    clear();
}

template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<string>;
template class LinkedList<char>;
