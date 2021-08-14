#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node* head, *tail, *ptr;

void Insertion(){
    struct node *newa;
    newa=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to be inserted : ");
    scanf("%d",&newa->data);
    if(head==NULL){
        newa->next=NULL;
        head=newa;
        tail=newa;
    }
    else{
        printf("Select location of insertion\n1:Start\n2:End\n3:At a particular index\n");
        printf("Enter the option : ");
        int i;
        scanf("%d",&i);
        if(i==1){
            newa->next=head;
            head=newa;
        }
        else if(i==2){
            newa->next=NULL;
            tail->next=newa;
            tail=newa;
        }
        else{
            int index;
            printf("\nEnter Index : ");
            scanf("%d",&index);
            ptr=head;
            for(int j=0;j<index-1;j++){
                ptr=ptr->next;
            }
            newa->next=ptr->next;
            ptr->next=newa;
        }
    }
}

void Deletion(){
    int x;
    printf("\nEnter element to be deleted : ");
    scanf("%d",&x);
    struct node *prev;
    ptr=head;
    if(ptr->data==x)
        head=head->next;
    else{
        while(ptr->data!=x){
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=ptr->next;
    }
    free(ptr);
    printf("\n%d deleted \n",x);
}
void Display(){
    printf("\n");
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main()
{
    int n=0;
    head=NULL;
    while(n!=4){
        printf("Select operation\n1:Insertion\n2:Deletion\n3:Display\n4:Exit\n");
        printf("Enter the option : ");
        scanf("%d",&n);
        if(n==1)
            Insertion();
        else if(n==2)
            Deletion();
        else if(n==3)
            Display();
        printf("\n");
    }
    printf("Operation Exited \n");
    return 0;
}
