// Implementing deletion of nodes if higher value is in right 

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

struct node* head = NULL;

int isEmpty(){
    if(head == NULL)
        return 1;
    else
        return 0;
}

void insertAtHead(int element){
	struct node * temp = (struct node*) malloc(sizeof(struct node));
	temp->data = element;
	temp->next = head;
	head = temp;
}

void display(){

    if(isEmpty()){
        printf("The linked list is empty\n");
        return;
    }
	struct node *ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void rev(){
	struct node * prev = NULL;
	struct node * p = head;
	struct node * nextt ;

	while(p!= NULL){
		nextt = p->next;
		p->next = prev;
		prev = p;
		p = nextt;
	}
	head = prev;
}

void main(){
    printf("Enter the number of elements to be inserted in linked list \n");
    int n;
    scanf("%d",&n);

    int i = 0 ;
    int ele;
    printf("Enter the elements\n");
    for(i = 0 ; i<n; i++){
        scanf("%d",&ele);

        insertAtHead(ele);
    }

    rev();


    //remove all the nodes that have a greater value to their right.

    struct node*ptr = head;
    struct node*prev = NULL;

    while(ptr->next != NULL){
        if(ptr->next->data > ptr->data){
            if(prev == NULL){
                    head = ptr->next;
                    free(ptr);
                    ptr = head;
            }
            else{
                prev->next = ptr->next;
                free(ptr);

                ptr = head;
            }

        }
        else{
            prev = ptr;
            ptr  = ptr->next;
        }
    }

    printf("\nFinal Linked List output");

    display();
}