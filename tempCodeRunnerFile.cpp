#include<iostream>
using namespace std;
#define prime 7

int n, cur, *ht; 
bool isFull(){
    return (cur == n);
}

int hash1(int i){
    return (i % n);
}

int hash2(int i){
    return (prime - (i % prime));
}

void create(){
    ht = new int[n];
    for(int i=0; i<n; i++)  
        ht[i] = -1;
    cur = 0;
}

void Insert(int data){
    if(isFull())
        return ;
    int index = hash1(data);
    if(ht[index] == -1)
        ht[index] = data;
    else{
        int index2 = hash2(data);
        int i = 1;
        while(true){
            int newIndex = (index + i*index2) % n;
            if (ht[newIndex] == -1) {
                ht[newIndex] = data;
                break;
            }
            i++;
        }
    }
    cur++;
}

void Delete(int data){
    int index = hash1(data);
    if(ht[index] == -1)
        ht[index] = data;
    else{
        int index2 = hash2(data);
        int i = 1;
        while(true){
            int newIndex = (index + i * index2) % n;
            if (ht[newIndex] == data) {
                ht[newIndex] = -1;
                break;
            }
            i++;
        }
    }
    cur--;
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