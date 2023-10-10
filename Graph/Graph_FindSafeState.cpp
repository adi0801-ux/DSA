#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycle(int node, vector<int>adj[], vector<int>&vis, vector<int>&pathVis, vector<int>&check){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(isCycle(it, adj, vis, pathVis, check)==true){
                    check[node]=0;
                    return true;//cycle detected
                }
            }
            else if(pathVis[it]){
                check[node]=0;
                return true;//cycle detected
            }
        }
        //cycle not detected
        pathVis[node]=0;
        check[node]=1;
        return false;
    }
    vector<int>EventualSafeState(int V,vector<int>adj[]){
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>check(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                isCycle(i, adj, vis, pathVis, check);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};



void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
                           {8}, {9}
    };
    int V = 12;
    Solution obj;
    vector<int>a=obj.EventualSafeState(V, adj);
    for(auto it:a){
        cout<<it<<" ";
    }

    return 0;
}