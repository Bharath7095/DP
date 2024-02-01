#include <bits/stdc++.h>
using namespace std;
int dp[100001][4];
int fun(int ind,vector<vector<int>>&ans,int n,int prev){
    if(ind>n-1) return 0;
    if(prev!=-1 and dp[ind][prev]!=-1) return dp[ind][prev];
    int ma=0;
    for(int i=0;i<3;i++){
        if(i!=prev){
            ma=max(ma,(ans[ind][i]+fun(ind+1,ans,n,i)));
        }
    }
    return dp[ind][prev]=ma;
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<vector<int>>ans;
	for(int i=0;i<n;i++){
	    vector<int>vt(3);
	    for(int j=0;j<3;j++) cin>>vt[j];
	    ans.push_back(vt);
	}
	memset(dp,-1,sizeof(dp));
	cout<<fun(0,ans,n,-1);
	
}
