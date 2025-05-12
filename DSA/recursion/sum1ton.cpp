#include<bits/stdc++.h>
using namespace std;
int sm = 0;
int smm(int i,int n){
    if(i>n){
        return sm;
    }
    sm = sm + i;
    i += 1;
    return smm(i,n);
}

int main(){
    // vector<int>arr={1,2,3};
    int sm=smm(0,5);
    cout << sm ;
    return 1;
}