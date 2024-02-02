#include <iostream>
using namespace std;
//Create Node Class

template<typename  T>
class Node
{
private:
    T data;
    Node* next;
public:
    int getData() const {
        return data;
    }

    Node *getNext() const {
        return next;
    }

    void setValue(T data) {
        this->data = data;
    }

    void setNext(Node *next) {
        this->next = next;
    }
};

//Create the Linked List Class
template<typename T>
class LinkedList
{
private:
    Node<T>* head;
public:
    LinkedList(){head = nullptr;}

    bool isempty(){return(head==nullptr);}

    void InsertFirst(T value)
    {

        Node<T> *new_node  = new Node<T>;
        new_node->setValue(value);
        if(isempty()) {
            head = new_node;
            new_node->setNext(nullptr);
        }
        else
        {
            new_node->setNext(head);
            head = new_node;
        }
    }

    void InsertLast(T value)
    {
        if(isempty())
        {
            InsertFirst(value);
        }
        else {
            Node<T> *new_node = new Node<T>;
            new_node->setValue(value);
            Node<T> *current = head;

            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            new_node->setNext(nullptr);
            current->setNext(new_node);
        }
    }

    void Delete(int value)
    {
        Node<T>*temp = head;

        if(isempty())
        {
            cout<<"The list is empty"<<endl;
        }
        else  if(head->getData() == value)
        {
            head = head->getNext();
            delete temp;
        }
        else
        {
            while(temp->getNext()->getData() != value)
            {
                temp = temp->getNext();
            }
            Node<T> *temp2 = temp->getNext();
            temp->setNext(temp2->getNext());
            delete temp2;
        }
    }
    void print()
    {
        if(isempty())
        {
            cout<<"The list is empty"<<endl;
        }
        else
        {
            Node<T>* current = head;
            while(current != nullptr)
            {
                cout<<current->getData()<<"\t";
                current = current->getNext();
            }
            cout<<endl;
        }
    }


    int count()
    {
        Node<T> *current = head;
        int counter = 0;
        while(current != nullptr)
        {
            counter++;
            current = current->getNext();
        }
        return counter;
    }
};




int main() {


    LinkedList<float> list;
    list.InsertFirst(5);
    list.InsertFirst(6);
    list.InsertLast(4);
    list.InsertLast(7);
    list.InsertLast(8);
    list.InsertLast(9);

    int num;

    while(!list.isempty()) {
        list.print();
        cout << endl;
        cout << "The number of nodes is " << list.count() << endl;
        cout << "Enter the elemet you want to delete" << endl;
        cin >> num;
        list.Delete(num);
    }

//    string name;
//    cout<<"Enter your name"<<endl;
//    //To take a multiple lines as input from the user
//    getline(cin , name , '0');
//    cout<<"The name is "<<name<<endl;



return 0;
}
