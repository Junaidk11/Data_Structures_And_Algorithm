//
//  main.c
//  Sorting Algorithms
//
//  Created by jjkhan on 7/12/21.
//

#include <stdio.h>
#include <math.h>

// Algorithm
void mergeSort(int *arr, int leftIndex, int rightIndex); // Recursive MergeSort
void iterative_mergerSort(int *arr, int size);

// Test Programs
void print_array(int arr[], int len);
void Recursive_merge_Sort(void);
void Iterative_merge_Sort(void);


int main(int argc, const char * argv[]) {
    // insert code here...
    Iterative_merge_Sort();
    return 0;
}


void print_array(int arr[], int len){
    int i;
    printf("Array elements are: ");
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void Iterative_merge_Sort(void){
    int arr[]={1,5,4,6,3,34,24};
    int arr2[]={0,-1,45,-10,-10,100};
    int arr3[] = {1};
    // test 1
    print_array(arr, 7);
    iterative_mergerSort(arr,7);
    print_array(arr, 7);
    
    //test 2
    print_array(arr2, 6);
    iterative_mergerSort(arr2, 6);
    print_array(arr2, 6);
    
    // test 3
    print_array(arr3, 1);
    iterative_mergerSort(arr3,1);
    print_array(arr3, 1);
}
// Tests Passed
void Recursive_merge_Sort(void){
    
    int arr[]={1,5,4,6,3,34,24};
    int arr2[]={0,-1,45,-10,-10,100};
    int arr3[] = {1};
    // test 1
    print_array(arr, 7);
    mergeSort(arr, 0, 6);
    print_array(arr, 7);
    
    //test 2
    print_array(arr2, 6);
    mergeSort(arr2, 0, 5);
    print_array(arr2, 6);
    
    // test 3
    print_array(arr3, 1);
    mergeSort(arr3, 0, 0);
    print_array(arr3, 1);
}


/*
    In this function, you break the given arr into two halves, sort them first,
    then merge their results.
        First subarray is arr[l..m]
        Second subarray is arr[m+1..r]
 
    The work done in this algorithm is: Breaking the arr into two halves and working
    on each half recursively so the worse case time complexity is O(logn).
 
    The space complexity of this algorithm is high because you make recursive
    calls to the same function, however, you break the workspace into two on each call,
    so the time complexity is O(logn)
 */

void merge(int *arr, int leftIndex, int midPoint, int rightIndex)
{
    // Calculate length of left and right sorted subarrays
    int i, j, k;
    int left_len = midPoint - leftIndex + 1;
    int right_len = rightIndex - midPoint;

    // Temp left and right subarrays
    int Left[left_len], Right[right_len];

    // Copy data over to the temp arrays
    for (i = 0; i < left_len; i++)
        Left[i] = arr[leftIndex + i];
    for (j = 0; j < right_len; j++)
        Right[j] = arr[midPoint + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = leftIndex; // Initial index of merged subarray
    while (i < left_len && j < right_len) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    
   // One of the arrays reached end
   // Copy remaing elements over
    while (i < left_len) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < right_len) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int *arr, int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int midpoint = leftIndex + (rightIndex - leftIndex) / 2;

        // Sort first and second halves
        mergeSort(arr, leftIndex, midpoint);
        mergeSort(arr, midpoint + 1, rightIndex);
        // Merge the two sorted subarrays
        merge(arr, leftIndex, midpoint, rightIndex);
    }
}


