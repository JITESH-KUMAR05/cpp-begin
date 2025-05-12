#include<bits/stdc++.h>
using namespace std;

bool issorted(int i,vector<int>& arr){
    if(arr[i] < arr[i-1]){
        return false;
    }
    return issorted(i++,arr);
    return true;
}
bool srted(int i,vector<int>&arr){
    if(i==arr.size()-1){
        return true;
    }
    if(arr[i] > arr[i+1]){
        return false;
    }
    srted(i+1,arr);
}
int main(){
    vector<int>arr = {1,2,5,4,5};
    // int i=1;
    // if(issorted(i,arr)){
    //     cout << true;
    // }else{
    //     cout << false;
    // }
    // for(int i=0;i<arr.size()-1;i++){
    //     if(arr[i] > arr[i+1]){
    //         cout << "Not sorted";
    //         return 0;
    //     }
        

    // }
    // cout << "Sorted" ;
    if(srted(0,arr)){
        cout << "sorted";
    }else{
        cout << "Not Sorted";
    }
    return 1;
}