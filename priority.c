#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5


int data[MAX_SIZE]; int priority[MAX_SIZE];
int rear = -1;


int isFull() {

return rear == MAX_SIZE - 1;

}

int isEmpty() { return rear == -1;
}



void enqueue(int newData, int newPriority) { if (isFull()) {
printf("Priority Queue is full. Cannot enqueue %d with priority %d\n", newData, newPriority); return;
}

int i;
for (i = rear; i >= 0; i--) {

if (newPriority > priority[i]) { data[i + 1] = data[i]; priority[i + 1] = priority[i];
} else {

break;

}

}



data[i + 1] = newData; priority[i + 1] = newPriority; rear++;

printf("%d enqueued with priority %d\n", newData, newPriority);

}



int dequeue()
{
    if (isEmpty()) {
printf("Priority Queue is empty. Cannot dequeue\n");
return -1;
}

int dequeuedData = data[rear]; rear--;

return dequeuedData;

}



void displayPriorityQueue() {
    if (isEmpty()) {
printf("Priority Queue is empty\n");
return;
}



printf("Priority Queue (front to rear): "); for (int i = 0; i <= rear; i++) {
printf("(%d, %d) ", data[i], priority[i]);

}

printf("\n");

}



int main() {

int choice, newData, newPriority,dequeuedData;


while (1) {

printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\nEnter your choice: "); scanf("%d", &choice);


switch (choice) {

case 1:
printf("Enter the data: "); scanf("%d", &newData);
printf("Enter the priority: ");
scanf("%d", &newPriority);
enqueue(newData, newPriority);
break;
case 2:

dequeuedData = dequeue();
if (dequeuedData != -1) {
printf("Dequeued: %d\n", dequeuedData);

}

break;
case 3:

displayPriorityQueue(); break;
case 4:

exit(0);
default:

printf("Invalid choice. Please try again.\n");

}

}

return 0;

}

