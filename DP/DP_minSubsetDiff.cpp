//
// Created by Aditya Chauhan on 27/11/23.
//
#include "bits/stdc++.h"
using namespace std;
bool subsetSum(int arr[],int n, int sum, vector<vector<int>>&dp){
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

// int mn = INT_MAX;
// for (int j = 0; j <= sum / 2; j++) {
//     if (t[n][j]) {
//         mn = min(mn, sum - 2 * j);
//         cout << mn << " ";
//     }
// }

int minDifference(int nums[], int n)  {
    // Your code goes here
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    vector<vector<int>>dp(n+1, vector<int>(sum+1));
    subsetSum(nums,n, sum, dp);

    int mn = INT_MAX;
    for (int j = 0; j <= sum / 2; j++) {
        if (dp[n][j]) {
            mn = min(mn, sum - 2 * j);

        }
    }
    return mn;
}
int main(){
    int n;
    cin>>n;
    int nums[n];
    for(auto it:nums){
        cin>>it;
    }
    cout<<minDifference(nums, n);
    return 0;

}