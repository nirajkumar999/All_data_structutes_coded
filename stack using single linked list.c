#include<stdlib.h>
struct node               //stack using single linked list
{
    int item;
    struct stack *next;
};
pop(struct node **s)
{
    struct node *temp;
    if(*s==NULL)
     printf("underflow");
    else
    {
    printf("%d",(*s)->item);
    temp=(*s)->next;
    free(*s);
    *s=temp;
    }
}
push(struct node **s,int data)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->item=data;
    temp->next=*s;
    *s=temp;
}
viewstack(struct node *start)
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
peek(struct node *start)
{
    (start==NULL)?printf("empty stack"):printf("%d",start->item);
}
int menu(struct node *start)
{
    viewstack(start);
    printf("\n\n");
    int choice;
    printf("1 push\n");
    printf("2 pop\n");
    printf("3 peek\n");
    printf("4 exit\n");
    scanf("%d",&choice);
    return choice;

}
main()
{
    struct node *start=NULL;
    int data;
    while(1)
{
switch(menu(start))
{
case 1:
    scanf("%d",&data);
    push(&start,data);
    break;
case 2:
    pop(&start);
    break;
case 3:
    peek(start);
    break;
case 4:
    exit(0);
}
getch();
system("cls");
}
}
