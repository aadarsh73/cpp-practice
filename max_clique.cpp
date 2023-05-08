#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;




class graph {

    vector<vector<int>> adj;
    int v;
public:

graph(int v) {
this->v = v;
}




void add_edge(int x, int y) {
    adj[x].push_back(y);

    adj[y].push_back(x);

}




void print() {

for (int i = 0; i < v; i++) {

cout << i << "-->";
for (int j : adj[i]) {

                cout << j << " ";

            }

            cout << endl;

        }

    }




    bool isSafe(int V, vector<int>& currclique, vector<bool>& visited) {

        for (int u : currclique) {

            if (find(adj[u].begin(), adj[u].end(), V) == adj[u].end()) {

                return false;

            }

        }

        return true;

    }




    void backtrack(int u, vector<int>& clique, vector<int>& currclique, vector<bool>& visited) {

        if (u == v) {

            if (currclique.size() > clique.size()) {

                clique = currclique;

            }

            return;

        }

        if (isSafe(u, currclique, visited)) {

            currclique.push_back(u);

            visited[u] = true;

            backtrack(u + 1, clique, currclique, visited);

            currclique.pop_back();

            visited[u] = false;

        }

        backtrack(u + 1, clique, currclique, visited);

    }




    void findmaxclique() {

        vector<int> clique;

        vector<int> currclique;

        vector<bool> visited(v, false);

        backtrack(0, clique, currclique, visited);

        cout << "Max clique: ";

        for (int i : clique) {

            cout << i << " ";

        }

        cout << endl;

    }

};




int main() {

    int v = 5; // number of vertices

    graph G(v);

    G.add_edge(0, 1);

    G.add_edge(0, 2);

    G.add_edge(1, 2);

    G.add_edge(1, 3);

    G.add_edge(2, 3);

    G.add_edge(3, 4);

    G.print();

    G.findmaxclique();

    return 0;

}