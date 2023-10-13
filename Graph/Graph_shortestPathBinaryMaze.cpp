//
// Created by Aditya Chauhan on 12/10/23.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>&grid, pair<int, int>src , pair<int, int>destination){
        int n=grid.size();
        int m=grid[0].size();
        if(src.first==destination.first && src.second==destination.second)return 0;
        vector<vector<int>>dis(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src.first, src.second}});
        dis[src.first][src.second]=0;
        int delrow[]={-1,0,+1, 0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()) {
            int dist=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && dist+1<dis[nrow][ncol]){
                    if(nrow==destination.first && ncol==destination.second){
                        return dist+1;
                    }
                    q.push({dist+1,{nrow, ncol}});
                    dis[nrow][ncol]=1+dist;
                }
            }
        }
        return -1;
    }
};



int main() {
    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 0;
    destination.second = 1;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
}