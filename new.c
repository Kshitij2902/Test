#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
}*head1,*head2,*ptr;

struct node * create(int a){
    struct node * newa;
    newa=(struct node *)malloc(sizeof(struct node));
    newa->data=a;
    newa->next=NULL;
    return newa;
}

void insert(struct node*root,int a){
    ptr=root;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=create(a);
}
void print(struct node * root){
    ptr=root;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void viewBothArrays(){
    printf("Array X : ");
    print(head1);
    printf("\nArray Y : ");
    print(head2);
}
void main(){
    int n,m,i,j,data;
    printf("Enter number of elements in array X : ");
    scanf("%d",&n);
    printf("Enter number of elements in array Y : ");
    scanf("%d",&m);
    for(i=0;i<n;i++){
        printf("Enter element %d of array X : ",i+1);
        scanf("%d",&data);
        if(i==0)
            head1=create(data);
        else
            insert(head1,data);
    }
    for(j=0;j<m;j++){
        printf("Enter element %d of array Y : ",j+1);
        scanf("%d",&data);
        if(j==0)
            head2=create(data);
        else
            insert(head2,data);
    }
    viewBothArrays();
}