/*
    In this function, the merge sort is performed iteratively.
 
    In recursive mergeSort, the given list was broken down into halves until you reach a single element and on your way
    back you merge the two sorted halves. In iterative mergeSort, you assume that each element in the given array is an individual
    array with just one element , i.e. an array with a single element is already sorted. So initially, we take 2 elements at a
    time (we call them two sorted lists now) and merge them to give you a sorted list of 2, we repeat this until we reach the
    end of the list. Next, we take sorted lists of two elements each time and merge them together. We repeat this until we
    have a final list of the given size - this is the sorted list. Thing of this breakdown as tree upside down.
 
    E.g. if you have a list of 8 elements -> then a height of a binary tree is log n -> so, log (8) = 3, so we go through
        passes of the given array to get the sorted array in the end. Note, passes means we sorted n elements 3 times, first by taking
        two at a time -> which produces a new list of 2 elements -> 4 of them, then we merge two of these 2-element-sorted list and
        merge them to get list of 4 element -> 2 of them, finally we merge this 2  4-element-sorted lists to get the final 8-element-sorted list.
 
        Visually:
                    Given A = 8,3,7,4,9,2,6,5  size=8, so we will have log(8) = 3 passes to get the inplace sorted array via mergesort
            
            1st Pass -> Sort 2 elements at a time from the unsorted array of "sorted-list"
                        
              Sorted list size = 2              3,8  4,7  2,9   5,6
            
            2nd Pass -> Sort 2 of the sorted 2-element-sorted-list at a time
              Sorted list size = 4              3,4,7,8   2,5,6,9
            
            3rd Pass -> Sort the two sorteed 4-element-sorted-lists
              Sorted list size = 8              2,3,4,5,6,7,8
        
            Merge sort result -> 2,3,4,5,6,7,8
 
            The time taken for this algorithm is dependent on height of the binary tree, which is logn, and the sort was performed
            on n elements, so the time complexity is O(nlogn)
 
    Note: In the above example the number of elements was even so you had all pairs at start, if there were odd elements
          then there would be a 4th pass to merge the last element with the result of the 3rd pass above.
        
        Visually:
                Given A = 8,3,7,4,9,2,6,5,1  size=9, so we will have ceil(log(9)) = 4 passes to get the inplace sorted array via mergesort

            1st Pass -> Sort 2 elements at a time from the unsorted array of "sorted-list", '1' has no pair so it will stay in place
     
                Sorted list size = 2        3,8  4,7  2,9  5,6  1

            2nd Pass -> Sort 2 of the sorted 2-element-sorted-list at a time, '1' will stay in place
                 Sorted list size = 4    3,4,7,8   2,5,6,9  1

            3rd Pass -> Sort the two sorteed 4-element-sorted-lists, '1' will stay in place
                 Sortedd list size = 8    2,3,4,5,6,7,8  1
 
            4th Pass -> Merge the sorted 8-element-sorted-list and the last element '1'

            Merge sort result -> 1,2,3,4,5,6,7,8

            The time taken for this algorithm is dependent on height of the binary tree, which is logn, and the sort was performed
            on n elements, so the time complexity is O(nlogn)
 
 
     So, algorithmicly, you have two for-loops, one for each pass depending,  the sorted list size for each pass increases by 2.
     Then, in each pass, you merge two sorted-list at a time, starting at the start and making your way to the end for EACH pass.
    
     Once you've exited the for-loops, you have sorted array of even size elements, so you check if the given size was odd, if so, then
    you need to perform merge one more time to place the last element of the given array at its correct position.

 */

// Utility function to find minimum of two integers
int min(int x, int y) { return (x<y)? x :y; }
 
// Iteratively sort subarray `A[low…high]`

/*
    Merge sort can be implemented iteratively in bottom-up manner. We start by sorting all subarrays of 1 element,
    then merge results into subarrays of 2 elements, then merge results into subarrays of 4 elements. Likewise,
    we perform successive merges until the array is completely sorted. 
 */
void iterative_mergerSort(int *arr, int size)
{
    int low = 0;
    int high = size-1;
    // divide the array into blocks of size `m`
    // m = [1, 2, 4, 8, 16…]
    for (int m = 1; m <= high - low; m = 2*m)
    {
        // for m = 1, i = 0, 2, 4, 6, 8…
        // for m = 2, i = 0, 4, 8…
        // for m = 4, i = 0, 8…
        // …
        for (int i = low; i < high; i += 2*m)
        {
            // Get left, mid, right indices for merge
            int from = i;
            int mid = i + m - 1;
            int to = min(i + 2*m - 1, high);
 
            merge(arr,from, mid, to);
        }
    }
}
 
