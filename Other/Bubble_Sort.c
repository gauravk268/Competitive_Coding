//Implementing Bubble Sort

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

    for(int i=0; i<(num-1); i++){
        for(int j=1; j<num; j++){
            comparison++;
            if(arr[j-1]>arr[j])
                swap(&arr[j-1], &arr[j]);
        }
    }

    printf("\nSorted array : ");
    for(int i=0; i<num; i++){
        printf("%d  ", arr[i]);
    }

    printf("\nSwappings = %d, Comparisons = %d\n", count, comparison);

    return 0;
}