#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abacbdd";
    int n = s.length();
    unordered_map<char,int>freq;
    string ans = "";
    queue<char> q;
    for(char ch:s){
        freq[ch]++;
        q.push(ch);
        while(!q.empty() && freq[q.front()] > 1){
            q.pop();
        }
        if(q.empty()){
            ans+="-1";
        }else{
            ans.push_back(q.front());
        }

    }
    queue<int>qq;
    qq.push(2);
    qq.push(3);
    cout << qq.back() << endl;
    // qq.popleft();
    cout << ans << endl;

}