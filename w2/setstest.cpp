#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> st;
    st.insert(1);
    // cout << st;
    for(auto v : st){
        cout << v << " ";
    }
    cout << endl;
    st.emplace(2);
    for(auto v : st){
        cout << v << " ";
    }
    cout << endl;
    st.insert(2);
    for(auto v : st){
        cout << v << " ";
    }
    cout << endl;
    st.insert(4);
    for(auto v : st){
        cout << v << " ";
    }
    cout << endl;
    st.insert(3);
    for(auto v : st){
        cout << v << " ";
    }
    cout << endl;
    auto it = st.find(2);
    cout << *(it) << endl;
    st.erase(it);
    for(auto v : st){
        cout << v << " ";
    }
    cout << endl; 
}