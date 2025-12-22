// Minimum Holes
// Problem Description
// The cardboard container measures n × m and features internal partitions. A top-view illustration is provided, showing the internal partitions within the container. The task is to create holes in the partition walls so that each partition contains at least one hole. Determine the minimum number of holes required. An example below illustrates the standard top view of such a cardboard box with its internal divisions.



// An input is considered invalid if the resulting partitions are neither squares nor rectangles.

// Constraints
// 1 < N <= 50

// 1 <= n, m <= 100

// 0 <= x, y <= 100

// Each partition line will be oriented parallel to either the X-axis or the Y-axis.

// Partition lines may overlap.

// Input
// The first line contains two space-separated integers, representing the dimensions n and m of the cardboard box.

// The subsequent line provides an integer N, which specifies the number of internal partition lines within the box.

// Each of the following N lines contains four space-separated integers, denoting the start and end coordinates of a partition in the format: x1 y1 x2 y2.

// Output
// Output a single integer representing the minimum number of holes required so that each partition contains at least one hole. If the input is invalid, display "Invalid".

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 5 4

// 5

// 1 0 1 3

// 1 2 5 2

// 1 1 1 4

// 3 1 3 4

// 0 1 5 1

// Output

// 4

// Explanation

// The cardboard structure given in the above input is shown below.


// The input specifies that the cardboard box has dimensions 5×4 and contains 4 partition lines. These lines divide the box into 7 separate partitions.

// As illustrated in the figure below, it is possible to create four holes while ensuring that each partition contains at least one hole.


// Please note that this represents one potential solution that achieves the minimum number of holes.

// Example 2

// Input

// 4 8

// 9

// 1 4 1 8

// 0 6 4 6

// 1 0 1 4

// 1 3 4 3

// 2 3 2 6

// 3 6 3 8

// 3 0 3 3

// 1 0 1 2

// 3 3 3 5

// Output

// Invalid

// Explanation

// The cardboard structure given in the above input is shown below.


// The provided partitions are deemed invalid because some are incomplete and do not conform to square or rectangular shapes.

#include <bits/stdc++.h>

using namespace std;

