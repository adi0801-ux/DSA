#include<bits/stdc++.h>9
using namespace std;

class Solution {
public:
    //kahns algo to check cycle
    bool CourseSchedule(int V, vector<vector<int>>&prerequisites) {
        vector<int> vis(V, 0);
        vector<int> adj[V];
        vector<int> indegree(V, 0);
        vector<int> topo;
        queue<int>q;
        for (auto it: prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < V; i++) {
            for (auto it: adj[i]) {
                if (!vis[it]) {
                    indegree[it]++;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==V){
            return true;
        }
        else return false;

    }

};




int main() {
    int N= 4;

    vector<vector<int>> prerequisites(3);
    prerequisites[0].push_back(0);
    prerequisites[0].push_back(1);

    prerequisites[1].push_back(1);
    prerequisites[1].push_back(2);

    prerequisites[2].push_back(2);
    prerequisites[2].push_back(3);

    Solution obj;
    cout<<obj.CourseSchedule( N, prerequisites);


    return 0;
}