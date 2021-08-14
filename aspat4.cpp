#include<iostream>
#include<string.h>
using namespace std;

class TEST{
    public:
    TEST(string data){
        int palin=0,n;
        n=data.length();
        for(int i=0;i<n/2;i++){
            if(data[i]!=data[n-i-1]){
                palin=1;
                break;
            }
        }
        if(palin==0)
            cout<<"Palindrome";
        else
            cout<<"Not Palindrome";   
    }
    ~TEST(delete[]);
};
int main(){
    string inp;
    cin>>inp;
    TEST obj(inp);
    return 0;
}