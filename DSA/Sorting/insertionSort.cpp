#include<bits/stdc++.h>
using namespace std;
//  it always takes an element and place it on it's right position 
void insertion(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j] ){
            swap(arr[j-1],arr[j]);
            j--;
        }
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
    insertion(arr);
    cout << "insertion Sort" << endl;
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }

    return 0;
    
}