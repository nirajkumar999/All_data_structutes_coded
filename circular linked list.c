#include<stdlib.h>
struct node
{
int item;
struct node *next;
};
view(struct node *last)
{
    struct node *t;
    if(last==NULL)
        printf("list is empty");
    else
    {
        t=last->next;
        while(t!=last)
        {
        printf("%d ",t->item);
        t=t->next;
        }
        printf("%d ",last->item);
    }

}
insertatstart(struct node **l,int data)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    if(*l==NULL)
    {
        *l=temp;
        temp->next=temp;
    }
    else
    {
       temp->next=(*l)->next;
       (*l)->next=temp;
    }
}
insertatlast(struct node **l,int data)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    if(*l==NULL)
    {
        *l=temp;
        temp->next=temp;
    }
    else
    {
        temp->next=(*l)->next;
        (*l)->next=temp;
        (*l)=temp;
    }
}
insertafter(struct node **l,struct node *t,int data)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    temp->next=t->next;
    t->next=temp;
    if(*l==t)
        *l=temp;
}
deletelast(struct node **l)
{
    if(*l==NULL)
        printf("list is empty");
    else
    {
        struct node *tfront=(*l)->next,*trear=NULL;
        while(tfront!=*l)
        {
            trear=tfront;
            tfront=tfront->next;
        }
        if(trear==NULL)
        {
            free(*l);
            *l=NULL;
        }
        else
        {
        trear->next=(*l)->next;
        free (*l);
        *l=trear;
        }
   }
}
deletestart(struct node **l)
{
    if(*l==NULL)
        printf("list is empty");
    else
    {
        struct node *start=(*l)->next;
        (start!=*l) ? ((*l)->next=start->next) : (*l=NULL);
        free(start);
    }
}
deletenode(struct node **l,struct node *t)
{
     if((*l)->next==*l)
        {
            free(*l);
            *l=NULL;
        }
     else
      {
       struct node *trear=*l;

        while(trear->next!=t)
        trear=trear->next;

        trear->next=t->next;
        free(t);
        if(t==*l)
        *l=trear;
      }
}
struct node* search(struct node *last,int datatosearch)
{
    if(last==NULL)
        return NULL;

    else
    {
        struct node *start=last->next;
        while(start!=last)
        {
            if(start->item==datatosearch)
            return (start);

        start=start->next;
        }
         if(last->item==datatosearch)
         return last;
     }
   return NULL;
}
int menu(struct node *last)
{
    view(last);
    printf("\n\n");
    int choice;
    printf("1 insertatstart\n");
    printf("2 insertatlast\n");
    printf("3 insertafter\n");
    printf("4 deletestart\n");
    printf("5 deletelast\n");
    printf("6 deletenode\n");
    printf("7 search\n");
    printf("8 exit\n");
    scanf("%d",&choice);
    return choice;

}
main()
{
    struct node *last=NULL,*t=NULL;
    int data,datatosearch;
    while(1)
{
switch(menu(last))
{
case 1:
    scanf("%d",&data);
    insertatstart(&last,data);
    break;
case 2:
    scanf("%d",&data);
    insertatlast(&last,data);
    break;
case 3:
    scanf("%d%d",&datatosearch,&data);
    t=search(last,datatosearch);
    (t!=NULL)?insertafter(&last,t,data):printf("underflow");
    break;
case 4:
    deletestart(&last);
    break;
case 5:
    deletelast(&last);
    break;
case 6:
    scanf("%d",&datatosearch);
    t=search(last,datatosearch);
    (t!=NULL)?deletenode(&last,t):printf("underflow");
    break;
case 7:
    scanf("%d",&datatosearch);
    t=search(last,datatosearch);
    (t!=NULL)?printf("%d",t):printf("not found");
    break;
case 8:
    exit(0);
}
getch();
system("cls");
}
}



