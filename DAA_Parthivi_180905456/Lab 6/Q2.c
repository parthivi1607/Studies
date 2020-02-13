#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  // selecting last element as pivot
    int i = (low - 1);  // index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int a[], int p, int r)    
{  int counter =0;
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        counter++;
        quicksort(a, q+1, r);
        counter++;
    }

      
}

void printArray(int a[], int sizeofe)
{
    int i;
    for (i=0; i < sizeofe; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter 10 elements for the array ");
    int arr[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Given array is : \n");
    printArray(arr,n);
    // call quickSort function
    quicksort(arr, 0, n-1);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}