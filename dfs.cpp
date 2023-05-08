#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &storeDfs){
    storeDfs.push_back(node);
    visited[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, visited, adj, storeDfs);
        }
    }
}

int main(){
    vector<int> graph[100];
    int V,E;
    cout << "Enter the number of vertices and edges: ";
    cin>>V>>E;
    cout << "Enter the edges: ";
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> storeDfs;
    vector<int> visited;
    for(int i=0;i<V;i++){
        visited.push_back(0);
    }
    for (int i = 0; i < V; i++)
    {
        if(!visited[i]){
            dfs(i,visited,graph, storeDfs);
        }
    }

    for(auto it: storeDfs){
        cout<<it<<" ";
    }

}