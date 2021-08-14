#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next, *prev;
};
struct node* head, *tail, *ptr;

void Insertion(){
    struct node *newa;
    newa=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to be inserted : ");
    scanf("%d",&newa->data);
    if(head==NULL){
        newa->next=NULL;
        newa->prev=NULL;
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
            newa->prev=NULL;
            head=newa;
        }
        else if(i==2){
            newa->next=NULL;
            newa->prev=tail;
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
            newa->prev=ptr;
            ptr->next=newa;
        }
    }
}

void Deletion(){
    int x;
    struct node *temp;
    printf("\nEnter element to be deleted : ");
    scanf("%d",&x);
    struct node *prev;
    ptr=head;
    if (head==NULL){
    printf("\nNo element to delete");
    }
    else{

        if(head->data==x){
            head=head->next;
            head->prev=NULL;
        }
        else if(tail->data==x){
            ptr=tail;
            tail=tail->prev;
            tail->next=NULL;
        }
        else{
            while(ptr->data!=x){
                ptr=ptr->next;
            }
            temp=ptr->prev;
            temp->next=ptr->next;
            temp=ptr->next;
            temp->prev=ptr->prev;
        }
    free(ptr);
    printf("\n%d deleted \n",x);
    }
}
void Display(){
    printf("\n");
    ptr=head;
    if (head==NULL){
        printf("\nNo element to display");
    }
    else{
        while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
        }
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
