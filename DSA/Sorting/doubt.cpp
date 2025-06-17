#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int>&arr,int cursum,int &maxsum){
    if(i==arr.size()){
        if(cursum % 3 == 0){
            maxsum = max(maxsum,cursum);
        }
        return;
    }
    // picking case
    solve(i+1,arr,cursum+arr[i],maxsum);
    solve(i+1,arr,cursum,maxsum);
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << arr.size() << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int maxsum = 0;
    solve(0,arr,0,maxsum);
    cout << maxsum;
    return 0;
}