//
// Created by Aditya Chauhan on 26/11/23.
//
#include<bits/stdc++.h>
using namespace std;
int knapsack(int n , int w, vector<int>&wt, vector<int>&val, vector<vector<int>>&t){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(wt[n-1]<=j){
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<"ans is: ";
    return t[n][w];
}
int main(){
    cout<<"enter val of n";
    int n;
    cin>>n;
    cout<<"enter val of w";
    int w;
    cin>>w;
    cout<<"enter the val";
    vector<int>val(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    cout<<"enter the wts";
    vector<int>wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<"finding result...";
//    int t[1001][1001];
//    memset(t, -1, sizeof t);
    vector<vector<int>>t(n+1, vector<int>(w+1, 0));
    cout<<knapsack(n, w, wt,val, t);
    return 0;
}