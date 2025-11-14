#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        // Thêm v vào danh sách kề của u
        adj[u].push_back(v);
        // Vì là đồ thị vô hướng, thêm u vào danh sách kề của v
        adj[v].push_back(u);
    }

    void DFS(int startVertex) {
        cout << "Ket qua duyet DFS :" << endl;
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(startVertex);

        while (!s.empty()) {

            int v = s.top();
            s.pop();

            if (!visited[v]) {
                visited[v] = true;
                cout << v << " ";
                for (int neighbor : adj[v]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }

    void BFS(int startVertex) {
        cout << "Ket qua duyet BFS: "<< endl;

        vector<bool> visited(V, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (q.empty() == false) {
            int v = q.front();
            cout << v << " ";
            q.pop();

            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};


int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.DFS(0);

    cout << "--------------------" << endl;

    g.BFS(0);
    return 0;
}
