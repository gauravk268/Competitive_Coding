//Implementing operations on queue

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*last, *front;

//Inserting an element at the last of queue
void push(int value){
	struct node *new, *p;
	new = (struct node *)malloc(sizeof(struct node));
	if(new == NULL){
		printf("\nOverflow, no space");
		return;
	}
	
	if(front==NULL){
		new ->data = value;
		new->next=NULL;
		last = new;
		front = new;
	}
	
	else
		last->next = new;
		new->data = value;
		new->next=NULL;
		last=new;
}

//Delete an element from the beginning
void pop(){
	struct node *p;
	p=front;
	if(p != NULL){
		printf("\nPopped : %d", p->data);
		p = p->next;
	}
	else
		printf("\nUnderflow, nothing to pop");
}

void search(int value){
	struct node *p;
	p=front;
	int j=1, i=0;
	while(j && p!=NULL){
		i++;
		if(p->data == value)
			j=0;
		p=p->next;
	}
	if(j)
		printf("\nNumber is not present in the queue");
	else
		printf("\nGiven number found at %d position", i);
}

int main(){
	front = NULL;
	last = NULL;
	
	int opt1=1, opt2, value;
	
	while(opt1){
		printf("\nChoose your option : ");
		printf("\n1 : PUSH");
		printf("\n2 : POP");
		printf("\n3 : SEARCH");
		printf("\nYour Choice : ");
		scanf("%d", &opt2);
		
		switch(opt2){
			case 1:
				printf("\nEnter the value to be pushed : ");
				scanf("%d", &value);
				push(value);
				break;
			
			case 2:
				printf("\n");
				pop();
				break;
				
			case 3:
				printf("\nEnter the number to be searched : ");
				scanf("%d", &value);
				search(value);
				break;
				
			default:
				printf("\nEnter valid choice");
		}
		
		printf("\nEnter 1 to continue 0 to terminate : ");
		scanf("%d", &opt1);
	}
	return 0;
}
