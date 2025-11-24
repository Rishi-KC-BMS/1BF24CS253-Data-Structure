#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create(int n){
    struct node *head=NULL,*p,*q;
    for(int i=0;i<n;i++){
        p=malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL) head=p;
        else q->next=p;
        q=p;
    }
    return head;
}

void display(struct node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

struct node* sort(struct node* head){
    struct node *i,*j;
    int t;
    for(i=head;i;i=i->next)
        for(j=i->next;j;j=j->next)
            if(i->data>j->data){
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
    return head;
}

struct node* reverse(struct node* head){
    struct node *p=NULL,*c=head,*n;
    while(c){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}

struct node* concat(struct node* a,struct node* b){
    if(a==NULL) return b;
    struct node* t=a;
    while(t->next) t=t->next;
    t->next=b;
    return a;
}

int main(){
    int n,m;
    scanf("%d",&n);
    struct node* A=create(n);
    scanf("%d",&m);
    struct node* B=create(m);
    A=sort(A);
    display(A);
    A=reverse(A);
    display(A);
    A=concat(A,B);
    display(A);
}
