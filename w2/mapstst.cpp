#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int ,int> m1;
    m1.insert({1,10});
    m1.insert({2,20});
    for(auto it : m1){
        cout << it.first << " " << it.second << endl;
    }

    map<int ,pair<int,int>> m2;
    m2.insert({1,{10,100}});
    m2.insert({2,{20,200}});
    for(auto it : m2){
        cout << it.first << "-->" << it.second.first << "," << it.second.second << endl;
    }

    // lower_bound and upper_bound
    map<int,int> m3;
    m3.insert({1,10});
    m3.insert({2,20});
    m3.insert({3,30});
    m3.insert({4,40});
    m3.insert({5,50});
    m3.insert({6,60});
    m3.insert({7,70});
    for(auto it : m3){
        cout << it.first << " " << it.second << endl;
    }
    int lb = m3.lower_bound(3)->first;
    int ub = m3.upper_bound(3)->first;
    cout << "Lower bound of 3 is " << lb << endl;
    cout << "Upper bound of 3 is " << ub << endl;

    
}