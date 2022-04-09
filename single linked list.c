#include<stdlib.h>
struct node               //single linked list
{
    int item;
    struct node *next;
};
deletefirst(struct node **s)
{
    struct node *temp;
    if(*s==NULL)
     printf("underflow");
    else
    {
    temp=(*s)->next;
    free(*s);
    *s=temp;
    }
}
deletelast(struct node** s)
{
    struct node *tr,*tf;
    if(*s==NULL)
        printf("underflow");
    else
    {
      tr=NULL;
      tf=*s;
      while(tf->next)
      {
        tr=tf;
        tf=tf->next;
      }
      free(tf);
      if(tr!=NULL)
      tr->next=NULL;
      else
        *s=NULL;
    }
}

deletenode(struct node **s,struct node *t)
{
     struct node *temp;

 if(*s==t)
    {
        *s=t->next;
        free(t);
    }
    else
     {
      temp=*s;
      while(temp->next!=t)
      temp=temp->next;
      temp->next=t->next;
      free(t);
     }
}
struct node* search(struct node *start,int datatosearch)
{
    while(start)
    {
    if(start->item==datatosearch)
        return(start);

    start=start->next;
    }
    return NULL;
};
insertafter(struct node *t,int data)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    temp->next=t->next;
    t->next=temp;
}
insertatfirst(struct node **s,int data)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    temp->next=*s;
    *s=temp;
}
insertatlast(struct node **s,int data)
{
    struct node *temp,*t;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    temp->next=NULL;
    if(*s==NULL)
        *s=temp;
    else
    {
        t=*s;
        while(t->next!=NULL)
        t=t->next;
        t->next=temp;
    }
}
view(struct node *start)
{
    if(start==NULL)
        printf("empty list\n");
    else
    {
        while(start!=NULL)
        {
            printf("%d  ",start->item);
            start=start->next;
        }
    }
}
int menu(struct node *start)
{
    view(start);
    printf("\n\n");
    int choice;
    printf("1 insertatfirst\n");
    printf("2 insertatlast\n");
    printf("3 insertafter\n");
    printf("4 deletefirst\n");
    printf("5 deletelast\n");
    printf("6 deletenode\n");
    printf("7 search\n");
    printf("8 exit\n");
    scanf("%d",&choice);
    return choice;

}
main()
{
    struct node *start=NULL,*t=NULL;
    int data,datatosearch;
    while(1)
{
switch(menu(start))
{
case 1:
    scanf("%d",&data);
    insertatfirst(&start,data);
    break;
case 2:
    scanf("%d",&data);
    insertatlast(&start,data);
    break;
case 3:
    scanf("%d%d",&datatosearch,&data);
    t=search(start,datatosearch);
    if(t!=NULL)
    insertafter(t,data);
    else
        printf("underflow");
    break;
case 4:
    deletefirst(&start);
    break;
case 5:
    deletelast(&start);
    break;
case 6:
    scanf("%d",&datatosearch);
    t=search(start,datatosearch);
    if(t!=NULL)
    deletenode(&start,t);
    else
        printf("underflow");
    break;
case 7:
    scanf("%d",&datatosearch);
    t=search(start,datatosearch);
    if(t!=NULL)
    printf("%d",t);
    else
        printf("underflow");
    break;
case 8:
    exit(0);
}
getch();
system("cls");
}
}
