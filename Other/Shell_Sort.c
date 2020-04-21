//Implementing Shell Sort

#include<stdio.h>
#include<stdlib.h>

int comparison=0;

void shellSort(int arr[], int num){
  for (int gap = num/2; gap > 0; gap /= 2){
    for (int i = gap; i < num; i += 1) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
        arr[j] = arr[j - gap];
        comparison++;
      }
      arr[j] = temp;
    }
  }
}

int main(){
    int num;
    printf("\nEnter the size of array : ");
    scanf("%d", &num);
    int arr[num];

    printf("\nEnter the array : ");
    for(int i=0; i<num; i++){
        printf("\nEnter %d value : ", i);
        scanf("%d", &arr[i]);
    }

    shellSort(arr, num);

    printf("\nSorted array : ");
    for(int i=0; i<num; i++){
        printf("%d  ", arr[i]);
    }

    printf("\nComparisons = %d\n", comparison);

    return 0;
}