#include<stdio.h>
int main(){
   int x=0;
   while(x!=4){
        printf("Select Operation\n");
        printf("1:New site\n2:Forward site\n3:Backward site\n4:Exit\nEnter ur : ");
        scanf("%d",&x);
        if(x==1)
            printf("Push\n");
        else if(x==2)
            printf("forward\n");
        else if(x==3)
            printf("backward\n");
    }
    if (x==4)
        printf("Exited");
   
    return 0;
}
