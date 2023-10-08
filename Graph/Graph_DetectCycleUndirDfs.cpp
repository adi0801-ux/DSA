#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int parent, int V, vector<int>adj[], vector<int>&vis){
        vis[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]){
                if(dfs(it, node, V, adj, vis)==true)return true;
            }
            else if(it!=parent)return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int>adj[]){
        vector<int>vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]) {
                if(dfs(i,-1,V, adj, vis)==true)return true;
            }
        }
        return false;
    }

};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> ans) {
    for (auto it: ans) {
        cout << it << " ";
    }
}

int main() {
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};    Solution obj;
    cout<<obj.isCycle(4,adj);

    return 0;
}