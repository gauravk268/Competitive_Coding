// Implementing DQUE using a one-dimensional array

#include<stdio.h>
#include<stdlib.h>

int *arr;
int n;
int f = -1, r= -1;
int restriction=1;

void addfromrear(int data){
        if(f == -1){
            f++;
            arr[(++r)%n] = data;
        }
        else if(r == 0 && n ==1)
            printf("Queue Overflow\n");
        else if((r%n)+1 ==(f) ){
            printf("Queue Overflow\n");
        }
        else {
            arr[(++r)%n] = data;
        }
}

void addfromfront(int data){
        if(f == -1){
            r = n-1;
            f = n-1;
            arr[f] = data;
        }
        else if(r == 0 && n ==1)
            printf("Queue Overflow\n");
        else if(f == 0){
            f = n-1;
            arr[f] =data;
        }
        else if((r%n)+1 ==(f) ){
            printf("Queue Overflow\n");
        }
        else {
            arr[--f] = data;
        }
}

void delfromfront(){
    if(r+1 == f)
        printf("Queue underflow\n");
    else if(r == -1)
        printf("Queue underflow\n");
    else
        ++f;
}

void delfromrear(){
    if(r+1 == f)
        printf("Queue underflow\n");
    else if(r == -1)
        printf("Queue underflow\n");
    else
        --r;
}

void display(){
    int i;

    if(r ==-1){
        printf("Queue is Empty\n");
        return;
    }
    else if(r+1 == f)
        printf("Queue underflow\n");

    for(i = f ; (i)<=r; i++ ){
        printf("%d ", arr[i%n]);
    }
    printf("\n");
}

void main(){
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    arr = (int *)calloc(n,sizeof(int));
    int q = 0 ;
    int element;
    while(1){
        if(restriction == 1){
            printf("1:Insert from front\n2:Insert from rear\n3:Delete from front\n4:Delete from rear\n5:Change restriction\n6:Print\n7:Exit\n");
            scanf("%d", &q);
            if(q == 1){
                printf("Enter the element\n");
                scanf("%d",&element);
                addfromfront(element);
            }
            else if(q==2){
                printf("Enter the element\n");
                scanf("%d", &element);
                addfromrear(element);
            }
            else if(q == 3)
                delfromfront();
            else if(q==4)
                delfromrear();
            else if(q == 5){
                printf("1:No Restriction\n2:Input Restriction\n3:Output Restriction\n");
                scanf("%d",&restriction);
            }
            else if(q == 6){
                display();
            }
            else if(q == 7)
                exit(1);
            else
                printf("Enter a proper query\n");

        }

        else if(restriction == 2){
            printf("1:Insert from rear\n2:Delete from front\n3:Delete from rear\n4:Change restriction\n5:Print\n6:Exit\n");
            scanf("%d", &q);
            if(q==1){
                printf("Enter the element\n");
                scanf("%d", &element);
                addfromrear(element);
            }
            else if(q == 2)
                delfromfront();
            else if(q==3)
                delfromrear();
            else if(q == 4){
                printf("1:No Restriction\n2:Input Restriction\n3:Output Restriction\n");
                scanf("%d",&restriction);
            }
            else if(q==5)
                display();
            else if (q == 6)
                exit(1);
            else
                printf("Enter a proper query\n");

        }

        else if(restriction == 3){
            printf("1:Insert from front\n2:Insert from rear\n3:Delete from front\n4:Change restriction\n5:Print\n6:Exit\n");
            scanf("%d", &q);
            if(q == 1){
                printf("Enter the element\n");
                scanf("%d",&element);
                addfromfront(element);
            }
            else if(q==2){
                printf("Enter the element\n");
                scanf("%d", &element);
                addfromrear(element);
            }
            else if(q == 3)
                delfromfront();
            else if(q == 4){
                printf("1:No Restriction\n2:Input Restriction\n3:Output Restriction\n");
                scanf("%d",&restriction);
            }
            else if(q == 5)
                display();
            else if(q == 6)
                exit(1);
            else
                printf("Enter a proper query\n");
        }
    }
}