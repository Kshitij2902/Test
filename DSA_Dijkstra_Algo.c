#include<stdio.h>
#include<limits.h>

int n,adjmat[10][10],dist[10],visited[10],path[10];
char vert[10];

void printEdges(){
    printf("\nEdges : { ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjmat[i][j]!=0)
                printf("(%c,%c,%d) ",vert[i],vert[j],adjmat[i][j]);
        }
    }
    printf("}");
}
int getIndex(char a){
    int i=0;
    while(vert[i]!=a)
        i++;
    return i;
}
int minDist(){
    int min=INT_MAX,next=-1,i;
    for(i=0;i<n;i++){
        if((!visited[i])&&(dist[i]<min)){
            next=i;
            min=dist[i];
        }
    }
    return next;
}
void DijkstraAlgo(int a){
    visited[a]=1;
    int i=a,j;
    for(j=0;j<n;j++){
        if((!visited[j])&&(adjmat[i][j]!=0)){
            if(dist[j]>dist[i]+adjmat[i][j]){
                path[j]=i;
                dist[j]=dist[i]+adjmat[i][j];
            }
        }
    }
    int next=minDist();
    if(next<0)
        return;
    DijkstraAlgo(next);
}
void printPath(int a){
    if(path[a]==-1)
        return;
    printPath(path[a]);
    printf("%c ",vert[a]);
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
    
    char start,end;
    printf("\n\nDijkstra Algorithm\nEnter start point : ");
    scanf(" %c",&start);
    printf("Enter end point : ");
    scanf(" %c",&end);
    int startIndex,endIndex;
    startIndex=getIndex(start);
    endIndex=getIndex(end);
    path[startIndex]=-1;
    for(i=0;i<n;i++){
        if (i==startIndex)
            dist[i]=0;
        else
            dist[i]=INT_MAX;
    }
    DijkstraAlgo(startIndex);
    printf("Shortest distance between %c and %c is %d",start,end,dist[endIndex]);
    printf("\nPath : %c ",start);
    printPath(endIndex);
    return 0;
}