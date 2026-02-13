#include<bits/stdc++.h>
using namespace std;

struct Edges{
    int a,b;
    long long x;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v,e;
    cin>>v>>e;
    vector<Edges>edges(e);
    for(int i = 0;i<e;i++){
        cin>>edges[i].a >> edges[i].b >>edges[i].x;
    }
    vector<long long>dist(v+1,LLONG_MIN);
    dist[1] = 0;
    for(int i = 1;i<=v - 1;i++){
        for(int j = 0;j<e;j++){
            int a = edges[j].a;
            int b = edges[j].b;
            long long x = edges[j].x;
            if(dist[a] != LLONG_MIN && dist[a] + x > dist[b]){
                dist[b] = dist[a] + x;
            }
            }
    }
     bool posCycle = false;
    for(int j=0;j<e;j++){
        int a = edges[j].a;
        int b = edges[j].b;
        long long x = edges[j].x;
        if(dist[a] != LLONG_MIN && dist[a] + x > dist[b]){
            posCycle = true;
            break;
        }
    }

    if(posCycle) cout << -1 << "\n";
    else cout << dist[v] << "\n";
return 0;
}