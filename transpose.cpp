#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> graph[100];
    cout<<"Enter the number of vertices and edges: ";
    int V,E;
    cin>>V>>E;
    cout<<"Enter the edges: ";
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    

}
