//
// Created by Aditya Chauhan on 11/10/23.
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>EventualSafeState(int V,vector<int>adj[]){
        vector<int>adjRev[V];
        vector<int>indegree(V,0);
        queue<int> q;
        vector<int>safeNode;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeNode.push_back(node);
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safeNode.begin(),safeNode.end());
        return safeNode;
    }

};




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