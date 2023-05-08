
// The time complexity of the algorithm is O(ElogV) where E is the number of edges and V is the number of vertices.

#include <iostream>
#include <vector>   
#include <queue>
#include <utility>
using namespace std;

vector<int> djikstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V);
    for (int i=0;i<V;i++){
        dist[i] = 1e9;
    }
    dist[S] = 0;
    pq.push({0,S});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            int edgeWt = it[1];
            int adjNode = it[0];
            if (dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> graph[100];
    int V;
    cout<<"Enter the number of vertices: ";
    cin>>V;
    cout<<"Enter the number of edges : ";
    int E;
    cin>>E;
    for (int i=0;i<E;i++){
        cout<<"Enter the edge and weight: ";
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    cout<<"Enter the source vertex: ";
    int source;
    cin>>source;
    vector<int> dist = djikstra(V, graph, source);
    for (int i=0;i<V;i++){
        cout<<"Distance from "<<source<<" to "<<i<<" is "<<dist[i]<<endl;
    }

    return 0;
}
