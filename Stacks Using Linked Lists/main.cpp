/*
 * The implementation of stack using linked lists and its operations:
 * - push()
 * - clear()
 * - getTop()
 * - pop()
 * - is empty()
 * - print()
 * */

#include<iostream>
using namespace std;

//This class for each node
template<typename t>
class Node
{
private:
    t data;
    Node<t>* next;
public:
    //Constructor
    Node(t data , Node<t>*next = nullptr): data(data) , next(next)
    {
    }

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

//class Stack
template<typename t>
class Stack
{
private:
    Node<t>*top;
    void recursive (Node<t> *temp)
    {
        if(temp == nullptr)
        {
            return;
        }
        else
        {
            recursive(temp->getNext());
        }
        cout<<temp->getData()<<endl;
    }

public:
    Stack(): top(nullptr)
    {
    }

    //To add elements in the stack
    void push(t value)
    {
        auto new_node = new Node<t>(value);
        new_node->setNext(top);
        top = new_node;
    }

    //Delete element from the stack ("removes the last item in it")
    void pop()
    {
        if(isempty())
        {
            cout<<"The stack already has no items to delete"<<endl;
        }
        else
        {
            auto temp = top;
            top = top->getNext();
            temp->setNext(nullptr);
            delete temp;
        }
    }
    //Returns the last item in the stack
    t getTop()
    {
        if(isempty())
        {
            cout<<"There is no items to return, the stack is empty"<<endl;
        }
        else
        {
            return top->getData();
        }
    }

    //Display all items in the stack
    void print()
    {
        if(isempty())
        {
            cout<<"The stack has no elements"<<endl;
        }
        else
        {
            auto current = top;
            while(current != nullptr)
            {
                cout<<current->getData()<<endl;
                current = current->getNext();
            }
        }
    }
    //Clear all elements in the stack
    void clear()
    {
        if(isempty())
        {
            cout<<"The stack has no elements"<<endl;
        }
        else
        {
            while(top != nullptr)
            {
                auto temp = top;
                top = top->getNext();
                delete temp;
            }
            cout<<"The stack is clear"<<endl;
        }
    }

    //Check if the stack is empty or not
    bool isempty()
    {
        return (top == nullptr);
    }


    void PrintRecursively()
    {
        auto *temp = top;
        recursive(temp);
    }




};

bool isPair(char open , char close)
{
    if(open == '(' && close == ')')
    {
        return  true;
    }
    else if(open == '{' && close == '}')
    {
        return true;
    }
    else if(open == '[' && close ==']')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Check if brackets are balanced or not using stacks
bool areBalanced(string word)
{
    Stack<char> s;
    for(int i = 0 ; i < word.length() ; i++)
    {
        if(word[i] == '(' || word[i] == '{' || word[i] == '[')
        {
            s.push(word[i]);
        }
        else if (word[i] == ')' || word[i] == '}' || word[i] == ']')
        {
            if(!s.isempty() && isPair(s.getTop() , word[i]))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            continue;
        }
    }
    return (s.isempty());
}





int main()
{
    int the_last_in_stack;
    Stack<int> stack;
//    stack.push(5);
//    stack.push(4);
//    stack.push(3);
//    stack.push(2);
//    stack.print();
//    cout<<endl;
//    stack.PrintRecursively();






string word;
cout<<"Enter the expression"<<endl;
cin>>word;
cout<<(areBalanced(word) ? "balanced" : "not balanced")<<endl;
    return 0;
}






