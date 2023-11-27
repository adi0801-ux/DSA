//
// Created by Aditya Chauhan on 26/11/23.
//
#include <bits/stdc++.h>
using namespace std;
int countSubset(vector<int>&arr, int sum, int n, vector<vector<int>>&dp){
    int mod=int(1e9+7);
    dp[0][0]=1;
    int count=1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count*=2;
            dp[i+1][0]=count;
        }else{
            dp[i+1][0]=dp[i][0];
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
            dp[i][j]%=mod;
        }
    }
    return dp[n][sum]%mod;
}
int main(){
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    vector<int>arr(n);
    for(auto it:arr){
        cin>>it;
    }
    vector<vector<int>>dp(n+1, vector<int>(sum+1,0));

    cout<<countSubset(arr, sum, n, dp);
    return 0;
}