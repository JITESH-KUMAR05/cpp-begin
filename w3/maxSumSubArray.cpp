#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {-2,-1,3,4,-1,2,1,-5,4};
    int cur = 0;
    int maxs = 0;
    for(int i=0;i<9;i++){
        cur += arr[i];
        if(cur > maxs){
            maxs = cur;
        }
        if(cur < 0){
            cur = 0;
        }
    }
    cout << maxs;
}