#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* create(struct node* head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (!head) return newnode;
    struct node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct node* insert_left(struct node* head, int target, int value) {
    struct node* temp = head;
    while (temp && temp->data != target) temp = temp->next;
    if (!temp) return head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = temp->prev;
    newnode->next = temp;
    if (temp->prev) temp->prev->next = newnode;
    else head = newnode;
    temp->prev = newnode;
    return head;
}

struct node* delete_value(struct node* head, int value) {
    struct node* temp = head;
    while (temp && temp->data != value) temp = temp->next;
    if (!temp) return head;
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int choice, val, target;

    while (1) {
        printf("\n1. Create Node\n2. Insert Left of Node\n3. Delete Value\n4. Display and Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            head = create(head, val);
        } 
        else if (choice == 2) {
            printf("Enter target value: ");
            scanf("%d", &target);
            printf("Enter new value: ");
            scanf("%d", &val);
            head = insert_left(head, target, val);
        } 
        else if (choice == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &val);
            head = delete_value(head, val);
        } 
        else if (choice == 4) {
            printf("List: ");
            display(head);
            break;
        } 
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
