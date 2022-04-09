#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int x=0;
void TOH(int n, char A,char B,char C)
{
    if(n==1)
        {
            printf("%c -> %c",A,C);
            x++;
            return ;
        }

        TOH(n-1,A,C,B);
        printf("\n%c -> %c\n",A,C);x++;
        TOH(n-1,B,A,C);

}
void main()
{

    int n;
    scanf("%d",&n);
    TOH(n,'A','B','C');
    printf("\n\n%d\n",x);

}
