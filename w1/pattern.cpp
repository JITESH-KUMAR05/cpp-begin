#include <bits/stdc++.h>
using namespace std;
int main(){
    // int n;
    // cin >> n;
    // for(int i=1;i<=n;i++){
    //     for(int j = 1;j<= (n-i);j++){
    //         cout << " ";
    //     }
    //     int d = n-1;
    //     int val = i;
    //     for(int j = 1;j<=i;j++){
    //         cout << val << " " ;
    //         val = val + d;
    //         d = d-1;
    //     }
    //     cout << endl;
    // }
    int n;
	cin >> n;
    int inspace = -1;
    int space = n;
	for(int i = 1;i<=(2*n)+1;i++){
        
		for(int j = 1;j<=space;j++){
			cout << " ";
		}
        cout << "*";
		if(inspace >=0){
            for(int j = 1;j<=inspace;j++){
			
            cout << " ";
		}
        cout << "*";
    }

		cout << endl;
        if(i==(n+1)){
            inspace += 2;
            space--;
        }
        else{
            inspace -= 2;
            space++;
        }
	}
	return 0;
}
