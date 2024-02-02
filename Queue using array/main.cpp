#include <iostream>
#include<cassert>
using namespace std;
template<typename t>
class Queue
{
private:
    t *array;
    int front , rear;
    int size;
    int length;

public:
    //default constructor
    Queue(int size)
    {
        this->size = size;
        array = new t[size];
        front = 0;
        rear = size-1;
        length=0;
    }

    void enqueue(t item)
    {
        if(isFull())
        {
            cout<<"The queue is full"<<endl;
        }
        else
        {
            rear = (rear+1)%size;
            array[rear] = item;
            length++;
        }
    }

    void dequeue()
    {
        if(isempty())
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
            front = (front+1)%size;
            length--;
        }
    }

    t getFront()
    {
        assert(!isempty());
        return array[front];
    }

    bool isempty()
    {
        return(length==0);
    }

    bool isFull()
    {
        return (length==size);
    }

    void print()
    {


        for(int i=front;i!=rear;i = (i+1)%size)
        {
            cout<<array[i];
            if (i!=rear)
            {
                cout<<"<-";
            }
        }
        cout<<array[rear];
    }

    int getLength() const;
};


int main() {
    Queue<int> queue(5);

    queue.enqueue(9);
    queue.enqueue(10);
    queue.enqueue(11);
    queue.enqueue(14);
    cout<<"The number of elements "<<queue.getLength()<<endl;

    queue.print();
    return 0;
}

template<typename t>
int Queue<t>::getLength() const {
    return length;
}
