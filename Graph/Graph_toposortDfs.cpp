#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, int V, vector<int>adj[], vector<int>&vis, stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) {
                dfs(it, V, adj, vis, st);
            }
        }
        st.push(node);
    }
    vector<int>toposort(int V, vector<int>adj[]){
        vector<int>vis(V,0);
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, V, adj, vis, st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
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