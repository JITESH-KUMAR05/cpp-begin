#include<bits/stdc++.h>
using namespace std;

int smm(int i,vector<int>&arr,int sm){
    if(i==arr.size()-1){
        return sm;
    }
    sm += arr[i];
    smm(i+1,arr,sm);

}

int main(){
    vector<int>arr={1,2,3};
    int sm=0;
    cout << smm(0,arr,sm);
    return 1;
}