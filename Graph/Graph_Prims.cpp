//
// Created by Aditya Chauhan on 14/10/23.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prims(vector<vector<int>>adj[], int V){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        //edWt, node
        pq.push({0,0});
        vector<int>vis(V,0);
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int edWt=it.first;
            int node=it.second;
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=edWt;
            for(auto iter:adj[node]){
                int dist=iter[1];
                int adjNode=iter[0];
                if(!vis[adjNode]){
                    pq.push({dist, adjNode});
                }
            }
        }
        return sum;
    }
};

int main() {


    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int sum = obj.prims( adj, V);
    cout << "The sum of all the edge weights: " << sum << endl;


}
