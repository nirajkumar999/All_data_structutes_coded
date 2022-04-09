#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    int pr;
};
insertion(struct node **s,int value,int pr)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->pr=pr;
    if(*s==NULL)
    {
        temp->next=NULL;
        *s=temp;
    }
    else
    {
        struct node *t=*s;
        if(pr>(*s)->pr)
        {
            temp->next=*s;
            *s=temp;
        }
        else
        {
            while(t->next!=NULL)
            {
                if(pr>t->next->pr)
                 break;
                t=t->next;
            }
                temp->next=t->next;
                t->next=temp;
        }
    }
}
deletion(struct node **s)
{
    if(*s==NULL)
    printf("empty list");
    else
    {
        struct node *t=*s;
        *s=(*s)->next;
        free(t);
    }

}
view(struct node **s)
{
  if(*s==NULL)
        printf("empty\n");
  else
  {
      struct node *start=*s;
      while(start!=NULL)
      {
          printf("%d (%d)  ",start->data,start->pr);
          start=start->next;
      }
  }
  printf("\ncount  = %d\n\n",count(*s));
  }
int count(struct node *start)
{
    int count=0;
    while(start!=NULL)
    {
        count++;
        start=start->next;
    }
    return count;
}
deletequeue(struct node **s)
{
    struct node *start=*s;
    while(start!=NULL)
    {
        struct node *temp=start->next;
        free (start);
        start=temp;
    }
    *s=NULL;
}
int menu(struct node *start)
{
    view(&start);
    printf("\n\n");
    int choice;
    printf("1 insertion\n");
    printf("2 deletion\n");
    printf("3 view\n");
    printf("4 exit\n");
    scanf("%d",&choice);
    return choice;

}

main()
{
    struct node *start=NULL;
    int value,pr;
    while(1)
    {
        switch(menu(start))
        {
        case 1:
            scanf("%d %d",&value,&pr);
            insertion(&start,value,pr);
            break;
        case 2:
            deletion(&start);
            break;
        case 3:
            view(&start);
            break;
        case 4:
            deletequeue(&start);
            printf("start = %d ",start);
            exit(0);
        }
        getch();
        system("cls");
        }

}

