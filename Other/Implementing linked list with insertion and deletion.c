// Implementing linked list with insertion and deletion

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head= NULL;

int isEmpty(){
    if(head == NULL)
        return 1;
    else
        return 0;
}

void delatpos(int pos){
    if(isEmpty()){
        printf("Linked List is Empty\n");
        return;
    }
    if(pos == 1){
        struct node* ptr = head;
        head = ptr->next;
        free(ptr);
    }
    else{
        pos--;
        struct node* ptr = head;
        int i;
        for(i =1 ;i<pos; i++){
            ptr = ptr->next;
            if(ptr == NULL){
                printf("Enter a proper position\n");
                return;
            }

        }
        struct node* p = ptr->next;
        ptr->next = ptr->next->next;
        free(p);

    }
}

void delatend(){
    struct node* ptr= head;

    if(isEmpty()){
        printf("List is empty\n");
        return;
    }

    while(ptr->next->next != NULL){
            ptr = ptr->next;
    }
    struct node*p = ptr->next;
    ptr->next= NULL;

    free(p);
}

void addatpos(int data, int pos){
	if(pos == 0 ){
		printf("Please enter a valid position\n");
		return;
	}
	else if(pos == 1){
        struct node *temp = (struct node*) malloc (sizeof(struct node));
        temp->data = data;
        temp->next = head;
        head = temp;
	}
	else {
        pos--;
        struct node *ptr = head;
		int i = 1 ;
		while(i<pos){
			ptr = ptr->next;
			i++;
			}
		struct node * temp = (struct node *) malloc (sizeof(struct node));
		temp ->data = data;
		temp ->next = ptr->next;
		ptr ->next = temp;
    }
}

void addatend (int data){
	struct node * temp = (struct node *) malloc(sizeof(struct node));
	temp ->data = data;
	struct node *ptr = head;

	while(ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = temp;
	temp->next = NULL;
}

void display(){
	struct node *ptr = head;

		while(ptr !=  NULL){
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
		printf("\n\n");
}

int main(){
    int q = 0 ;
    while(1){
        printf("Enter the query\n");
        printf("1:Insert\n");
        printf("2:Delete\n");
        printf("3:Print\n");
        printf("4:Exit\n");
        scanf("%d",&q);

        if(q == 1){
            int data,k;
            int q1 = 0 ;
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("1:Insert at the beginning\n2: Insert at some position\n3: Insert at the end\n");

            scanf("%d", &q1);

            switch(q1){
                case 1: addatpos(data,1);
                        break;
                case 2: printf("Enter the position\n");
                        scanf("%d", &k);
                        addatpos(data,k);
                        break;
                case 3: addatend(data);
                        break;
                default: printf("Enter a proper query\n");
            }
        }
        else if(q == 2){
            int data,k;
            int q1 = 0 ;
            printf("1:Delete at the beginning\n2: Delete at some position\n3: Delete at the end\n");

            scanf("%d", &q1);

            switch(q1){
                case 1: delatpos(1);
                        break;
                case 2:printf("Enter the position\n");
                    scanf("%d", &k);
                        delatpos(k);
                        break;
                case 3: delatend();
                        break;
                default: printf("Enter a proper query\n");
            }
        }
        else if(q == 3){
                if(isEmpty())
                    printf("The List is Empty\n\n");
                else
                    display();

        }
        else if(q == 4){
            break;
        }
        else{
                printf("Please enter a proper query\n");
        }
    }
    return 0;
}