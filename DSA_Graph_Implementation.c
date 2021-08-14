#include<stdio.h>
#include<stdlib.h>

int n,adjmat[10][10];
char ver[]={'A','B','C','D','E','F','G','H','I','J'};

void DirectedGraph(){
    int i,j;
    char adj;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Is %c adjacent to %c : ",ver[j],ver[i]);
            scanf(" %c",&adj);
            if(adj=='y')
                adjmat[i][j]=1;
            else
                adjmat[i][j]=0;
        }
    }
}
void UndirectedGraph(){
    int i,j;
    char adj;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i<=j){
                printf("Is %c adjacent to %c : ",ver[j],ver[i]);
                scanf(" %c",&adj);
                if(adj=='y')
                    adjmat[i][j]=adjmat[j][i]=1;
                else
                    adjmat[i][j]=adjmat[j][i]=0;
            }
        }
    }
}
void PrintMatrix(){
    int i,j;
    printf("\nAdjacency Matrix : \n  ");
    for(i=0;i<n;i++)
        printf("%c ",ver[i]);
    printf("\n");
    for(i=0;i<n;i++){
        printf("%c ",ver[i]);
        for(j=0;j<n;j++){
            printf("%d ",adjmat[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int x;
    printf("Select option\n1:Directed Graph\n2:Undirected Graph\nSelect option: ");
    scanf("%d",&x);
    printf("Enter no. of elements :  ");
    scanf("%d",&n);
    if(x==1)
        DirectedGraph();
    else
        UndirectedGraph();
    PrintMatrix();
    return 0;
}