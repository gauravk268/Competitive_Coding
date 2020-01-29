//Implementing Quick Sort

#include<stdio.h>
#include<stdlib.h>

int count = 0;
int comparison=0;

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    count++;
}

int partition (int arr[], int beg, int end){ 
    int left, right, flag, pivot;
    pivot=beg;
    left = beg;
    right = end;
    flag =0;
    while(flag!=1){
        while(arr[pivot]<=arr[right] && (pivot!=right)){
            comparison++;
            right--;
        }
        if(pivot == right)
            flag =1;
        else if(arr[pivot]>arr[right]){
            comparison++;
            swap(&arr[pivot], &arr[right]);
            pivot = right;
        }
        
        if(flag!=1){
            while(arr[pivot]>=arr[left] && (pivot != left)){
                left++;
                comparison++;;
            }
            if(pivot==left)
                flag=1;
            else if(arr[pivot]<arr[left]){
                comparison++;
                swap(&arr[pivot], &arr[left]);
                pivot = left;
            }
        }
    }
    return pivot;
} 

void quickSort(int arr[], int beg, int end) { 
    if (beg < end){
        int pi = partition(arr, beg, end); 

        quickSort(arr, beg, pi - 1); 
        quickSort(arr, pi + 1, end); 
    } 
} 

int main(){
    int num;
    printf("\nEnter the size of array : ");
    scanf("%d", &num);
    int arr[num];

    printf("\nEnter the array");
    for(int i=0; i<num; i++){
        printf("\nEnter %d value : ", i);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, num-1);

    printf("\nSorted array : ");
    for(int i=0; i<num; i++){
        printf("%d  ", arr[i]);
    }

    printf("\nSwappings = %d, Comparisons = %d\n", count, comparison);

    return 0;
}