#include<bits/stdc++.h>
using namespace std;

int n,x;
vector<int>arr;
vector<vector<int>>dp;
int solve(int index,int reqSum){
    //pruning
    if(reqSum > x ||index == n )return 1e9;
    //basecase
    if(reqSum == x){
        return 0;
    }
    //cachecck
    if(dp[index][reqSum] != -1)return dp[index][reqSum];
    //transition
    int take = 1 + solve(index,reqSum + arr[index]);
    int nottake = solve(index+1,reqSum);

    //save and return
    return dp[index][reqSum] = min(take,nottake);


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    //n = no of coins
    //x = the desired sum of money
    arr.resize(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    dp.assign(n,vector<int>(x+1,-1));
    
    int ans = solve(0,0);
    if(ans >= 1e9)cout<<-1;
    else cout<<ans;

    return 0;
}