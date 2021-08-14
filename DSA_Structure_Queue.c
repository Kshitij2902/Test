#include<stdio.h>
#include<string.h>
int f=0,r=-1,n=4;
struct
{
    char name[10];
    char order[10];
    int bill;
}queue[4];
void enque()
{
    if (r>=n-1)
        printf("\nQueue is Full\n\n");
    else
    {
        r++;
        printf("\nEnter the name : ");
        scanf("%s",&queue[r].name);
        printf("\nEnter marks : ");
        scanf("%d",&queue[r].marks);
        printf("\n");
    }
}
void deque()
{
    if (r==-1)
        printf("Queue is empty\n");
    else
    {
        r--;
        printf("\n%s %d removed\n\n",queue[f].name,queue[f].marks);
        for (int i=0;i<r+1;i++)
        {
            strcpy(queue[i].name,queue[i+1].name);
            queue[i].marks=queue[i+1].marks;
        }
    }
}
void display()
{
    printf("\n");
    if (r==-1)
        printf("Queue is empty");
    for (int i=0;i<r+1;i++)
        printf("%s %d ",queue[i].name,queue[i].marks);
    printf("\n\n");
}
void main()
{
    int x;
    printf("Enter Operation :\n");
    printf("1: New costumer\n2: Place order\n3: View queue\n4 to Exit\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        enque();
        break;
    case 2:
        deque();
        break;
    case 3:
        display();
        break;
    case 4:
        break;
    default:
        printf("Invalid Input\n");
    }
    if (x==4)
        printf("\nExited");
    else
        main();
}
