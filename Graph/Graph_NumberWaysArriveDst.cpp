//
// Created by Aditya Chauhan on 13/10/23.
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPath(int n, vector<vector<int>>roads){
        vector<pair<int, int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(n, 1e9);
        vector<int>ways(n, 0);
        dist[0]=0;
        ways[0]=1;int mod=(int)(1e9+7);
        //node, dis
        pq.push({0, 0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.first;
            int dis=it.second;
            for(auto iter:adj[node]){
                int adjNode=iter.first;
                int edWt=iter.second;
                if(dis+edWt<dist[adjNode]){
                    dist[adjNode]=dis+edWt;
                    pq.push({adjNode, dis+edWt});
                    ways[adjNode]=ways[node];
                }
                else if(dis+edWt==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return (ways[n-1])%mod;
    }
};



int main() {

    int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
                                 {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    int ans = obj.countPath(n, edges);

    cout << ans;
    cout << endl;
    return 0;
}