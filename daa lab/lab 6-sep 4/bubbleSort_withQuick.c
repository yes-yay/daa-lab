// C code to implement quicksort

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than the pivot
        if (arr[j] < pivot) {

            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
    if (low < high) {

        // pi is partitioning index, arr[p]
        // is now at right place
        int pi1 = partition(arr, low, high);
        int pi2= partition(arr,low,high);
        
        
        // Separately sort elements before
        // partition and after partition
       // if(pi1<pi2)
        
        quickSort(arr, low, pi1-1);
       // pi2=partition(arr,low,high-1);
        quickSort(arr, pi1+1, pi2-1);
       quickSort(arr, pi2+1, high);
        
       // else
    //    {
      //      quickSort(arr, low, pi2-1);
       // pi2=partition(arr,low,high-1);
    //    quickSort(arr, pi2+1, high);
      //  quickSort(arr, pi1+1, high);
        
        
        
        
    }
}

// Driver code
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5, 2, 6, 3};
    
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    quickSort(arr, 0, N - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}