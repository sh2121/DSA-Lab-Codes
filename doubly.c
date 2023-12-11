#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
struct node *last = NULL;

void create()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->info);
    temp->next = NULL;
    temp->prev = NULL;
    start = temp;
    last = temp;  // Update last after creating the first node
    char ch;
    do
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter next data: ");
        scanf("%d", &temp->info);
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        last = temp;
        printf("Press 'y' to insert more nodes: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
}

void display_fwd()
{


    if (start == NULL)
        printf("Linked list is empty\n");
    else
    {
        struct node *temp = start;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

void display_bwd()
{
    if (last == NULL)
        printf("Linked list is empty\n");
    else
    {
        struct node *temp = last;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->prev;
        }
        printf("\n");
    }
}


void insert_begin()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &temp->info);

    if (start == NULL)
    {
        temp->prev=NULL;
        temp->next = NULL;
        start=last = temp;
    }
    else
    {
        temp->next = start;
        start->prev=temp;
        temp->prev=NULL;
        start = temp;
    }
}

void insert_end()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &temp->info);

    if (start == NULL)
    {
        temp->next = NULL;
        temp->prev=NULL;
        start= last= temp;
    }
    else
    {
        temp->prev=last;
        last->next=temp;
        temp->next = NULL;
        last=temp;
    }
}
void delete_first()
{
    if (start == NULL)
        printf("List is empty.\n");
    else
    {
        struct node *temp = start;
        start = start->next;
        if (start != NULL)  // Check if the list is not empty after deletion
            start->prev = NULL;
        free(temp);
    }
}

void delete_last()
{
    if (start == NULL)
        printf("List is empty.\n");
    else
    {
        struct node *temp = last;
        last = last->prev;
        if (last != NULL)  // Check if the list is not empty after deletion
            last->next = NULL;
        free(temp);
    }
}
void delete_specific()
{
    int x;
    printf("Enter node you want to delete: ");
    scanf("%d", &x);
    struct node *loc = start;
    while (loc != NULL && loc->info != x)
        loc = loc->next;

    if (loc != NULL)
    {
        if (loc->prev != NULL)
            loc->prev->next = loc->next;
        if (loc->next != NULL)
            loc->next->prev = loc->prev;
        free(loc);
    }
    else
    {
        printf("Node not found.\n");
    }
}
void insert_specific()
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&temp->info);
    int x;
    printf("enter node after which you want to insert: ");
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

void reverse()
{
    struct node *p, *q, *r;
    p = start;
    q = NULL;
    r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    start = q;
}


int main()
{
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Display forward\n");
        printf("3. Display backword\n");
        printf("4. Insert at the Beginning\n");
        printf("5. Insert at the End\n");
        printf("6. Insert at Position\n");
        printf("7. Delete from the Beginning\n");
        printf("8. Delete from the End\n");
        printf("9. Count\n");
        printf("10. Reverse\n");
        printf("11. delete_at_position\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display_fwd();
            break;
        case 3:
            display_bwd();
            break;
        case 4:
            insert_begin();
            break;
        case 5:
            insert_end();
            break;
        case 6:
            insert_specific();
            break;
        case 7:
            delete_first();
            break;
        case 8:
            delete_last();
            break;
        case 9:
            reverse();
            break;
        case 10:
            reverse();
            break;
        case 11:
            delete_specific();
            break;
        case 0:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}


