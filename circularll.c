#include<stdio.h>
#include<stdlib.h>
void create();
void insert_begin();
void insert_last();
void insert_location();
void delete_first();
void delete_last();
void delete_location();
void Display();
struct node
{
	int info;
	struct node *next;
};
struct node *start=NULL;
void create()
{
	printf("This is the creatipn of Linked List.....\n");
char ch;
struct node *temp=(struct node*)malloc(sizeof(struct node*));
printf("Enter the data");
scanf("%d",&temp->info);
temp->next=temp;
start=temp;
do
{
	struct node *temp1=(struct node*)malloc(sizeof(struct node*));
		printf("Enter next data");
		scanf("%d",&temp1->info);
		temp->next=temp1;
		temp=temp1;
		printf("Press Y or y to insert next node\n");
		ch=getch();	}
	while(ch=='Y'||ch=='y');
	temp->next=start;
}
void insert_begin()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
printf("Enter the data");
scanf("%d",&temp->info);
if(start==NULL)
	{
		temp->next=temp;
		start=temp;
	}
	else
	{
		temp->next=start;
		struct node *last=start;
		while(last->next!=start)
		{
			last=last->next;
		}
		last->next=temp;
		start=temp;
		printf("The node is successfuly inserted.....\n");
	}
}
void insert_last()
{
struct node *temp=(struct node*)malloc(sizeof(struct node*));
printf("Enter the data");
scanf("%d",&temp->info);
if(start==NULL)
	{
		temp->next=temp;
		start=temp;
	}
	struct node *last=start;
	while(last->next!=start)
		{
			last=last->next;
		}
		last->next=temp;
		temp->next=start;
}
void insert_location()
{
int val;
struct node *temp=(struct node*)malloc(sizeof(struct node*));
printf("Enter the data after which u want to insert the node");
scanf("%d",&val);
printf("Enter the data");
scanf("%d",&temp->info);
struct node *temp1=start;
while(temp1->info!=val)
{
	temp1=temp1->next;
}
temp->next=temp1->next;
temp1->next=temp;
}
void delete_first()
{
	if(start==NULL)
	printf("List is empty");
	else
	{
		struct node *temp=start;
		struct node *temp1=start->next;
		while(temp->next->next!=start)
		{
		temp=temp->next;
	    }
	    temp->next->next=start->next;
	    temp=start;
	    free(temp);
	    start=temp1;
	}
}
void delete_last()
{
	if(start==NULL)
	printf("List is Empty");
	else
	{
		struct node *temp=start;
		while(temp->next->next!=start)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=start;
	}
}
void delete_location()
{
	int data;
	struct node*temp=start;
	if(start==NULL)
	printf("List is empty");
	else
	{
		struct node *q=NULL;
		printf("Enter the info which has to be deleted");
		scanf("%d",&data);
		while(temp->info!=data)
		{
			q=temp;
			temp=temp->next;
		}
		q->next=temp->next;
		free(temp);
	}
}
void Display()
{
	struct node *temp=start;
	printf("The Current list is:\n");
	while(temp->next!=start)
	{
		printf("%d,",temp->info);
		temp=temp->next;
	}
	printf("%d",temp->info);
}
int main()
{
    int ch;
    create();
    while(1)
    {
    printf("\nThe Linked List operations are:-\n");
    printf("1: Insertion at Beginning.\n");
    printf("2: Traversing.\n");
    printf("3: Insertion at Last.\n");
    printf("4: Insertion at Particular location.\n");
    printf("5: Deletion from Beginning.\n");
    printf("6: Deletion from last.\n");
    printf("7: Deletion from Particular Location.\n");
    printf("8: Exit.\n");
    printf("Enter the choice");
    scanf("%d",&ch);
    switch(ch)
    {
	    case 1:
                             insert_begin();
		break;
	    case 2:
		Display();
        break;
	    case 3:
		insert_last();
		break;
	    case 4:
		insert_location();
		break;
	    case 5:
		delete_first();
		break;
	    case 6:
		delete_last();
		break;
	    case 7:
	   	delete_location();
	   	break;
	    case 8:
		exit(1);
		break;
    	default:
    	printf("Invalid choice");
	}
}
return 0;
}

