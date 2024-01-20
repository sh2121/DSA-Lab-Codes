#include<stdio.h>
#include <stdlib.h>
#include <string.h>

 int create();
    void insert_begin();
    void insert_loc();
    void insert_last();
    void delete_begin();
    void delete_loc();
    void delete_last();
    void display();
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
struct node *start=NULL;
struct node *last=NULL;
int create()
{
    char ch;
  struct node*temp =(struct node*)malloc(sizeof(struct node*));
   printf("Enter info");
   scanf("%d",&temp->info);
   temp->prev=temp->next=NULL;
   start=last=temp;
do
{
    struct node*temp =(struct node*)malloc(sizeof(struct node*));
  printf("Enter data");
  scanf("%d",&temp->info);
  last->next=temp;
  temp->prev=last;
  last=temp;
  printf("do u want to insert more node");
  scanf("%c",&ch);
}while(ch=="y"||ch=="Y");
    last->next=NULL;
}

void display()
{
    struct node *temp=start;
   {
       if(start==NULL)
       {
           printf("list is empty");
       }
       else
       {
        while(temp!=NULL)
         {
             printf("%d",temp->info);
             temp=temp->next;
         }
       }
   }
}
void insert_begin()
{
    struct node*temp=(struct node*)malloc(sizeof(struct node*));
    printf("Enter data");
    scanf("%d",&temp->info);
    if(start==NULL)
    {
        temp->prev=temp->next=NULL;
        start=last=temp;
    }

    {
        temp->next=start;
        start->prev=temp;
        temp->prev=NULL;
        start=temp;
    }
}

void insert_last()
{

    struct node*temp=(struct node*)malloc(sizeof(struct node*));
    printf("Enter data");
    scanf("%d",&temp->info);
    if(start==NULL)
    {

        temp->prev=temp->next=NULL;
        start=last=temp;
    }
    else
    {

        temp->prev=last;
        last->next=temp;
        temp->next=NULL;
        last=temp;
    }
}
void insert_loc()
{
int x;
    struct node*temp=(struct node*)malloc(sizeof(struct node*));
    printf("Enter data");
    scanf("%d",&temp->info);
    printf("enter the node after which node insert");
    scanf("%d",&x);
     struct node *loc=start;
    while(loc->info!=x)
    {

        loc=loc->next;
    }
    temp->next=loc->next;
    temp->next->prev=temp;
    loc->next=temp;
    temp->prev=loc;
}

void delete_begin()
{

    if(start==NULL)
        printf("List is empty");
    else
    {

        struct node*temp=start;
        start=start->next;
        start->prev=NULL;
        free(temp);
    }
}

void delete_last()
{

    if(start==NULL)
    printf("list is empty");
    else
    {

        struct node*temp=last;
        last=last->prev;
        last->next=NULL;
        free(temp);
    }
}
void delete_loc()
 { int x;
     printf("Enter the node after which node delete");
     scanf("%d",&x);
     struct node *loc=start;
     while(loc->info!=x)
     {
         loc=loc->next;
     }
     loc->next->prev=loc->prev;
     loc->prev->next=loc->next;
     free(loc);
 }
 void main()
 {
      int choice;
 while(1){
 printf("Link list Operations:");

 printf("\n 1. Create Link list:");
  printf("\n 2. Insert from beginning:");
   printf("\n 3. Insert at particular location:");
    printf("\n 4.Insert from last.");
     printf("\n 5. Delete from beginning:");
      printf("\n 6. Delete at Particular Location:");
       printf("\n 7. Delete from last:");
       printf("\n 8.Display link list:\n\n");

       printf("Enter the Choice :- ");
       scanf("%d",&choice);
          switch(choice)
          {
       case 1: create();
           break;
       case 2: insert_begin();
           break;
       case 3: insert_loc();
           break;
      case 4: insert_last();
           break;
      case 5: delete_begin();
           break;
      case 6: delete_loc();
           break;
      case 7: delete_last();
           break;
      case 8: display();
           break;
    }
  }
 }
