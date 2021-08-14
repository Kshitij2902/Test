#include<stdio.h>
#include<stdlib.h>

struct node1{
    int id;
    struct node1 * next;
}*head1, *tail1, *ptr1;

struct node2{
    char name[20];
    int sal;
    struct node2 *next, *prev;
}*head2, *tail2, *ptr2;

void Insert(int n){
    int i;
    for(i=0;i<n;i++){
    struct node1 *new1;
    new1=(struct node1*)malloc(sizeof(struct node1));
    struct node2 *new2;
    new2=(struct node2*)malloc(sizeof(struct node2));
    printf("Enter name of employee %d : ",i+1);
    scanf("%s",&new2->name);
    printf("Enter ID of employee %d : ",i+1);
    scanf("%d",&new1->id);
    printf("Enter salary of employee %d : ",i+1);
    scanf("%d",&new2->sal);
    if(head1==NULL){
        new1->next=NULL;
        new2->next=NULL;
        new2->prev=NULL;
        head1=tail1=new1;
        head2=tail2=new2;
    }
    else{
        new1->next=NULL;
        new2->next=NULL;
        new2->prev=tail2;
        tail1->next=new1;
        tail2->next=new2;
        tail1=new1;
        tail2=new2;
    }
    }
}

void Display(){
    ptr1=head1;
    ptr2=head2;
    while(ptr1!=NULL){
        printf("%s %d %d\n",ptr2->name,ptr1->id,ptr2->sal);
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
}

int main(){
    int n;
    printf("Enter number of employees : ");
    scanf("%d",&n);
    head1=NULL;
    head2=NULL;
    Insert(n);
    Display();
    return 0;
}