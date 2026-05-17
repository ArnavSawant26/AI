#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minKey(vector<int>& key,
           vector<bool>& mst,
           int V) {

    int min = INT_MAX;
    int index;

    for(int i = 0; i < V; i++) {

        if(!mst[i] && key[i] < min) {

            min = key[i];
            index = i;
        }
    }

    return index;
}

void primMST(vector<vector<int>>& graph, int V) {

    vector<int> parent(V);

    vector<int> key(V, INT_MAX);

    vector<bool> mst(V, false);

    key[0] = 0;

    parent[0] = -1;

    for(int count = 0; count < V - 1; count++) {

        int u = minKey(key, mst, V);

        mst[u] = true;

        for(int v = 0; v < V; v++) {

            if(graph[u][v] &&
               !mst[v] &&
               graph[u][v] < key[v]) {

                parent[v] = u;

                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;

    cout << "\nEdge \tWeight\n";

    for(int i = 1; i < V; i++) {

        cout << parent[i]
             << " - "
             << i
             << "\t"
             << graph[i][parent[i]]
             << endl;

        total += graph[i][parent[i]];
    }

    cout << "\nTotal Weight = "
         << total << endl;
}

int main() {

    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < V; i++) {

        for(int j = 0; j < V; j++) {

            cin >> graph[i][j];
        }
    }

    primMST(graph, V);

    return 0;
}