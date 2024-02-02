#include <iostream>
using namespace std;

template<typename t>
class Stack
{
private:
    int top;
    int size;
    t *array;
public:
    Stack(int size)
    {
        top = -1;
        this->size = size;
        array = new t[size];
    }

    void Push(t value)
    {
        top++;
        array[top] = value;
    }
    void pop()
    {
        if(isempty())
        {
            cout<<"The stack is already empty"<<endl;
        }
        else
        {
            top--;
        }
    }
    t getTop()
    {
        if(isempty())
        {
            cout<<"No items in the stack"<<endl;
        }
        else
        {
            return array[top];
        }
    }
    bool isempty()
    {
        return(top == -1);
    }

    void clear()
    {
        top = -1;
        delete array;
    }
    void display()
    {
        cout<<"[ ";
            for(int  i = 0 ; i <=top ; i ++)
            {
                cout << array[i];
                if (i != top) {
                    cout << " , ";
                } else {
                    continue;
                }
            }
        cout<<" ]";
            cout<<endl;
    }

    void setSize(int size);

};

int main() {
    Stack<string>stack(5);
    stack.Push("Omar");
    stack.Push("Youssef");
    stack.Push("Mohamed");
    stack.Push("Abdel-wahed");
    stack.display();





    return 0;
}

template<typename t>
void Stack<t>::setSize(int size) {
    Stack::size = size;
}
