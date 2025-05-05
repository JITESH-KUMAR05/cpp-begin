#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b){
    if(a%2 != 0 && b%2 != 0) return a<b;
    else if(a%2 != 0 || b%2!=0){
        if(a%2 != 0) return true;
        else return false;
    }
    else return a>b;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),comp);
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }

}