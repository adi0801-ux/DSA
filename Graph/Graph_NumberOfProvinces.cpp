//
// Created by Aditya Chauhan on 07/10/23.
//
//
// Created by Aditya Chauhan on 07/10/23.
//
#include<bits/stdc++.h>

using namespace std;
//
// Created by Aditya Chauhan on 07/10/23.
//
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int start, vector<int> adjLs[], vector<int> &vis, vector<int> &ls) {
        ls.push_back(start);
        vis[start] = 1;
        for (auto it: adjLs[start]) {
            if(!vis[it])
            dfs(it, adjLs, vis, ls);
        }
    }

    int numberOfProvince(int V, vector<vector<int>> &adj) {
        vector<int> adjLs[V];
        vector<int> ls;
        vector<int> vis(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                count++;
                dfs(i, adjLs, vis, ls);
            }
        }
        return count;
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
    vector<vector<int>> adj
            {
                    {1, 0, 1},
                    {0, 1, 0},
                    {1, 0, 1}
            };

    Solution obj;
    cout<<obj.numberOfProvince(3, adj);

    return 0;
}