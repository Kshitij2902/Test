#include<stdio.h>
struct quiz{
    char name[10],reg[10];
    int mark;
};
int main(){
    int i,n,min=0,max=0;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    struct quiz std[n];
    for(i=0;i<n;i++){
        printf("Enter data of student %d\n",i+1);
        scanf("%s%s%d",std[i].reg,std[i].name,&std[i].mark);
    }
    for(i=1;i<n;i++){
        if(std[min].mark>std[i].mark)
            min=i;
        if(std[max].mark<std[i].mark)
            max=i;
    }
    printf("MAX = %s %s %d\n",std[max].reg,std[max].name,std[max].mark);
    printf("MIN = %s %s %d\n",std[min].reg,std[min].name,std[min].mark);
    return 0;
}