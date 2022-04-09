main()
{
    int a[]={10,-30,-10,45,89,12,2,5,0,0};
    printf("before sorting\n");
    display(a,10);
    quick_sort(a,0,9);
    printf("\nafter sorting\n");
    display(a,10);
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
        return;
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
        return;
       else
         {
            swap(&a[loc],&a[left]);
            loc=left;
            right--;
         }
        goto step1;
    return loc;
}
quick_sort(int a[],int l,int u)
{
    int upper[10],lower[10];
    int top=-1;
    top++;
    upper[top]=u;
    lower[top]=l;
    while(top!=-1)
    {
    l=lower[top];
    u=upper[top];
    top--;
    int loc=quick(a,l,u);
    if(loc>l+1)
    {
        top++;
        lower[top]=l;
        upper[top]=loc-1;
     }
    if(loc<u-1)
    {
        top++;
        lower[top]=loc+1;
        upper[top]=u;
    }
    }
}
display(int a[],int size)
{
    for(int i=0;i<=size-1;i++)
        printf("%d  ",a[i]);
}
swap(int *a,int *b)
{
    if(a!=b)
    {
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
    }
}

