#include<bits/stdc++.h>
using namespace std;
int main() {
	cout << "Hello World";
	cout << "Jitesh Kumar";
	cout << endl;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.emplace_back(3);
	// cout << v;

	vector<pair<int,int>> vec;
	vec.push_back({1,2});
	vec.emplace_back(3,4);
	
	for(vector<int>::iterator it = v.begin();it != v.end();it++){
		cout << *(it) << " ";
	}
	cout << endl;
	// v.erase(v.begin(),v.begin()+2);
	v.erase(v.begin());
	for(auto it = v.begin();it != v.end();it++){
		cout << *(it) << " ";
	}
	cout << endl;
	v.insert(v.begin(),2 , 1) ;
	
	for(auto it : v){
		cout << (it) << " ";
	}
	cout << endl;
	vector<int> vecc(3,50);
	v.insert(v.begin(),vecc.begin(),vecc.end());
	for(auto it : v){
		cout << (it) << " ";
	}
	return 0;
}