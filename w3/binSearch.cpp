#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    for(int i=0;i<=9;i++){
        v.push_back(i);
    }
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
    int search = 1;
    int low = 0;
    int high = v.size();
    int mid = low + ((high - low) / 2);
    while(low < high){
        if(v[mid] == search){
            cout << mid;
            return mid;
        }else if(v[mid] > search){
            high = mid-1;
            mid = low + ((high - low) / 2);
        }else{
            low = mid+1;
            mid = low + ((high - low) / 2);
        }
    }
}