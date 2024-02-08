/*
 * Course: Data Structure
 * Assignment 1
 *
 * Team Members:
 * Name: Omar Youssef Mohamed    ID: 20210591
 * Name: Omar Samir Emam         ID: 20200345
 * Name: Youssef Ahmed Yassin    ID: 20200644
 * */

#include <iostream>
#include<fstream>
#include<chrono>
#include"Student.h"

using namespace std;

//---------------------------------------------------
//Numbers of comparisons of each algorithm
//---------------------------------------------------
//Here we declared variables to store the number of comparisons in each sorting algorithm. We make it Global to be clear to understand
int number_of_comparisons_of_SelectionSort=0;
int number_of_comparisons_of_BubbleSort=0;
int number_of_comparisons_of_QuickSort=0;
int number_of_comparisons_of_InsertionSort=0;
int number_of_comparisons_of_ShellSort=0;
int number_of_comparisons_of_MergeSort=0;



//----------------------------------------------------------------------------------------------------------------------
//Prototypes of functions
//----------------------------------------------------------------------------------------------------------------------

int Calculate_number_of_lines();//This function is made to compute the number of lines in file to get the number of objects
void Read(Student s[] , int size , int lines);
//These functions Write the modified data in two text files Called SortByGPA and SortByName
void Write_GPA_File(Student students[] , int size ,ofstream &out); //SortByGPA
void Write_Name_File(Student students[] , int size ,ofstream &out);//SortByName






//Sorting Algorithms

template <class T>
void SelectionSortByGPA(T s[] , int size);
template <class T>
void SelectionSortByName(T s[] , int size);
template<class T>
void InsertionSortByGPA(T s[] , int size);
template<class T>
void InsertionSortByName(T s[] , int size);
template <class T>
void BubbleSortByGPA(T s[] , int size);
template <class T>
void BubbleSortByName(T s[] , int size);
template <class T>
void QuickSortByGPA(T s[],int left ,int right);
template <class T>
void QuickSortByName(T s[],int left ,int right);
template <class T>
void ShellSortByGPA(T s[] , int size);
template <class T>
void ShellSortByName(T s[] , int size);
template<class T>
void MergeSortByGPA(T s[] , int left , int right);
template<class T>
void MergeSortByName(T s[] , int left , int right);

template<class T>
int PartitionGPA(T s[] , int left , int right);
template<class T>
int PartitionName(T s[] , int left , int right);
template<class T>
void MergeGPA(T s[] , int left , int middle , int right);
template<class T>
void MergeName(T s[] , int left , int middle , int right);
//--------------------------------------------------------------------------------------------------------------




