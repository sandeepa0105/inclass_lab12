
#include <iostream>
using namespace std;
#include <limits.h>
  
// Number of vertices in the graph
#define V 6
  

int minDistance(int dist[], bool sptSet[])
{
  
    // Initialize min value
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}
  
void printSolution(int dist[])
{
    cout << "Vertex \t           Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

  

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 
  
    bool sptSet[V]; 

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
  
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet);
  
        // Mark the picked vertex as processed
        sptSet[u] = true;
  
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
  

            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
  
    // print the constructed distance array
    printSolution(dist);
}
  


int main()
{
  
  
    int graph[V][V] = { { 0,10,0,0,15,5 },
                        { 10,0,10,30,0,0},
                        { 0,10,0,12,5,0 },
                        { 0,30,12,0,0,20 },
                        { 15,0,5,0,0,0 },
                        { 5,0,0,20,0,0 },
                         };
  
    // Function call
    dijkstra(graph, 3);
  
    return 0;
}
  
