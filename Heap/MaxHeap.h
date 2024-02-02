//
// Created by Omar Youssif on 8/24/2023.
//

#ifndef HEAP_MAXHEAP_H
#define HEAP_MAXHEAP_H

#include <vector>
using namespace std;

template <class t>
class MaxHeap {
private:
    vector<t> array;
    void Heapify(int index , vector<t> &arr , int size);
public:
    MaxHeap();
    int GetMax();
    int GetSize();
    void Insert(t item);
    void Print();
    int leftChild(int index);
    int rightChild(int index);
    int parent(int index);
    void Build_Max_Heap(vector<t> &arr , int size);
    bool isHeap(vector<t> arr);
    void HeapSort(vector<t> &arr);
    t ExtractMax(vector<t> &arr , int size);

};


#endif //HEAP_MAXHEAP_H
