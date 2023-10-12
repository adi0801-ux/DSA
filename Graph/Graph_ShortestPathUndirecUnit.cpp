//
// Created by Aditya Chauhan on 11/10/23.
//


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfsTopo(int start, int V , vector<int>adj[], vector<int>&vis, stack<int>&st){
        vis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
                dfsTopo(it, V, adj, vis, st);
            }
        }
        st.push(start);

    }
    vector<int>shortestPath(int V, int M , int src, vector<vector<int>>&edges) {
        vector<int>adj[V];
            for(auto it:edges){
                adj[it[0]].push_back(it[1]);
            }
            vector<int>dis(V,1e9);
            dis[0]=0;
            vector<int>vis(V,0);
            stack<int>st;
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    dfsTopo(i, V, adj, vis, st);
                }
            }
            while(!st.empty()){
                int node=st.top();
                st.pop();
                for(auto it:adj[node]){
                    if(dis[node]+1<dis[it]){
                        dis[it]=dis[node]+1;
                    }
                }
            }
            return dis;

    }

    };




int main() {
    vector<vector<int>> edges= {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    int N=9,M=10;
    Solution obj;
    vector<int>a=obj.shortestPath(N,M,0, edges);
    for(auto it:a){
        cout<<it<<" ";
    }

    return 0;
}