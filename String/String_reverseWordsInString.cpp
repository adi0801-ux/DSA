//
// Created by Aditya Chauhan on 06/10/23.
//
#include<iostream>
#include <stack>

using namespace std;
void reverseWords(string s) {
    stack <string> st;
    string temp="";
    int i=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]!= ' ')temp.push_back(s[i]);
        if((i==n-1 || s[i]== ' ')&& !temp.empty()){
            st.push(temp);
            temp="";
        }
    }
    //akkaka
    while(!st.empty()){
        temp.append(st.top());
        st.pop();
        temp.append(" ");
    }
    temp.pop_back();
    cout<< temp;
}

int main(){
    string s;
    getline(cin, s);
    int n=s.size();
    reverseWords(s);
    return 0;
}