#include<bits/stdc++.h>
using namespace std;

class Solution {
public:



    void dfs(int row0, int col0, vector<vector<int>>&grid, vector<vector<int>>&vis, vector<pair<int, int>>&vec, int row, int col){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        vec.push_back({
                     row - row0, col - col0
                      });
        int delrow[]={-1,0,+1,0};
        int delcol[] = {0, -1, 0, +1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
               && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(row0, col0, grid, vis,vec, nrow, ncol);
            }
        }
    }

    int distinctIslands(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        set<vector<pair<int, int>>>st;
        for(int i=0;i<n;i++) {
            for (int j = 0; j < m; j++) {
                vector<pair<int, int>> vec;
                if (grid[i][j] == 1 && !vis[i][j]) {

                    dfs(i, j, grid, vis, vec, i, j);

                    st.insert(vec);
                }
            }
        }
        return st.size();
    }

};



int main() {
    vector<vector<int>> grid
            {{1, 1, 0, 1, 1},
             {1, 0, 0, 0, 0},
             {0, 0, 0, 0, 1},
             {1, 1, 0, 1, 1}};
    Solution ob;
    // n = 5, m = 4

    cout<< ob.distinctIslands(grid);

    return 0;
}