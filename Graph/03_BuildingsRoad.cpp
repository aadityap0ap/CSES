#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
    visited[node] = true;
    for(int i = 0;i<adj[node].size();i++){
        int neigh = adj[node][i];
        if(!visited[neigh]){
            dfs(neigh,adj,visited);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; //n-->no of nodes,m-->no of edges or roads at present
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(n,false);
    vector<int>rep;
    for(int i =0;i<n;i++){
        if(!visited[i]){
            rep.push_back(i);
            dfs(i,adj,visited);
        }
    }
    int newRoads = rep.size()-1;
    cout<<newRoads<<"\n";
    for(int i = 1;i<rep.size();i++){
        cout<<rep[0] + 1 <<" "<<rep[i]+1<<"\n";
    }
    return 0;
}