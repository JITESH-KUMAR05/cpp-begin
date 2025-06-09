#include<bits/stdc++.h>
using namespace std;

// bubble Sort
void bubble(vector<int>&arr){
    int n = arr.size();
    for(int i=n-1;i>=0;i--){
        // int midx = i;
        int didSwap=0;
        for(int j=0;j<i;j++){
            if(arr[j] > arr[j+1]){
                // midx = j;
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap==0){
            break;
        }
        // swap(arr[i],arr[midx]);
        // int temp = arr[i];
        // arr[i] = arr[midx];
        // arr[midx] = temp;
    }
}
//  worst and avg time complexity is O(n^2) but best is O(n)


int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>barr(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    bubble(arr);
    cout << "bubble Sort" << endl;
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }

    return 0;
    
}