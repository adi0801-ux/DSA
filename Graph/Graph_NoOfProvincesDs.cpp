//
// Created by Aditya Chauhan on 15/10/23.
//
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUpar(int node){
        if(node==parent[node])return node;
        else{
            return parent[node]= findUpar(parent[node]);
        }
    }
    void unionByRank(int u, int v){
        int uParU= findUpar(u);
        int uParV= findUpar(v);
        if(uParU ==uParV)return;
        if(rank[uParU]<rank[uParV]){
            parent[uParU]=uParV;
        }
        else if(rank[uParU>rank[uParV]]){
            parent[uParV]=uParU;
        }
        else{
            parent[uParU]=uParV;
            rank[uParV]++;
        }

    }
    void unionBySize(int u, int v){
        int uParU= findUpar(u);
        int uParV= findUpar(v);
        if(uParU==uParV)return;
        if(size[uParU]<size[uParV]){
            parent[uParU]=uParV;
            size[uParV]+=size[uParU];
        }
        else{
            parent[uParV]=uParU;
            size[uParU]+=size[uParV];
        }
    }

};
class Solution {
public:
    int numberOfProvince(int V, vector<vector<int>> &adj) {
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt=0;
        for (int i = 0; i <V ;i++) {
            if(ds.parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> ans) {
    for (auto it: ans) {
        cout << it << " ";
    }
}

int main() {
    vector<vector<int>> adj
            {
                    {1, 0, 1},
                    {0, 1, 0},
                    {1, 0, 1}
            };

    Solution obj;
    cout<<obj.numberOfProvince(3, adj);

    return 0;
}