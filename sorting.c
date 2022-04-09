#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int menu();
void insertion_sort(int[],int);
void selection_sort(int[],int);
int search_min_index(int[],int , int );
void modified_bubble_sort(int[],int);
void bubble_sort(int[],int);
void swap(int*,int*);
void display(int[],int);
void quick_sort_recursion(int[],int,int);
int partition(int[],int,int);
void quick_sort(int[],int,int);
int quick(int[],int,int);
void merge_sort(int[],int,int);
void merge(int[],int,int,int);
void heapify_for_build_heap_method(int *,int,int);
void heapify_for_insertion_method(int *,int);
void heapsort_using_build_heap_method(int[],int);
void heapsort_using_insertion_method(int[],int);

int count=0;//counter to count no of function call
void main()
{
    int a[]={0,1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8};//input the array elments of your choice
    int size=sizeof(a)/4;
    while(1)
    {
    printf("before sorting\n");
    display(a,size);
    switch(menu())
    {
    case 1:
        bubble_sort(a,size);
        break;
    case 2:
        modified_bubble_sort(a,size);
        break;
    case 3:
        insertion_sort(a,size);
        break;
    case 4:
        selection_sort(a,size);
        break;
    case 5:
        merge_sort(a,0,size-1);
        break;
    case 6:
        quick_sort(a,0,size-1);
        break;
    case 7:
        quick_sort_recursion(a,0,size-1);
        break;
    case 8:
        heapsort_using_insertion_method(a,size);
        break;
    case 9:
        heapsort_using_build_heap_method(a,size);
        break;
    case 10:
        exit(0);
        break;
    default:
        printf("\nWrong choice...press enter to continue");
        getch();
        system("cls");
        continue;
    }

    printf("\nafter sorting\n");
    display(a,size);
    printf("\n\npress enter to continue");
    getch();
    system("cls");
    }
}

int  menu()
{
    int x;
    printf("\n\n1  bubble sort");
    printf("\n2  modified bubble sort");
    printf("\n3  insertion sort");
    printf("\n4  selection sort");
    printf("\n5  merge sort");
    printf("\n6  quick sort using traditional method");
    printf("\n7  quick sort using divide and conquer");
    printf("\n8  heap sort using insertion method");
    printf("\n9  heap sort using build heap method");
    printf("\n10 to exit");
    printf("\n\nEnter your preferred choice for sorting\n");
    scanf("%d",&x);
    return x;
}
void merge(int a[],int l,int mid,int u)
{

    int a1=l;
    int a2=mid+1;
    int c[u-l+1];
    int k=0;
    while(a1<=mid&&a2<=u)
{

        if(a[a1]<=a[a2])
            c[k++]=a[a1++];
        else
        c[k++]=a[a2++];
}
    for(;a1<=mid;a1++)
    c[k++]=a[a1];
    for(;a2<=u;a2++)
    c[k++]=a[a2];

    for(int i=0;i<sizeof(c)/4;i++)
    a[l++]=c[i];
}
void merge_sort(int a[],int l,int u)
{
    if(l<u)
    {
    int mid=(l+u)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,u);
    merge(a,l,mid,u);
    }
}
int quick(int a[],int l,int u)
{
    int left=l;
    int right=u;
    int loc=l;
step1:
        while(left<right&&a[loc]<=a[right])
        right--;

        if(left==right)
        return loc;
        else
        {
            swap(&a[loc],&a[right]);
            loc=right;
            left++;
        }
    goto step2;
step2:
      while(left<right&&a[loc]>=a[left])
        left++;

        if(left==right)
        return loc;
       else
         {
            swap(&a[loc],&a[left]);
            loc=left;
            right--;
         }
        goto step1;


}
void quick_sort(int  a[],int l,int u)
{
    int loc=quick(a,l,u);
    if(loc>l+1)
    quick_sort(a,l,loc-1);
    if(loc<u-1)
    quick_sort(a,loc+1,u);
}
int partition(int a[],int lb,int ub)
{
    int pivot=a[ub];
    int i=lb-1;
    for(int j=lb;j<=ub-1;j++)
    if(a[j]<=pivot)
    {
        i++;
      swap(&a[j],&a[i]);
    }
         swap(&a[i+1],&a[ub]);
        return(i+1);
}
void quick_sort_recursion(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);
        quick_sort_recursion(a,lb,loc-1);
        quick_sort_recursion(a,loc+1,ub);
    }
}
void display(int a[],int size)
{
    for(int i=0;i<=size-1;i++)
        printf("%d  ",a[i]);
}
void swap(int *a,int *b)
{
    if(a!=b)
    {
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
    }
}
void bubble_sort(int a[],int size)
{
for(int round=1;round<=size-1;round++)
        for(int j=0;j<=size-1-round;j++)
            if(a[j]>a[j+1])
            swap(&a[j],&a[j+1]);
}
void modified_bubble_sort(int a[],int size)
{
for(int round=1,flag=0;round<=size-1;round++,flag=0)
{
        for(int j=0;j<=size-1-round;j++)
            if(a[j]>a[j+1])
            {
            swap(&a[j],&a[j+1]);
            flag=1;
            }

if(flag==0)
break;
}
}
int search_min_index(int a[],int size, int i)
{
    int min_index=i;
    for(i=i+1;i<=size-1;i++)
    if(a[min_index]>a[i])
        min_index=i;

    return min_index;
}
void selection_sort(int a[],int size)
{
    for(int i=0;i<=size-2;i++)
        swap(&a[i],&a[search_min_index(a,size,i)]);
}
void insertion_sort(int a[],int size)
{
    for(int i=1;i<=size-1;i++)
    {
     int k=a[i];
     int j;
    for(j=i;j>0;j--)
    {
     if(k<a[j-1])
     a[j]=a[j-1];
     else
     break;
     }
     a[j]=k;
}
}
void heapify_for_build_heap_method(int *a,int index,int size)
{
    int largest=index;
    int left=2*index + 1;
    int right=2*index + 2;
    if(left<=size-1 && a[largest]<a[left])
        largest=left;
    if(right<=size-1 && a[largest]<a[right])
        largest=right;
    if(largest!=index)
    {
        swap(&a[largest],&a[index]);
        heapify_for_build_heap_method(a,largest,size);
    }

}
void heapify_for_insertion_method(int *a,int index)
{
    int largest=index;
    int parent=(largest-1)/2;
    if(a[largest]>a[parent])
    {
    swap(&a[parent],&a[largest]);
    largest=parent;
    heapify_for_insertion_method(a,largest);
    }
}
void heapsort_using_build_heap_method(int a[],int size)
{
    //building heap for array a
    for(int index=size/2 - 1;index>=0;index--)
        heapify_for_build_heap_method(a,index,size);
    //extract max
    for(int round=0;round<=size-2;round++)
    {
     swap(&a[0],&a[size-1-round]);
     heapify_for_build_heap_method(a,0,size-1-round);
    }

}
void heapsort_using_insertion_method(int a[],int size)
{
    //building heap for array a
    for(int index=0;index<=size-1;index++)
        heapify_for_insertion_method(a,index);
    //extract max
 for(int round=0;round<=size-2;round++)
    {
        swap(&a[0],&a[size-1-round]);
        //this is the correct way
        heapify_for_build_heap_method(a,0,size-1-round);

/* for(int index=0;index<=size-2-round;index++)
heapify_for_insertion_method(a,index);*/

    }

}
