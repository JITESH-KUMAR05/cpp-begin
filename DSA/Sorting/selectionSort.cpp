#include<bits/stdc++.h>
using namespace std;

// Selection Sort
// it takes the minimum element and swaps with the first element of the array
void selection(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<=n-2;i++){
        int midx = i;
        for(int j=i;j<n;j++){
            if(arr[j] < arr[midx]){
                midx = j;
            }
        }
        swap(arr[i],arr[midx]);
        // int temp = arr[i];
        // arr[i] = arr[midx];
        // arr[midx] = temp;
    }
}
//  time complexity is O(n^2)


int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>barr(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    selection(arr);
    cout << "Selection Sort" << endl;
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }

    return 0;
    
}