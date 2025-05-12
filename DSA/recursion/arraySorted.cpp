#include<bits/stdc++.h>
using namespace std;

bool issorted(int i,vector<int>& arr){
    if(arr[i] < arr[i-1]){
        return false;
    }
    return issorted(i++,arr);
    return true;
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    int i=1;
    if(issorted(i,arr)){
        cout << true;
    }else{
        cout << false;
    }
}