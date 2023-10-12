//
// Created by Aditya Chauhan on 11/10/23.
//
//
// Created by Aditya Chauhan on 11/10/23.
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>>wordLadder2(string beginWord, string targetWord, vector<string>wordList){
        vector<vector<string>>ans;
        queue<vector<string>>q;
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        unordered_set<string>st( wordList.begin(), wordList.end());
        q.push({beginWord});
        int level=0;
        while(!q.empty()){
            vector<string>vec=q.front();
            q.pop();
            if(vec.size()>level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
            }
            string word=vec.back();
            if(word==targetWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }

};


//bool comp(vector<string> a, vector<string> b)
//{
//    string x = "", y = "";
//    for (string i : a)
//        x += i;
//    for (string i : b)
//        y += i;
//
//    return x < y;
//}

int main() {
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    Solution obj;
    vector<vector<string>>ans =obj.wordLadder2(startWord, targetWord, wordList);
//    for(auto it:v){
//        for(auto i:it){
//            cout<<i<<" ";
//        }
//        cout<<endl;
//    }
    if(ans.size() == 0)
        cout << -1 << endl;
    else
    {
//        sort(ans.begin(), ans.end(), comp);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}