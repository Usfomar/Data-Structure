/*
 * Queue Problems
 * */
#include <iostream>
using namespace std;

//Class Node
template<class t>
class Queue
{
private:
    struct Node
    {
        t item;
        Node* next;
    };
    int length;
    Node* frontPtr, * rearPtr;

public:

    //Default constructor
    Queue() :frontPtr(nullptr), rearPtr(nullptr), length(0)
    {}

    //Check is the queue empty or not
    bool isEmpty()
    {
        return (length == 0);
    }

    //This function computes the size of the queue ("The number of nodes in it")
    int size() const {
        int count = 0;
        Node* temp = frontPtr;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    //Removes elements from the queue
    void dequeue()
    {
        Node* current = frontPtr;
        if (isEmpty())
            cout << "Empty Queue" << endl;
        else if (length == 1)
        {

            delete current;
            rearPtr = frontPtr = nullptr;
            length = 0;
        }
        else
        {
            frontPtr = frontPtr->next;
            delete current;
            length--;
        }
    }

    //Adds items in the queue
    void enqueue(t item)
    {
        Node* newNode = new Node;
        newNode->item = item;
        newNode->next = nullptr;

        if (length == 0)
            rearPtr = frontPtr = newNode;
        else
        {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
        length++;
    }

    //Returns the front element
    t front()
    {
       if(isEmpty())
       {
           throw runtime_error("The queue is empty");
       }
        return frontPtr->item;
    }

    //Returns the last element
    t rear()
    {
        if(isEmpty())
        {
            throw runtime_error("The queue is empty");
        }
        return rearPtr->item;
    }
    //Generates all binary numbers from 1 to N and print them
    void GenerateBinaryNumbers(int Num)
    {
        Queue<string> s;
        s.enqueue("1");

        for (int i = 0; i < Num; i++) {
            s.enqueue(s.front() + "0");
            s.enqueue(s.front() + "1");
            cout << s.front() << " ";
            s.dequeue();
        }
        cout<<endl;
    }

    //Sort the queue ascending
    void sortQueue(Queue& q) {
        Node* temp = q.frontPtr;
        while (temp != nullptr) {
            Node* minNode = temp;
            Node* curr = temp->next;
            while (curr != nullptr) {
                if (curr->item < minNode->item) {
                    minNode = curr;
                }
                curr = curr->next;
            }

            t store = temp->item;
            temp->item = minNode->item;
            minNode->item = store;

            temp = temp->next;
        }
    }

    //Display queue's elements
    void print()
    {
        Node* cur = frontPtr;
        while (cur != nullptr)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};





int main()
{
    Queue<int> queue;
    //Add numbers in the queue
    queue.enqueue(5);
    queue.enqueue(4);
    queue.enqueue(3);
    queue.enqueue(2);
    cout<<"The original queue"<<endl;
    queue.print();

    //Deletes the last element
    queue.dequeue();
    cout<<"The queue after dequeue"<<endl;
    queue.print();

    //Prints all binary numbers from 1 to N=10
    cout<<"Binary numbers"<<endl;
    queue.GenerateBinaryNumbers(10);


    //Sorting the queue
    cout<<"The queue after soring"<<endl;
    queue.sortQueue(queue);
    queue.print();

    //Get the front and the end
    cout<<"The first item "<<queue.front()<<endl;
    cout<<"The last item "<<queue.rear()<<endl;
    return 0;
}
