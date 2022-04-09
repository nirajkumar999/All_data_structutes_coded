#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//numbering of vertex starts from 1,2,3,4...
struct list_node
{
    int vertex_name;
    struct list_node *next;
};
struct graph_node
{
    int vertex_count;
    int edge_count;
    struct list_node *p; //pointer to point array of listnode
};
//for graph traversal use bfs and dfs

struct queue_node
{
    int data;
    struct node *next;
};

void deletionathead(struct queue_node **,struct queue_node **);
void insertionattail(struct queue_node **,struct queue_node **,int value);
void deletionattail(struct queue_node **,struct queue_node **);
int count(struct queue_node *,struct queue_node *);

struct graph_node* create_graph(int,int);
void display_graph(struct graph_node *);
int menu();
void insert_vertex(struct graph_node *);
void insert_edge(struct graph_node *);
int indexof(struct graph_node *,int );
int find_edge(struct graph_node *,int,int );
void delete_edge(struct graph_node *,int,int);
void BFS_traversal(struct graph_node*,int);
//void DFS_traversal(struct graph_node*);


void insertionattail(struct queue_node **h,struct queue_node **t,int value)
{
    struct queue_node *n=(struct queue_node*)malloc(sizeof(struct queue_node));
    n->data=value;
    n->next=NULL;
    if(*t==NULL)
    {
        *t=n;
        *h=n;
    }
    else
    {
      (*t)->next=n;
      *t=n;
    }
}
void deletionathead(struct queue_node **h,struct queue_node **t)
{
    if(*h==NULL)
        printf("nothing to delete");
    else if(*h==*t)
    {
        free(*h);
        *h=NULL;
        *t=NULL;
    }
    else
    {
        struct queue_node *temp=(*h)->next;
        free (*h);
        *h=temp;
    }
}
void deletionattail(struct queue_node **h,struct queue_node **t)
{
    if(*t==NULL)
        printf("nothing to delete");
    else if(*h==*t)
    {
        free(*t);
        *h=NULL;
        *t=NULL;
    }
    else
        {
            struct queue_node *secondlast=*h;
            while(secondlast->next!=*t)
                secondlast=secondlast->next;
            free(*t);
            secondlast->next=NULL;
            *t=secondlast;
        }
}

int count(struct queue_node *head,struct queue_node *tail)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}



/*both for bfs and dfs we use double
ended queue implementation using linked list*/

