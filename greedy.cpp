#include <bits/stdc++.h>
using namespace std;

class edge {
public:
    int u, v, w;

    edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool compare(edge a, edge b) {
    return a.w < b.w;
}

class graph {
public:
    int v;
    vector<vector<pair<int,int>>> adj;
    vector<edge> edges;

    graph(int v) {
        this->v = v;
        adj.resize(v + 1);
    }

    void addedge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back(edge(u, v, w));
    }

    // 🔹 Prim's
    void prims() {
        int mst = 0;
        vector<bool> visited(v + 1, false);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, 1});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (visited[node]) {
                continue;
            }

            visited[node] = true;
            mst += wt;

            for (auto it : adj[node]) {
                int neigh = it.first;
                int edgew = it.second;

                if (!visited[neigh]) {
                    pq.push({edgew, neigh});
                }
            }
        }

        cout << "Prim MST cost = " << mst << endl;
    }

    // 🔹 Find Parent (DSU)
    int findparent(int node, vector<int> &parent) {
        while (node != parent[node]) {
            node = parent[node];
        }
        return node;
    }

    // 🔹 Kruskal
    void kruskals() {
        int mst = 0;

        vector<int> parent(v + 1);
        for (int i = 0; i <= v; i++) {
            parent[i] = i;
        }

        sort(edges.begin(), edges.end(), compare);

        cout << "Edges in MST:\n";

        for (auto s : edges) {
            int pu = findparent(s.u, parent);
            int pv = findparent(s.v, parent);

            if (pu != pv) {
                cout << s.u << "-" << s.v << " : " << s.w << endl;
                mst += s.w;
                parent[pu] = pv;
            }
        }

        cout << "Kruskal MST cost = " << mst << endl;
    }

    // 🔹 Dijkstra
    void dijkstra(int src) {
        vector<int> dist(v + 1, INT_MAX);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            for (auto nbr : adj[node]) {
                int next = nbr.first;
                int wt = nbr.second;

                if (dist[next] > d + wt) {
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 1; i <= v; i++) {
            cout << "Node " << i << " = " << dist[i] << endl;
        }
    }

    void display() {
        for (int i = 1; i <= v; i++) {
            cout << "Node " << i << " -> ";
            for (auto it : adj[i]) {
                cout << "(" << it.first << "," << it.second << ") ";
            }
            cout << endl;
        }
    }
};

// 🔹 Selection Sort (clean version)
void selectionSort() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        swap(a[i], a[minIndex]);
    }

    cout << "Sorted array: ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int v, e;

    cout << "Enter number of vertices: ";
    cin >> v;

    graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addedge(u, v, w);
    }

    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's MST\n";
        cout << "4. Kruskal's MST\n";
        cout << "5. Dijkstra\n";
        cout << "6. Selection Sort\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                int u, v, w;
                cout << "Enter edge (u v w): ";
                cin >> u >> v >> w;
                g.addedge(u, v, w);
                break;
            }

            case 2:
                g.display();
                break;

            case 3:
                g.prims();
                break;

            case 4:
                g.kruskals();
                break;

            case 5: {
                int src;
                cout << "Enter source: ";
                cin >> src;
                g.dijkstra(src);
                break;
            }

            case 6:
                selectionSort();
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}
