#include <stdio.h>
#define MAX_SIZE 10
struct Queue {
int arr[MAX_SIZE]; int front, rear;
};

void initializeQueue(struct Queue* queue) { queue->front = -1;
queue->rear = -1;

}

int isEmpty(struct Queue* queue) {

return (queue->front == -1 && queue->rear == -1);

}

int isFull(struct Queue* queue) {

return (queue->rear == MAX_SIZE - 1);

}

void enqueue(struct Queue* queue, int value) { if (isFull(queue)) {
printf("Queue is full. Cannot enqueue.\n");

} else {

if (isEmpty(queue)) { queue->front = 0;
}

queue->rear++;

queue->arr[queue->rear] = value;

printf("%d enqueued to the queue.\n", value);

}

}

void dequeue(struct Queue* queue) { if (isEmpty(queue)) {
printf("Queue is empty. Cannot dequeue.\n");

} else {

int removedValue = queue->arr[queue->front];

printf("%d dequeued from the queue.\n", removedValue);


if (queue->front == queue->rear) { queue->front = -1;
queue->rear = -1;

} else {

queue->front++;

}

}

}

void displayQueue(struct Queue* queue) { if (isEmpty(queue)) {
printf("Queue is empty.\n");

} else {

printf("Queue elements: ");

for (int i = queue->front; i <= queue->rear; i++) { printf("%d ", queue->arr[i]);
}

printf("\n");

}

}


int main() {

struct Queue myQueue; initializeQueue(&myQueue);




int choice, value;




do {

printf("1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n"); printf("Enter your choice: ");
scanf("%d", &choice);




switch (choice) { case 1:
printf("Enter the value to enqueue: "); scanf("%d", &value); enqueue(&myQueue, value);
break; case 2:
dequeue(&myQueue); break;


case 3:

displayQueue(&myQueue); break;
case 0:

printf("Exiting the program.\n"); break;
default:

printf("Invalid choice. Please enter a valid option.\n");

}

} while (choice != 0);

return 0;

}
