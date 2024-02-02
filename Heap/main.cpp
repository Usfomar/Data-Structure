#include<iostream>
#include"MaxHeap.h"
using namespace std;
// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
int main()
{
    MaxHeap<int> maxHeap;
    vector<int> arr = {9,8,7,6,1,5,10,20,15};
//    maxHeap.HeapSort(arr);


    cout<<endl;

    cout<<"The maximum value is extracted "<<maxHeap.ExtractMax(arr , arr.size())<<endl;

//maxHeap.Build_Max_Heap(arr, arr.size());
    for(int i: arr)
    {
        cout<<i<<"  ";
    }

    return 0;
}
