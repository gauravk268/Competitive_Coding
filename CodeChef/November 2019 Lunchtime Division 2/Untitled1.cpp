#include <stdio.h>

struct node{
	int question;
	int marks;
	struct node *next;
}*start;

int max(int a, int b){
	if(a>b)
		return a;
	else 
		return b;
}

void add(int q, int m){
	struct node *p, *temp;
	p=start;
	temp->question = q;
	temp->marks = m;
	
	if(p==NULL){
		temp->next = start;
		start = temp;
		return;
	}
	
	else if(p->question == q)
			p->marks = max(m, p->marks);
			
		else {
			while(p->question != q)
				p=p->next;
			p->marks = max(m, p->marks);
			
			if(p==NULL){
				temp->next = p->next;
				p->next = temp;
			}	
		}
	}
}

int main() {
    int t;
    scanf("%d" &t);
    while(t--){
    	start = NULL;
        int n, question, marks;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d %d", &question, &marks);
            add(question, marks);
        }
    }
}
