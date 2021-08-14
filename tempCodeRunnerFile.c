void printPath(int a){
    if(path[a]==-1)
        return;
    printPath(path[a]);
    printf("%c ",vert[a]);
}