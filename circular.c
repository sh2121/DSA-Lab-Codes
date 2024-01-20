#include<stdio.h>
#define MAXSIZE 5
int cq[MAXSIZE];
int front=-1;
int rear=-1;
void enqueue()
{
    int item;
    printf("\nEnter the elements");
    scanf("%d",&item);
    if(front==(rear+1)%MAXSIZE)
    {
        printf("circular queue is full");}
        else if(front==-1)
        {
            front=rear=0;
            cq[rear]=item;

        }
        else 
        {
            rear=(rear+1)%MAXSIZE;
            cq[rear]=item;
        }
    }


void dequeue()
{
    if(front==-1)
    {
        printf("circular queue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;

    }
    else{
        front=(front+1)%MAXSIZE;
    }
}

void display()
{
    if(front==-1)
    {
        printf("cq is empty");}
        else{
            for(int i=front;i<MAXSIZE;i++)
            {
                printf("%d",cq[i]);
            }
        }
    }


int main()
{
    int choice;
    while(1)
    {
        printf("\nCircular Queue");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
{

        case 1:
          enqueue();
        break;
        case 2:
          dequeue();
        break;
        case 3:
          display();
        break;

    }
}
return 0;
}

