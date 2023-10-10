#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int start, int c, int V, vector<int>adj[], vector<int>&col){
        col[start]=c;
        for(auto it:adj[start]){
            if(col[it]==-1){
                if(check(it, !col[start],V, adj, col)==false)return false;
            }
            else if(col[it]==c){
                return false;
            }
        }
        return true;
    }
    bool isBipertide(int V, vector<int>adj[]){
        vector<int>color(V, -1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(check(i,0,V, adj, color)==false)return false;
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
    return 0;
}