void BFS_traversal(struct graph_node *g,int start_vertex)
{
    int status_arr[g->vertex_count];

    //zero for not traversed vertex and 1 for traversed vertex

    for(int i=0;i<=g->vertex_count-1;i++)
        status_arr[i]=0;

    //using queue ADT

    struct queue_node *head =NULL,*tail=NULL;
    insertionattail(&head,&tail,start_vertex);
    status_arr[indexof(g,start_vertex)]=1;

    while(count(head,tail)>0)
    {
        struct list_node *traverse=g->p[indexof(g,head->data)].next;
        while(traverse)
        {
            if(status_arr[indexof(g,traverse->vertex_name)]==0)
            {
              insertionattail(&head,&tail,traverse->vertex_name);
              status_arr[indexof(g,traverse->vertex_name)]=1;
            }
            traverse=traverse->next;
        }
        printf("%d ",head->data);
        deletionathead(&head,&tail);
    }
    printf("\n");
}
struct graph_node* create_graph(int nodes,int edges)
{
    struct graph_node *g=malloc(sizeof(struct graph_node));
    g->vertex_count=nodes;
    g->edge_count=0;
    g->p=malloc(sizeof(struct list_node)*g->vertex_count);
    for(int i=0;i<g->vertex_count;i++)
    {
        g->p[i].vertex_name=i+1;
        (g->p + i)->next=NULL;
    }
    if(edges>0)
    {
    printf("enter edge details\n\n");
    for(int i=0;i<edges;i++)
    {
     insert_edge(g);
    }
    }
    getch();
system("cls");
printf("graph created successfully\n");
return g;
}
int find_edge(struct graph_node *g,int from,int to)
{
    if(indexof(g,from)==-1 || indexof(g,to)==-1)
        return -1;
    struct list_node *traverse;
    traverse=g->p[indexof(g,from)].next;
    while(traverse)
    {
        if(traverse->vertex_name==to)
            return 1;
        traverse=traverse->next;
    }
   return 0;
}
void display_graph(struct graph_node *g)
{
    struct list_node *ptr;
   for(int i=0;i<g->vertex_count;i++)
   {
       ptr=g->p+i;
       printf("%d ",ptr->vertex_name);
       while(ptr->next!=NULL)
       {
           ptr=ptr->next;
           printf("-> %d ",ptr->vertex_name);
       }
       printf("\n");
   }
   printf("\n%d - vertex count and %d - edge count\n",g->vertex_count,g->edge_count);
}
void insert_vertex(struct graph_node *g)
{
     int i;
     int vertex_name=g->p[g->vertex_count-1].vertex_name;
     g->vertex_count++;
    struct list_node *p=NULL;
    p=(struct list_node*)malloc(sizeof(struct list_node)*g->vertex_count);
    for( i=0;i<g->vertex_count-1;i++)
    {
        p[i].vertex_name=g->p[i].vertex_name;
        p[i].next=g->p[i].next;
    }
    p[i].vertex_name=vertex_name+1;
    p[i].next=NULL;
    free(g->p);
    g->p=p;
}
void insert_edge(struct graph_node *g)
{
    int from, to;
    printf("Enter edge from - to \n");
    scanf("%d %d",&from,&to);
    if(find_edge(g,from,to)==0)
    {
    g->edge_count++;
    struct list_node *node,*traverse;
    node=(struct list_node*)malloc(sizeof(struct list_node));
    node->vertex_name=to;
    node->next=NULL;
    traverse=g->p+indexof(g,from);
    while(traverse->next)
      traverse=traverse->next;
    traverse->next=node;
    }
    else if(find_edge(g,from,to)==-1)
        printf("invalid edge entry\n");
    else
        printf("Duplicate edge\n");

};
int indexof(struct graph_node *g,int vertex_name)
{
    for(int i=0;i<=g->vertex_count-1;i++)
        if(g->p[i].vertex_name==vertex_name)
        return i;
    return -1;
}
void delete_vertex(struct graph_node *g,int vertex_name)
{
    if(indexof(g,vertex_name)==-1)
    {
        printf("invalid vertex\n");
        return;
    }
    if(g->vertex_count>1)
    {
    for(int i=0;i<=g->vertex_count-1;i++)
    {
        if(g->p[i].vertex_name!=vertex_name)
            if(find_edge(g,g->p[i].vertex_name,vertex_name)==1)
                delete_edge(g,g->p[i].vertex_name,vertex_name);
    }
    struct list_node *traverse;
    traverse=g->p+indexof(g,vertex_name);
    while(traverse->next)
    {
        delete_edge(g,vertex_name,traverse->next->vertex_name);
    }
    int index_of_p=0;
struct list_node *p=(struct list_node*)malloc(sizeof(struct list_node)*(g->vertex_count-1));
for(int i=0;i<=g->vertex_count-1;i++)
{
    if(g->p[i].vertex_name!=vertex_name)
    {
    p[index_of_p].vertex_name=g->p[i].vertex_name;
    p[index_of_p++].next=g->p[i].next;
    }
}
g->vertex_count--;
free(g->p);
g->p=p;
    }
    else
    printf("minimum 1 vertex to be there\n");
}
void delete_edge(struct graph_node *g,int from,int to)
{
    if(find_edge(g,from,to)==1)
    {
    struct list_node *traverse,*temp;
    traverse=g->p+indexof(g,from);
    while(traverse->next)
    {
    if(traverse->next->vertex_name==to)
    {
        temp=traverse->next->next;
        free(traverse->next);
        traverse->next=temp;
        g->edge_count--;
    }
    else
        traverse=traverse->next;
    }
    }
    else printf("edge not found\n");
}
int menu()
{
    int choice;
    printf("\n\nenter 1 to add vertex\n");
    printf("enter 2 to add edge\n");
    printf("enter 3 to delete vertex\n");
    printf("enter 4 to delete edge\n");
    printf("enter 5 to BFS traversal\n");
    printf("enter 6 to exit\n");
    printf("\n\nenter your choice\n");
    scanf("%d",&choice);
    return choice;
}
void main()
{
printf("Enter Initial no. of nodes( > zero ) and edges( >= zero)\n");
int nodes,edges,from,to,vertex,start_vertex;
scanf("%d %d",&nodes,&edges);
struct graph_node *g=NULL;
g=create_graph(nodes,edges);
while(1)
{
display_graph(g);
switch(menu())
{
case 1:
    insert_vertex(g);
    break;
case 2:
    insert_edge(g);
    break;
case 3:
    printf("enter vertex to delete\n");
    scanf("%d",&vertex);
    delete_vertex(g,vertex);
    break;
case 4:
    printf("enter node to be deleted from - to\n");
    scanf("%d %d",&from,&to);
    delete_edge(g,from,to);
    break;
case 5:
    printf("enter start vertex\n");
    scanf("%d",&start_vertex);
    BFS_traversal(g,start_vertex);
    break;
case 6:
    exit(0);
default:
    printf("wrong choice\n");

}
getch();
system("cls");
}
}
