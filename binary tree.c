#include<stdio.h>
struct bstnode
{
    int item;
    struct bstnode *left;
    struct bstnode *right;
};
struct queuenode
{
    struct bstnode *data;
    struct queuenode *next;
};
struct ptr
{
    struct bstnode *_ptr;
    struct bstnode *_pptr;
};
insertqueue(struct queuenode **f,struct queuenode **r,struct bstnode *value)
{
    struct queuenode *n=malloc(sizeof(struct queuenode));
    n->data=value;
    n->next=NULL;
    if(*r==NULL)
    {
        *r=n;
        *f=n;
    }
    else
    {
      (*r)->next=n;
      *r=n;
    }
}
int countqueue(struct queuenode *front,struct queuenode *rear)
{
    int count=0;
    while(front!=NULL)
    {
        count++;
        front=front->next;
    }
    return count;
}
struct bstnode* deletequeue(struct queuenode **f,struct queuenode **r)
{
    struct bstnode *address;
    if(*f==*r)
    {
        address=(*f)->data;
        free(*f);
        *f=NULL;
        *r=NULL;
        return(address);
    }
    else
    {
        struct queuenode *temp=(*f)->next;
        address=(*f)->data;
        free (*f);
        *f=temp;
        return(address);
    }
}

insertion(struct bstnode **r,int value)
{
    struct bstnode *ptr=*r,*temp =malloc(sizeof(struct bstnode));
    temp->item=value;
    temp->right=NULL;
    temp->left=NULL;
    if(*r==NULL)
    {
        *r=temp;
        return;
    }
        while(ptr)
       {
        if(ptr->item==value)
        {
           printf("duplicate not allowed");
           free(temp);
           break;
        }
        else if(value<ptr->item)
        {
            if(ptr->left==NULL)
                {
                  ptr->left=temp;
                  break;
                }
                else
                    ptr=ptr->left;
        }
        else
        {
            if(ptr->right==NULL)
                {
                  ptr->right=temp;
                  break;
                }
                else
                    ptr=ptr->right;
        }
        }
    }

preorder(struct bstnode *root)
{
    if(root)
    {
    printf("%d ",root->item);
    preorder(root->left);
    preorder(root->right);
    }
}
postorder(struct bstnode *root)
{
    if(root)
    {
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->item);
    }
}
inorder(struct bstnode *root)
{
   if(root)
    {
    inorder(root->left);
    printf("%d ",root->item);
    inorder(root->right);
    }
}
levelorder_L_to_R(struct bstnode *root)
{
    if(root)
    {
        struct queuenode *front =NULL,*rear=NULL;
        insertqueue(&front,&rear,root);
        while(countqueue(front,rear))
        {
            root=deletequeue(&front,&rear);
            printf("%d ",root->item);
            if(root->left)
            insertqueue(&front,&rear,root->left);
            if(root->right)
            insertqueue(&front,&rear,root->right);
        }
    }
}
levelorder_R_to_L(struct bstnode *root)
{
    if(root)
    {
        struct queuenode *front =NULL,*rear=NULL;
        insertqueue(&front,&rear,root);
        while(countqueue(front,rear))
        {
            root=deletequeue(&front,&rear);
            printf("%d ",root->item);
            if(root->right)
            insertqueue(&front,&rear,root->right);
            if(root->left)
            insertqueue(&front,&rear,root->left);
        }

    }
}
delete0(struct bstnode **r,struct ptr object)
{
if(object._pptr==NULL)
{
    free(object._ptr);
    *r=NULL;
}
else
{
    if(object._ptr==object._pptr->right)
    {
        free(object._ptr);
        object._pptr->right=NULL;
    }
    else
    {
        free(object._ptr);
        object._pptr->left=NULL;
    }
}
}
delete1(struct bstnode **r,struct ptr object)
{
if(object._pptr==NULL)
{
    if(object._ptr->left!=NULL)
        *r=object._ptr->left;
    else
        *r=object._ptr->right;
    free(object._ptr);
}
else
{
    if(object._ptr==object._pptr->right)
    {
        if(object._ptr->left!=NULL)
         object._pptr->right=object._ptr->left;
        else
        object._pptr->right=object._ptr->right;

           free(object._ptr);
    }
    else
    {
        if(object._ptr->left!=NULL)
        object._pptr->left=object._ptr->left;
        else
        object._pptr->left=object._ptr->right;
        free(object._ptr);
    }
}
}
struct ptr search(struct bstnode *root,int value)
{
    struct ptr object;
    object._ptr=root;
    object._pptr=NULL;
   if(root==NULL)
       {
        printf("value not found\n");
        object._ptr=NULL;
        object._pptr=NULL;
        return object;
       }
    else
    {
        while(object._ptr)
        {
          if(object._ptr->item==value)
          return object;
          else if(value<object._ptr->item)
          {
              object._pptr=object._ptr;
              object._ptr=object._ptr->left;
          }
        else
        {
            object._pptr=object._ptr;
            object._ptr=object._ptr->right;
        }
        }
        object._ptr=NULL;
        object._pptr=NULL;
        printf("value not found\n");
        return object;
}
}
deletion(struct bstnode **r,int value)
{
       struct bstnode *pred,*parpred;
       struct ptr object=search(*r,value);
       if(object._ptr!=NULL)
       {
            if(object._ptr->left==NULL&&object._ptr->right==NULL)
            delete0(r,object);
            else if(object._ptr->left==NULL||object._ptr->right==NULL)
            delete1(r,object);
           else
           {
           parpred=object._ptr;
           pred=object._ptr->left;
           while(pred->right!=NULL)
           {
              parpred=pred;
              pred=pred->right;
           }
          object._ptr->item=pred->item;
          object._ptr=pred;
          object._pptr=parpred;
          if(pred->left==NULL)
            delete0(r,object);
          else
            delete1(r,object);
            }
       }

       else
        printf("nothing to delete");
}
int menu()
{
    int choice;
    printf("\n\n1 for insertion\n");
    printf("2 for deletion\n");
    printf("3 for search\n");
    printf("4 for exit\n");
    scanf("%d",&choice);
    return choice;
}
main()
{
    struct bstnode *root=NULL;
    int value;
    while(1)
    {
        printf("PREORDER             ");
        preorder(root);
        printf("\n\nPOSTORDER            ");
        postorder(root);
        printf("\n\nINORDER              ");
        inorder(root);
        printf("\n\nLEVELORDER(L to R)   ");
        levelorder_L_to_R(root);
        printf("\n\nLEVELORDER(R to L)   ");
        levelorder_R_to_L(root);
        switch(menu())
        {
        case 1:
            scanf("%d",&value);
            insertion(&root,value);
            break;
        case 2:
            scanf("%d",&value);
            deletion(&root,value);
            break;
        case 3:
            scanf("%d",&value);
            struct ptr object=search(root,value);
            printf("\n%d",object._ptr);
            break;
        case 4:
            exit(0);
       }
       getch();
       system("cls");
    }
}
