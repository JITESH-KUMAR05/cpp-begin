// There are n cities and m flight connections between them. Your task is to determine the length of the shortest route from Syrjälä to every city.
// Input
// The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,\dots,n, and city 1 is Syrjälä.
// After that, there are m lines describing the flight connections. Each line has three integers a, b and c: a flight begins at city a, ends at city b, and its length is c. Each flight is a one-way flight.
// You can assume that it is possible to travel from Syrjälä to all other cities.
// Output
// Print n integers: the shortest route lengths from Syrjälä to cities 1,2,\dots,n.
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n
// 1 \le c \le 10^9

// Example
// Input:
// 3 4
// 1 2 6
// 1 3 2
// 3 2 3
// 1 3 4

// Output:
// 0 5 2

#include<bits/stdc++.h>
using namespace std;

void dijkstra(int src,unordered_map<int,vector<pair<int,int>>>&adj,vector<long long>&cost){
    priority_queue<pair<long long ,int>>pq;
    pq.push({0,src});
    cost[src]=0;
    while(!pq.empty()){
        auto [curcost ,u] = pq.top();
        curcost *= (-1);
        pq.pop();
        if(curcost > cost[u]) continue;
        for(auto &[v,w]:adj[u]){
            long long newcost = cost[u] + w;
            if(newcost < cost[v]){
                cost[v] = newcost;
                pq.push({-newcost,v});
            }
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    unordered_map<int,vector<pair<int,int>>>adj;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    vector<long long>cost(n+1,LLONG_MAX);
    dijkstra(1,adj,cost);
    for(int i=1;i<cost.size();i++){
        cout << cost[i] << " ";
    }
    return 0;
}