#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
}*root,*ptr;
struct node* create(int a)
{
    struct node* newa;
    newa = (struct node*)malloc(sizeof(struct node));
    newa->data=a;
    newa->left=NULL;
    newa->right=NULL;
    return(newa);
}
void insert(struct node* nod,int a)
{
    ptr=nod;
    struct node* prev;
    while(ptr!=NULL)
    {
        prev=ptr;
        if(ptr->data>a)
        {
            ptr=ptr->left;
            if(ptr==NULL)
                prev->left=create(a);
        }
        else
        {
            ptr=ptr->right;
            if(ptr==NULL)
                prev->right=create(a);
        }
    }
}
int search(struct node* root,int a)
{
    struct node* ptr=root;
    while(ptr!=NULL)
    {
        if(a==ptr->data)
            return 1;
        else if(a<ptr->data)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    return 0;
}
void Inorder(struct node* node)
{
    if(node!=NULL)
    {
        Inorder(node->left);
        printf("%d ",node->data);
        Inorder(node->right);
    }
}
struct node* min(struct node* nod)
{
    while(nod->left!=NULL)
        nod=nod->left;
    return nod;
}
void deletion(struct node* nod,int a)
{
    ptr=nod;
    struct node* prev;
    if(search(nod,a))
    {
        while(ptr->data!=a)
        {
            prev=ptr;
            if(ptr->data>a)
                ptr=ptr->left;
            else
                ptr=ptr->right;

        }
        if((ptr->right==NULL)&&(ptr->left==NULL))
        {
            if(prev->left==ptr)
            {
                prev->left=NULL;
                free(ptr);
            }
            else
            {
                prev->right=NULL;
                free(ptr);
            }

        }
        else if(ptr->left==NULL)
        {
            struct node* next=ptr->right;
            if(prev->left==ptr)
            {
                prev->left=next;
                free(ptr);
            }
            else
            {
                prev->right=next;
                free(ptr);
            }
        }
        else if(ptr->right==NULL)
        {
            struct node* next=ptr->left;
            if(prev->right==ptr)
            {
                prev->right=next;
                free(ptr);
            }
            else
            {
                prev->left=next;
                free(ptr);
            }
        }
        else
        {
            struct node* mini = min(ptr->right);
            ptr->data=mini->data;
            while(ptr!=mini)
            {
                prev=ptr;
                if(ptr->data>mini->data)
                {
                    ptr=ptr->left;
                    if(ptr==mini)
                        prev->left=NULL;
                }
                else
                {
                    ptr=ptr->right;
                    if(ptr==mini)
                        prev->right=NULL;
                    free(mini);
                }
            }
        }
        printf("\nElement %d removed.\n\n",a);
    }
    else
        printf("\nElement to be deleted does not exist.\n\n");
}
int main()
{
    int n=0,i,x=0,flag=0,d;
    while(flag==0)
    {
        printf("1: Insertion\n2: Deletion\n3: View(Inorder)\n4: Search\n5: Exit\n");
        printf("Enter an option: ");
        scanf("%d",&x);
        if(x==1)
        {
            printf("\nEnter element to be inserted : ");
            scanf("%d",&i);
            if(n==0)
            {
                root=create(i);
                n++;
                printf("\n");
            }
            else
            {
                insert(root,i);
                printf("\n");
            }
        }
        else if(x==2)
        {
            printf("\nEnter the element to be deleted :");
            scanf("%d",&d);
            deletion(root,d);
        }
        else if(x==3)
        {
            printf("\nInorder Traversal : ");
            Inorder(root);
            printf("\n\n");
        }
        else if(x==4)
        {
            printf("\nElement to be searched : ");
            scanf("%d",&x);
            if(search(root,x))
                printf("Element found.");
            else
                printf("Element not found.");
            printf("\n\n");
        }
        else if(x==5)
            flag=1;
        else
            printf("\nInvalid Input\n\n");
    }
    printf("\n-------Program Ended-------\n");
    return 0;
}
