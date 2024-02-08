/*
 * Tree Problems
 * */
#include <iostream>
#include<queue>
using namespace std;


//The node class of binary search tree
template<class t>
class BSTNode
{
private:
    t data;
    BSTNode<t> *left , *right;
public:
    //Default constructor
    BSTNode():left(nullptr) , right(nullptr){}

    //And Parametrized one
    BSTNode(t data , BSTNode<t>*left= nullptr,BSTNode<t> *right = nullptr)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }

    //Setters & Getters
    t getData() const {
        return data;
    }

    void setData(t data) {
        BSTNode::data = data;
    }

    void setLeft(BSTNode<t> *left) {
        this->left = left;
    }

    void setRight(BSTNode<t> *right) {
        this->right = right;
    }

    BSTNode<t> *getLeft(){
        return left;
    }

    BSTNode<t> *getRight(){
        return right;
    }
};

//Binary Search Tree Class
template<class t>
class BST{
private:
    BSTNode<t>*root;

    //Do recursion of Inorder printing
    void InOrderRecursive(BSTNode<t> *temp)
    {
        if(temp != nullptr)
        {
            InOrderRecursive(temp->getLeft());
            cout<<temp->getData()<<"   ";
            InOrderRecursive(temp->getRight());
        }
    }

    BSTNode<t>* findMin(BSTNode<t>* node) {
        while (node->getLeft() != nullptr)
            node = node->getLeft();
        return node;
    }

public:
    BST():root(nullptr){}

    //BLA BLA BLA
    bool isEmpty(){return root == nullptr;}

    //Search for an item in the tree and return true if it's found and false if not
    t Search(t value)
    {
        auto* temp = root;
        while(temp!= nullptr)
        {
            if(value == temp->getData())
            {
                return temp->getData();
            }
            else if(value < temp->getData())
            {
                temp = temp->getLeft();
            }
            else
            {
                temp = temp ->getRight();
            }
        }
        return 0;
    }

    //Printing the items in the tree using breadth first way by queue
    void BreadthFirst()
    {
        queue<BSTNode<t>*> queue;
        auto *temp = root;
        if(temp != nullptr)
        {
            queue.push(temp);
            while(!queue.empty())
            {
                temp = queue.front();
                queue.pop();
                cout<<temp->getData()<<"   ";
                if(temp->getLeft() != nullptr)
                {
                    queue.push(temp->getLeft());
                }
                if(temp->getRight() != nullptr)
                {
                    queue.push(temp->getRight());
                }
            }
        }
        cout<<endl;
    }

    //In Order Function
    void InOrder()
    {
        auto *temp = root;
        InOrderRecursive(temp);
        cout<<endl;
    }



    //Insert a new node in correct place
    void Insert(const t& item)
    {
        auto *new_node = new BSTNode<t>(item);
        auto *temp = root;
        BSTNode<t> *prev = nullptr;

        while(temp != nullptr)
        {
            prev = temp;
            if (item < temp->getData())
            {
                temp = temp->getLeft();
            }
            else
            {
                temp = temp ->getRight();
            }
        }

        if(isEmpty())
        {
            root = new BSTNode<t>(item);
        }
        else if (item < prev->getData())
        {
            prev->setLeft(new_node);
        }
        else
        {
            prev->setRight(new_node);
        }
    }

    //Returns the minimum item in the tree
    //Get the left most node and returns its data
    t GetMinimum()
    {
        if(isEmpty())
        {
            throw runtime_error("There are no items in the tree");
        }
        auto *temp = root;
        while(temp->getLeft() != nullptr)
        {
            temp = temp->getLeft();
        }
        return temp->getData();
    }


    //Delete a specific node from the tree
    BSTNode<t>* Delete( int key)
    {
        BSTNode<t>* curr = root;
        BSTNode<t>* parent = nullptr;

        // Find the node to be deleted and its parent
        while (curr != nullptr && curr->getData() != key)
        {
            parent = curr;
            if (key < curr->getData())
                curr = curr->getLeft();
            else
                curr = curr->getRight();
        }

        if (curr == nullptr)
        {
            cout<<"NOT FOUND"<<endl;
            return root;  // Node not found, return unchanged root
        }

        // Case 1: Node with no left child (or only right child)
        if (curr->getLeft() == nullptr)
        {
            BSTNode<t>* temp = curr->getRight();
            if (parent == nullptr)
                root = temp;
            else if (parent->getLeft() == curr)
                parent->setLeft(temp);
            else
                parent->setRight(temp);
            delete curr;
        }
        else if (curr->getRight() == nullptr)
        {
            BSTNode<t>* temp = curr->getLeft();
            if (parent == nullptr)
                root = temp;
            else if (parent->getLeft() == curr)
                parent->setLeft(temp);
            else
                parent->setRight(temp);
            delete curr;
        }
        else // Case 3: Node with two children
        {
            BSTNode<t>* successor = findMin(curr->getRight());
            curr->setData(successor->getData());

            // Delete the in-order successor (node with one or no child)
            BSTNode<t>* temp = successor->getRight();
            if (curr->getRight() == successor)
            {
                curr->setRight(temp);
            }
            else
            {
                BSTNode<t>* succParent = curr->getRight();

                while (succParent->getLeft() != successor)
                {
                    succParent = succParent->getLeft();
                }
                succParent->setLeft(temp);
            }
            delete successor;
        }
        return root;
    }


};





int main() {
    BST<int> tree;
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);

    cout<<"The original"<<endl;
    tree.InOrder();

    cout<<"After  '50' deletion "<<endl;
    tree.Delete(50);
    tree.InOrder();



    cout<<"The minimum number in the tree is "<<tree.GetMinimum()<<endl;

    cout<<"Tree using breadth first method"<<endl;
    tree.BreadthFirst();

    cout<<"Tree using Inorder method"<<endl;
    tree.InOrder();



    cout<<tree.Search(20)<<"      "<<tree.Search(100)<<endl;


    return 0;
}
