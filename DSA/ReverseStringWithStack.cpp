#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "acdbbf";
    stack<char>st;
    string rev;
    for(char ch:s){
        st.push(ch);
    }
    while(!st.empty()){
        rev += st.top();
        st.pop();
    }
    for(char ch:rev){
        cout << ch;
    }
    cout << endl;
    string sn = "abcde";
    int k=3;
    queue<char>q;
    for(int i=0;i<k;i++){
        q.push(sn[i]);
    }
    string revn;
    for(int i=k;i<sn.length();i++){
        revn += sn[i];
    }
    while(!q.empty()){
        revn += q.front();
        q.pop();
    }
    for(char ch:revn){
        cout << ch;
    }
}