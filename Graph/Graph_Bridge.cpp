//
// Created by Aditya Chauhan on 20/10/23.
//
#include <bits/stdc++.h>
using namespace std;
class Solution{
    int timer=0;
public:
    void dfs(int node, int parent, int tin[], int low[], vector<int> &vis,vector<vector<int>>&bridge, vector<int> adj[]){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(vis[it]==0){
                dfs(it, node, tin, low, vis, bridge, adj);
                low[node]=min(low[node], low[it]);
                //check bridge btw node--it
                if(low[it]>tin[node]){
                    bridge.push_back({node, it});
                }
            }
            //vis[it]==1
            else{
                low[node]=min(low[node] , low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, tin, low,vis, bridges, adj);
        return bridges;
    }
};

int main() {

    int n = 4;
    vector<vector<int>> connections = {
            {0, 1}, {1, 2},
            {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}