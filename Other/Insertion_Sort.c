//Implementing Insertion Sort

#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, i, j, count=0, comparison=0, val=0;
    printf("\nEnter the size of array : ");
    scanf("%d", &num);
    int arr[num];

    printf("\nEnter the array");
    for(int i=0; i<num; i++){
        printf("\nEnter %d value : ", i);
        scanf("%d", &arr[i]);
    }

    for (i=1;i<num;i++) { 
        val=arr[i]; 
        j=i-1; 
        while(j>=0 && arr[j]>val){
            comparison++;
            arr[j+1]=arr[j]; 
            j=j-1;
        }
        count++;
        arr[j+1]=val;
    }

    printf("\nSorted array : ");
    for(int i=0; i<num; i++){
        printf("%d  ", arr[i]);
    }

    printf("\nSwappings = %d, Comparisons = %d\n", count, comparison);

    return 0;
}