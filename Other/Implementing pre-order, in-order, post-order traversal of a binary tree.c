//Implementing pre-order, in-order, post-order traversal of a binary tree

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *l;
    struct node *r;
};

struct node *newnode(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->l=NULL;
    temp->r=NULL;
    return(temp);
}

void preorder(struct node *p){
    if(p==NULL)
        return;
    printf("%d  ",p->data);
    preorder(p->l);
    preorder(p->r);
}

void inorder(struct node *p){
    if(p==NULL)
        return;
    inorder(p->l);
    printf("%d  ",p->data);
    inorder(p->r);
}

void postorder(struct node *p){
    if(p==NULL)
       return;
    postorder(p->l);
    postorder(p->r);
    printf("%d  ",p->data);
}

int main(){
    struct node *root;
    root=newnode(15);
    
    root->l=newnode(9);
    root->l->l=newnode(6);
    root->l->r=newnode(11);
    root->r=newnode(18);
    root->r->l=newnode(16);
    root->r->r=newnode(20);
    
    printf("\npreorder\n");
    preorder(root);
    
    printf("\npostorder\n");
    postorder(root);
    
    printf("\ninorder\n");
    inorder(root);
    
    return 0;
}
