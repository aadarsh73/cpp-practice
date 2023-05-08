#include <iostream>
#include <vector>
using namespace std;

bool cycleCheck(int a, int b, vector<int> &visited, vector<int> adj[]){
    visited[a] = 1;
    for(auto it: adj[a]){
        if(visited[it] == 0){
            if(cycleCheck(it, a, visited, adj)) return true;

        }else if(it!=b){
            return true;
        }
    }
    return false;
}

bool dfs(int V, vector<int> adj[]){
    vector<int> visited(V+1,0);

    for(int i=1;i<=V;i++){
        if(!visited[i]){
            if(cycleCheck(i, -1, visited, adj)) return true;
        }
    }
    return false;
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


    if(dfs(V ,graph)==true){
        cout<<"Cycle is present";
    }else{
        cout<<"Cycle is not present";
    }
}