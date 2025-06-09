#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abab"; // abcd   aabb // 
    int n = s.length();
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(s[i] == s[j]){
                res++;
            }
        }
    }
    cout << res;
    return res;
}