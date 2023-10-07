//
// Created by Aditya Chauhan on 07/10/23.
//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int>ans){
    for(auto it:ans){
        cout<<it<<" ";
    }
}
int main(){
    vector<int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1,2);
    addEdge(adj, 1,3);
    addEdge(adj, 0,4);


    return 0;
}