//
// Created by Aditya Chauhan on 18/10/23.
//
#include <bits/stdc++.h>
using namespace std;




class Solution
{
public:
    void dfs(int node,vector<int>&vis, vector<vector<int>>& adj,  stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<int>&vis, vector<int> adjT[]){
        vis[node]=1;
        for(auto it:adjT[node]){
            if(!vis[it]){
                dfs2(it, vis, adjT);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj){
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        vector<int>adjT[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            auto node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs2(node, vis, adjT);
            }
        }
        return scc;
    }
};

int main() {

    int n = 5;
    vector<vector<int>>adj={
            {1, 0}, {0, 2},
            {2, 1}, {0, 3},
            {3, 4}
    };

    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}
