/*
 * Linked List problems:
 * */

#include <iostream>
#include "LinkedList.h"
using namespace std;



int main() {
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


    cout<<"Now the size of the list is "<<list.getSize()<<endl;


    //Destructor activate
    return 0;
}
