#include <iostream>
#include <climits>

#define V 6 // Number of cities(Edges of the graph)

// A Function to find the vertex with the minimum distance
int minDistance(int dist[], bool visited[]) 
{
    int minDist = INT_MAX, minIndex;
    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] <= minDist) 
        {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// A Function to print the shortest distances from the source to other cities
void printShortestDistances(int dist[]) 
{
    std::cout << "City\tShortest Distance from Source\n";
    for (int i = 0; i < V; ++i) 
    {
        std::cout << i << "\t" << dist[i] << "\n";
    }
}

// Dijkstra's algorithm to find the shortest path from the source city to all other cities
void dijkstra(int graph[V][V], int source) 
{
    int dist[V];     // An array to store the shortest distances from the source
    bool visited[V]; // An array to track visited cities
    
    // Initialize distances and visited array
    for (int i = 0; i < V; ++i) 
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    // Distance from source city to itself is always 0
    dist[source] = 0;
    
    // Find shortest path for all cities
    for (int count = 0; count < V - 1; ++count) 
    {
        int u = minDistance(dist, visited);
        visited[u] = true;
        
        // Update distances of adjacent cities if they are not visited and the new distance is shorter
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // Print the shortest distance from the source city
    printShortestDistances(dist);
}

int main()
{
    //The graph represented as an array
    int graph[V][V] = 
    {
        { 0, 10,  0,  0, 15,  5},
        {10,  0, 10, 30,  0,  0},
        { 0, 10,  0, 12,  5,  0},
        { 0, 30, 12,  0,  0, 20},
        {15,  0,  5,  0,  0,  0},
        { 5,  0,  0, 20,  0,  0}
    };
    
    //Print the shortest distance to other cities from all the edges as source 
    for(int i=0; i<7; i++){
        int source = i; // Choose the source city
    
        dijkstra(graph, source);
    }
    
    
    return 0;
}
