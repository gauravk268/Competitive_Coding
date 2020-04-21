// Implementing priority queue using two dimensional array

#include<stdio.h>
#include<stdlib.h>

int **arr;
int n;
int f= -1, r= -1;

void enqueue(int data,int prio){
    if(f==0 && r==(n-1))
        printf("Queue Overflow");
    else if((r%n)+1 == (f%n))
        printf("Queue Overflow");
    else if(f== -1 && r == -1){
        arr[(++r)%n][0] = prio;
        arr[(r)%n][1] = data;
        ++f;
    }
    else{
        arr[(++r)%n][0] = prio;
        arr[(r)%n][1] = data;
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
    int j;
    int m = 999999;
    int element=0;
    for(j = 0 ; j<=(r-f); j++){
    int p = 0;
        for(i = f ; i<=r; i++){
            if(arr[i%n][0]<m && arr[i%n][0]>p){
                p = arr[i%n][0];
                element = arr[i%n][1];
            }
        }
        printf("%d %d\n",p,element);
        m = p;
    }
    printf("\n");
}

void main(){
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    arr = (int **)malloc(n*sizeof(int*));
    int i= 0;
    for(i =0 ;i<n; i++){
        arr[i] = (int *)malloc(2*sizeof(int));
    }

    while(1){
        printf("1:Insert\n2:Delete\n3:Print\n4:Exit\n");
        int q= 0;
        scanf("%d",&q);
        if(q==1){
            printf("Enter the data\n");
            int data;
            scanf("%d", &data);
            printf("Enter the priority\n");
            int prio;
            scanf("%d",&prio);
            enqueue(data,prio);
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
