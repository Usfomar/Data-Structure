//Insertion Sort by Omar the destroyer

#include <iostream>
using namespace std;
static int number=0;

template <class T>
void InsertionSort(T arr[] , T n)
{
    for(int i = 1 , j ; i < n ; i++)
    {
        int tmp = arr[i];
        number++;
        for(j = i ; j>0 && tmp < arr[j-1] ; j--)
        {
            number+=2;
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<"     ";
    }
}



int main() {
    int array[] = {2 ,5,4,3};
    int size = sizeof (array) / sizeof(array[0]);

    InsertionSort(array , size);
    cout<<endl;
    cout<<number<<endl;
    return 0;
}
