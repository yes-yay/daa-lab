//sri rama jayam 
//implementation of bfs in c++.
#include<iostream>
#include<queue>

using namespace std;

struct node {
    int v;
    struct node* next;
};

struct graph{
    int V;
    struct node* adjList[100];
    int visited[100];
};

struct node* createNode(int v)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->v=v;
    newNode->next=NULL;
    return newNode;
}

struct graph* createGraph(int v)
{
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->V=v;
    for(int i=0;i<v;i++)
    {
        g->adjList[i]=NULL;
    }
    return g;
}

void addEdge(struct graph* graph, int src, int dest) {

  struct node* newNode = createNode(dest);
  newNode->next = graph->adjList[src];
  graph->adjList[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjList[dest];
  graph->adjList[dest] = newNode;
}


void printGraph(struct graph* g)
{
    for(int i=0;i<g->V;i++)
    {
        struct node* temp=g->adjList[i];
        while(temp!=NULL)
        {
            cout<<temp->v<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void bfs(struct graph* g,int startVertex)
{
    queue<int> q;
    g->visited[startVertex]=1;
    q.push(startVertex);

    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        cout<<current<<" ";

        struct node* temp=g->adjList[current];
        while(temp!=NULL)
        {
            int adjVertex=temp->v;
            if(g->visited[adjVertex]==0)
            {
                g->visited[adjVertex]=1;
                q.push(adjVertex);
            }
            temp=temp->next;
        }
    }
}

int main()
{
    struct graph* g = createGraph(4); // You can change the number of vertices as needed
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);

    printGraph(g);
    
    bfs(g,0);

}








