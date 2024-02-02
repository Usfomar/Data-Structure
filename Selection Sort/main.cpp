//Selection Sort By Omar

#include <iostream>
using namespace std;

void SelectionSort(int arr[] , int n);
void swap(int &x , int &y);


int main() {

    int array[] = {7,2,8,5 , 4 };

    //This equation used for getting  the n of an array
    int size = sizeof(array)/sizeof (array[0]);

    SelectionSort(array , size);




    return 0;
}

void SelectionSort(int arr[] , int n)
{

    for(int i=0;i<n-1;i++)
    {

        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[i])
                //Swap operation
            swap(arr[i] , arr[j]);

        }
    }

    for(int i =0;i<n ;i++)
    {
        cout<<arr[i]<<"   ";
    }
}

void swap(int &x , int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}