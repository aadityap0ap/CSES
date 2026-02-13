#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<char>>matrix;
vector<vector<bool>>visited;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void dfs(int x,int y){
    visited[x][y] = true;
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >=0 && ny < m){
            if(!visited[nx][ny] && matrix[nx][ny] == '.'){
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    matrix.resize(n,vector<char>(m));
    visited.resize(n,vector<bool>(m,false));
    for(int i = 0;i<n;i++){
       for(int j = 0;j<m;j++){
        cin>>matrix[i][j];
       }
    }
    int roomCount = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j] == '.' && visited[i][j] == false){
                dfs(i,j);
                roomCount++;
            }
        }
    }
    cout<<roomCount;
    return 0;
}