#include<stdio.h>
#include<conio.h>
#include<direct.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *prev;
    struct node *next;
};

void insert_atfirst(struct node **s,int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->item=value;
    if(*s!=NULL)
    {
        temp->next=(*s);
        temp->prev=(*s)->prev;
        (*s)->prev->next=temp;
        (*s)->prev=temp;
        *s=temp;
    }
    else
    {
        temp->next=temp;
        temp->prev=temp;
        *s=temp;
    }
}

void insert_atlast(struct node **s,int value)
{
    struct node *temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->item=value;
    if(*s==NULL)
        printf("List is empty");

    else
    {
        t=*s;
        if(t==t->next)
        {
            temp->next=t;
            temp->prev=t;
            t->next=temp;
            t->prev=temp;
        }
        else
        {
        t=t->prev;
        temp->next=*s;
        temp->prev=t;
        t->next=temp;
        (*s)->prev=temp;
        }
    }
}

void insert_after(struct node **s,struct node *t,int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->item=value;

    if(*s==NULL)
    {
      printf("List is empty");
      return;
    }

    if(t==NULL)
     printf("Node not present");

    else
    {
        if(t==t->next)
        {
            temp->next=t;
            temp->prev=t;
            t->next=temp;
            t->prev=temp;
        }
        else
        {
            t->next->prev=temp;
            temp->prev=t;
            temp->next=t->next;
            t->next=temp;
        }
    }
}

struct node* searchnode(struct node *start, int value)
{
    struct node *t;

    if(start==NULL)
        return NULL;

    else
    {
         t=start;

        if(t==t->next)
          {
          if(value==start->item)
            return start;
          else
            return NULL;
          }
        else
        {
           while(start!=t->next)
           {
               if(t->item==value)
                return t;
               t=t->next;
           }
           if(t->item==value)
            return t;
           else
            return NULL;
        }
   }
}

void delete_firstnode(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("List is empty");
    else
    {
        t=*s;

        if(*s==t->next)
        {
            *s==NULL;
            free(t);
        }

        else
        {
            (*s)->next->prev=(*s)->prev;
            (*s)->prev->next=(*s)->next;
            *s=(*s)->next;
            free(t);
        }
    }
}

void delete_lastnode(struct node **s)
{
    struct node *t;

    if(*s==NULL)
        printf("List is empty");

    else
    {
       t=(*s)->prev;

        if(t==*s)
        {
          *s==NULL;
           free(t);
        }
        else
        {
            t->prev->next=t->next;
            (*s)->prev=t->prev;
            free(t);
        }
    }
}

void deleteafter(struct node *start, struct node *n)
{
    struct node *t;

    if(start==NULL)
     {
       printf("List is empty");
       return;
    }

    if(n==NULL)
    {
        printf("Node not present");
    }

    else
    {
        t=start;

       if(t==t->next)
         {
          printf("Node not present");
          return;
         }

       if(t->next==start)
         {
          printf("Node not present");
          return;
         }

       else
        {
          t=n->next;

          if(t->next==start)
          {
            n->next=t->next;
            start->prev=n;
            free(t);
          }
          else
          {
            n->next=t->next;
            t->next->prev=n;
            free(t);
          }
        }
      }
}

void viewlist(struct node *start)
{
    struct node *t;

    if(start==NULL)
        printf("List is empty");

    else
    {
         t=start;

        while(start!=t->next)
        {
            printf("%d ",t->item);
            t=t->next;
        }
        printf("%d ",t->item);
    }
}

int menu()
{
    int choice;
    printf(" *****Double Circular Linked-list program*****\n\n");
    printf("\n1.Insert node at the start");
    printf("\n2.Insert node at the last");
    printf("\n3.Insert item after a given node");
    printf("\n4.Delete first node");
    printf("\n5.Delete last node");
    printf("\n6.Delete a particular node after a given node");
    printf("\n7.View list items");
    printf("\n8.Exit");

    printf("\n\nEnter your choice:- ");
    scanf("%d",&choice);

    return choice;
}

main()
{
    struct node *start=NULL,*temp;
    int value,v;

    while(1)
    {
        system("cls");
         switch(menu())
         {
         case 1:
            printf("Enter the value to be stored in the beginning of the list:-  ");
            scanf("%d",&value);
            insert_atfirst(&start,value);
            break;

         case 2:
            printf("Enter the value to be stored at the end of the list:- ");
            scanf("%d",&value);
            insert_atlast(&start,value);
            break;

         case 3:
            printf("Enter the value to be stored in the list:- ");
            scanf("%d",&value);
            printf("Enter the value after which the new value is to be stored :- ");
            scanf("%d",&v);
            temp=searchnode(start,v);
            insert_after(&start,temp,value);
            break;

         case 4:
            delete_firstnode(&start);
            break;

         case 5:
            delete_lastnode(&start);
            break;

         case 6:
            printf("Enter the value after which the node is to be deleted:- ");
            scanf("%d",&value);
            temp=searchnode(start,value);
            deleteafter(start,temp);
            break;

         case 7:
            viewlist(start);
            break;

         case 8:
            printf("ThankYou, Press any key to exit");
            getch();
            exit(0);

         default:
            printf("Invalid choice");

         }
        getch();
    }
}





















