#include<bits/stdc++.h>
using namespace std;
int smm(int i,int n){
    if(i>n){
        return 0;
    }
    return i + smm(i+1,n);
}

int main(){
    // vector<int>arr={1,2,3};
    int sm=smm(0,5);
    cout << sm ;
    return 1;
}