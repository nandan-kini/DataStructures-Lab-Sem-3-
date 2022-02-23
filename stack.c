// stack

#include <stdio.h>
#include <stdlib.h>
#define stack_size 5
int top, s[10],item;

void push()
{
    if (top == stack_size - 1)
    {
        printf("stack overflow \n");
        return;
    } else 
    
    s[++top] = item;
}

int pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
        return s[top--];
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("stack underflow");
        return;
    }
    else

        printf("contents of stack are \n ");
    for (i = 0; i <= top; i++)

    {
        printf("%d", s[i]);
    }
}

void main()
{
    int item_del, choice;
    top = -1;
    while (1)
    {
        printf("1. push \n");
        printf("2. pop \n");

        printf("3. display \n");
        printf("4. exit \n");
        printf("enter your choice \n");
        scanf("%d",&choice);
        
        switch(choice)
        {
        case 1:
            

            printf("enter item to be inserted \n");
            scanf("%d",&item);
            push();
            break;

        case 2:
            item_del = pop();
            if (item_del == -1){

                printf("stack is empty");

             } else{

                printf("item deleted = %d \n", item_del);
        }
            break;

        case 3:
            display();
            break;

        default:
            exit(0);
        }
    }
}