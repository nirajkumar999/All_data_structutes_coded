#include<stdlib.h>    //stack using simple array
#include<conio.h>
#include<stdio.h>
struct stack
{
    int capacity;
    int lastindex;
    int *ptr;
};
struct array* createstack(int cap)
{
    struct stack *sta;
    sta=(struct stack*)malloc(sizeof(struct stack));
    sta->capacity=cap;
    sta->lastindex=-1;
    sta->ptr=(int*)malloc(sizeof(int)*cap);
    return sta;
}
void editvalue(struct stack *sta,int index,int data)
{
    if(index<0||index>sta->lastindex)
        printf("invalid index");
    else
        sta->ptr[index]=data;
}
void push(struct stack *sta,int data)   //append
{
    if(sta->capacity-1==sta->lastindex)
        printf("overflow");
    else
    {
    sta->lastindex+=1;
        sta->ptr[sta->lastindex]=data;
    }

}
void pop(struct stack *sta)
{
    if(sta->lastindex==-1)
        printf("underflow");
    else
    {
        printf("%d",sta->ptr[sta->lastindex]);
        sta->lastindex--;
    }

}
viewstack(struct stack *sta)
{
    for(int i=0;i<=sta->lastindex;i++)
    printf("%d  ",sta->ptr[i]);
}
peek(struct stack *sta)
{
    (sta->lastindex==-1)?printf("empty stack"):printf("%d",sta->ptr[sta->lastindex]);
}
int menu(struct stack *sta)
{
    int choice;
    printf("current update %d  %d\n",sta->lastindex,sta->capacity);
    viewstack(sta);
    printf("\n\n");
    printf("1 push\n");
    printf("2 pop\n");
    printf("3 peek\n");
    printf("4 edit values\n");
    printf("5 exit\n");
    scanf("%d",&choice);
    return choice;
}
main()
{
int index,data;
struct stack *sta;
sta=createstack(5);
while(1)
{
switch(menu(sta))
{
case 4:
    scanf("%d%d",&index,&data);
    editvalue(sta,index,data);
    break;
case 1:
    scanf("%d",&data);
    push(sta,data);
    break;
case 2:
    pop(sta);
    break;
case 3:
    peek(sta);
    break;

case 5:
    exit(0);
}
getch();
system("cls");
}
}
