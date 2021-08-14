#include<stdio.h>
 
void main()
{
    int deg, n, i=1;
    float rad, sum, t;
    printf(" Enter the value for x in degree: ");
    scanf("%d",&deg);
    printf(" Enter the value for n : ");
    scanf("%d",&n);
    rad=deg*3.14159/180;
    t=rad;
    sum=rad;
    while(i<=n)
    {
        t=(t*(-1)*rad*rad)/(2*i*(2*i+1));
        sum=sum+t;
        i++;
    }
    printf(" The value of Sin(%f) = %.4f",rad,sum);
}