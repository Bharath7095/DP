#include <bits/stdc++.h>
using namespace std;
#define ll long long
double dp[3001][3001];
double solver(ll n, ll x,vector<double>&coins){
    if(x==0) return 1.0;
    if(n==0) return 0.0;
    if(dp[n][x] != -1.0) return dp[n][x];
    return dp[n][x] = coins[n-1]*solver(n-1,x-1,coins) + (1-coins[n-1])*solver(n-1,x,coins);
}
int main(){
    ll n;
    cin >> n;
    vector<double>coins(n);
    ll x = (n+1)/2;
    for(int i = 0 ; i < n ; i++) cin >> coins[i];
    for(int i = 0 ;i <= n ;i++){
        for(int j = 0 ; j <= x ; j++){
            dp[i][j] = -1.0;
        }
    }
    double ans = solver(n,x,coins);
    cout<<setprecision(10)<<ans<<endl;
}
