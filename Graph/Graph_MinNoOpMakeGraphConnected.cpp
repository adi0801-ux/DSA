//
// Created by Aditya Chauhan on 15/10/23.
//
//
// Created by Aditya Chauhan on 14/10/23.
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cntExtra=0;
        DisjointSet ds(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v)){
                cntExtra++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cntC++;
            }
        }
        int ans=cntC-1;
        if(cntExtra>=ans){
            return ans;
        }
        return -1;
    }
};
int main(){
    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    Solution obj;
    int ans = obj.makeConnected(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;
}