#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>board, vector<vector<int>>&vis,int row, int col){
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='0' && vis[nrow][ncol]=='0'){
                dfs(board, vis, nrow, ncol);
            }
        }
    }
    vector<vector<char>> solve(vector<vector<char>>board){
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //check top and bottom row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='0'){
                dfs(board, vis,0, j);
            }
            if(!vis[n-1][j] && board[n-1][j]=='0'){
                dfs(board, vis, n-1, j);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='0'){
                dfs(board, vis, i, 0);
            }
            if(!vis[i][m-1] && board[i][m-1]=='0'){
                dfs(board, vis, i, m-1);
            }
        }

        //convert unvisited and 0's into X
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( !vis[i][j] && board[i][j]=='0'){
                    board[i][j]='X';
                }
            }
        }
        return board;
    }
};



int main() {
    vector<vector<char>> mat{
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
            {'X', 'X', 'O', 'O'}
    };

    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.solve( mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}