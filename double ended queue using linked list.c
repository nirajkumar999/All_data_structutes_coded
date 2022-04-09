#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
insertionattail(struct node **h,struct node **t,int value)
{
    struct node *n=malloc(sizeof(struct node));
    n->data=value;
    n->next=NULL;
    if(*t==NULL)
    {
        *t=n;
        *h=n;
    }
    else
    {
      (*t)->next=n;
      *t=n;
    }
}
insertionathead(struct node **h,struct node **t,int value)
{
    struct node *n=malloc(sizeof(struct node));
    n->data=value;
    if(*h==NULL)
    {
        n->next=NULL;
        *h=n;
        *t=n;
    }
    else
        {
            n->next=*h;
           *h=n;
        }
}
deletionathead(struct node **h,struct node **t)
{
    if(*h==NULL)
        printf("nothing to delete");
    else if(*h==*t)
    {
        free(*h);
        *h=NULL;
        *t=NULL;
    }
    else
    {
        struct node *temp=(*h)->next;
        free (*h);
        *h=temp;
    }
}
deletionattail(struct node **h,struct node **t)
{
    if(*t==NULL)
        printf("nothing to delete");
    else if(*h==*t)
    {
        free(*t);
        *h=NULL;
        *t=NULL;
    }
    else
        {
            struct node *secondlast=*h;
            while(secondlast->next!=*t)
                secondlast=secondlast->next;
            free(*t);
            secondlast->next=NULL;
            *t=secondlast;
        }
}
view(struct node **h,struct node **t)
{
  if(*h==NULL)
        printf("empty\n");
  else
  {
      struct node *head=*h;
      while(head!=NULL)
      {
          printf("%d  ",head->data);
          head=head->next;
      }
  }
  printf("\ncount  = %d\n\n",count(*h,*t));
  }
int count(struct node *head,struct node *tail)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
deletequeue(struct node **h, struct node **t)
{
    struct node *head=*h;
    while(head!=NULL)
    {
        struct node *temp=head->next;
        free (head);
        head=temp;
    }
    *h=NULL;
    *t=NULL;
}
int menu(struct node *head,struct node *tail)
{
    view(&head,&tail);
    int choice;
    printf("enter 1 for insertion at head\n");
    printf("enter 2 for insertion at tail\n");
    printf("enter 3 for deletion at head\n");
    printf("enter 4 for deletion at tail\n");
    printf("enter 5 for view\n");
    printf("enter 6 to exit\n");
    scanf("%d",&choice);
    return choice;
}
main()
{
    struct node *head =NULL,*tail=NULL;
    int value;
    while(2)
    {
        switch(menu(head,tail))
        {
        case 1:
            scanf("%d",&value);
            insertionathead(&head,&tail,value);
            break;
        case 2:
            scanf("%d",&value);
            insertionattail(&head,&tail,value);
            break;
        case 3:
            deletionathead(&head,&tail);
            break;
        case 4:
            deletionattail(&head,&tail);
            break;
        case 5:
            view(&head,&tail);
            break;
        case 6:
            deletequeue(&head, &tail);
            printf("head = %d , tail = %d",head,tail);
            exit(0);
        }
        getch();
        system("cls");
    }
}
