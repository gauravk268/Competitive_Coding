// Implementing calculation of frequency of elements in order of appearance

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};
struct freq{
	int numb;
	int freq;
};
struct node* head = NULL;

void addatbeg(int element){
	struct node * temp = (struct node*) malloc(sizeof(struct node));
	temp->data = element;
	temp->next = head;
	head = temp;
	}

void display(){
	struct node *ptr = head;
	while(ptr != NULL){
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
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

void main(){
	printf("Enter the number of elements\n");
	int n;
	scanf("%d", &n);

	int i= 0 ;
	int element;
	printf("Enter the elements\n");
	for(i = 0 ;i<n ; i++){
		scanf("%d", &element);
		addatbeg(element);
	}
	rev();

	struct node* p = head;

	struct freq *arr = (struct freq *)malloc(sizeof(struct freq));
	arr->numb = p->data;
	arr->freq = 0;
	int dist = 1 ;

	while(p!= NULL){
		int flag = 0 ;
		for(i = 0 ; i<dist; i++){
			if((arr+i)->numb == p->data){
				((arr+i)->freq )++;
				flag = 1;
				break;
			}
		}

		if(flag == 0){
			arr = (struct freq*) realloc(arr,(dist+1)*sizeof(struct freq));
			(arr+dist)->numb = p->data;
			(arr+dist)->freq = 1;
			dist++;
		}
		p = p->next;
	}

	//Printing the frequencies of the numbers

	for(i = 0 ; i<dist; i++)
		printf("Frequency(%d) = %d\n", (arr+i)->numb, (arr+i)->freq);
}