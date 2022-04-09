#include<stdlib.h>    //dynamic array
#include<conio.h>
#include<stdio.h>
struct array
{
    int capacity;
    int lastindex;
    int *ptr;
};
struct array* createarray(int cap)
{
    struct array *arr;
    arr=(struct array*)malloc(sizeof(struct array));
    arr->capacity=cap;
    arr->lastindex=-1;
    arr->ptr=(int*)malloc(sizeof(int)*cap);
    return arr;
}
void setvalue(struct array *arr,int index,int data)
{
    if(index<0||index>arr->lastindex+1)
        printf("invalid index");
    else
    {
        if (arr->capacity-1==arr->lastindex)
        doublearray(arr);

        for(int i=arr->lastindex;i>=index;i--)
        arr->ptr[i+1]=arr->ptr[i];

        arr->ptr[index]=data;
        arr->lastindex+=1;
    }

}
void editvalue(struct array *arr,int index,int data)
{
    if(index<0||index>arr->lastindex)
        printf("invalid index");
    else
        arr->ptr[index]=data;
}
void append(struct array *arr,int data)
{
    if(arr->capacity-1==arr->lastindex)
        doublearray(arr);

        arr->lastindex+=1;
        arr->ptr[arr->lastindex]=data;

}
void deletevalue(struct array *arr,int index)
{
    if(arr->lastindex==-1)
        printf("underflow");
    else if(index<0||index>arr->lastindex)
        printf("invalid index");
    else
        {
      for(int i=index;i<arr->lastindex;i++)
        arr->ptr[i]=arr->ptr[i+1];
        arr->lastindex-=1;
        }
if(arr->lastindex+1<=arr->capacity/2&&arr->capacity>1)
halfarray(arr);

}

count(struct array *arr)
{
    printf("%d",arr->lastindex+1);
}

get(struct array *arr,int index)
{
    if(index<0||index>arr->lastindex)
        printf("invalid index");
    else
        printf("%d",arr->ptr[index]);
}
doublearray(struct array *arr)
{
    arr->capacity*=2;
    arr->ptr=realloc(arr->ptr,arr->capacity*sizeof(struct array));
};
halfarray(struct array *arr)
{
    arr->capacity/=2;
    arr->ptr=realloc(arr->ptr,arr->capacity*sizeof(struct array));
}

search(struct array *arr,int data)
{
    int flag=0;
    for(int i=0;i<=arr->lastindex;i++)
            if(arr->ptr[i]==data)
             {
               printf("found\n");
               flag=1;
               break;
             }
             if(flag==0)
        printf("not found");
}

sorting(struct array *arr)
{
    int n=arr->lastindex+1;
    for(int i=1;i<=n-1;i++)
        for(int j=0;j<=n-1-i;j++)
    {
        if(arr->ptr[j]>arr->ptr[j+1])
        {
            int swap=arr->ptr[j];
            arr->ptr[j]=arr->ptr[j+1];
            arr->ptr[j+1]=swap;
        }
    }
}
int menu(struct array *arr)
{
    int choice;
    printf("current update %d  %d\n",arr->lastindex,arr->capacity);
    for(int i=0;i<=arr->lastindex;i++)
    printf("%d  ",arr->ptr[i]);
    printf("\n\n");
    printf("1 setvalue\n");
    printf("2 editvalue\n");
    printf("3 append\n");
    printf("4 deletevalue\n");
    printf("5 count\n");
    printf("6 get\n");
    printf("7 search\n");
    printf("8 sorting\n");
    printf("9 exit\n");
    scanf("%d",&choice);
    return choice;
}


main()
{
int index,data;
struct array *arr;
arr=createarray(3);
while(1)
{
switch(menu(arr))
{
case 1:
    scanf("%d%d",&index,&data);
    setvalue(arr,index,data);
    break;
case 2:
    scanf("%d%d",&index,&data);
    editvalue(arr,index,data);
    break;
case 3:
    scanf("%d",&data);
    append(arr,data);
    break;
case 4:
    scanf("%d",&index);
    deletevalue(arr,index);
    break;
case 5:
    count(arr);
    break;
case 6:
    scanf("%d",&index);
    get(arr,index);
    break;
case 7:
    scanf("%d",&data);
    search(arr,data);
    break;
case 8:
    sorting(arr);
    break;
case 9:
    exit(0);
}
getch();
system("cls");
}
}
