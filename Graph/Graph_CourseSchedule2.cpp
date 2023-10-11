//
// Created by Aditya Chauhan on 10/10/23.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //kahns algo to check cycle
    vector<int> CourseSchedule(int V, vector<vector<int>>&prerequisites) {
        vector<int>vis(V,0);
        vector<int>topo;
        queue<int>q;
        vector<int>indegree(V,0);
        vector<int>adj[V];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
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
//        reverse(topo.begin(), topo.end());
        return topo;
    }

};




int main() {
    int N = 4;
    int M = 3;

    vector<vector<int>> prerequisites(3);
    prerequisites[0].push_back(0);
    prerequisites[0].push_back(1);

    prerequisites[1].push_back(1);
    prerequisites[1].push_back(2);

    prerequisites[2].push_back(2);
    prerequisites[2].push_back(3);

    Solution obj;
    vector<int>ans = obj.CourseSchedule( N, prerequisites);
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}