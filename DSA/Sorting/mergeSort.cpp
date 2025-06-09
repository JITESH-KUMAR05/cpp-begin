//  divide and merge
// it will perform in O(n * log(n))
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int l,int mid ,int r){
    // we can make two arrays left and right with length m - l + 1 and r - m - 1 + 1
    vector<int>left(arr.begin()+l,arr.begin()+mid+1);
    vector<int>right(arr.begin()+mid+1,arr.begin()+r+1);
    int n1 = mid - l + 1;
    int n2 = r- mid;
    // vector<int>left(n1);
    // vector<int>right(n2);
    int k=l;
    // for(int i=0;i<n1;i++){
    //     left[i] = arr[k];
    //     k++;
    // }
    // for(int i=0;i<n2;i++){
    //     right[i] = arr[k];
    //     k++;
    // }
    // merge both
    int i=0,j=0;
    k=l;
    while(i<n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>&arr,int l,int r){
    if(l>=r) return;
    int mid = l + (r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>barr(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    cout << "Merge Sort" << endl;
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }

    return 0;
    
}