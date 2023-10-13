//
// Created by Aditya Chauhan on 13/10/23.
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void floydWarshal(vector<vector<int>>&matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=1e9;
                }
                if(i==j){
                    matrix[i][j]=0;
                }
            }
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j], matrix[i][via]+matrix[via][j]);
                }
            }
        }
        //check negative cycle
//        for(int i=0;i<n;i++){
//            if(matrix[i][i]<0)return {{-1}};
//        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};



int main() {

    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, -1));
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    Solution obj;
    obj.floydWarshal(matrix);

    for (auto row : matrix) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}