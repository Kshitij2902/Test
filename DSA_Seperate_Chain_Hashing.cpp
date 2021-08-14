#include <iostream>
using namespace std;

int n,**ht,k[10];
void create(){
    ht = new int *[n];
    for(int i=0; i<n; i++)
        ht[i] = new int[10];
    for(int i=0; i<n; i++)
        for(int j=0; j<10; j++)
            ht[i][j] = -1;
}

void Insert(int data){
    int index = data % n;
    if(ht[index][k[index]] == -1){
        ht[index][k[index]]=data;
    }
    else{
        k[index] = k[index] + 1;
        ht[index][k[index]] = data;
    }
}

void Delete(int data){
    int a,i;
    a = data % n;
    for(i=0; i<=k[a]; i++ ){
        if(ht[a][i] == data){
            ht[a][i] = -1;
        }
    }
}

void Display()
{
    for(int i=0; i<n; i++){
        cout<<i;
        for(int j=0; j<=k[i]; j++){
            if(ht[i][j]==-1){
                continue;
            }
            cout<<"--->"<<ht[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    cout<<"Enter the size of hash table: ";
    cin>>n;
    create();
    int x=0,a;
    while(x!=4){
        cout<<"Select option\n1.Insert \n2.Delete \n3.Display \n4.Exit"<<endl;
        cout<<"Enter option : ";
        cin>>x;
        if(x==1){
            cout<<"Enter value to be inserted : ";
            cin>>x;
            Insert(x);
        }
        else if(x==2){
            cout<<"Enter value to be deleted : ";
            cin>>x;
            Delete(x);
        }
        else if(x==3)
            Display();
    };
    cout<<"EXIT"<<endl;
    return 0;
}