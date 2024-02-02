#include <iostream>
#include<chrono>
using namespace std;

template<class t>
void ShellSort(t arr[] , int size)
{
    for(int gap = size/2 ; gap > 0 ; gap/=2)
    {
        for(int i = gap; i<size; i++)
        {
            int temp= arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap] > temp;j-=gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }

}



void Insertion(int arr[] , int size)
{
    for(int i = 1 ; i < size ; i++)
    {
        int temp = arr[i];
        int j ;
        for( j = i ; j >0 && arr[j-1] > temp ;j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

int main() {
    int size=5;
    int array[5] = {2,4,5,1,3};

//    ShellSort(array,5);
//
//    cout<<"Shell Sort"<<endl;
//    for(int  i=0;i<5;i++)
//    {
//        cout<<array[i]<<"  ";
//    }
//    cout<<endl;




    auto start = chrono::system_clock::now();
    ShellSort(array,5);
    auto end = chrono::system_clock::now();
    auto diff = end - start;
    cout<<chrono::duration<double , milli> (diff).count()<<endl;


    for(int  i=0;i<5;i++)
    {
        cout<<array[i]<<"  ";
    }



    return 0;
}
