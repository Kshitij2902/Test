#include<stdio.h>

int n,adjmat[10][10],visited[10];
char vert[]={'A','B','C','D','E','F','G','H','I','J'};

void SortWeights(int arr[],int a){
    for(int i=0;i<a-1;i++){
        for(int j=i+1;j<a;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i]= arr[j];
                arr[j] = temp;
            }
        }
    }
}
void KrushkalAlgo(){
    int x=0,weights[n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjmat[i][j]!=0&&i!=j){
                weights[x]=adjmat[i][j];
                x++;
            }
        }
    }
    SortWeights(weights,x);
    printf("Edges of Mininum Spanning Tree using Krushkals Algorithm : ");
    for(int i=0;i<x;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if((visited[k]==0||visited[j]==0)&&adjmat[j][k]==weights[i]){
                    printf("(%c,%c,[%d]), ",vert[j],vert[k],adjmat[j][k]);
                    visited[j]=visited[k]=1;
                }
            }
        }
    }
}

int main(){
    int i,j;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        visited[i]=0;
        for(j=0;j<n;j++)
            scanf("%d",&adjmat[i][j]);
    }
    KrushkalAlgo();
    return 0;
}