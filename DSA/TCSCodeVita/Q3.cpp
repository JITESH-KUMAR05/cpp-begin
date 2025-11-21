// Zoobin
// Problem Description
// The city zoo is currently undergoing significant renovations. To improve both visitor experience and animal welfare, the zookeeping staff have opted to reorganize certain animal habitats.

// The zoo is organized as a network of enclosures connected by designated paths, with no additional space available. Animals cannot be swapped between enclosures because they would disrupt each other if they used the same path. To resolve this, the zookeeper developed a rotational strategy known as the "zoobin approach," where all animals are moved simultaneously to their subsequent locations. This method ensures that each animal arrives at its intended enclosure without crossing paths or creating confusion.

// For example, consider,


// Assume the nodes [1 to 5] as enclosures and edges connecting them as path. zoobin approach involves moving the animals from enclosures1 to 3, 3 to 4, 4 to 2 and 2 to 1 simultaneously. A single rotation is made to achieve this.

// Now given the initial layout of the zoo and an expected layout, find the minimum such rotation required to move the animals to their expected places.

// Constraints
// Number of simple loops present * E <= 50

// Input
// First Line consist of Integer E representing the total path connecting enclosures

// Next E lines will contain two integers A and B separated by space representing the paths between enclosure A and B, of current layout

// Next E lines will contain two integers A and B separated by space representing the paths between enclosure A and B, of Expected layout

// Output
// Single integer representing minimum rotation required to achieve the expected layout

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 6

// 1 2

// 1 3

// 1 5

// 3 4

// 4 5

// 2 4

// 1 2

// 1 4

// 1 5

// 2 3

// 3 4

// 3 5

// Output

// 2

// Explanation

// Assume the zoo layout as the left one below. Initially we will make the round move on 1,2,4 and 5 loop. The resultant layout will be the middle layout below. Next, we will make the move on 1,5,3 and 2 loop resulting in the right layout which is the resultant layout.


// Thus 2 rotations are needed, that's the minimum hence print the same.

// Example2

// Input

// 7

// 5 6

// 6 1

// 5 4

// 3 4

// 2 3

// 1 2

// 5 7

// 1 2

// 1 6

// 2 3

// 2 7

// 3 4

// 4 5

// 5 6

// Output

// 3

// Explanation

// The layout below on left represents the given input. Moving animals on the outer layer results 3 times will result in the expected layout on right.



#include <bits/stdc++.h>
using namespace std;

using Adj = vector<vector<char>>;

int maxNode = 0;
set<int> active_nodes;

vector<int> normalize_cycle(const vector<int>& cyc) {
    int m = cyc.size();
    int pos = 0;
    for (int i = 1; i < m; ++i) if (cyc[i] < cyc[pos]) pos = i;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) a[i] = cyc[(pos + i) % m];
    vector<int> b;
    b.push_back(a[0]);
    for (int i = m - 1; i >= 1; --i) b.push_back(a[i]);
    return min(a, b);
}

set<vector<int>> found_cycles;
vector<char> on_path;

void dfs_cycles(int start, int u, vector<int>& path, const Adj& G) {
    path.push_back(u);
    on_path[u] = 1;
    for (int v : active_nodes) {
        if (!G[u][v]) continue;
        if (v == start) {
            if (path.size() >= 3) found_cycles.insert(normalize_cycle(path));
        } else if (!on_path[v] && v >= start) {
            dfs_cycles(start, v, path, G);
        }
    }
    on_path[u] = 0;
    path.pop_back();
}

set<vector<int>> all_simple_cycles(const Adj& G) {
    found_cycles.clear();
    on_path.assign(maxNode + 1, 0);
    for (int s : active_nodes) {
        vector<int> path;
        dfs_cycles(s, s, path, G);
        on_path[s] = 1;
    }
    return found_cycles;
}

Adj apply_rotation(const Adj& G, const vector<int>& cyc) {
    unordered_map<int,int> perm;
    for (int x : active_nodes) perm[x] = x;
    int m = cyc.size();
    for (int i = 0; i < m; ++i) perm[cyc[i]] = cyc[(i+1)%m];
    unordered_map<int,int> inv;
    for (auto &p : perm) inv[p.second] = p.first;
    Adj H(maxNode+1, vector<char>(maxNode+1, 0));
    for (int u : active_nodes) for (int v : active_nodes) {
        if (u >= v) continue;
        int uu = inv[u], vv = inv[v];
        if (G[uu][vv]) { H[u][v] = H[v][u] = 1; }
    }
    return H;
}

string encode(const Adj& G) {
    string s;
    s.reserve((maxNode+1)*(maxNode+1));
    for (int i = 1; i <= maxNode; ++i) for (int j = 1; j <= maxNode; ++j) s.push_back(G[i][j] ? '1' : '0');
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int E;
    if (!(cin >> E)) return 0;
    vector<pair<int,int>> e1(E), e2(E);
    for (int i = 0; i < E; ++i) {
        int a,b; cin >> a >> b; e1[i] = {a,b}; maxNode = max(maxNode, max(a,b)); active_nodes.insert(a); active_nodes.insert(b);
    }
    for (int i = 0; i < E; ++i) {
        int a,b; cin >> a >> b; e2[i] = {a,b}; maxNode = max(maxNode, max(a,b)); active_nodes.insert(a); active_nodes.insert(b);
    }
    Adj G0(maxNode+1, vector<char>(maxNode+1, 0));
    Adj Gt(maxNode+1, vector<char>(maxNode+1, 0));
    for (auto &p : e1) G0[p.first][p.second] = G0[p.second][p.first] = 1;
    for (auto &p : e2) Gt[p.first][p.second] = Gt[p.second][p.first] = 1;

    queue<Adj> q;
    unordered_map<string,int> dist;
    string s0 = encode(G0), st = encode(Gt);
    dist.reserve(200000);
    dist[s0] = 0;
    q.push(G0);

    while (!q.empty()) {
        Adj cur = q.front(); q.pop();
        int d = dist[encode(cur)];
        if (encode(cur) == st) { cout << d; return 0; }

        auto cycles = all_simple_cycles(cur);
        for (const auto &cyc : cycles) {
            Adj nx = apply_rotation(cur, cyc);
            string enc = encode(nx);
            if (!dist.count(enc)) { dist[enc] = d+1; q.push(nx); }
            vector<int> rev; rev.push_back(cyc[0]);
            for (int i = (int)cyc.size()-1; i >= 1; --i) rev.push_back(cyc[i]);
            Adj nxr = apply_rotation(cur, rev);
            string encr = encode(nxr);
            if (!dist.count(encr)) { dist[encr] = d+1; q.push(nxr); }
        }
    }

    cout << -1;
    return 0;
}