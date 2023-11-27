//
// Created by Aditya Chauhan on 26/11/23.
//
#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>arr, int sum){
    int n=arr.size();
    vector<vector<bool>>t(n+1, vector<bool>(sum+1));
    for(int i =0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=false;
            }
            if(j==0){
                t[i][j]=true;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];

    // code here
}
bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i =0;i<nums.size();i++){
        sum+=nums[i];
    }
    if(sum%2!=0)return false;
    else return isSubsetSum(nums,sum/2);
}


int main() {
    int n;
    cout<<"enter n: ";
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    cout<<canPartition(v);
    return 0;
}