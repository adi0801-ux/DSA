#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isDetect(int src, vector<int>adj[], vector<int>&vis){
        vis[src]=1;
        queue<pair<int, int>>q;
        q.push({src, -1});
        while(!q.empty()){
            int node=q.front().first;
            int parentNode=q.front().second;
            q.pop();
            for(auto adjNode:adj[node]){
                if(!vis[adjNode]){
                    q.push({adjNode, node});
                    vis[adjNode]=1;
                }
                else if(adjNode!=parentNode){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int>adj[]){
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isDetect(i, adj, vis))return true;
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
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    cout<<obj.isCycle(4,adj);

    return 0;
}