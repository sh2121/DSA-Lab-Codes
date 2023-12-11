#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int deque[MAX_SIZE]; int front = -1, rear = -1;
int isFull() {

return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);

}

int isEmpty() {
    return front == -1;
}

void insertFront(int value) {
    if (isFull()) {
printf("Dequeue is full. Cannot insert %d at the front\n", value);
return;
}


if (isEmpty()) {

front = rear = 0;

} else if (front == 0) { front = MAX_SIZE - 1;
} else {

front--;

}

deque[front] = value;

printf("%d inserted at the front\n", value);

}

void insertRear(int value) {
    if (isFull()) {
printf("Dequeue is full. Cannot insert %d at the rear\n", value);
return;
}



if (isEmpty()) { front = rear = 0;
} else if (rear == MAX_SIZE - 1) { rear = 0;
} else {


rear++;

}

deque[rear] = value;

printf("%d inserted at the rear\n", value);

}
int deleteFront() { if (isEmpty()) {
printf("Dequeue is empty. Cannot delete from the front\n");
return -1;
}
int deletedValue = deque[front];

if (front == rear) { front = rear = -1;
} else if (front == MAX_SIZE - 1) { front = 0;
} else {

front++;

}

return deletedValue;

}

int deleteRear() {
    if (isEmpty()) {
printf("Dequeue is empty. Cannot delete from the rear\n");
return -1;
}
int deletedValue = deque[rear];

if (front == rear) { front = rear = -1;
} else if (rear == 0) { rear = MAX_SIZE - 1;
} else {

rear--;

}

return deletedValue;

}
void displayDeque() {


if (isEmpty()) {

printf("Dequeue is empty\n");
return;
}



printf("Deque: ");
int i = front;
while (1) {
printf("%d ", deque[i]); if (i == rear)
break;

i = (i + 1) % MAX_SIZE;

}
printf("\n");

}

int main() {

int choice, value;
while (1) {

printf("\n1. Insert at front");
printf("\n2. Insert at rear");
printf("\n3. Delete from front");
printf("\n4. Delete from rear");
printf("\n5.Display");printf("\n6. Quit");
printf("\nEnter your choice: ");
scanf("%d", &choice);


switch (choice) {

case 1:

printf("Enter the value to insert at the front: ");
scanf("%d", &value);
insertFront(value);
break;
case 2:

printf("Enter the value to insert at the rear: ");
scanf("%d", &value);
insertRear(value);
break;
case 3:

value = deleteFront();
if (value != -1) {
printf("Deleted from front: %d\n", value);

}
break;
case 4:
value = deleteRear(); if (value != -1) {
printf("Deleted from rear: %d\n", value);

}

break;

case 5:

displayDeque();
break;
case 6:

exit(0);
default:
printf("Invalid choice. Please try again.\n");}}
return 0;
}
