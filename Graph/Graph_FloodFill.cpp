#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>> &image, vector<vector<int>> &ans, int sr, int sc, int newCol,int iniCol, int delrow[], int delcol[]) {
        ans[sr][sc] = 1;
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        q.push({sr,sc});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i =0;i<4;i++) {
                    int nrow = r + delrow[i];
                    int ncol = c + delcol[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniCol && ans[nrow][ncol]!=newCol) {
                        ans[nrow][ncol] = newCol;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

    vector<vector<int>> FloodFill(vector<vector<int>> & image, int sr, int sc, int newCol) {
        vector<vector<int>> ans = image;
        int iniCol=image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
//        vector<vector<int>> vis(n, vector<int>(m, 0));
        bfs(image, ans , sr, sc, newCol,iniCol, delrow, delcol);
        return ans;
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
    vector<vector<int>>image{
            {1,1,1},
            {1,1,0},
            {1,0,1}
    };

// sr = 1, sc = 1, newColor = 2
    Solution obj;
    vector<vector<int>> ans = obj.FloodFill(image, 1, 1, 2);
    for(auto i: ans){
        for(auto j: i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}