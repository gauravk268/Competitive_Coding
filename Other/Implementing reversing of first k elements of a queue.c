// Implementing reversing of first k elements of a queue

#include<stdio.h>
#include<stdlib.h>

int *arr;
int n;
int f= -1, r=-1;

void enqueue(int data){
    if(f==0 && r==(n-1))
        printf("Queue Overflow");
    else if((r%n)+1 == (f%n))
        printf("Queue Overflow");
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
void rev(int k){

    if(f+k>r){
        printf("Please enter a valid value of k\n");
        return;
    }
    int s[k];
    int top = -1 ;
    int i = 0;

    while(top!=(k-1))
        s[++top] = arr[(f++)%n];

    while(i<=top){
        arr[(--f)%n] = s[i++];
    }
}

void main(){
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    arr= (int *)calloc(n,sizeof(int));
    while(1){
        printf("1:Insert\n2:Delete\n3:Print\n4:Reverse\n5:Exit\n");
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
        else if(q == 4){
            int k;
            printf("Enter the value of k\n");
            scanf("%d",&k);
            rev(k);
        }
        else if(q==5)
            exit(1);
        else
            printf("Enter a proper query\n");
    }
}
