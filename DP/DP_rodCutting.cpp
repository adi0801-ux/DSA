//
// Created by Aditya Chauhan on 28/11/23.
//
#include "bits/stdc++.h"
using namespace std;
int cutRod(int price[], int n) {
    vector<int>len;

    for(int i=0;i<n;i++){
        len.push_back(i+1);
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1, 0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(len[i-1]<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][n];
    //code here
}

int main(){
    cout<<"enter val of n:";
    int n;
    cin>>n;
    cout<<"enter the price:";
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<"finding result...";
//    int t[1001][1001];
//    memset(t, -1, sizeof t);
    cout<<cutRod(price, n);
    return 0;
}