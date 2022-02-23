// queue
#include <stdio.h>
# include <stdlib.h>
#define SIZE 5 
int Q[SIZE];
int front = -1; 
int rear = -1; 
int element;
void enQueue()
{
    
    printf("\n Enter the element to be added into the Queue \t");
    scanf("%d", &element);
    
    if(rear == SIZE-1)
    printf("\n Overflow");
    else
    {
    if(front == -1) 
    front = 0; 
    rear=rear+1;
    Q[rear] = element;
    
    }
    
    
}

void deQueue()
{
    
    if(front == -1 || front > rear)
     printf("\n Underflow");
    else
    {
    element = Q[front++];
  
      
        if(front == rear+1)
        {
        
        front = -1;
        rear = -1;
        }
    }
    
    
}

void display()
{
   
    if(front == -1 || front > rear)
    printf("\n Queue is Empty!!");
    else
    {
        printf("\n Displaying Queue Elements:");
        for(int i = front; i<=rear; i++)
        printf("\n %d ", Q[i]);
        
       
    }
    
    
    
}

int main()
{
    int choice;
    
    while(1)
    {
        printf("\n Press 1. To Insert into Queue");
        printf("\n Press 2. To Delete from Queue");
        printf("\n Press 3. To Display Queue\t");
        printf("\n Press 4. To Exit Menu\t");
        printf("enter your choice ");
        scanf("%d", &choice);
        
       switch(choice)
       {
           case 1: enQueue();
           break;

           case 2: deQueue();
           break;

           case 3: display();
           break;

           default: exit(0);
       }
    }
    
}
