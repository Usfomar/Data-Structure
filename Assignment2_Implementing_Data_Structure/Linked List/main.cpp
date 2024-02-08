#include <iostream>
using namespace std;
template<class t>
class Node {
private:
    t data;
    Node<t> *next;
public:
    Node(){next = nullptr;}


    Node(t data , Node<t> *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }

    t getData() const{ return data;}

    Node<t> *getNext() const{ return next;}

    void setData(t d){data=d;}

    void setNext(Node<t> *n){next=n;}
};

template<class t>
class LinkedList {
private:
    friend class Node<t>;
    Node<t> *head , *tail;
    int size;
public:
    LinkedList(){head=tail=nullptr; size=0;}

    void AddToHead(t value){
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


    void AddToTail(t value){
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


    t RemoveFromHead()
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
    t RemoveFromTail()
    {
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

    t GetValueAtHead()
    {
        if(isEmpty())
        {
            throw runtime_error ("The list is empty");
        }
        return head->getData();
    }


    void PairwiseSwap()
    {
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


    void RemoveDuplicates()
    {
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

    void clear()
    {

        if(isEmpty())
        {
            throw runtime_error ("The list is empty");
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

    bool isEmpty(){return(head== nullptr);}

    int getSize(){return size;}

    ~LinkedList()
    {
        cout<<"The list is deleted"<<endl;
        clear();
    }


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
                out<<" -> ";
            }
            current = current->getNext();
        }
        out<<endl;
        return out;
    }
};

int main()
{
    LinkedList<int> list;
    //Add items to the head and the tail
    list.AddToHead(5);
    list.AddToHead(4);
    list.AddToHead(3);
    list.AddToTail(6);
    list.AddToHead(2);
    list.AddToHead(1);
    list.AddToHead(5);
    list.AddToHead(2);
    list.AddToHead(4);
    list.AddToHead(10);
    list.AddToTail(20);
    list.AddToTail(2);
    list.AddToTail(6);

    cout<<"The size of the original list is "<<list.getSize()<<endl;
    cout<<"The original list\n"<<list<<endl;

    list.PairwiseSwap();
    cout<<"The list after swap its items pairwise\n"<<list<<endl;


    list.RemoveDuplicates();
    cout<<"The list after removes all duplicates\n"<<list<<endl;

    cout<<"The first item "<<list.GetValueAtHead()<<endl;

    list.RemoveFromTail();
    cout<<"The list after removes the item at the end\n"<<list<<endl;

    list.RemoveFromHead();
    cout<<"The list after removes the item at the head\n"<<list<<endl;

    cout<<"the current value at head is :\n"<<list.GetValueAtHead()<<endl;

    cout<<"Now the size of the list is "<<list.getSize()<<endl;


    //Destructor activate
    return 0;
}
