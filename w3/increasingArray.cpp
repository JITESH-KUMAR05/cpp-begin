#include<bits/stdc++.h>
using namespace std;

int main(){
    // int n;
    // cin >> n;
    vector<int> v = {3,2,5,1,7};
    // for(int i=0;i<n;i++){
    //     cin >> v[i];
    // }
    int c =0;
    for(int i=0;i<4;i++){
        // while(v[i] > v[i+1]){
        //     v[i+1]++;
        //     c++;
        // }
        
        if(v[i] > v[i]+1){
            int diff = v[i] - v[i]+1;
            v[i+1] += diff;
            c += diff;
        }
    }
    cout << c;
    cout << endl;
    for(int i=0;i<5;i++){
        cout << v[i] << " ";
    }
    
}