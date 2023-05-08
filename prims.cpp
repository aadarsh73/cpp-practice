// Time complexity: O(ElogE)
// Space complexity: O(E)

#include <iostream>
#include <vector>   
#include <queue>
#include <utility>
using namespace std;

int mst(int V, vector<vector<int>> adj[]){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(V,0);
    // {wt, node}
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if (vis[node]) continue;
        vis[node] = 1;
        sum += wt;
        for (auto it: adj[node]){
            int edgeWt = it[1];
            int adjNode = it[0];
            if (!vis[adjNode]){
                pq.push({edgeWt, adjNode});
            }
        }
    }
    return sum;
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

    int sum = mst(V, graph);
    cout<<"The minimum spanning tree cost is: "<<sum<<endl;

    return 0;
}
