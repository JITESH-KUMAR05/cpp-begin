// Problem Statement: Investigator Pursuing the Fugitive

// Detective Chase is investigating a homicide and is determined to chase down the perpetrator who plans to evade capture by using village roads to flee the crime scene instead of the main roads.

// Chase is equipped with a city map displaying only the main roads, not the village roads. This map represents a graph with N nodes labeled from 1 to N. Node S indicates Chase's current location, while the other nodes represent various places in the city. Edges between nodes (x, y) indicate main roads between two locations in the city, while the absence of an edge signifies the presence of village roads (side lanes).

// Chase's mission is to compute the shortest distance from his position (Node S) to all other locations in the city using only the village roads (side lanes).

// Input Format:

// The first line contains T, denoting the number of test cases. T test cases follow.
// For each test case:
// The first line contains two integers N and M, representing the number of cities in the map and the count of roads in the map, respectively.
// The next M lines contain two integers x and y, indicating a main road between city x and city y.
// The last line contains an integer S, representing Chase's current position.
// Constraints:

// 1 <= T <= 10
// 2 <= N <= 2e5
// 0 <= M <= 120000
// 1 <= x, y, S <= N
// No node has a road to itself.
// There are no multiple edges between any pair of nodes.
// The graph is guaranteed to be sparse.
// A path exists between any pair of nodes using the side lanes.
// Output Format:
// For each test case, print a single line consisting of N-1 space-separated integers. These integers represent the shortest distances from Chase's position to the remaining N-1 locations in ascending order based on the vertex number, using only the village roads/side lanes.

// Sample Input:


// 2
// 4 3
// 1 2
// 2 3
// 1 4
// 1
// 4 2
// 1 2
// 2 3
// 2
// Sample Output:


// 3 1 2
// 2 2 1
// Explanation:
// In the first test case, the shortest distances from Chase's position (Node 1) are as follows:

// Distance from 1 to 2 is 3 (Path: 1 -> 3 -> 4 -> 2)
// Distance from 1 to 3 is 1 (Path: 1 -> 3)
// Distance from 1 to 4 is 2 (Path: 1 -> 3 -> 4)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int s,vector<int>&cost,vector<vector<int>> &adj){
        queue<int>q;
        q.push(s);
        cost[s]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int neg:adj[node]){
                if(cost[neg]==1e9){
                    cost[neg] = cost[node] + 1;
                    q.push(neg);
                }
            }
        }
    }
int main(){
	// cout << "Hello World!";
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<int>> adj(n+1);
        set<pair<int,int>> mainRoads;
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            mainRoads.insert({u,v});
            mainRoads.insert({v,u});
        }
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(u!=v && mainRoads.find({u,v})==mainRoads.end()){
                    adj[u].push_back(v);
                }
            }
        }
        int s;
        cin >> s;
        vector<int> cost(n + 1, 1e9);
        bfs(s, cost, adj);
        vector<int>cost(n+1,1e9);
        for(int i=1;i<=n;i++){
            if(i==s) continue;
            cout << cost[i] << " " ;
        }
        cout << endl;
	return 0;
}
}