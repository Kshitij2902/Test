#include<stdio.h>
#include<stdlib.h>

int n;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int a){
    struct node* newa;
    newa = (struct node*)malloc(sizeof(struct node));
    newa->data=a;
    newa->left=NULL;
    newa->right=NULL;
    return newa;
}

struct node* Insertion (int i, struct node* head,int a[]){
    if(i<n){
        head = create(a[i]);
        head->left=Insertion(2*i+1,head->left,a);
        head->right=Insertion(2*i+2,head->right,a);
    }
    return head;
}

void Preorder(struct node* head){
    if(head!=NULL){
        printf("%d ",head->data);
        Preorder(head->left);
        Preorder(head->right);
    }
}

void Inorder(struct node* head){
    if(head!=NULL){
        Inorder(head->left);
        printf("%d ",head->data);
        Inorder(head->right);
    }
}

void Postorder(struct node* head){
    if(head!=NULL){
        Postorder(head->left);
        Postorder(head->right);
        printf("%d ",head->data);
    }
}

int main(){
    int i;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct node* root = Insertion(0,root,arr);

    printf("\nPreorder : ");
    Preorder(root);

    printf("\n\nInorder : ");
    Inorder(root);

    printf("\n\nPostorder : ");
    Postorder(root);
    return 0;
}