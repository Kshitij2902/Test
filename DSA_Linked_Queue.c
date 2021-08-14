#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top,*head=NULL,*temp;
void push(int x)
{
    struct Node *newa;
    newa = (struct Node*)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        newa->data=x;
        newa->next=NULL;
        head=newa;
        top=head;
    }
    else
    {
        newa->data=x;
        newa->next=NULL;
        top->next=newa;
        top=newa;
    }
}
void pop()
{
    if(head==NULL)
        printf("Queue is empty\n");
    else
    {
        temp=head;
        head=head->next;
        printf("%d removed\n",temp->data);
        free(temp);
    }
}
void display()
{
    temp=head;
    if(head==NULL)
        printf("Queue is empty");
    else
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    printf("\n");
}
void main()
{
   printf("Select Operation\n");
   printf("1 to Push\n2 to Pop\n3 to Display\n4 to End\n");
   int i,n;
   scanf("%d",&i);
   switch(i)
   {
    case 1:
       printf("Enter data : ");
       scanf("%d",&n);
       push(n);
       break;
   case 2:
        pop();
        break;
   case 3:
        display();
        break;
   case 4:
        break;
   default:
        printf("Invalid Output");
   }
   if (i==4)
   printf("Exited");
   else
    main();
}