int main() {
    //ٌThe program was configured to take the input file's name from the user ,but we changed it to become easier and don't make you confused
    ifstream in;
    ofstream out_to_GPA , out_to_Name;
    int size;
    //Get the size of the say via this function

    int lines = Calculate_number_of_lines();
    size = lines/3;
    Student students[size];

    //Open output files.txt
    out_to_GPA.open("SortByGpa.txt");
    out_to_Name.open("SortByName.txt");


    Read(students , size , lines);//Read(students);//Read the data from text file


    //Insertion Sort
    auto start = chrono::steady_clock::now();
    InsertionSortByGPA(students , size);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    out_to_GPA<<"Algorithm: Insertion Sort"<<endl;
    out_to_GPA<<"Comparisons = "<<number_of_comparisons_of_InsertionSort<<endl;
    out_to_GPA <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    out_to_Name<<"Algorithm: Insertion Sort"<<endl;
    out_to_Name<<"Comparisons = "<<number_of_comparisons_of_InsertionSort<<endl;
    out_to_Name <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    Write_GPA_File(students , size , out_to_GPA);
    InsertionSortByName(students,size);
    Write_Name_File(students , size , out_to_Name);


    Read(students , size , lines);//Read(students);//Read the data from text file and store it in array students again

    //Selection Sort
    start = chrono::steady_clock::now();
    SelectionSortByGPA(students , size);
    end = chrono::steady_clock::now();
    diff = end - start;
    out_to_GPA<<"Algorithm: Selection Sort"<<endl;
    out_to_GPA<<"Comparisons = "<<number_of_comparisons_of_SelectionSort<<endl;
    out_to_GPA <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    out_to_Name<<"Algorithm: Selection Sort"<<endl;
    out_to_Name<<"Comparisons = "<<number_of_comparisons_of_SelectionSort<<endl;
    out_to_Name <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    Write_GPA_File(students , size , out_to_GPA);
    SelectionSortByName(students , size);
    Write_Name_File(students , size , out_to_Name);


    Read(students , size , lines);//Read(students);//Read the data from text file and store it in array students again
    //Bubble Sort
    start = chrono::steady_clock::now();
    BubbleSortByGPA(students,size);
    end = chrono::steady_clock::now();
    diff = end - start;
    out_to_GPA<<"Algorithm: Bubble Sort"<<endl;
    out_to_GPA<<"Comparisons = "<<number_of_comparisons_of_BubbleSort<<endl;
    out_to_GPA <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    out_to_Name<<"Algorithm: Bubble Sort"<<endl;
    out_to_Name<<"Comparisons = "<<number_of_comparisons_of_BubbleSort<<endl;
    out_to_Name <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    Write_GPA_File(students , size , out_to_GPA);
    BubbleSortByName(students,size);
    Write_Name_File(students , size , out_to_Name);


    Read(students , size , lines);//Read(students);//Read the data from text file and store it in array students again

    //Shell Sort
    start = chrono::steady_clock::now();
    ShellSortByGPA(students , size);
    end = chrono::steady_clock::now();
    diff = end - start;
    out_to_GPA<<"Algorithm: Shell Sort"<<endl;
    out_to_GPA<<"Comparisons = "<<number_of_comparisons_of_ShellSort<<endl;
    out_to_GPA <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    out_to_Name<<"Algorithm: Shell Sort"<<endl;
    out_to_Name<<"Comparisons = "<<number_of_comparisons_of_ShellSort<<endl;
    out_to_Name <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    Write_GPA_File(students , size , out_to_GPA);
    ShellSortByName(students,size);
    Write_Name_File(students , size , out_to_Name);


    Read(students , size , lines);//Read(students);//Read the data from text file and store it in array students again


    //Quick Sort
    start = chrono::steady_clock::now();
    QuickSortByGPA(students , 0 , size-1);
    end = chrono::steady_clock::now();
    diff = end - start;
    out_to_GPA<<"Algorithm: Quick Sort"<<endl;
    out_to_GPA<<"Comparisons = "<<number_of_comparisons_of_QuickSort<<endl;
    out_to_GPA <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    out_to_Name<<"Algorithm: Quick Sort"<<endl;
    out_to_Name<<"Comparisons = "<<number_of_comparisons_of_QuickSort<<endl;
    out_to_Name <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    Write_GPA_File(students , size , out_to_GPA);
    QuickSortByName(students,0 ,size-1);
    Write_Name_File(students , size , out_to_Name);





    Read(students , size , lines);//Read(students);//Read the data from text file and store it in array students again

    //Merge Sort
    start = chrono::steady_clock::now();
    MergeSortByGPA(students , 0 , size-1);
    end = chrono::steady_clock::now();
    diff = end - start;
    out_to_GPA<<"Algorithm: Merge Sort"<<endl;
    out_to_GPA<<"Comparisons = "<<number_of_comparisons_of_MergeSort<<endl;
    out_to_GPA <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    out_to_Name<<"Algorithm: Merge Sort"<<endl;
    out_to_Name<<"Comparisons = "<<number_of_comparisons_of_MergeSort<<endl;
    out_to_Name <<"Runtime = " <<chrono::duration <double, milli> (diff).count() << " milliseconds" << endl;
    Write_GPA_File(students , size , out_to_GPA);
    MergeSortByName(students,0,size-1);
    Write_Name_File(students , size , out_to_Name);



    //Close output files
    out_to_GPA.close();
    out_to_Name.close();

    return 0;
}
//----------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------
//Implementation of functions
//---------------------------------------------------

