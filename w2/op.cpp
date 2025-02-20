#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    int c = 0;
    for(long long int i=1;(i*i)<=n;i++){
        if(n%i==0 && i*i != n){
            c+=2;
        }else if(n%i==0 && i*i == n){
            c++;
        }
    }
    cout << c;
}