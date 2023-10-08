//
// Created by Aditya Chauhan on 07/10/23.
//
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
    void bfs(int row, int col ,vector<vector<int>> &vis,  vector<vector<char>> & grid){
        vis[row][col]=1;
        queue<pair<int, int>>q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({row, col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=r+delrow;
                    int ncol=c+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol] ){
                        vis[nrow][ncol]=1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> & grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,  j, vis, grid);
                }
            }
        }
        return cnt;
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
    vector<vector<char>> adj
            {
                    {'0', '1', '1', '1', '0', '0', '0'},
                    {'0', '0', '1', '1', '0', '1', '0'}
            };

    Solution obj;
    cout<<obj.numIslands(adj);

    return 0;
}