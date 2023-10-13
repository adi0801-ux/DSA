//
// Created by Aditya Chauhan on 13/10/23.
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cheapestFlight(int n , vector<vector<int>>flights, int src, int dst, int K){
        queue<pair<int, pair<int, int>>>q;
        //stops, node, dist
        q.push({0,{src, 0}});
        vector<int>fare(n,1e9);
        fare[src]=0;
        vector<pair<int, int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>K)continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edWt=it.second;
                if(cost+edWt<fare[adjNode]){
                    fare[adjNode]=cost+edWt;
                    q.push({stops+1, {adjNode, fare[adjNode]}});
                }
            }
        }
        if(fare[dst]==1e9)return -1;
        else return fare[dst];
    }
};



int main() {

    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
                                   {2, 3, 200}};

    Solution obj;

    int ans = obj.cheapestFlight(n, flights, src, dst, K);

    cout << ans;
    cout << endl;

    return 0;
}