int Calculate_number_of_lines()
{
    ifstream  in;
    string line;
    int number_of_lines2 = 0;
    in.open("students.txt");
    while(getline(in , line))
    {
        number_of_lines2++;
    }
    in.close();
    return  number_of_lines2;
}

void Read(Student s[] , int size , int lines)
{
    string array[lines];
    ifstream  in;
    string line;
    in.open("students.txt");
    int i =0;
    while(getline(in,line))
    {
        array[i++] = line;
    }
    int c=0;
    for(int j =0 ; j < size ; j++)
    {
        s[j].setName(array[c++]);
        s[j].setId(array[c++]);
        s[j].setGpa(stod(array[c++]));
    }
    in.close();
}

void Write_GPA_File(Student students[] , int size ,ofstream &out)
{
    for(int j=0;j<size;j++)
    {
        out<<students[j].getName()<<"\n"<<students[j].getId()<<"\n"<<students[j].getGpa()<<endl;
    }
    out<<endl;
}

void Write_Name_File(Student students[] , int size ,ofstream &out)
{
    for(int j=0;j<size;j++)
    {
        out<<students[j].getName()<<"\n"<<students[j].getId()<<"\n"<<students[j].getGpa()<<endl;
    }
    out<<endl;
}


//Selection Sort
//By GPA
template <class T>
void SelectionSortByGPA(T s[] , int size)
{
    for(int i = 0 ; i < size-1 ; i++)
    {
        int min = i;
        for(int j = i+1 ; j < size ; j++)
        {
            number_of_comparisons_of_SelectionSort++;
            if(s[min].getGpa() > s[j].getGpa())
            {
                min = j;
            }
        }
            swap(s[i] , s[min]);
    }
}

//By Name
template <class T>
void SelectionSortByName(T s[] , int size)
{
    for(int i = 0 ; i < size-1 ; i++)
    {
        int min = i;
        for(int j = i+1 ; j < size ; j++)
        {
            if(s[j] < s[min])
            {
                min = j;
            }
        }
        swap(s[i] , s[min]);
    }
}


//Insertion Sort
//By GPA
template<class T>
void InsertionSortByGPA(T s[] , int size)
{
    int j;
    T key;
    for(int i = 1 ; i < size ;i++)
    {
        key=s[i];
        j=i-1;
        while(j>=0 && s[j].getGpa()>key.getGpa())
        {
            number_of_comparisons_of_InsertionSort++;
            s[j+1]=s[j];
            j=j-1;
        }
        s[j+1]=key;
    }
}

template<class T>
void InsertionSortByName(T s[] , int size)
{
    int j;
    T key;
    for(int i=1;i<size;i++) {
        j = i - 1;
        key = s[i];
        while (j >= 0 && s[j] > key) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;

    }
}

//Bubble Sort
//By GPA
template <class T>
void BubbleSortByGPA(T s[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size-i-1 ; j++)
        {
            number_of_comparisons_of_BubbleSort++;
            if(s[j].getGpa() > s[j+1].getGpa())
            {
                swap(s[j] , s[j+1]);
            }
        }
    }
}
//By Name
template <class T>
void BubbleSortByName(T s[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size-i-1 ; j++)
        {
            if(s[j] > s[j+1])
            {
                swap(s[j] , s[j+1]);
            }
        }
    }
}

//Quick Sort
//By GPA
template <class T>
void QuickSortByGPA(T s[],int left ,int right)
{
    if(left>right)
    {
        return;
    }
    else
    {
        int piv = PartitionGPA(s,left,right);
        QuickSortByGPA(s,left,piv-1);
        QuickSortByGPA(s,piv+1,right);
    }
}
//Partition For Quick Sort By GPA
template<class T>
int PartitionGPA(T s[] , int left , int right)
{
    T pivot = s[left];
    int i =left;
    for(int j = left+1;j<=right ; j++)
    {
        number_of_comparisons_of_QuickSort++;
        if(s[j].getGpa() < pivot.getGpa())
        {
            i++;
            swap(s[i] , s[j]);
        }
    }
    swap(s[left] , s[i]);
    return i;
}
//By Name
template <class T>
void QuickSortByName(T s[],int left ,int right)
{
    if(left>right)
    {
        return;
    }
    else
    {
        int piv = PartitionName(s,left,right);
        QuickSortByName(s,left,piv-1);
        QuickSortByName(s,piv+1,right);
    }
}

