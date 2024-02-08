/*
 * Stack Problems
 * */
#include <iostream>
using namespace std;


//Class Node
template<typename t>
class Node
{
private:
    t data;
    Node<t> *next;
public:
    //Default constructor
    Node():next(nullptr){}
    //Parametrized constructor
    Node(t data , Node<t> *next = nullptr):data(data) , next(next){}

    //Setters and Getters
    t getData() const {
        return data;
    }

    Node<t> *getNext() const {
        return next;
    }

    void setData(t data) {
        Node::data = data;
    }

    void setNext(Node<t> *next) {
        Node::next = next;
    }
};



//Class Stack
template<typename t>
class Stack
{
private:
    Node<t> *top;
    int size;
    void Reverse(Node<t> *temp)
    {
        if(temp == nullptr)//Base Case
        {
            return;
        }
        else
        {
            Reverse(temp->getNext());
        }
        cout<<temp->getData()<<"   ";
    }
public:
    Stack():top(nullptr) , size(0){}

    //Returns the number of items in stack
    int length()
    {
        return size;
    }

    //Push items in the stack
    void Push(t value)
    {
        auto *new_node = new Node<t>(value);
        new_node->setNext(top);
        top = new_node;
        size++;
    }

    //Pop() function removes the top element of the stack
    t Pop()
    {
        t n;
        if(isEmpty())
        {
            throw runtime_error ("The stack is empty");
        }

        auto *temp = top;
        top = top->getNext();
        temp->setNext(nullptr);
        n = temp ->getData();
        delete temp;
        size--;
        return n;
    }

    //Delete the middle items in the stack
    void DeleteMiddle()
    {
        if (isEmpty())
        {
            throw runtime_error("The stack has no elements");
        }
        auto *temp = top;
        for(int i = 1 ; i<(size/2)-1 ; i++)
        {
            temp = temp->getNext();
        }


            temp = temp->getNext();
            auto *x1 = temp->getNext();
            temp->setNext(x1->getNext());
            x1->setNext(nullptr);
            delete x1;

    }



    //Top() returns the top element in the stack
    t Top()
    {
        if(isEmpty())
        {
            throw runtime_error("The stack has no items to return");
        }
        return top->getData();
    }

    //Prints all elements in the stack reversely
    void PrintReverse()
    {
        auto *temp = top;
        if(isEmpty())
        {
            throw runtime_error("The stack is empty");
        }
        while(temp != nullptr)
        {
            cout<<temp->getData()<<"   ";
            temp = temp->getNext();
        }
        cout<<endl;
    }

    //Prints stack's elements in correct order
    void Print()
    {
        if(isEmpty())
        {
            cout<<"The stack is empty"<<endl;
        }
        else
        {
            auto *temp = top;
            //This function is declared in  private
            Reverse(temp);
        }
        cout<<endl;
    }


    //Return true if stack is empty and false if not
    bool isEmpty()
    {return(top== nullptr && size == 0);}
};



int main() {
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.Push(6);
    stack.Push(7);
    stack.Push(8);
    stack.Push(9);
    stack.Push(10);

    cout<<"The length of the stack before changes "<<stack.length()<<endl;
    cout<<"The original"<<endl;
    stack.Print();

    cout<<"After the delete all the middle elements"<<endl;
    stack.DeleteMiddle();
    stack.Print();

    cout<<"The stack elements in reverse"<<endl;
    stack.PrintReverse();

    cout<<"The top element in the stack "<<stack.Top();

    stack.Pop();
    stack.Pop();
    stack.Pop();
    cout<<"The stack after items deletion"<<endl;
    stack.Print();
    cout<<"The length after changes is "<<stack.length()<<endl;


    return 0;
}
