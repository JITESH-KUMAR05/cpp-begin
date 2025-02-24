#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> arr2;
    for(int i=0; i<n; i++){
        cin >> arr2[i];
    }
    for(int i=0; i<n; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "Sorting arr2" << endl;
    sort(arr2.begin(), arr2.end());
    for(int i=0; i<n; i++){
        cout << arr2[i] << " ";
    }
    return 0;
}