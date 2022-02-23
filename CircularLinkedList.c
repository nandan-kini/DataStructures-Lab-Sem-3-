// circular linked list

# include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

node *create()
{
    node *newptr = (node *)malloc(sizeof(node));
    printf("enter the data");
    scanf("%d", &newptr->data);
    newptr->next = NULL;
}

void insertbegin()
{
    node *newptr = create();

    if(head== NULL)
    {
        head = newptr;
        tail=newptr;
        return;
    }

    newptr->next = head;
    head = newptr;
    tail->next=head;
}

void insertend()
{
    if (head == NULL)
    {
        insertbegin();
        return;
    }
    node *newptr=create();
    tail->next=newptr;
    tail=newptr;
    tail->next=head;
}

node *search(int data)
{
    node *ptr= head;
    if (ptr == NULL)
       {
        return NULL;
       }
    
    while(ptr!=NULL)
    {
     if(ptr->data == data)
            return ptr;
             ptr = ptr->next;
    }
    return NULL;
}

void insertany()
{
    if (head == NULL)
    {
        insertbegin();
        return;
    }

    int pos, datapos;

    printf("enter 0 for left and 1 for right");
    scanf("%d", &pos);
    printf("enter the adjacent position ");
    scanf("%d", &datapos);

    node *ptr = search(datapos);

    if (ptr == NULL)
    {
        printf(" element does not exist");
    }
    node *newptr = create();
    if (pos == 0)
    {
        if (ptr == head)
        {
            newptr->next = head;
            head = newptr;
            tail->next=head;
            return;
        }

        node *temp = head;
        while (temp->next != ptr)
        {
            temp = temp->next;
        }
        temp->next = newptr;
        newptr->next=ptr;
        return;
    }

    if(pos==1)
    {   
        if(ptr==tail)
        {
            insertend();
            return;
        }
        newptr->next=ptr->next;
        ptr->next=newptr;
    }
}

void delete()
{
    if(head==NULL)
    {
        printf(" there is nothing to delete");
    }

    int e;
    printf(" enter the element to delete");
    scanf("%d",&e);

    node *temp= search(e);

   

    if(temp==head)
    {
        head=head->next;
        tail->next=head;
        free(temp);
        return;
    }
    node *ptr=head;
    while(ptr->next!=temp)
    {
        ptr=ptr->next;
    }
    ptr->next=temp->next;
    free(temp);

    if(temp==tail)
    tail=ptr;
    free(temp);

}

void display()
{
    if(head==NULL)
    {
        printf(" nothing to display");
        return;
    }
        node *ptr=head;
        
      do{
        printf("%d",ptr->data);
        ptr=ptr->next;
        }while(ptr!=head);
    
}


void main()
{
    int ch;

    while(1)
    {
        printf(" \n 1.insertbegin \n 2.inserafter \n 3.insertany \n 4.delete \n 5.display \n 6.exit  ");
        printf(" enter your choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            insertbegin();
            break;

            case 2:
            insertend();
            break;

            case 3:
            insertany();
            break;

            case 4:
            delete();
            break;

            case 5:
            display();
            break;

            case 6:
            exit(0);
        }
    }
}
