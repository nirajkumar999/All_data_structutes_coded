#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
insertion(struct node **f,struct node **r,int value)
{
    struct node *n=malloc(sizeof(struct node));
    n->data=value;
    n->next=NULL;
    if(*r==NULL)
    {
        *r=n;
        *f=n;
    }
    else
    {
      (*r)->next=n;
      *r=n;
    }
}
deletion(struct node **f,struct node **r)
{
    if(*f==NULL)
        printf("nothing to delete");
    else if(*f==*r)
    {
        free(*f);
        *f=NULL;
        *r=NULL;
    }
    else
    {
        struct node *temp=(*f)->next;
        free (*f);
        *f=temp;
    }
}
view(struct node **f,struct node **r)
{
  if(*f==NULL)
        printf("empty\n");
  else
  {
      struct node *front=*f;
      while(front!=NULL)
      {
          printf("%d  ",front->data);
          front=front->next;
      }
  }
  printf("\ncount  = %d\n\n",count(*f,*r));
  }
int count(struct node *front,struct node *rear)
{
    int count=0;
    while(front!=NULL)
    {
        count++;
        front=front->next;
    }
    return count;
}
deletequeue(struct node **f, struct node **r)
{
    struct node *front=*f;
    while(front!=NULL)
    {
        struct node *temp=front->next;
        free (front);
        front=temp;
    }
    *f=NULL;
    *r=NULL;
}
int menu(struct node *front,struct node *rear)
{
    view(&front,&rear);
    int choice;
    printf("enter 1 for insertion\n");
    printf("enter 2 for deletion\n");
    printf("enter 3 for view\n");
    printf("enter 4 to exit\n");
    scanf("%d",&choice);
    return choice;
}
main()
{
    struct node *front =NULL,*rear=NULL;
    int value;
    while(2)
    {
        switch(menu(front,rear))
        {
        case 1:
            scanf("%d",&value);
            insertion(&front,&rear,value);
            break;
        case 2:
            deletion(&front,&rear);
            break;
        case 3:
            view(&front,&rear);
            break;
        case 4:
            deletequeue(&front, &rear);
            printf("front = %d , rear = %d",front,rear);
            exit(0);
        }
        getch();
        system("cls");
    }
}
