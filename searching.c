#include<stdio.h>
#include<stdlib.h>
void create();
void Display();
void insert_begin();
void insert_last();
void insert_location();
void delete_first();
void delete_last();
void delete_location();
void count_nodes();
void reverse_list();
void find_middle();
struct node
{
	int info;
	struct node *next;
};
struct node *start=NULL;
void create()
{
char ch;
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the data");
	scanf("%d",&temp->info);
	temp->next=NULL;
	start=temp;
	do
	{
		struct node *temp1=(struct node*)malloc(sizeof(struct node*));
		printf("Enter next data");
		scanf("%d",&temp1->info);
		temp->next=temp1;
		temp=temp1;
		printf("Press Y or y to insert next node\n");
		ch=getch();
	}
	while(ch=='Y'||ch=='y');
	temp->next=NULL;
}
void Display()
{
	struct node *temp=start;
	if(start==NULL)
	printf("List is empty");
	else
	{
		printf("\nThe currrent list is:\n");
		while(temp!=NULL)
		{
			printf("%d ",temp->info);
			temp=temp->next;
		}
	}
}
void insert_begin()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter next data");
	scanf("%d",&temp->info);
	if(start==NULL)
	{
		temp->next=NULL;
		start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
		printf("The node is successfuly inserted.....\n");
	}
}
void insert_last()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter next data");
	scanf("%d",&temp->info);
	if(start==NULL)
	{
		temp->next=NULL;
		start=temp;
	}
	else
	{
		struct node *temp1=start;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
		temp->next=NULL;
		printf("The node is successfuly inserted.....\n");
	}
}
void insert_location()
{
	int loc,choice;
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter next data");
	scanf("%d",&temp->info);
	struct node *temp1=start;
	printf("1: Press 1 to insert a node after a particular location\n");
	printf("2: Press 2 to insert a node before a particular location\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    		{
    		printf("Enter the info after which you want to insert the node");
	        scanf("%d",&loc);
           	while(temp1->info!=loc)
	        {
	     	temp1=temp1->next;
	        }
	        temp->next=temp1->next;
	        temp1->next=temp;
	        printf("The node is successfuly inserted.....\n");
	        break;
	        }
	    case 2:
	    	{
	    		printf("Enter the info before which you want to insert the node");
	    		scanf("%d",&loc);
	    		while(temp1->next->info!=loc)
	            {
	     	     temp1=temp1->next;
	            }
	            temp->next=temp1->next;
	            temp1->next=temp;
	            break;
	            printf("The node is successfuly inserted.....\n");
			}
			default:
				printf("Invalid choice");
    }
}
void delete_first()
{
	struct node *temp=start;
	if(start==NULL)
	printf("List is Empty");
	else
	{
		start=start->next;
		free(temp);
		printf("The node is successfuly Deleted from the list.....\n");
	}
}
void delete_last()
{
	struct node *temp=start;
	if(start==NULL)
	printf("List is empty");
	else
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
		printf("The node is successfuly Deleted from the list.....\n");
	}
}
void delete_location()
{
int data;
struct node*temp=start;
if(start==NULL)
printf("List is Empty");
else
{
	struct node *q;
	printf("Enter the info which has to be deleted:");
	scanf("%d",&data);
	while(temp->info!=data)
	{
		q=temp;
		temp=temp->next;
	}
	q->next=temp->next;
	free(temp);
	printf("The node is successfuly Deleted from the list.....\n");
}
}
void count_nodes()
{
	int ctr=0;
struct node*temp=start;
if(start==NULL)
printf("List is Empty");
else
{
	while(temp!=NULL)
		{
			ctr++;
			temp=temp->next;
		}
		printf("The no. of nodes prseent in the List are:%d\n",ctr);
}
}
void reverse_list()
{
struct node *p,*q,*r;
p=start;
q=p->next;
p->next=NULL;
while(q!=NULL)
{
r=q->next;
q->next=p;
p=q;
q=r;
}
start=p;
}
void find_middle()
{
	int i,c=0;
	struct node *slow=start;
	struct node *fast=start;
	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	printf("The middle node is:%d\n",slow->info);
}
int main()
{
    int ch;
    printf("This is the Creation of Linked List.\n");
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
    printf("8: To count no. of nodes present in the List.\n");
    printf("9: Reversing of the List.\n");
    printf("10: To find the middle node of the List.\n");
    printf("11: Exit.\n");
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
		count_nodes();
		break;
	    case 9:
        reverse_list();
        break;
	     case 10:
		find_middle();
		break;
	    case 11:
		exit(1);
		break;
    	default:
    	printf("Invalid choice");
	}
}
return 0;
}
