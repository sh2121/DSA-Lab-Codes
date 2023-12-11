#include <stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int power;
    struct node * next;
};
struct node *poly1=NULL,*poly2=NULL,*poly=NULL;
void display(struct node*temp){
    while(temp->next!=NULL){
        printf("%dx^%d +",temp->coef,temp->power);
        temp=temp->next;

    }
    printf("%dX^%d\n", temp->coef, temp->power);
}
void create(struct node *temp) {
    char ch;
    do {
        printf("Enter coeff: ");
        scanf("%d", &temp->coef);
        printf("Enter power: ");
        scanf("%d", &temp->power);
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp = temp->next;
        temp->next = NULL;
        printf("Continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

polyadd(struct node *poly1,struct node *poly2,struct node *poly)
{
   while(poly1->next!=NULL && poly2->next!=NULL)
   {
       if(poly1->power>poly2->power)
       {
           poly->coef=poly1->coef;
           poly->power=poly1->power;
           poly1=poly1->next;
       }
       else if(poly1->power<poly2->power)
   {
       poly->coef=poly2->coef;
           poly->power=poly2->power;
           poly2=poly2->next;
   }
       else
       {
           poly->coef=poly1->coef+poly2->coef;
           poly->power=poly1->power;
           poly1=poly1->next;
           poly2=poly2->next;
       }
       poly->next=(struct node*)malloc(sizeof(struct node*));
       poly=poly->next;
       poly->next=NULL;
   }

}
int main(){
    poly1=(struct node*)malloc(sizeof(struct node*));
    poly2=(struct node*)malloc(sizeof(struct node*));
    create(poly1);
    create(poly2);
    display(poly1);
    display(poly2);
    poly=(struct node*)malloc(sizeof(struct node*));
    polyadd(poly1,poly2,poly);
    printf("\n");
    display(poly);

}