//Partition For Quick Sort By Name
template<class T>
int PartitionName(T s[] , int left , int right)
{
    T pivot = s[left];
    int i =left;
    for(int j = left+1;j<=right ; j++)
    {
        if(s[j] < pivot)
        {
            i++;
            swap(s[i] , s[j]);
        }
    }
    swap(s[left] , s[i]);
    return i;
}


//Donald Shell Sort
//By GPA
template<class T>
void ShellSortByGPA(T s[] , int size)
{
    for(int gap = size/2; gap>0 ; gap/=2)
    {
        for(int i = gap ; i < size ; i++)
        {
            T temp = s[i];
            int j;
            for(j = i ; j >= gap && s[j-gap].getGpa() > temp.getGpa() ; j-=gap )
            {
                number_of_comparisons_of_ShellSort++;
                s[j] = s[j-gap];
            }
            s[j] = temp;
        }
    }
}
//By Name
template<class T>
void ShellSortByName(T s[] , int size)
{
    for(int gap = size/2; gap>0 ; gap/=2)
    {
        for(int i = gap ; i < size ; i++)
        {
            T temp = s[i];
            int j;
            for(j = i ; j >= gap && s[j-gap] > temp ; j-=gap )
            {
                s[j] = s[j-gap];
            }
            s[j] = temp;
        }
    }
}

//Merge Sort
//By GPA
template<class T>
void MergeSortByGPA(T s[] , int left , int right)
{
    if(left < right)
    {
        int middle =left+(right-left)/2;
        MergeSortByGPA(s,0,middle);
        MergeSortByGPA(s,middle+1,right);
        MergeGPA(s,left,middle,right);
    }
}
//Merge Function By GPA
template<class T>
void MergeGPA(T s[] , int left , int middle , int right)
{
    int s1=middle-left+1;
    int s2=right-middle;
    int c,j,k;
    c=j=0;
    k=left;
    T L[s1],R[s2];

    for(int i=0;i<s1;i++)
    {
        L[i] = s[left + i];
    }

    for(int m=0;m<s2;m++)
    {
        R[m] = s[middle + 1 + m];
    }

    while(c<s1 && j<s2)
    {
        number_of_comparisons_of_MergeSort++;
        if(L[c].getGpa() <= R[j].getGpa())
        {
            s[k]=L[c];
            c++;
        }
        else
        {
            s[k]=R[j];
            j++;
        }
        k++;
    }
    while(c<s1)
    {
        s[k]=L[c];
        c++;
        k++;
    }
    while(j<s2)
    {
        s[k]=R[j];
        j++;
        k++;
    }
}

//By Name
template<class T>
void MergeSortByName(T s[] , int left , int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;
        MergeSortByName(s, 0, middle);
        MergeSortByName(s, middle + 1, right);
        MergeName(s, left, middle, right);
    }
}

template <class T>
void MergeName(T s[] , int left , int middle , int right)
{
    int s1=middle-left+1;
    int s2=right-middle;
    int c,j,k;
    c=j=0;
    k=left;
    T L[s1],R[s2];

    for(int i=0;i<s1;i++)
    {
        L[i] = s[left + i];
    }

    for(int m=0;m<s2;m++)
    {
        R[m] = s[middle + 1 + m];
    }

    while(c<s1 && j<s2)
    {
        if(L[c]<=R[j])
        {
            s[k]=L[c];
            c++;
        }
        else
        {
            s[k]=R[j];
            j++;
        }
        k++;
    }
    while(c<s1)
    {
        s[k]=L[c];
        c++;
        k++;
    }
    while(j<s2)
    {
        s[k]=R[j];
        j++;
        k++;
    }
}







