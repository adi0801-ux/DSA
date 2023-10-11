#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int>toposort(int V, vector<int>adj[]){
        vector<int>vis(V,0);
        vector<int>topo(V);
        vector<int>indegree(V,0);
        queue<int> q;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[i]++;
            }
        }
        for(auto it:indegree){
            if(indegree[it]==0){
                q.push(it);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
};




int main() {
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;
    Solution obj;
    vector<int> a = obj.toposort(V, adj);

    for (auto node : a) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}