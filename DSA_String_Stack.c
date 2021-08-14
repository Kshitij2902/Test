#include<stdio.h>
int top=-1,n=4;
char stack[4][100];
void push()
{
    if (top>=n-1)
        printf("\nStack full\n");
    else
    {
        top++;
        printf("\nEnter the string : ");
        scanf("%s",&stack[top]);
        printf("\n");
    }
    main();
}
void pop()
{
    if (top==-1)
        printf("\nStack empty\n");
    else
    {
        printf("\n");
        top--;
        printf("%s removed\n\n",stack[top+1]);
    }
    main();
}
void display()
{
    if (top==-1)
        printf("\nStack empty\n");
    else
    {
        printf("\n");
        int x = top;
        while(x>=0)
        {
            printf("%s\n",stack[x]);
            x--;
        }
        printf("\n");
    }
    main();
}
void main()
{
   printf("Select Operation\n");
   printf("1 to Push\n2 to Pop\n3 to Display\n4 to End\n");
   int i;
   scanf("%d",&i);
   switch(i)
   {
    case 1:
       push();
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
}
