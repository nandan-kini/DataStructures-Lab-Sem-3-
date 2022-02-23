// circular queue

#include<stdio.h>
#define SIZE 3
void enQueue();
void deQueue();
void display();
int myCQ[SIZE]; 
int front = -1;
int rear = -1;
int element;
int main()
{
    int choice;
   
    while(1){
        printf("\n****** CIRCULAR Q MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:enQueue();
            break;
            case 2: deQueue();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("\nPlease select the correct choice!!!\n");
        }
    }
}
void enQueue()
{
    printf("\nEnter the value to be inserted:  ");
    scanf("%d",&element);
    
    
    if((front == 0 && rear == SIZE - 1) || (front == rear+1))
    printf("overflow");
    
    else
    {
       
       
        
       
        
        if(rear == SIZE-1 && front != 0) 
        rear = -1;
        
        
        myCQ[++rear] = element;
      
        
        
        if(front == -1)
        front = 0;
    }
    
    
}
void deQueue()
{
    
    
    
    if(front == -1 && rear == -1)
    printf("\nCircular Queue is Empty. Therefore deletion is not possible!\n");
    
   
    else
    {
       
        
        element = myCQ[front++];
    
        
if(front == rear + 1)
        front = rear = -1;
        
       
        
        if(front == SIZE )
            front = 0;
    }
    
  
}
void display()
{
    if(front == -1)
    printf("\nCircular Queue is Empty!\n");
    else
    {
        int i;
        printf("\nCircular Queue Elements are : \n");
        if(front <= rear)
        {
           
            for (i=front; i <= rear; i++)
            printf("%d\t",myCQ[i]);
        }
       
        else
        {
           
            
            for (i = 0;i <= rear; i++)
            printf("%d\t",myCQ[i]);
            
            for (i = front;i <= SIZE - 1; i++)
            printf("%d\t", myCQ[i]);
            
            
        }
    }
}
