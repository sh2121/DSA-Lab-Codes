#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int data);
int pop();
int peek();
void display();

int main() {
    int choice, data;

    while (1) {
        printf("\nStack Operations:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the data to push:");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("\nPopped element is %d", data);
                }
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    printf("\nTop element is %d", data);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!!!!");
        }
    }

    return 0;
}
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("\n%d pushed to stack", data);
}
int pop() {
    if (isEmpty()) {
        printf("\nStack Underflow");
        return -1;
    }
    struct Node* temp = top;
    int data = temp->data;
    top = top->next;
    free(temp);
    return data;
}
int peek() {
    if (isEmpty()) {
        printf("\nStack is empty");
        return -1;
    }
    return top->data;
}
void display() {
    if (isEmpty()) {
        printf("\nStack is empty");
        return;
    }
    struct Node* temp = top;
    printf("\nStack elements:");
    while (temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}
int isEmpty() {
    return top == NULL;
}
