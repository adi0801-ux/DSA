//
// Created by Aditya Chauhan on 16/10/23.
//
//
#include<bits/stdc++.h>

using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])return node;
        else {
            return parent[node] = findUpar(parent[node]);
        }
    }

    void unionByRank(int u, int v) {
        int uParU = findUpar(u);
        int uParV = findUpar(v);
        if (uParU == uParV)return;
        if (rank[uParU] < rank[uParV]) {
            parent[uParU] = uParV;
        } else if (rank[uParU > rank[uParV]]) {
            parent[uParV] = uParU;
        } else {
            parent[uParU] = uParV;
            rank[uParV]++;
        }

    }

    void unionBySize(int u, int v) {
        int uParU = findUpar(u);
        int uParV = findUpar(v);
        if (uParU == uParV)return;
        if (size[uParU] < size[uParV]) {
            parent[uParU] = uParV;
            size[uParV] += size[uParU];
        } else {
            parent[uParV] = uParU;
            size[uParU] += size[uParV];
        }
    }

};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNodes;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNodes.find(mail) == mapMailNodes.end()) {
                    mapMailNodes[mail] = i;
                } else {
                    ds.unionBySize(i, mapMailNodes[mail]);
                }
            }
        }
        vector<string> mergedMail[n];
        for (auto it: mapMailNodes) {
            int node = ds.findUpar(it.second);
            string mail = it.first;
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0)continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it: mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
                                       {"John", "j4@com"},
                                       {"Raj",  "r1@com", "r2@com"},
                                       {"John", "j1@com", "j5@com"},
                                       {"Raj",  "r2@com", "r3@com"},
                                       {"Mary", "m1@com"}
    };


    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);
    for (auto acc: ans) {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
