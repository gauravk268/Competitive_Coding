#include<stdio.h>

void shift_array(int shape[8][8]){
  int i, j;
  
  for(i=0; i<8; i++){
  	
  	int temp=shape[i][0];
    for(j=0; j<8; j++){
      shape[i][j]=shape[i][j+1];
    }
    
    shape[i][7]=temp;
  }
}

void printArray(int shape[8][8]){
    int i=0, j=0;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            printf(" %d ", shape[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int array[8][8]={
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8}
    };
    
    printArray(array);
    
    printf("\n\n");
    int count=5;
    
    while(count--){
    	shift_array(array);
    	printArray(array);
    	printf("\n\n");
	}
	
    return 0;
}
