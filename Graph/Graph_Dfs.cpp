//
// Created by Aditya Chauhan on 07/10/23.
//
#include<bits/stdc++.h>
using namespace std;
    //
// Created by Aditya Chauhan on 07/10/23.
//
#include<iostream>
#include<bits/stdc++.h>
    using namespace std;
    class Solution{
    public:
        void dfs(int start, vector<int>adj[], vector<int>&ls, vector<int> &vis){
            vis[start]=1;
            ls.push_back(start);
            for(auto it:adj[start]){
                if(!vis[it]){
                    dfs(it, adj, ls, vis);
                }
            }
        }
        vector<int> dfsOfGraph(int V, vector<int> adj[]) {
            vector<int> ls;
            int start=0;
            vector<int> vis(V,0);
            dfs(start, adj, ls, vis);
            return ls;
        }
    };
    void addEdge(vector<int> adj[], int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printAns(vector<int>ans){
        for(auto it:ans){
            cout<<it<<" ";
        }
    }
    int main(){
        vector <int> adj[5];

        addEdge(adj, 0, 2);
        addEdge(adj, 2, 4);
        addEdge(adj, 0, 1);
        addEdge(adj, 0, 3);

        Solution obj;
        vector <int> ans = obj.dfsOfGraph(5, adj);
        printAns(ans);

        return 0;
    }