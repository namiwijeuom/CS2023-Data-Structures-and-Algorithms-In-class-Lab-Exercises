#include <iostream>
#include <vector>
#include <climits>

using namespace std;
//In this program, the user has the freedom to enter the number of edges and the adjacency matrix


//A function to find the vertex with the minimum key value that has not been included in the MST yet
int findMinKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int minKey = INT_MAX;
    int minIndex = -1;
  
    for (int i = 0; i < V; ++i) {
        if (!mstSet[i] && key[i] < minKey) {
            minKey = key[i];
            minIndex = i;
        }
    }
  
    return minIndex;
}

//A function to display the edges and the respective weights of the generated MST
void printMST(const vector<int>& parent, const vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n";
  
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

//A function to get the Prim's MST
void primMST(const vector<vector<int>>& graph, int V) {
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);
  
    key[0] = 0;     // Start with the first vertex
    parent[0] = -1; // First node is always the root of MST
  
    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mstSet, V);
        mstSet[u] = true;
  
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
  
    printMST(parent, graph, V);
}

int main() {
    
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
  
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
  
    primMST(graph, V);
  
    return 0;
}
