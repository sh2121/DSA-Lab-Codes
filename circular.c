#include <stdio.h> #include <stdlib.h>
#define MAX_SIZE 5


int queue[MAX_SIZE]; int front = -1, rear = -1;
int isFull() {

return (front == (rear + 1) % MAX_SIZE);

}

int isEmpty()
{ return front == -1;
}



void enqueue(int value) { if (isFull()) {
printf("Queue is full. Cannot enqueue %d\n", value); return;
}


if (isEmpty()) {

front = rear = 0;

} else {

rear = (rear + 1) % MAX_SIZE;

}

queue[rear] = value;

printf("%d enqueued to the queue\n", value);

}

int dequeue() { if (isEmpty()) {
printf("Queue is empty. Cannot dequeue\n"); return -1;
}

int dequeuedValue = queue[front];



if (front == rear) { front = rear = -1;
} else {

front = (front + 1) % MAX_SIZE;

}


 return dequeuedValue;
}



void displayQueue()
{ if (isEmpty()) {
printf("Queue is empty\n");
return;
}



printf("Circular Queue: ");
int i = front;
while (1) {

printf("%d ", queue[i]);
if (i == rear)
break;

i = (i + 1) % MAX_SIZE;

}

printf("\n");

}



int main() {

int choice, value;
while (1) {

printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\nEnter your choice: "); scanf("%d", &choice);


switch (choice) {
case 1:
printf("Enter the value to enqueue: "); scanf("%d", &value);
enqueue(value); break;
case 2:

value = dequeue();
if (value != -1) {
printf("Dequeued: %d\n", value);

}
break;

case 3:
displayQueue();
break;

case 4:
exit(0);

default:

printf("Invalid choice. Please try again.\n");

}

}

return 0;

}

