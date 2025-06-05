//
//  main.c
//  Review
//
//  Created by jjkhan on 9/3/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int* union_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len, int* resultSize);

int main(){
    
    int arr1[]={3,5,7,9,11};
    int arr2[]={1,3,5,11,15};
    
    int resultSize = 0;

    int *result = union_of_sorted_sets(&arr1[0], 5, &arr2[0],5,&resultSize);
    
    int i;
    for(i=0; i<resultSize; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    
    
    return 0;
}
/*

    [1, 2, 3, 4, 5]

    read 1 into a variable
    loop from 0 to size and shift all the variables to the left
*/
void left_shift(int *arr, int length){

    int i;
    for (i=0; i<length; i++){
        arr[i] = arr[i+1];
    }
    arr[i-1] = 0;

}
void right_shift(int *arr, int length){
    
    int i;
    for(i=length-1; i>=0; i--){
        arr[i]=arr[i-1];
    }
    arr[0]=0;
}

void rotate_left(int *arr, int length){
    int firstElement = arr[0];
    
    int i;
    for(i=0; i<length; i++){
        arr[i] = arr[i+1];
    }
    arr[length-1] = firstElement;
}
void rotate_right(int *arr, int length){
    
    int lastElement = arr[length-1];
    
    int i;
    for(i=length-1; i>0; i--){
        arr[i] =  arr[i-1];
    }
    arr[i] = lastElement;
}

/*
        Use two indexers -> one from front and the other from back, swap the two index elements
        
 */
void reverse_array(int *arr, int length){
    int i, j, temp;
    
    for(i=0,j=length-1; i<j; i++, j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j]=temp;
    }
}

/*
    use two indexers
        [-1, 3, -1, -2, 6, 8, -7]
    One starts at the front and the other at the back, i is looking for positive numbers and j is looking for negative numbers
    you swap when the two find the integers they're looking for.
    Repeat  this until i crosses j or the other way around
 */
void move_negative_to_left(int *arr, int length){
    
    int i = 0, j = length-1, temp;
    
    while(i<j){
        
        while(arr[i]<0){
            i++;
        }
        
        while(arr[j]>0){
            j--;
        }
        
        if(i<j){
            temp = arr[i];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    
}
int* mergeArrays(int *arr1, int arr1_length, int *arr2, int arr2_length){
    
    int *mergeResult  = (int*)malloc((arr1_length+arr2_length)*sizeof(int));
    
    // Indexer for each array
    int i=0,  j=0, k=0;
    
    while(i<arr1_length || j<arr2_length){
        
        if(arr1[i]<arr2[j]){
            // Move arr1  element to the result array
            mergeResult[k++] = arr1[i++];
        }else{
            // Move arr2 element to the result array
            mergeResult[k++] = arr2[j++];
        }
    }
    
    // Copy the remaining elements of the array not scanned completely
    while(i<arr1_length){
        // Move arr1  element to the result array
        mergeResult[k++] = arr1[i++];
    }
    
    while(j<arr2_length){
        mergeResult[k++] = arr2[j++];
    }
    
    return mergeResult;
}

/*
 
    All elements of two arrays without duplicates - union
    Common elements of two arrays -> intersection
    Difference of two arrays -> A-B = Elements that are in B but not A
    
 
 */


bool linearSearch(int *arr, int size, int key){
    
    int i;
    for(i=0; i<size; i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

typedef struct dynamicArray{
    int size;
    int length;
    int *arr;
} dynamicArray;

/*
    The maximum size of the result array could be set1+set2 -> i.e. all elements are unique in both sets
    So, we create a max size array and keep track of its length. If the length is shorter than allocated size, then we resize it.
 
 */
int* union_of_unsorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len){
    
    // Declare struct for union result
    dynamicArray result;
    result.size = arr1_len + arr2_len;
    result.length =0;
    result.arr = (int*)malloc(result.size*sizeof(int));
    
    // Copy over the elements of one of the sets
    int i;
    for(i=0; i<arr1_len; i++){
        result.arr[result.length] = arr1[i];
        result.length++;
    }
    
    // Now for each element in arr2, you search if the element already exist in arr1
    for(i=0; i<arr2_len; i++){
        if(!linearSearch(arr1, arr1_len, arr2[i])){
            // set2 element not in arr1, copy it over to result
            result.arr[result.length] = arr2[i];
            result.length++;
        }
    }
    
    // Now we check if the length of the result array is less or equal to allocated memory
    if(result.length+1<result.size){
        result.arr = (int*)realloc(result.arr, (result.length+1)*sizeof(int));
        result.size = result.length+1;
    }
    
    return result.arr;
    
}
/*
    Same idea as merge
    Only copy once if the two sets have the same element, else copy the other.
    
    Worse  case is that all the elements of both sets are unique -> then max size of result is set1+set2
    
    
 */
int* union_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len, int* resultSize){
   
    // Allocate memory for result
    dynamicArray result;
    result.size = arr1_len+arr2_len;
    result.length = 0;
    result.arr = (int*)malloc(result.size*sizeof(int));
    
    // Indexers for each array
    int i=0, j=0;
    
    while(i<arr1_len || j<arr2_len){
        if(arr1[i]==arr2[j]){
            result.arr[result.length++] = arr1[i];
            i++;
            j++;
        }else if(arr1[i]<arr2[j]){
            result.arr[result.length++] = arr1[i++];
            
        }else{
            result.arr[result.length++] = arr2[j++];
        }
    }
    
    // copy the values of the set not scanned completely
    while(i<arr1_len){
        result.arr[result.length++] = arr1[i++];
    }
    
    while(j<arr2_len){
        result.arr[result.length++] = arr2[j++];
    }
    
    // Now check if all the allocated memory is used, else resize
    if(result.length<result.size){
        // Realloc memory
        result.arr = (int*)realloc(result.arr, (result.length)*sizeof(int));
        result.size = result.length;
    }
    
    *resultSize = result.size;
    return result.arr;
}
int* intersection_of_unsorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
int* intersection_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
int* difference_of_unsorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
int* difference_of_sorted_sets(int *arr1, int arr1_len, int *arr2, int arr2_len);
bool is_memeber_of_unsorted_set(int *arr, int len, int value);
bool is_memeber_of_sorted_set(int *arr, int len, int value);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode * res=NULL,*start=NULL;
    int x,y,c=0;
    
    if (!l1 && !l2)
        return NULL;
    else if (!l1)
        return l2;
    else if (!l2)
        return l1;

    while(l1 || l2 || c)
    {
        x = l1->val;
        y = l2->val;
        if (!res)
        {
            res = malloc(sizeof(struct ListNode));
            start = res;
        }
        else
        {
            res->next = malloc(sizeof(struct ListNode));
            res = res->next;
        }
        res->next =NULL;
        res->val = (x+y+c)%10;
        c = (x+y+c)/10;
        l1=l1->next;
        l2=l2->next;
    }
    return start;
}