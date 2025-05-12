#include<bits/stdc++.h>
using namespace std;

int binsearch(int l,int h,int t,vector<int>&nums){
    int mid = l+(h-l)/2;
    if(l >= h){
        return -1;
    }
    if(nums[mid] < t){
        binsearch(mid+1,h,t,nums);
    }else if(nums[mid] > t){
        binsearch(l,mid-1,t,nums);
    }else{
        // cout << mid;
        return mid;
    }
    
}

int main(){
    vector<int>nums = {0,2,4,6,8};
    int target = 4;
    int i = binsearch(0,4,target,nums);
    cout << i;
    return 0;
}