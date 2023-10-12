//
// Created by Aditya Chauhan on 12/10/23.
//
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>>adj[], int src){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({src, 0});
        vector<int>dist(V,1e9);
        dist[src]=0;
        while(!pq.empty()){
                int node=pq.top().first;
                int dis=pq.top().second;
                pq.pop();
                for(auto it:adj[node]){
                    int adjNode=it[0];
                    int edgeWt=it[1];
                    if(dis+edgeWt<dist[adjNode]){
                        dist[adjNode]=dis+edgeWt;
                        pq.push({adjNode, dist[adjNode]});
                    }
                }
        }
    return dist;
    }
};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
