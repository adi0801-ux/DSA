#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int start, int V, vector<int>adj[], vector<int>&color){
        queue<int> q;
        color[start]=0;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipertide(int V, vector<int>adj[]){
        vector<int>color(V, -1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(check(i,V, adj, color)==false)return false;
            }
        }
        return true;

    }
};



void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    vector<int>adj[4];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    Solution obj;
    bool ans = obj.isBipertide(4, adj);
    if(ans)cout << "1\n";
    else cout << "0\n";

    return 0;
}