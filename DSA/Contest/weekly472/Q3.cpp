#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>cnt(26,0);
        for(char &ch:s){
            cnt[ch-'a']++;
        }
        string res="";
        for(int i=0;i<n;i++){
            for(char c='a';c<='z';c++){
                int chid = c - 'a';
                if(cnt[chid]==0){
                    continue;
                }
                cnt[chid]--;
                string mxsuf="";
                for(int k=25;k>=0;k--){
                    if(cnt[k]>0){
                        mxsuf+=string(cnt[k],(char)('a'+k));
                    }
                }

                string comb = res + c + mxsuf;

                if(comb <= target){
                    continue;
                }

                res += c;

                if(c>target[i]){
                    string minsuf = "";
                    for(int k=0;k<26;k++){
                        if(cnt[k]>0){
                            minsuf += string(cnt[k],(char)('a'+k));
                        }
                    }
                    return res+minsuf;
                }
                break;
            }
        }
        return res>target?res:"";
    }
};