#include<stdio.h>
int main()
{
    int cost=0,i,n,flag=1;
    scanf("%d",&n);
    int a[100],b[100];
    if(n>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            scanf("%d",&b[i]);
            if(a[i]>0 && b[i]>0)
                cost=cost+(a[i]*b[i]);
            else
            {
                printf("Invalid Input");
                flag=0;
            }
        }

    }
    else
    {
        printf("Invalid Input");
        flag=0;
    }
    if(flag==1)
        printf("%d", cost);
    return 0;
}
