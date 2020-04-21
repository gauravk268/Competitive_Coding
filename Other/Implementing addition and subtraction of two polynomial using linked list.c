//Implementing addition and subtraction of two polynomial using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef,expo;
    struct node* next;
};

struct node* insertpoly(struct node* root,int c,int e){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->coef=c;
    ptr->expo=e;
    if(root==NULL){
        ptr->next=NULL;
        return ptr;
    }
    struct node* prev,* curr;
    prev=curr=root;
    while(curr!=NULL && curr->expo>e){
        prev=curr;
        curr=curr->next;
    }
    if(curr==root){
        ptr->next=curr;
        return ptr;
    }
    else if(curr==NULL){
        prev->next=ptr;
        ptr->next=NULL;
    }
    else{
        ptr->next=curr;
        prev->next=ptr;
    }
    return root;
}

struct node* append(struct node* root,int c,int e){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->coef=c;
    ptr->expo=e;
    if(root==NULL){
    ptr->next=NULL;
    return ptr;
    }
    struct node* trav=root;
    while(trav->next!=NULL)
        trav=trav->next;
    trav->next=ptr;
    ptr->next=NULL;
    return root;
}

struct node* polyaddition(struct node* p1root,struct node* p2root){
    struct node* result=NULL;
    struct node* t1,* t2;
    t1=p1root;
    t2=p2root;
    while(t1!=NULL && t2!=NULL){
        if(t1->expo > t2->expo){
            result=append(result,t1->coef,t1->expo);
            t1=t1->next;
        }
        else if(t1->expo < t2->expo){
            result=append(result,t2->coef,t2->expo);
            t2=t2->next;
        }
        else{
            result=append(result,(t1->coef)+(t2->coef),t1->expo);
            t1=t1->next;
            t2=t2->next;
        }
    }

    while(t1!=NULL){
        result=append(result,t1->coef,t1->expo);
        t1=t1->next;
    }

    while(t2!=NULL){
        result=append(result,t2->coef,t2->expo);
        t2=t2->next;
    }
    return result;
}

struct node* polysub(struct node* p1root,struct node* p2root){
    struct node* result=NULL;
    struct node* t1,* t2;
    t1=p1root;
    t2=p2root;
    while(t1!=NULL && t2!=NULL){
        if(t1->expo > t2->expo){
            result=append(result,t1->coef,t1->expo);
            t1=t1->next;
        }
        else if(t1->expo < t2->expo){
            result=append(result,(t2->coef)*-1,t2->expo);
            t2=t2->next;
        }
        else{
            result=append(result,(t1->coef)-(t2->coef),t1->expo);
            t1=t1->next;
            t2=t2->next;
        }
    }
 while(t1!=NULL){
        result=append(result,t1->coef,t1->expo);
        t1=t1->next;
    }

    while(t2!=NULL){
        result=append(result,(t2->coef)*-1,t2->expo);
        t2=t2->next;
    }
    return result;
}

void display(struct node* root){
    struct node* temp=root;
    if(temp==NULL){
        printf("\nEmpty");
    }
    else{
        while(temp->next!=NULL){
            printf(" %dx^%d +",temp->coef,temp->expo);
            temp=temp->next;
        }
       printf(" %dx^%d ",temp->coef,temp->expo);
    }
}

int main(){
    int a,b,n,i;
    
    struct node* p1root,* p2root,* p3root,* p4root;
    p1root=p2root=NULL;
    
	printf("Enter the number of terms in 1st polynomial\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the coefficient and exponent of term %d\n",i+1);
        scanf("%d%d",&a,&b);
        p1root=insertpoly(p1root,a,b);
    }
    
	printf("Enter the number of terms in 2nd polynomial\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the coefficient and exponent of term %d\n",i+1);
        scanf("%d%d",&a,&b);
        p2root=insertpoly(p2root,a,b);
    }
    
	p3root=polyaddition(p1root,p2root);
	p4root=polysub(p1root,p2root);
    printf("\nThe sum of the two polynomials is ");
    display(p3root);
    printf("\nThe difference of the two polynomials is ");
    display(p4root);
    
	return 0;
}








