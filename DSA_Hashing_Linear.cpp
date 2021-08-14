#include<iostream>
using namespace std;

int n, *ht;
void create(){
    ht = new int[n];
    for(int i=0; i<n; i++)
        ht[i] = -1;
}
void Insert(int data){
    int index = data%n;
    if(ht[index] == -1)
        ht[index] = data;
    else{
        while(ht[index] != -1){ 
            index++;
            index %= n;
        }
        ht[index] = data;
    }
}
void Delete(int data){
    int index = data % n;
    if(ht[index] == data)
        ht[index] = -1;
    else{
        while(ht[index] != data){
            index++;
            index %= n;
        }
        ht[index] = -1;
    }
}
void Display(){
    for(int i=0; i<n; i++){
        if(ht[i] != -1)
            cout<<i<<" --> "<<ht[i]<<endl;
        else
            cout<<i<<endl;
    }
}
int main()
{
    cout<<"Enter the number of elements: ";
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