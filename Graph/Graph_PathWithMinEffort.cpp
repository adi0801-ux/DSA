//
// Created by Aditya Chauhan on 12/10/23.
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int minEffort(vector<vector<int>>&height){
         priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
         pq.push({0,{0,0}});
         int n=height.size();
         int m=height[0].size();
         vector<vector<int>>dist(n,vector<int>(m,1e9));
         dist[0][0]=0;
         int delrow[]={-1,0,+1,0};
         int delcol[]={0,+1,0,-1};
         while (!pq.empty()){
             auto it=pq.top();
             pq.pop();
             int diff=it.first;
             int r=it.second.first;
             int c=it.second.second;
             if(r==n-1 && c==m-1)return diff;
             for(int i=0;i<4;i++){
                 int nrow=r+delrow[i];
                 int ncol=c+delcol[i];
                 if(nrow>=0 && nrow<n &&ncol>=0 && ncol<m){
                     int newEff = max(abs(height[r][c]-height[nrow][ncol]), diff);
                     if (newEff<dist[nrow][ncol]){
                         dist[nrow][ncol]=newEff;
                         pq.push({newEff,{nrow, ncol}});
                     }
                 }
             }
         }
        return 0;
     }
};



int main() {

    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;

    int res = obj.minEffort(heights);

    cout << res;
    cout << endl;

    return 0;
}