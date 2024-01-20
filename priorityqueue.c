#include <stdio.h>
#define MAX_SIZE 100  

int pq[MAX_SIZE];  
int rear = -1;     

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("\nPriority queue overflow");
        return;
    }
    rear++;
    pq[rear] = data;
    int i = rear;
    while (i > 0 && pq[(i - 1) / 2] < pq[i]) {
        swap(&pq[(i - 1) / 2], &pq[i]);
        i = (i - 1) / 2;
    }
}
int dequeue() {
    if (rear == -1) {
        printf("\nPriority queue underflow");
        return -1;  
    }

    int max = pq[0];
    pq[0] = pq[rear];
    rear--;
    int i = 0, child;
    while (i * 2 + 1 <= rear) {
        child = i * 2 + 1;
        if (child + 1 <= rear && pq[child + 1] > pq[child]) {
            child++;
        }
        if (pq[child] > pq[i]) {
            swap(&pq[child], &pq[i]);
            i = child;
        } else {
            break;
        }
    }

    return max;
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Exit");
        printf("\n.Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to enqueue:");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("\nDequeued element is %d", data);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}
