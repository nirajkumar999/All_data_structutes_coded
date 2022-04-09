#include<stdlib.h>    //using array
#include<conio.h>
#include<stdio.h>
struct queue
{
    int front, rear, capacity;
    int *ptr;
};
struct queue* createqueue(int capacity)
{
    struct queue *q=malloc(sizeof(struct queue));
    q->front=q->rear=-1;
    q->capacity=capacity;
    q->ptr=malloc(sizeof(int)*capacity);
    return q;
}
insertionatrear(struct queue *q,int data)
{
    if((q->rear==q->front-1)||(q->rear==q->capacity-1&&q->front==0))
        printf("overflow");
    else if(q->rear==-1)
    {
        q->rear++;
        q->front++;
        q->ptr[q->rear]=data;
    }
    else if(q->rear==q->capacity-1)
    {
        q->rear=0;
        q->ptr[q->rear]=data;
    }
    else
    {
    q->rear++;
    q->ptr[q->rear]=data;
    }
}
insertionatfront(struct queue *q,int data)
{
    if((q->rear==q->front-1)||(q->rear==q->capacity-1&&q->front==0))
        printf("overflow");
    else if(q->front==-1)
    {
        q->rear++;
        q->front++;
        q->ptr[q->front]=data;
    }
    else if(q->front==0)
    {
        q->front=q->capacity-1;
        q->ptr[q->front]=data;
    }
    else
    {
    q->front--;
    q->ptr[q->front]=data;
    }
}
deletionatfront(struct queue *q)
{
    if(q->front==-1)
        printf("underflow");
    else if(q->rear==q->front)
    {
        q->rear=-1;
        q->front=-1;
    }
    else if(q->front==q->capacity-1)
        q->front=0;
    else
        q->front++;
}
deletionatrear(struct queue *q)
{
    if(q->rear==-1)
        printf("underflow");
    else if(q->rear==q->front)
    {
        q->rear=-1;
        q->front=-1;
    }
    else if(q->rear==0)
        q->rear=q->capacity-1;
    else
        q->rear--;
}
view(struct queue *q)
{
if(q->rear==-1)
{
printf("empty queue\n\n");
printf("queuecount = %d\n",queuecount(q));
printf("front index = %d , rear index = %d , capacity = %d\n\n",q->front,q->rear,q->capacity);
}
else
{
    int i;
    for(i=q->front;i!=q->rear;  )
    {
     printf("%d  ",q->ptr[i]);
     (i==q->capacity-1)?(i=0):(++i);
    }
    printf("%d\n",q->ptr[i]);

    printf("queuecount = %d\n",queuecount(q));
    printf("value at front = %d , value at rear = %d , capacity = %d\n\n",q->ptr[q->front],q->ptr[q->rear],q->capacity);
}
}
deletequeue(struct queue **q1)
{
    free((*q1)->ptr);
    free(*q1);
    *q1=NULL;
}
int queuecount(struct queue *q)
{
    int count=0;
    if(q->rear==-1)
        return 0;
    else
    {
    for(int i=q->front;i!=q->rear;count++)
    (i==q->capacity-1)?(i=0):(++i);

    return(count+1);
    }
}
int menu(struct queue *q)
{
    int choice;
    view(q);
    printf("enter 1 for insertionatrear\n");
    printf("enter 2 for insertionatfront\n");
    printf("enter 3 for deletionatrear\n");
    printf("enter 4 for deletionatfront\n");
    printf("enter 5 to view\n");
    printf("enter 6 to exit\n");
    scanf("%d",&choice);
    return choice;
}
main()
{
    struct queue *q;
    int data;
    q=createqueue(5);
    while(1)
    {
    switch(menu(q))
    {
    case 1:
        scanf("%d",&data);
        insertionatrear(q,data);
        break;
        case 2:
        scanf("%d",&data);
        insertionatfront(q,data);
        break;
        case 3:
        deletionatrear(q);
        break;
    case 4:
        deletionatfront(q);
        break;
    case 5:
        view(q);
        break;
    case 6:
        deletequeue(&q);
        printf("q = %d",q);
        exit(0);
    }
    getch();
    system("cls");
    }
}
