#include <iostream>
using namespace std;

void BubbleSort(int arr[] , int n)
{
    for(int i = 0 ; i<n ;i++)
    {
        for(int j = 0 ; j< n-i-1;j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for(int i=0; i<n ; i++)
    {
        cout<<arr[i]<<"   ";
    }

}
void print(int arr[] , int n)
{
   }

int main() {
    int array[6] = { 1 ,2,3,5,0 , -1};
    BubbleSort(array , 6);

    return 0;
}
