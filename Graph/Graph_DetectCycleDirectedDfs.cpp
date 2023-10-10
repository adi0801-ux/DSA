#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int start, vector<int>adj[], vector<int>&vis, vector<int>&pathVis ){
        vis[start]=1;
        pathVis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis)==true)return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int>adj[]){
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)==true)return true;
            }
        }
        return false;
    }
};



void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int V = 11;
    Solution obj;
    cout<<obj.isCycle(V, adj);


    return 0;
}