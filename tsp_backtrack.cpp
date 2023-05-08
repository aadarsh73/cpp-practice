#include <iostream>
using namespace std;

int tsp(int mask, int pos, int n, int graph[][100]){
    int visited_all = (1<<n)-1;
    if(mask==visited_all){
        return graph[pos][0];
    }
    int ans = INT_MAX;
    for(int city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int newAns = graph[pos][city] + tsp(mask|(1<<city), city, n, graph);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main(){
    int graph[100][100];
    cout<<"Enter the number of vertices and edges: ";
    int V,E;
    cin>>V>>E;

    for (int i=0;i<E;i++){
        cout<<"Enter the edge and weight: ";
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    // int s;
    // cout<<"Enter the source: ";
    // cin>>s;

    int dis = tsp(0, 0, V, graph);
    cout<<"The minimum distance is: "<<dis<<endl;
    return 0;
}