//Implementing linear queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*last, *front;

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

void display(){
	struct node *p;
	p=front;
	if(p != NULL){
		while(p->next != NULL){
			printf("%d ->", p->data);
			p=p->next;
		}
	}
	else
		printf("\nQueue is empty");
}

int main(){
	front = NULL;
	last = NULL;
	
	int opt1=1, opt2, value;
	
	while(opt1){
		printf("\nChoose your option : ");
		printf("\n1 : PUSH");
		printf("\n2 : POP");
		printf("\n3 : DISPLAY");
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
				printf("\n");
				display();
				break;
				
			default:
				printf("\nEnter valid choice");
		}
		
		printf("\nEnter 1 to continue 0 to terminate : ");
		scanf("%d", &opt1);
	}
	return 0;
}
