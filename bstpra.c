# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
    int data;
    struct node*left;
    struct node*right;
}node;
node *root=NULL;

node *createnode(data)
{
    node *n = (node*)malloc(sizeof(node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;

}

node* insert(node *t,node*n)
{
    if(t==NULL){
    return n;
    }
    if(t->data > n->data){
        t->left=insert(t->left,n);
    }
    if(t->data < n->data){
        t->right=insert(t->right,n);
    }
    return t;

}

void preorder(node *r)
{
    if (r!=NULL)
    {
        printf("%d",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(node *r)
{
    if (r!=NULL)
    {
        
        postorder(r->left);
        postorder(r->right);
        printf("%d",r->data);
    }
}

void inorder(node *r)
{
    if (r!=NULL)
    {
        inorder(r->left);
        printf("%d",r->data);
        inorder(r->right);
    }
}




int main()
{
    int ch;
    int data;
    node *n=NULL;

    while(1)
    {
        printf("\n 1.Insert \n 2.Preorder\n 3.Postorder \n 4. inorder");
        printf("\n enter your choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            while(1){
                printf("enter data or -1 to stop");
                scanf("%d",&data);

                if(data==-1)
                break;

                n=createnode(data);
                root=insert(root,n);
                
            }
            break;
           
            case 2:
            preorder(root);
            break;

            case 3:
            postorder(root);
            break;

            case 4:
            inorder(root);
            break;
        }

    }
}