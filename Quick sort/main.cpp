//The Quick Sort by Omar
//Quick Sort is a Divide and conquer algorithm , is in-place and stable

#include <iostream>
using namespace std;

int Partition(int A[] , int left , int right)
{
    int pivot = A[left];
    int i =left;
    for(int j = left+1;j<=right ; j++)
    {
        if(A[j]<pivot)
        {
            i++;
            swap(A[i] , A[j]);
        }
    }
    swap(A[left] , A[i]);
    return i;
}

void QuickSort(int A[] , int left , int right)
{
    if(left>right)
    {return;}
    else{
        int middle = Partition(A , left , right);
        QuickSort(A , left , middle-1);
        QuickSort(A , middle+1 , right);


    }
}

int main() {
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int array[size];
    for(int i = 0 ; i<size;i++)
    {
        cout<<"The "<<i+1<<" element: ";
        cin>>array[i];
        cout<<endl;
    }


    QuickSort(array , 0 , size-1);

    for(int i = 0 ; i<size;i++)
    {
        cout<<array[i]<<"  " ;
    }
    return 0;
}
