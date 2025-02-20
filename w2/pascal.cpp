#include <iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
        long long ans = 1;
		cout << ans << " ";
		cout << endl;
        for(int row = 2;row<=n;row++){
			cout << 1 << " ";
			for(int col = 1;col<row;col++){
            ans = ans * (row - col);
            ans = ans / col;
			cout << ans << " ";
        }
		cout << endl;
		}
	return 0;
}
