#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> grid){
        int n =grid.size();
        int m=grid[0].size();
        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>>dis(n, vector<int>(m,0));
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;i<m;j++){
                if(grid[i][j]==1){
                    q.push({{i, j},0});

                    vis[i][j]=1;

                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()) {
            int r= q.front().first.first;
            int c= q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[r][c]=steps;
            for (int i = 0; i < 4; i++) {
                int nrow =r+delrow[i];
                int ncol =c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    q.push({{nrow, ncol}, steps+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return dis;
    }
};



int main() {
    vector<vector<int>>grid{
            {0,1,1,0},
            {1,1,0,0},
            {0,0,1,1}
    };

    Solution obj;
    vector<vector<int>> ans = obj.updateMatrix(grid);

    for(auto i: ans){
        for(auto j: i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}