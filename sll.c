#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *head = NULL;
// int sroll;
// char []sname;
void printDetails()
{
    printf("0. Menu\n1. Search an Element\n2. Insert at Beginning\n3. Insert at End\n4. Insert Any\n5. Delete\n6. Display\nEnter your choice\n");
}
Node *searchElement(int data)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == data)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}
Node *findPrevNode(Node *h)
{
    Node *ptr = head;
    if (ptr == NULL || ptr == h)
    {
        return NULL;
    }
    while (ptr->next != h)
    {
        ptr = ptr->next;
    }
    return ptr;
}
Node *createElement(Node *h)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    printf("Enter the data\n");
    scanf("%d", &newNode->data);
    newNode->next = h;
    return newNode;
}
void *insertBegin()
{
    if (head == NULL)
    {
        head = createElement(NULL);
        return;
    }
    Node *newNode = createElement(head);
    head = newNode;
    printf("Insterd at beginning\n");
    // return head;
}
void *insertEnd()
{
    if (head == NULL)
    {
        return createElement(NULL);
    }
    Node *newNode = createElement(NULL);
    Node *ptr = findPrevNode(NULL);
    ptr->next = newNode;
    printf("Insterd at last\n");
}

void *insertAny()
{
    if (head == NULL)
    {
        insertBegin();
        return;
    }
    int pos;
    printf("Enter the position to enter: 0 for left 1 for right\n");
    scanf("%d", &pos);
    int datapos;
    printf("Enter the position to whose adjacent to insert\n");
    scanf("%d", &datapos);
    Node *ptr = searchElement(datapos);
    if (ptr == NULL)
        printf("Data does not exist");
    else if(ptr==head){
        if(pos==0)
            insertBegin();
        else if(pos==1){
            head->next = createElement(head->next);
        }
    }
    else
    {
        if (head->next == NULL)
        {
            if (pos == 0)
                insertBegin();
            else if (pos == 1)
                insertEnd();
            else
                printf("Enter 0 or 1 for left or right");
        }
        else
        {
            if(pos==0){
                Node *pptr = findPrevNode(ptr);
                pptr->next = createElement(ptr);
            }
            else if(pos==1){
                ptr->next = createElement(ptr->next);
            }
        }
    }
}
void *deleteAny(){
    if(head==NULL){
        printf("No data to delete");
        return;
    }
    int data;
    printf("Enter data to delete\n");
    scanf("%d",&data);
    Node *temp = searchElement(data);
    if(temp==NULL){
        printf("Element does not exists");
        return;
    }
    Node *ptr = head;
    if(ptr->data==data){
        head = head->next;
        free(ptr);
        return;
    }
    ptr = findPrevNode(temp);
    ptr->next = temp->next;
    free(temp);
    
}

void display()
{
    if (head == NULL)
    {
        printf("NOTHING TO DISPLAY");
        return;
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void main(void)
{
    int ch;
    int ele;
    while (1)
    {
        printDetails();
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            printDetails();
            break;
        case 1:

            printf("Enter the data to search\n");
            scanf("%d", &ele);
            Node *a = searchElement(ele);
            if (a == NULL)
                printf("Element not present");
            else
                printf("Element present");
            break;
        case 2:
            insertBegin();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            insertAny();
            break;
        case 5:
            deleteAny();
            break;
        case 6:
            display();
            printf("\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid input");
        }
    }
}