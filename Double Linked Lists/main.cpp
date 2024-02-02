/*
 * Double Linked Lists
 * */

#include <iostream>
using namespace std;

template<typename t>
class Node
{
private:
    t data;
    Node<t> * next , * previous;
public:
    //Default constructor
    Node(){next = previous = nullptr;}
    //parameterized constructor
    Node(t data , Node<t>*next = nullptr , Node<t> *previous = 0)
    {
        this->data = data;
        this->next = next;
        this->previous = previous;
    }

    void setData(t data) {
        Node::data = data;
    }

    t getData() const {
        return data;
    }

    Node<t> *getNext() const {
        return next;
    }

    Node<t> *getPrevious() const {
        return previous;
    }

    void setNext(Node<t> *next) {
        Node::next = next;
    }

    void setPrevious(Node<t> *previous) {
        Node::previous = previous;
    }
};


template<typename t>
class LinkedList
{
private:
    Node<t> *head , *tail;
public:
    LinkedList()
    {
        head = tail = nullptr;
    }
    void InsertFirst(t data)
    {
        auto *new_node = new Node<t>(data);
        if(isempty())
        {
            new_node->setPrevious(nullptr);
            new_node->setNext(nullptr);
            head = tail = new_node;
        }
        else
        {
            new_node->setPrevious(nullptr);
            new_node->setNext(head);
            head = new_node;
        }
    }

    void InsertLast(t data)
    {
        if(isempty())
        {
            InsertFirst(data);
        }
        else
        {
            auto *new_node = new Node<t>(data);
            new_node->setNext(nullptr);
            new_node->setPrevious(tail);
            tail->setNext(new_node);
            tail = new_node;
        }
    }

    void DeleteLast()
    {
        auto *temp = new Node<t>;
        tail->getPrevious()->setNext(nullptr);
        temp = tail;
        tail = tail->getPrevious();
        delete temp;
    }
    bool isempty()
    {
        return (head == nullptr && tail == nullptr);
    }

    void DeleteFirst()
    {
        auto *temp = new Node<t>;
        head->getNext()->setPrevious(nullptr);
        temp = head;
        head = head->getNext();
        delete temp;
    }

    void Print()
    {
        auto *temp = new Node<t>;
        for(temp = head ; temp != nullptr ; temp = temp->getNext())
        {
            cout<<temp->getData()<<"   ";
        }

    }
};





int main() {
    LinkedList<int> list;
    list.InsertFirst(4);
    list.InsertFirst(2);
    list.InsertLast(6);
    list.DeleteLast();
    list.DeleteFirst();
    list.Print();
    return 0;
}
