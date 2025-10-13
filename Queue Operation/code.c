#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    printf("\nOptions Available:\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }
    return 0;
}
