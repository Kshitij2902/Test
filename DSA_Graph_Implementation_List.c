#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
}*Node;

struct graph {
  int num;
  struct node** adjLists;
}*Graph;

struct node* createNode(int a) {
  Node = (struct node *)malloc(sizeof(struct node));
  Node->vertex = a;
  Node->next = NULL;
  return Node;
}

struct graph* createGraph(int v) {
  Graph = (struct graph *)malloc(sizeof(struct graph));
  Graph->num = v;
  Graph->adjLists = malloc(v * sizeof(struct node*));
  for(int i=0; i<v; i++)
    Graph->adjLists[i] = NULL;
  return Graph;
}

void addEdge(struct graph* g, int s, int d) {
  Node = createNode(d);
  Node->next = g->adjLists[s];
  g->adjLists[s] = Node;
}

void PrintGraph(struct graph* g) {
  int v;
  for(v=0; v<(g->num); v++) {
    struct node* temp = g->adjLists[v];
    printf("\n  Node %d : %d ", v+1,v+1);
    while (temp) {
      printf("-> %d ", temp->vertex + 1);
      temp = temp->next;
    }
    printf("\n");
  }
}

void DirectedGraph(){
  int n,i,j;
  char ch;
  printf("\nEnter the number of vertices: ");
  scanf("%d",&n);
  struct graph *g = createGraph(n);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      printf("Is Node %d adjacent to Node %d : " , j+1 , i+1);
      scanf(" %c" , &ch);
      if(ch == 'y')
        addEdge(g , i , j);
    }
  }
  PrintGraph(g);
}

void UndirectedGraph()
{
  int n,i,j;
  char ch;
  printf("\nEnter the number of vertices: ");
  scanf("%d" , &n);
  struct graph *g = createGraph(n);
  for(i=0; i<n; i++){
    for(j=i; j<n; j++){
      printf("Is Node %d adjacent to Node %d : " , j+1 , i+1);
      scanf(" %c" , &ch);
      if(ch == 'y'){
        addEdge(g , i , j);
        addEdge(g , j , i);
      }
    }
  }
  PrintGraph(g);
}
int main(){
    int x;
    printf("Select option\n1:Directed Graph\n2:Undirected Graph\nSelect option: ");
    scanf("%d",&x);
    if(x==1)
        DirectedGraph();
    else
        UndirectedGraph();
    return 0;
}
