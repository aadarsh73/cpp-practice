#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}

void topologicalSort(int V, vector<int> adj[], vector<int> &ans){
    int vis[V] = {0};
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

}

int main(){
    int V;
    cout<<"Enter the number of vertices: ";
    cin>>V;
    vector<int> adj[V];
    cout<<"Enter the number of edges: ";
    int E;
    cin>>E;
    for(int i=0;i<E;i++){
        cout<<"Enter the edge: ";
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> ans;
    topologicalSort(V, adj, ans);
    cout<<"The topological sort is: ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}