#include<stdio.h>
#include<string.h>

int adjmat[20][20],visited[20],stack[20],n=20;
int top;
char city[20][20]={"Arad","Zerind","Oradea","Timisoora","Luguj","Dorbeta","Mehadia","Sibiu","Rimnieuvilea","Craiova","Fagaras","Pitesti","Becharest","Giurgu","Neamt","Iasi","Vasului","Urzieni","Hirsova","Eforie"};

int min(int a){
    int m=100000,ind=-1;
    for(int j=0;j<n;j++){
        if(m>adjmat[a][j]&&adjmat[a][j]!=0&&visited[j]==0){
            m=adjmat[a][j];
            ind=j;
        }
    }
    return ind;
}
void DFS(int i){
    while(min(i)>-1){
        visited[min(i)]=1;
        stack[++top]=min(i);
        DFS(min(i));
    }
}
int main(){
    int i,j;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                adjmat[i][j]=adjmat[j][i]=0;
            else{
                if(i<j){
                printf("Enter the dist betweeen %s and %s : ",city[i],city[j]);
                scanf("%d",&adjmat[i][j]);
                adjmat[j][i]=adjmat[i][j];
                }

            }
        }
    }
    for(i=0;i<n;i++)
        visited[i]=0;
    top=-1;
    DFS(0);
    for(i=0;i<n;i++){
        printf("\n%s",city[stack[i]]);
    }
}