#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//numbering of vertex starts from 1,2,3,4...
struct list_node
{
    int vertex_no;
    struct list_node *next;
};
struct graph_node
{
    int vertex;
    int edges;
    struct list_node *p; //pointer to point array of listnode
};


void matrix_representation()
{
    struct graph_node *g=malloc(sizeof(struct graph_node));
    printf("enter no. of vertex and edges\n");
    scanf("%d %d",&g->vertex,&g->edges);
    g->p=malloc(sizeof(struct list_node)*g->vertex);
    for(int i=0;i<g->vertex;i++)
    {
        g->p[i].vertex_no=i+1;
        (g->p + i)->next=NULL;
    }
    printf("enter edge details\n");
    int x, y;
    for(int i=0;i<g->edges;i++)
    {
    scanf("%d %d",&x,&y);
    struct list_node *p1,*p2,*traverse;
    p1=malloc(sizeof(struct list_node));
    p2=malloc(sizeof(struct list_node));
    p1->vertex_no=x;
    p2->vertex_no=y;
    p1->next=NULL;
    p2->next=NULL;
    traverse=g->p+x-1;
    while(traverse->next!=NULL)
        traverse=traverse->next;
    traverse->next=p2;
        traverse=g->p + y-1;
    while(traverse->next!=NULL)
        traverse=traverse->next;
    traverse->next=p1;
}

display_list(g);
}
void display_list(struct graph_node *g)
{
    struct list_node *ptr;
   for(int i=0;i<g->vertex;i++)
   {
       ptr=g->p+i;
       printf("%d ",ptr->vertex_no);
       while(ptr->next!=NULL)
       {
           ptr=ptr->next;
           printf("-> %d ",ptr->vertex_no);
       }
       printf("\n");
   }
}
void main()
{
matrix_representation();
}
