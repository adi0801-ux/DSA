//
// Created by Aditya Chauhan on 14/10/23.
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

int main(){

    //CALL FOR UNION BY RANK
//    DisjointSet ds(7);
//    ds.unionByRank(1, 2);
//    ds.unionByRank(2, 3);
//    ds.unionByRank(4, 5);
//    ds.unionByRank(6, 7);
//    ds.unionByRank(5, 6);
//    // if 3 and 7 same or not
//    if (ds.findUpar(3) == ds.findUpar(7)) {
//        cout << "Same\n";
//    }
//    else cout << "Not same\n";
//
//    ds.unionByRank(3, 7);
//
//    if (ds.findUpar(3) == ds.findUpar(7)) {
//        cout << "Same\n";
//    }
//    else cout << "Not same\n";
//    return 0;

//UNION BY SIZE
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUpar(3) == ds.findUpar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUpar(3) == ds.findUpar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}