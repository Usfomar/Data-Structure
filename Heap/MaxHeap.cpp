//
// Created by Omar Youssif on 8/24/2023.
//

#include "MaxHeap.h"
#include<iostream>
using namespace std;
template<class t>
MaxHeap<t>::MaxHeap() {}


template <class t>
int MaxHeap<t>::GetMax() {
    return array[0];
}

template <class t>
int MaxHeap<t>::GetSize() {
    return array.size();
}


template <class t>
void MaxHeap<t>::Print() {
    for(int iter:array)
    {
        cout<<iter<<"    ";
    }
}

template <class t>
int MaxHeap<t>::leftChild(int index) {
    return (2*index+1);
}

template <class t>
int MaxHeap<t>::rightChild(int index) {
    return (2*index+2);
}
template <class t>
int MaxHeap<t>::parent(int index) {
    return ((index-1)/2);
}

template <class t>
void MaxHeap<t>::Heapify(int index , vector<t> &arr , int size) {

    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if(left < size && arr[index] < arr[left])
    {
        largest = leftChild(index);
    }
    if(right< size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if(largest != index)
    {
        swap(arr[largest] , arr[index]);
        Heapify(largest , arr , size);
    }
}



template <class t>
void MaxHeap<t>::Insert(t item) {
    array.push_back(item);
    int i = (GetSize()-1);
    while(i > 0 && array[i] > array[parent(i)])
    {
        swap(array[i] , array[parent(i)]);
        i = parent(i);
    }

}

template<class t>
void MaxHeap<t>::Build_Max_Heap(vector<t> &arr , int size) {

    for (int i = size/2-1; i >=0 ; i--)
    {
        Heapify(i , arr , size);
    }
}




//Check the array is heap or not
template<class t>
bool MaxHeap<t>::isHeap(vector<t> arr) {
    bool boolean = true;

    for(int i = (arr.size()/2)-1 ; i>=0 && boolean ; i--)
    {
        if(leftChild(i) < arr.size() &&arr[i] < arr[leftChild(i)])
        { boolean = false;
            break;
        }

        if(rightChild(i) < arr.size() &&arr[i] < arr[rightChild(i)])
        { boolean = false;
            break;
        }
    }
    return boolean;
}


template<class t>
void MaxHeap<t>::HeapSort(vector<t> &arr) {
    int n = arr.size();
    for (int i = n/2-1; i >=0 ; i--)
    {
        Heapify(i , arr , n);
    }
    for(int i = n-1 ; i >=0;i--)
    {
        swap(arr[0] , arr[i]);
        Heapify(0,arr ,i);
    }
}

template<class t>
t MaxHeap<t>::ExtractMax(vector<t> &arr, int size) {
    Build_Max_Heap(arr , size);
    int max = arr[0];
    swap(arr[0] , arr[size-1]);
    arr.pop_back();//when we removed the last element the size of the array is decreased
    Heapify(0 , arr , size-1);
    return max;
}




template class MaxHeap<int>;
