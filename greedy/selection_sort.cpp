// Selection Sort is a comparison-based sorting algorithm. It sorts by repeatedly
// selecting the smallest (or largest)element from the unsorted
// portion and swapping it with the first unsorted element


#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) //array is passed like ptr to first element not need for ref(&)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex = i;
        for(int j=i+1;j<n;j++) //loop starts form i + 1
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j; //remeber j
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[n];

    cout<<"Enter elements:\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    selectionSort(arr,n);

    cout<<"Sorted array:\n";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}