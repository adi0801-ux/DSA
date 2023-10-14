//
// Created by Aditya Chauhan on 14/10/23.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCity(vector<vector<int>> &edges, int distThreshold) {
        int n = edges.size();

        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        int city = -1;
        int maxCount = n;
        for (auto it: edges) {
            adj[it[0]][it[1]] = it[2];
            adj[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][via] == INT_MAX || adj[via][j] == INT_MAX)
                        continue;
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= distThreshold) {
                    count++;
                }
            }

            if (count <= maxCount) {
                maxCount = count;
                city = i;
            }
        }

        return city;

    }
};

int main() {


    int n = 4;
    int m = 4;
    vector<vector<int>> edges = {{0, 1, 3},
                                 {1, 2, 1},
                                 {1, 3, 4},
                                 {2, 3, 1}};
    int distanceThreshold = 4;

    Solution obj;
    int cityNo = obj.findCity(edges, distanceThreshold);
    cout << "The answer is node: " << cityNo << endl;

    return 0;
}