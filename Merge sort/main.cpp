#include <iostream>
using namespace std;
void Merge(int A[] , int first, int middle , int last)
{
    int i , j , k;
    //Get the size of the arrays
    int size1 = middle - first +1;
    int size2 = last - middle;

    //Declare two arrays with its sizes
  int arr1[size1] , arr2[size2];
    //Entering the values in it
    for(int c=0 ; c<size1 ; c++)
    {
        arr1[c] = A[first + c];
    }

    for(int c = 0  ; c<size2 ; c++)
    {
        arr2[c] = A[middle + 1 + c];
    }

     i = 0;
    j=0;
     k=first;
    while (i<size1 && j<size2)
    {
        if(arr1[i] <= arr2[j])
        {
            A[k++] = arr1[i];
            i++;
        }
        else
        {
            A[k++] = arr2[j];
            j++;
        }

    }
    while(i<size1)
    {
        A[k] = arr1[i];
        i++;
        k++;
    }
    while(j<size2)
    {
        A[k] = arr2[j];
        j++;
        k++;
    }
}
void MergeSort(int A[] , int first , int last)
{
    if(first < last) {
        int middle = first + (last - first) / 2;
        MergeSort(A, first, middle);
        MergeSort(A, middle + 1, last);
        Merge(A, first, middle, last);
    }


}

int main() {

    int array [] = { 1,2,5,4 , 6 ,0,3};
    int size = sizeof (array) / sizeof(array[0]);



    MergeSort(array , 0 , size-1);

    for(int c = 0 ; c<7 ;c++)
    {
        cout<<array[c]<<"   ";
    }
    return 0;
}
