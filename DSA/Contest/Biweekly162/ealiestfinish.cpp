#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
		int mini = INT_MAX;
		for(int i=0;i<landStartTime.size();i++){
			for(int j=0;j<waterStartTime.size();j++){
				// here first we are taking land ride
				int lf=landStartTime[i]+landDuration[i];
				int wal=max(lf,waterStartTime[j]);
				int tf1=wal+waterDuration[j];

				// now we will try water ride first;
				int wf=waterStartTime[j]+waterDuration[j];
				int law=max(wf,landStartTime[i]);
				int tf2=law+landDuration[i];

				mini = min(mini,min(tf1,tf2));
			}
		}
		return mini;
	}
}; 