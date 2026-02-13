#include<bits/stdc++.h>
using namespace std;

bool bfs(int start,vector<vector<int>>&adj,vector<int>&team){
    queue<int>q;
    q.push(start);
    team[start] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
    for(int i = 0;i<adj[node].size();i++){
        int neigh = adj[node][i];
        if(team[neigh] == -1){
            team[neigh] = 3 - team[node];
            q.push(neigh);
        }
        else if(team[neigh] == team[node]){
            return false;
        }
    }
}
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>team(n,-1);
    for(int i= 0;i<n;i++){
        if(team[i] == -1){
            if(!bfs(i,adj,team)){
                cout<<"IMPOSSIBLE"<<"\n";
                return 0;
            }
        }
    }
        for(int i = 0;i<team.size();i++){
            cout<<team[i]<<" ";
        }
        return 0;
}