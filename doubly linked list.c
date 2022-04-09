#include<stdlib.h>
struct node                      //doubly linked list
{
    int item;
    struct node* prev;
    struct node* next;
};
view(struct node *start)
{
    if(start==NULL)
    printf("list empty");
    else
    while(start!=NULL)
    {
     printf("%d ",start->item);
     start=start->next;
    }
}
struct node* search(struct node *start,int datatosearch)
{
    while(start)
    {
     if(start->item==datatosearch)
            return start;

     start=start->next;
    }
    return NULL;
};
deletenode(struct node **s,struct node *t)
{
    if(*s==t)
    {
    *s=t->next;
    if(*s!=NULL)
    (*s)->prev=NULL;

    free (t);
    }
    else
    {
      t->prev->next=t->next;
      if(t->next!=NULL)
      t->next->prev=t->prev;

      free(t);
    }

}

deleteafter(struct node *t)
{
    struct node *t1=t->next;
if (t->next==NULL)
printf("nothing to delete");
else
{
 if(t->next->next!=NULL)
 t->next->next->prev=t;

 t->next=t->next->next;
 free(t1);
}
}
deletebefore(struct node **s, struct node *t)
{
    struct node *t1=t->prev;
    if(t->prev==NULL)
        printf("nothing to delete");
    else
        {
            if(t->prev->prev!=NULL)
           t->prev->prev->next=t;
           else
            *s=t;
            t->prev=t->prev->prev;
           free (t1);
        }
}
deletestart(struct node**s)
{
    if(*s==NULL)
        printf("underflow");
    else
    {
        if((*s)->next==NULL)
        {
            free(*s);
            *s=NULL;
        }
        else
        {
        *s=(*s)->next;
        free((*s)->prev);
        (*s)->prev=NULL;
        }
    }
}
deletelast(struct node**s)
{
    struct node *tlast;
    if(*s==NULL)
        printf("underflow");
    else
    {
        tlast=*s;
        while(tlast->next!=NULL)
            tlast=tlast->next;

        (tlast->prev==NULL) ? (*s=NULL) : (tlast->prev->next=NULL);

            free(tlast);
    }
}
insertafter(struct node *t, int data)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    temp->prev=t;
    temp->next=t->next;
    if(t->next!=NULL)
    t->next->prev=temp;

    t->next=temp;

}
insertatlast(struct node **s,int data)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    temp->next=NULL;
    if(*s==NULL)
    {
        *s=temp;
        temp->prev=NULL;
    }
    else
    {
    struct node*t=*s;
    while(t->next!=NULL)
        t=t->next;
    temp->prev=t;
    t->next=temp;
 }
 }

insertatstart(struct node **s,int data)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    temp->prev=NULL;
    if(*s==NULL)
    {
        *s=temp;
        temp->next=NULL;
    }
    else
    {
    temp->next=*s;
    (*s)->prev=temp;
    *s=temp;
    }
}
int menu(struct node *start)
{
    view(start);
    printf("\n\n");
    int choice;
    printf("1 insertatstart\n");
    printf("2 insertatlast\n");
    printf("3 insertafter\n");
    printf("4 deletestart\n");
    printf("5 deletelast\n");
    printf("6 deletenode\n");
    printf("7 deleteafter\n");
    printf("8 deletebefore\n");
    printf("9 search\n");
    printf("10 exit\n");

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
    insertatstart(&start,data);
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
    deletestart(&start);
    break;
case 5:
    deletelast(&start);
    break;
case 6:
    scanf("%d",&datatosearch);
    t=search(start,datatosearch);
    (t!=NULL)?deletenode(&start,t):printf("underflow");
    break;

case 7:
    scanf("%d",&datatosearch);
    t=search(start,datatosearch);
    (t!=NULL)?deleteafter(t):printf("underflow");
    break;
case 8:
    scanf("%d",&datatosearch);
    t=search(start,datatosearch);
    (t!=NULL)?deletebefore(&start,t):printf("underflow");
    break;
case 9:
    scanf("%d",&datatosearch);
    t=search(start,datatosearch);
    (t!=NULL)?printf("%d",t):printf("underflow");
    break;
case 10:
    exit(0);
}
getch();
system("cls");
}
}

