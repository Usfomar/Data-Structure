/*Build a queue using linked lists*/
#include <iostream>
using namespace std;
//Class Node
template<typename t>
class Node
{
private:
    t data;
    Node<t>*next;
public:
    //Default constructor
    Node(){
        next = nullptr;
        data =0;
    }
    //Parameterized constructor
    Node(int data , Node<t>*next=nullptr)
    {
        this->data = data;
        this->next = next;
    }


    //Setters and Getters
    t getData() const {
        return data;
    }

    Node<t> *getNext() const {
        return next;
    }

    void setData(t data) {
        this->data = data;
    }

    void setNext(Node<t> *next) {
        this->next = next;
    }
};

//Class Queue
template<typename t>
class Queue
{
private:
    //Two Node pointers represent the beginning and the end
    Node<t>*front , *end;
    int num_of_nodes;
public:
    //Constructor
    Queue()
    {
        num_of_nodes = 0;
        front = end = nullptr;
    }

    //Add items in the queue add to the end
    void enqueue(t item)
    {
        auto *new_node = new Node<t>(item);
        if(isempty())
        {
            front = end = new_node;
        }
        else
        {
            end->setNext(new_node);
            new_node->setNext(nullptr);
            end = new_node;
        }
        num_of_nodes++;
    }


    //Delete items from the queue removes items on the front
    Node<t>* dequeue()
    {
        auto *temp = front;
        if(isempty())
        {
            cout<<"The queue is already empty"<<endl;
        }
        else if (front == end)
        {
            front = end = nullptr;
            return temp;
            num_of_nodes--;
        }
        else
        {
            front = temp->getNext();
            temp->setNext(nullptr);
            return  temp;
            num_of_nodes--;
        }
    }

    //Return the item in the front
    t first()
    {
        if(isempty())
        {
            return false;
        }
        else
        {
            return front->getData();
        }
    }

    //Check if an item is found in the queue or not
    bool isFound(t value)
    {
        auto *temp = front;

        bool found = false;
        while(temp != nullptr)
        {
            if(temp->getData() == value)
                found = true;

            temp = temp->getNext();
        }
//        return(temp != nullptr);
        return found;
    }

    //Prints the elements of the queue
    void print()
    {
        if(isempty())
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
            auto*temp = front;
            while(temp != nullptr)
            {
                cout<<temp->getData();
                if(temp->getNext() != nullptr)
                {
                    cout<<"<-";
                }
                temp = temp -> getNext();
            }
        }
        cout<<endl;
    }

    //Returns the number of items
    int count()
    {
        return num_of_nodes;
    }

    //Delete all elements in the queue
    void clear()
    {
        while(!isempty())
        {
            dequeue();
        }
    }
    //Check if the queue is empty or not
    bool isempty()
    {
        return (front==nullptr && end == nullptr);
    }
};


int main() {
    Queue<int> queue;

    queue.enqueue(5);
    queue.enqueue(6);





    return 0;
}
