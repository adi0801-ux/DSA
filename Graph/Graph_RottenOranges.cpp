#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>&grid, int delrow[], int delcol[], int &cnt, vector<vector<int>>&vis,queue<pair<pair<int,int>,int>>q){
        int n =grid.size();
        int m=grid[0].size();
        int tmax=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tmax=max(t, tmax);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({{nrow, ncol},t+1});
                    vis[nrow][ncol]=1;
                    cnt++;
                }
            }
        }
        return tmax;
    }
    int rottenOranges(vector<vector<int>>&grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        int cntFresh = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }
        int time = bfs(grid, delrow, delcol, cnt, vis, q);
        if (cnt != cntFresh)return -1;
        else return time;

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
    vector<vector<int>>grid{
            {2,1,1},
            {1,1,0},
            {0,1,1}
    };

// sr = 1, sc = 1, newColor = 2
    Solution obj;
    cout<<obj.rottenOranges(grid);

    return 0;
}