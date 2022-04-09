#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//numbering of vertex starts from 1,2,3,4...
struct graph_node
{
    int vertex;
    int edges;
    int **matrix; //pointer to point 2d matrix
};



struct graph_node* create_graph(int vertex,int edges)
{

    struct graph_node *g=(struct graph_node*)malloc(sizeof(struct graph_node));
    g->vertex=vertex;
    g->edges=edges;
    g->matrix=(int**)malloc(sizeof(int*)*g->vertex);
    for(int i=0;i<g->vertex;i++)
     g->matrix[i]=(int*)malloc(sizeof(int)*g->vertex);

    for(int i=0;i<g->vertex;i++)
    for(int j=0;j<g->vertex;j++)
        g->matrix[i][j]=0;
        if(edges>0)
        {
          printf("enter details of all %d edges (start vertex , end vertex)\n",edges);
          int x,y;
          for(int i=0;i<g->edges;i++)
          {
           scanf("%d %d",&x,&y);
           g->matrix[x-1][y-1]=1;
           g->matrix[y-1][x-1]=1;
          }
        }
        display_matrix(g);
        printf("graph created\n");
        return g;

}
void display_matrix(struct graph_node *g)
{
    for(int i=0;i<g->vertex;i++){
     for(int j=0;j<g->vertex;j++)
      printf("%d ",g->matrix[i][j]);
     printf("\n");}
}
void main()
{
create_graph(2,0);
}
