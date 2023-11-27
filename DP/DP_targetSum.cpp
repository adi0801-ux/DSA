#include<bits/stdc++.h>
using namespace std;
int mod=(int)(1e9+7);

int perfectSum(vector<int> &arr, int n, int target){
    // Your code goes here
    vector<vector<int>>dp(n+1, vector<int>(target+1,0));
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
        for(int j=1;j<target+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
            dp[i][j]%=mod;
        }
    }
    return dp[n][target]%mod;
}

int findTargetSumWays(vector<int>& nums, int target) {
    target=abs(target);
    int n=nums.size();
    int sum=0;
    for(auto it:nums){
        sum+=it;
    }
    int x =sum+target;
    int z=(sum+target)/2;
    if(sum<target||(x)%2!=0)
        return 0;
    return perfectSum(nums, n, z);
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int target;
    cin>>target;
    return findTargetSumWays(v, target);
}