#include<stdio.h>
#include<stdlib.h>

int *ptr;
int capacity;
struct stack1
{
    int top1;
};

struct stack2
{
    int top2;
};

struct stack1* createstack1()
{
    struct stack1 *s1;
    s1=malloc(sizeof (struct stack1));
    s1->top1=-1;
    return s1;
};
struct stack2* createstack2()
{
    struct stack2 *s2;
    s2=malloc(sizeof (struct stack2));
    s2->top2=capacity;
    return s2;
};
pushstack1(struct stack1 *s1,struct stack2 *s2,int data)
{
    if(s1->top1+1!=s2->top2)
    {
        s1->top1++;
        ptr[s1->top1]=data;
    }
    else
        printf("stack is full");
}
pushstack2(struct stack1 *s1,struct stack2 *s2,int data)
{
    if(s1->top1+1!=s2->top2)
    {
        s2->top2--;
        ptr[s2->top2]=data;
    }
    else
        printf("stack is full");
}
popstack1(struct stack1 *s1)
{
    s1->top1==-1?printf("stack1 is empty"):s1->top1--;
}
popstack2(struct stack2 *s2)
{
    s2->top2==capacity?printf("stack2 is empty"):s2->top2++;
}
peekstack1(struct stack1 *s1)
{
    s1->top1==-1?printf("empty"):printf("%d",ptr[s1->top1]);
}
peekstack2(struct stack2 *s2)
{
    s2->top2==capacity?printf("empty"):printf("%d",ptr[s2->top2]);
}
view(struct stack1 *s1,struct stack2 *s2)
{
    printf("stack1   ");
    for(int i=0;i<=s1->top1;i++)
    printf("%d  ",ptr[i]);
    printf("\nstack2   ");
    for(int i=capacity-1;i>=s2->top2;i--)
    printf("%d  ",ptr[i]);
    printf("\n\n");
}

int menu(struct stack1 *s1,struct stack2 *s2)
{
    view(s1,s2);
        printf("press 1 for push stack 1\n");
        printf("press 2 for push stack 2\n");
        printf("press 3 for pop stack 1\n");
        printf("press 4 for pop stack 2\n");
        printf("press 5 for peek stack 1\n");
        printf("press 6 for peek stack 2\n");
        printf("press 7 to eixit\n");
        int choice;
        scanf("%d",&choice);
        return choice;
}
main()
{
  capacity=10;
    ptr=malloc(capacity*sizeof(int));
    int data;
    struct stack1 *s1;
    struct stack2 *s2;
    s1=createstack1(10);
    s2=createstack2(10);
    while(1)
    {
        switch(menu(s1,s2))
        {
        case 1:
            scanf("%d",&data);
            pushstack1(s1,s2,data);
            break;
        case 2:
            scanf("%d",&data);
            pushstack2(s1,s2,data);
            break;
        case 3:
            popstack1(s1);
            break;
        case 4:
            popstack2(s2);
            break;
        case 5:
            peekstack1(s1);
            break;
        case 6:
            peekstack2(s2);
            break;
        case 7:
            exit(0);
        }
        getch();
        system("cls");
    }
}

