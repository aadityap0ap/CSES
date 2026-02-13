#include<bits/stdc++.h>
using namespace std;

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
    vector<int>parent(n,-1);
    vector<bool>visited(n,false);
    queue<int>q;
    q.push(0);
    visited[0] = true;
    bool found = false;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == n-1){
            found = true;
            break;
        }
        for(int i = 0;i<adj[node].size();i++){
            int neigh = adj[node][i];
            if(!visited[neigh]){
                visited[neigh] = true;
                parent[neigh] = node;
                q.push(neigh);
            }
        }
    }
    if(!found){
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
    vector<int>path;
    int curr = n - 1;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(begin(path),end(path));
    cout<<path.size()<<"\n";
    for(int i = 0;i<path.size();i++){
        cout<<path[i] + 1<<" ";
    }
return 0;
}