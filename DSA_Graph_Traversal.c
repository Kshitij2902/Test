#include<stdio.h>

int n,adjmat[10][10],visited[10],queue[10],stack[10];
char vert[10];
int f,r,top;

void printEdges(){
    printf("\nEdges : { ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjmat[i][j]==1)
                printf("(%c,%c) ",vert[i],vert[j]);
        }
    }
    printf("}");
}

void BFS(int i){
    for(int j=0;j<n;j++){
        if((!visited[j])&&(adjmat[i][j]==1)){
            visited[j]=1;
            queue[++r]=j;
        }
    }
    if (f++==n-1)
        return;
    BFS(queue[f]);
}

void DFS(int i){
    for(int j=0;j<n;j++){
        if((!visited[j])&&(adjmat[i][j]==1)){
            visited[j]=1;
            stack[++top]=j;
            DFS(j);
        }
    }
}

int main(){
    int i,j;
    char ch = 'A';
    printf("Enter no. of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjacent Matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&adjmat[i][j]);
    }
    for(i=0;i<n;i++){
        vert[i]=ch;
        ch++;
    }
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("\nVertices : ");
    for(i=0;i<n;i++)
        printf("%c ",vert[i]);
    printEdges();

    // BFS
    r=0,f=0;
    queue[0]=0;visited[0]=1;
    BFS(0);
    printf("\n\nBFS (starting from A) : ");
    for(i=0;i<n;i++)
        printf("%c ",vert[queue[i]]);
    
    // DFS
    for(i=0;i<n;i++)
        visited[i]=0;
    top=0,visited[0]=1,stack[0]=0;
    DFS(0);
    printf("\n\nDFS (Starting from A) : ");
    for(i=0;i<n;i++)
        printf("%c ",vert[stack[i]]);
    
    printf("\n\n");
    return 0;
}