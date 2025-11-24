#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* push(struct node* top,int x){
    struct node* p=malloc(sizeof(struct node));
    p->data=x;
    p->next=top;
    return p;
}

struct node* pop(struct node* top){
    if(top){
        struct node* t=top;
        top=top->next;
        free(t);
    }
    return top;
}

struct node* enqueue(struct node* rear,struct node** front,int x){
    struct node* p=malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;
    if(*front==NULL) *front=p;
    else rear->next=p;
    return p;
}

struct node* dequeue(struct node* front){
    if(front){
        struct node* t=front;
        front=front->next;
        free(t);
    }
    return front;
}

void display(struct node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct node *top=NULL,*front=NULL,*rear=NULL;
    int c,x;
    while(scanf("%d",&c)!=EOF){
        if(c==1){ scanf("%d",&x); top=push(top,x); }
        if(c==2){ top=pop(top); }
        if(c==3){ scanf("%d",&x); rear=enqueue(rear,&front,x); }
        if(c==4){ front=dequeue(front); if(front==NULL) rear=NULL; }
        if(c==5){ display(top); }
        if(c==6){ display(front); }
    }
}
