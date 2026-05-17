#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {

    int u, v, wt;
};

bool cmp(Edge a, Edge b) {

    return a.wt < b.wt;
}

int findParent(int v, vector<int>& parent) {

    if(parent[v] == v)
        return v;

    return parent[v] =
           findParent(parent[v], parent);
}

void kruskal(vector<Edge>& edges,
             int V) {

    sort(edges.begin(),
         edges.end(),
         cmp);

    vector<int> parent(V);

    for(int i = 0; i < V; i++)
        parent[i] = i;

    int total = 0;

    cout << "\nEdges in MST:\n";

    for(auto e : edges) {

        int pu = findParent(e.u, parent);

        int pv = findParent(e.v, parent);

        if(pu != pv) {

            cout << e.u
                 << " - "
                 << e.v
                 << " : "
                 << e.wt
                 << endl;

            total += e.wt;

            parent[pu] = pv;
        }
    }

    cout << "\nTotal Weight = "
         << total << endl;
}

int main() {

    int V, E;

    cout << "Enter vertices and edges: ";

    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v wt):\n";

    for(int i = 0; i < E; i++) {

        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].wt;
    }

    kruskal(edges, V);

    return 0;
}