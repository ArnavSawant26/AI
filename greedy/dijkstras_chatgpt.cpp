// Applications
// Dijkstra’s Algorithm underlies numerous practical systems. It is used in Google
// Maps-style navigation, Internet Engineering Task Force routing protocols such as
// OSPF, logistics optimization, and network flow analysis. It also serves as the
// conceptual basis for algorithms like A search algorithm* and variants used in
// AI pathfinding

// How it works
// Initialize all node distances to infinity except the source (0).

// Use a priority queue (often a min-heap) to select the node with the smallest distance.

// Update neighboring nodes’ tentative distances via edge relaxation.

// Mark the current node as “visited” once processed.

// Continue until the queue is empty or all nodes are finalized.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minDistance(vector<int>& dist, vector<bool>& visited, int V)
{
    int min = INT_MAX;
    int index;

    for(int i=0;i<V;i++)
    {
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(vector<vector<int>>& graph, int src, int V)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for(int count=0; count<V-1; count++)
    {
        int u = minDistance(dist, visited, V);

        visited[u] = true;

        for(int v=0; v<V; v++)
        {
            if(!visited[v] &&
               graph[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout<<"Vertex\tDistance from Source\n";

    for(int i=0;i<V;i++)
    {
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}

int main()
{
    int V;

    cout<<"Enter number of vertices: ";
    cin>>V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout<<"Enter adjacency matrix:\n";

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }

    int src;

    cout<<"Enter source vertex: ";
    cin>>src;

    dijkstra(graph, src, V);

    return 0;
}