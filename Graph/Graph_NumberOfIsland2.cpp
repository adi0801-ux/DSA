//
// Created by Aditya Chauhan on 16/10/23.
//

#include<bits/stdc++.h>

using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])return node;
        else {
            return parent[node] = findUpar(parent[node]);
        }
    }

    void unionByRank(int u, int v) {
        int uParU = findUpar(u);
        int uParV = findUpar(v);
        if (uParU == uParV)return;
        if (rank[uParU] < rank[uParV]) {
            parent[uParU] = uParV;
        } else if (rank[uParU > rank[uParV]]) {
            parent[uParV] = uParU;
        } else {
            parent[uParU] = uParV;
            rank[uParV]++;
        }

    }

    void unionBySize(int u, int v) {
        int uParU = findUpar(u);
        int uParV = findUpar(v);
        if (uParU == uParV)return;
        if (size[uParU] < size[uParV]) {
            parent[uParU] = uParV;
            size[uParV] += size[uParU];
        } else {
            parent[uParV] = uParU;
            size[uParU] += size[uParV];
        }
    }

};


class Solution {
public:
    vector<int>numOfIslands(int n, int m, vector<vector<int>>&operators){
        vector<vector<int>>vis(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        int cnt=0;
        vector<int>ans;
        for(auto it:operators){
            int r=it[0];
            int c=it[1];
            if(vis[r][c]==1){
                ans.push_back(cnt);
            }
            else{
                vis[r][c]=1;
                cnt++;
            }
            int delr[]={-1,0,+1,0};
            int delc[]={0,+1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=r+delr[i];
                int ncol=c+delc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==1){
                    if (vis[nrow][ncol] == 1) {
                        int nodeNo = r * m + c;
                        int adjNodeNo = nrow * m + ncol;
                        if (ds.findUpar(nodeNo) != ds.findUpar(adjNodeNo)) {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
                                     {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };


    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
