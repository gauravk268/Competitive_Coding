// Implementing circular queue using array

#include<stdio.h>
#include<stdlib.h>

int f = -1, r = -1;
int *arr;
int n;

void enqueue(int data){
    if(f==0 && r==(n-1))
        printf("Queue Overflow\n");
    else if((r%n)+1 == (f%n))
        printf("Queue Overflow\n");
    else if(f== -1 && r == -1){
        arr[(++r)%n] = data;
        ++f;
    }
    else{
        arr[(++r)%n] = data;
    }
}

void dequeue(){
    if(f==-1 && r==-1)
        printf("Queue Underflow\n");
    else if((r%n)+1 == (f%n) )
        printf("Queue Underflow\n");
    else
        ++f;
}

void display(){
    int i;
    for(i = f ; i<=r; i++){
        printf("%d ", arr[i%n]);
    }
    printf("\n");
}

void main(){
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    arr= (int *)calloc(n,sizeof(int));
    while(1){
        printf("1:Insert\n2:Delete\n3:Print\n4:Exit\n");
        int q= 0;
        scanf("%d",&q);
        if(q==1){
            printf("Enter the data\n");
            int data;
            scanf("%d", &data);
            enqueue(data);
        }
        else if(q==2){
            dequeue();
        }

        else if(q==3){
            display();
        }
        else if(q==4)
            exit(1);
        else
            printf("Enter a proper query\n");

    }
}