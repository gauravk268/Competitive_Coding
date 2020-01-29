//Implementing two stacks on a single array

#include <stdio.h>
#include <stdlib.h>

int arr[100], top1, top2, i, size;

void push(int stack, int value){
	if(stack==1 && top1<top2){
		arr[top1++] = value;
	}
	else if(stack==2 && top2>top1){
		arr[top2--] = value;
	}
	else
		printf("\nOverflow, cannot push");
}

int pop(int stack){
	if(stack==1 && top1>-1)
		printf("\nPopped : %d", arr[top1--]);
	else if(stack == 2 && top2<size)
		printf("\nPopped : %d", arr[top2--]);
	else
		printf("\nUnderflow, cannot pop");
}

void display(int stack){
	if(stack==1 && top1>-1){
		for(i=0; i<top1; i++)
			printf("%d -> ", arr[i]);
	}
	else if(stack == 2 && top2<size){
		for(i=size; i>top2; i--)
			printf("%d -> ", arr[i]);
	}
	else
		printf("Nothing to display");
}

int main(){
	int opt1, opt2=1, stack, value;
	printf("\nEnter the size of array: ");
	scanf("%d", &size);
	
	top1=-1;
	top2=size;
	
	while(opt2){
		printf("\nSelect stack 1 or 2 for operation : ");
		scanf("%d", &stack);	
		
		printf("\n\nChoose your option : ");
		printf("\n1 : PUSH");
		printf("\n2 : POP");
		printf("\n3 : DISPLAY");
		printf("\nYour Choice : ");
		scanf("%d", &opt1);
		
		switch(opt1){
			case 1:
				printf("\nEnter value to be pushed : ");
				scanf("%d", &value);
				push(stack, value);
				break;
				
			case 2:
				pop(stack);
				break;
				
			case 3:
				printf("\n");
				display(stack);
				break;
				
			default:
				printf("\nEnter valid option");
		}
		
		printf("\nEnter 1 to continue 0 to terminate : ");
		scanf("%d", &opt2);
	}
	
	return 0;
}
