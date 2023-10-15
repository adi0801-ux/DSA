//
// Created by Aditya Chauhan on 15/10/23.
//
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;
public:
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
class Solution{
public:
    int kruskal(int V , vector<vector<int>>adj[]){
        vector<pair<int, pair<int, int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int node=i;
                int wt=it[1];
                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt=0;
        for(auto it:edges){
            int wt=it.first;
            int node=it.second.first;
            int adjNode=it.second.second;
            if(ds.findUpar(node)!=ds.findUpar(adjNode)){
                mstWt+=wt;
                ds.unionBySize(node, adjNode);
            }
        }
        return mstWt;
    }
};

int main(){

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int mstWt = obj.kruskal(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}