const int MAX_DIM = 205;
int board[MAX_DIM][MAX_DIM];
int roomId[MAX_DIM][MAX_DIM];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct MatchSolver {
    int n;
    vector<vector<int>> adj;
    vector<int> match;
    vector<int> p;
    vector<int> base;
    vector<int> q;
    vector<bool> in_blossom;
    vector<bool> in_queue;

    MatchSolver(int nodes) : n(nodes), adj(nodes), match(nodes, -1), p(nodes), base(nodes), in_queue(nodes) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int getLCA(int root, int u, int v) {
        vector<bool> visited(n, false);
        while (true) {
            u = base[u];
            visited[u] = true;
            if (match[u] == -1) break;
            u = p[match[u]];
        }
        while (true) {
            v = base[v];
            if (visited[v]) return v;
            v = p[match[v]];
        }
    }

    void markBlossom(int u, int b, int child) {
        while (base[u] != b) {
            in_blossom[base[u]] = in_blossom[base[match[u]]] = true;
            p[u] = child;
            child = match[u];
            u = p[match[u]];
        }
    }

    int bfs(int s) {
        fill(in_queue.begin(), in_queue.end(), false);
        fill(p.begin(), p.end(), -1);
        iota(base.begin(), base.end(), 0);

        q.clear();
        q.push_back(s);
        in_queue[s] = true;

        int head = 0;
        while (head < q.size()) {
            int u = q[head++];
            for (int v : adj[u]) {
                if (base[u] == base[v] || match[u] == v) continue;

                if (v == s || (match[v] != -1 && p[match[v]] != -1)) {
                    int curBase = getLCA(s, u, v);
                    in_blossom.assign(n, false);
                    markBlossom(u, curBase, v);
                    markBlossom(v, curBase, u);
                    
                    for (int i = 0; i < n; ++i) {
                        if (in_blossom[base[i]]) {
                            base[i] = curBase;
                            if (!in_queue[i]) {
                                in_queue[i] = true;
                                q.push_back(i);
                            }
                        }
                    }
                } else if (p[v] == -1) {
                    p[v] = u;
                    if (match[v] == -1) return v;
                    
                    int next = match[v];
                    in_queue[next] = true;
                    q.push_back(next);
                }
            }
        }
        return -1;
    }

    int calcMaxMatching() {
        int matches = 0;
        for (int i = 0; i < n; ++i) {
            if (match[i] == -1) {
                int pathEnd = bfs(i);
                if (pathEnd != -1) {
                    while (pathEnd != -1) {
                        int prev = p[pathEnd];
                        int next = match[prev];
                        match[pathEnd] = prev;
                        match[prev] = pathEnd;
                        pathEnd = next;
                    }
                    matches++;
                }
            }
        }
        return matches;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    if (!(cin >> H >> W)) return 0;

    int lineCount;
    cin >> lineCount;

    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            board[i][j] = 0;
            roomId[i][j] = -1;
        }
    }

    for (int k = 0; k < lineCount; k++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        r1 *= 2; c1 *= 2;
        r2 *= 2; c2 *= 2;

        if (r1 == r2) {
            if (c1 > c2) swap(c1, c2);
            for (int j = c1; j <= c2; j++) board[r1][j] = 1;
        } else {
            if (r1 > r2) swap(r1, r2);
            for (int i = r1; i <= r2; i++) board[i][c1] = 1;
        }
    }

    int rooms = 0;
    int maxR = 2 * H;
    int maxC = 2 * W;

    for (int i = 1; i < maxR; i += 2) {
        for (int j = 1; j < maxC; j += 2) {
            if (roomId[i][j] == -1) {
                int currentRoom = rooms++;
                queue<pair<int, int>> q;
                q.push({i, j});
                roomId[i][j] = currentRoom;

                int cellCount = 0;
                int minX = i, maxX = i;
                int minY = j, maxY = j;

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();
                    cellCount++;

                    int r = curr.first;
                    int c = curr.second;

                    minX = min(minX, r);
                    maxX = max(maxX, r);
                    minY = min(minY, c);
                    maxY = max(maxY, c);

                    for (int d = 0; d < 4; d++) {
                        int nr = r + dx[d] * 2;
                        int nc = c + dy[d] * 2;
                        int wr = r + dx[d];
                        int wc = c + dy[d];

                        if (nr > 0 && nr < maxR && nc > 0 && nc < maxC) {
                            if (board[wr][wc] == 0 && roomId[nr][nc] == -1) {
                                roomId[nr][nc] = currentRoom;
                                q.push({nr, nc});
                            }
                        }
                    }
                }

                int h = (maxX - minX) / 2 + 1;
                int w = (maxY - minY) / 2 + 1;
                
                if (cellCount != h * w) {
                    cout << "Invalid" << endl;
                    return 0;
                }
            }
        }
    }

    if (rooms == 0) {
        cout << 0 << endl;
        return 0;
    }

    set<pair<int, int>> edges;
    for (int i = 0; i <= maxR; i++) {
        for (int j = 0; j <= maxC; j++) {
            if (board[i][j] == 1) {
                if (i % 2 == 0 && j % 2 != 0) {
                    if (i > 0 && i < maxR) {
                        int rA = roomId[i - 1][j];
                        int rB = roomId[i + 1][j];
                        if (rA != -1 && rB != -1 && rA != rB) {
                            if (rA > rB) swap(rA, rB);
                            edges.insert({rA, rB});
                        }
                    }
                }
                else if (j % 2 == 0 && i % 2 != 0) {
                    if (j > 0 && j < maxC) {
                        int rA = roomId[i][j - 1];
                        int rB = roomId[i][j + 1];
                        if (rA != -1 && rB != -1 && rA != rB) {
                            if (rA > rB) swap(rA, rB);
                            edges.insert({rA, rB});
                        }
                    }
                }
            }
        }
    }

    MatchSolver solver(rooms);
    for (auto e : edges) {
        solver.addEdge(e.first, e.second);
    }

    int matching = solver.calcMaxMatching();
    cout << rooms - matching << endl;

    return 0;
}