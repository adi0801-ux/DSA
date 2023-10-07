//
// Created by Aditya Chauhan on 07/10/23.
//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        //int vis[V] = {0};
        vector<int>vis(V);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            vis[node] = 1;
            bfs.push_back(node);
            for (auto it: adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
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

    Solution obj;
    vector<int> ans=obj.bfsOfGraph(5,adj);
    print(ans);
    return 0;
}