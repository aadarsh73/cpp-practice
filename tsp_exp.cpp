#include <iostream>
using namespace std;

int dp[100][100];

int tsp(int mask, int pos, int n, int graph[][100], int dp[][100]){
    int vis_all = (1<<n)-1;
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    if (mask==vis_all){
        return graph[pos][0];
    }
    int ans = INT_MAX;
    for (int city=0; city<n;city++){
        if((mask&(1<<city))==0){
            int newAns = graph[pos][city] + tsp(mask|(1<<city), city, n, graph, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
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

    
    for (int i=0;i<(1<<V);i++){
        for (int j=0;j<V;j++){
            dp[i][j] = -1;
        }
    }

    int distance = tsp(0,0,V,graph, dp);
    cout<<"The minimum distance is: "<<distance<<endl;
}