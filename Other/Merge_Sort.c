//Implementing Merge Sort

#include<stdio.h>
#include<stdlib.h>

int comparison=0;
int size = 100;

void merge(int arr[], int beg, int mid, int end){ 
    int i=beg, j=mid+1, index=beg, temp[size];
    while((i<=mid) && (j<=end)){
        comparison++;
        if(arr[i]<arr[j])
            temp[index++] = arr[i++];
        else
            temp[index++] = arr[j++];
    }

    if(i>mid){
        comparison++;
        while(j<=end){
            temp[index++]=arr[j++];
        }
    }
    else{
        comparison++;
        while(i<=mid)
            temp[index++]=arr[i++];
    }
    
    for(i=beg; i<index; i++)
        arr[i]=temp[i];
}
  
void mergeSort(int arr[], int beg, int end){
    int mid; 
    if (beg < end){
        mid = (end+beg)/2;

        mergeSort(arr, beg, mid); 
        mergeSort(arr, mid+1, end); 
  
        merge(arr, beg, mid, end); 
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

    mergeSort(arr, 0, num-1);

    printf("\nSorted array : ");
    for(int i=0; i<num; i++){
        printf("%d  ", arr[i]);
    }

    printf("\nComparisons = %d\n",comparison);

    return 0;
}