//
// Created by Aditya Chauhan on 11/10/23.
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfsTopo(int start, vector<pair<int, int>>adj[],vector<int>&vis, stack<int>&st){
        vis[start]=1;
        for(auto it:adj[start]){
            int v=it.first;
            if(!vis[v]) {
                dfsTopo(v, adj, vis, st);
            }
        }
        st.push(start);
    }
    vector<int>shortestPath(int V, int M , int src, vector<vector<int>>&edges){
        vector<int>vis(V, 0);
        stack<int> st;
        vector<pair<int, int>>adj[V];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v, w});
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsTopo(i, adj,vis,st);
            }
        }
        vector<int>dis(V, 1e9);
        dis[src]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int w=it.second;
                if(dis[node]+w<dis[v]){
                    dis[v]=dis[node]+w;
                }
            }
        }
        return dis;
    }

};




int main() {
    vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    int N=6,M=7;
    int V = 12;
    Solution obj;
    vector<int>a=obj.shortestPath(N,M,0, edges);
    for(auto it:a){
        cout<<it<<" ";
    }

    return 0;
}