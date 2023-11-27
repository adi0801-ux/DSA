//
// Created by Aditya Chauhan on 26/11/23.
//
#include<bits/stdc++.h>
using namespace std;
bool subsetSum(vector<int>arr, int sum){
    // code here
    int n=arr.size();
    vector<vector<int>>dp(n+1, vector<int>(sum+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)dp[i][j]=false;
            if(j==0)dp[i][j]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<subsetSum(arr, sum);
    return 0;
}