//
// Created by Aditya Chauhan on 28/11/23.
//
#include "bits/stdc++.h"
using namespace std;

int coinChange2(int amount, vector<int>& coins) {
    int n =coins.size();
    vector<vector<int>> v(n+1,vector<int>(amount+1));
    for(int i =0;i<=n;i++){
        for(int j =0; j<=amount;j++){
            if(i==0){
                v[i][j]=0;
            }
            else if(j==0){
                v[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1; j<=amount;j++){
            if(coins[i-1]<=j){
                v[i][j]=(v[i][j-coins[i-1]]+v[i-1][j]);
            }
            else if(coins[i-1]>j){
                v[i][j]=v[i-1][j];
            }
        }
    }
    return v[n][amount];
}

int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(auto  it:coins){
        cin>>it;
    }
    int amount;
    cin>>amount;
    coinChange2(amount, coins);
    return 0;

}