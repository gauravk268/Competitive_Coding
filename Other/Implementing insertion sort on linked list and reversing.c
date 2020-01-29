// Implementing insertion sort on linked list and reversing

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

struct node* head = NULL;

void addatbeg(int element){
	struct node * temp = (struct node *) malloc(sizeof(struct node));
	temp->data = element;
	temp->next= head;
	head = temp;
}

void rev(){
	struct node * prev = NULL;
	struct node * p = head;
	struct node * next ;

	while(p!= NULL){
		next = p->next;
		p->next = prev;
		prev = p;
		p = next;
	}
	head = prev;
}

void display(){
	struct node *ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void main(){
	printf("Enter the number of elements\n");
	int n ;
	scanf("%d",&n);
	int i,j;
	int element;
	printf("Enter the elements of the list\n");
	for(i =0 ; i<n ; i++){
		scanf("%d",&element);
		addatbeg(element);
	}

	rev();
	printf("The list is\n");
	display();
	// Insertion Sorting

    int flag = 0 ;
	struct node *ptr = head->next;
	struct node *p = head;
	struct node *ptrprev = head;
	struct node *pprev = NULL;
	while(ptr!= NULL){
        flag = 0;
        pprev = NULL;
        p = head;
        while(p!= ptr){
            if(p->data >ptr->data){
                ptrprev->next = ptr->next;
                ptr->next =p;
                if(pprev == NULL)
                    head = ptr;
                else
                    pprev->next =ptr;
                p = head;
                ptr = ptrprev->next;
                pprev = NULL;
                flag = 1;
                break;
            }
            else{
                pprev = p;
                p = p->next;
            }

        }
        if(!flag){
            ptrprev = ptr;
            ptr = ptr->next;
        }

	}
	printf("The sorted list is\n");

	display();
}