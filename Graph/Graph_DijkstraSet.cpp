//
// Created by Aditya Chauhan on 12/10/23.
//

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int>dijkstra(int V, vector<vector<int>>adj[], int src){
        set<pair<int, int>>st;
        vector<int>dis(V, 1e9);
        dis[src]=0;
        st.insert({src, 0});
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.first;
            int dist=it.second;
            st.erase(it);
            for(auto i:adj[node]){
                int edWt=i[1];
                int adjNode=i[0];
                if(dist+edWt<dis[adjNode]){
                    if(dis[adjNode]!=1e9){
                        st.erase({dist, dis[adjNode]});
                    }
                    dis[adjNode]=dist+edWt;
                    st.insert({adjNode, dis[adjNode]});
                }
            }
        }
        return dis;
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
