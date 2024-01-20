#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Deque {
    struct Node* front;
    struct Node* rear;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    if (deque == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}
int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    printf("\nElement %d inserted at the front", data);
}
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("\nElement %d inserted at the rear", data);
}
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("\nDeque is empty");
        return;
    }

    struct Node* temp = deque->front;
    deque->front = temp->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }

    int data = temp->data;
    free(temp);

    printf("\nElement %d deleted from the front", data);
}
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("\nDeque is empty");
        return;
    }

    struct Node* temp = deque->rear;
    deque->rear = temp->prev;

    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }

    int data = temp->data;
    free(temp);

    printf("\nElement %d deleted from the rear", data);
}
void displayDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("\nDeque is empty");
        return;
    }

    struct Node* current = deque->front;
    printf("\nDeque elements:");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void freeDeque(struct Deque* deque) {
    struct Node* current = deque->front;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(deque);
}

int main() {
    struct Deque* deque = createDeque();

    int choice, data;

    do {
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
        printf("\n5. Display Deque");
        printf("\n6. Exit");

        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to insert at the front:");
                scanf("%d", &data);
                insertFront(deque, data);
                break;

            case 2:
                printf("\nEnter the element to insert at the rear:");
                scanf("%d", &data);
                insertRear(deque, data);
                break;

            case 3:
                deleteFront(deque);
                break;

            case 4:
                deleteRear(deque);
                break;

            case 5:
                displayDeque(deque);
                break;

            case 0:
                break;

            default:
                printf("\nInvalid choice!!!!");
        }

    } while (choice != 0);
    freeDeque(deque);

    return 0;
}
;;