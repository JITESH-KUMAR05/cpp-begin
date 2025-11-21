








#include <bits/stdc++.h>
using namespace std;

struct SegKey {
    pair<int,int> a,b;
    SegKey(int x1,int y1,int x2,int y2){
        a = {x1,y1}; b = {x2,y2};
        if (a > b) swap(a,b);
    }
    bool operator<(SegKey const& o) const {
        if (a!=o.a) return a<o.a;
        return b<o.b;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin>>N)) return 0;
    set<SegKey> segments;
    set<pair<int,int>> verts;
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        segments.insert(SegKey(x1,y1,x2,y2));
        verts.insert({x1,y1}); verts.insert({x2,y2});
    }

    // helper to check exact segment presence
    auto has_seg = [&](int x1,int y1,int x2,int y2)->bool{
        SegKey k(x1,y1,x2,y2);
        return segments.count(k)>0;
    };

    // find all unit faces (bottom-left corner at (x,y))
    vector<pair<int,int>> faces; // store bottom-left coordinates
    map<pair<int,int>,int> face_index;
    for(auto v : verts){
        int x = v.first, y = v.second;
        if (verts.count({x+1,y}) && verts.count({x,y+1}) && verts.count({x+1,y+1})){
            if (has_seg(x,y,x+1,y) && has_seg(x+1,y,x+1,y+1) && has_seg(x,y+1,x+1,y+1) && has_seg(x,y,x,y+1)){
                int id = faces.size();
                faces.push_back({x,y});
                face_index[{x,y}] = id;
            }
        }
    }

    int F = faces.size();
    if(F==0){
        cout << 0 << '\n';
        return 0;
    }

    // build net adjacency (edges between faces that share an edge)
    vector<vector<int>> net_adj(F);
    for(int i=0;i<F;i++){
        auto [x,y] = faces[i];
        vector<pair<int,int>> neigh = {{x,y+1},{x+1,y},{x,y-1},{x-1,y}};
        for(auto nb : neigh){
            if(face_index.count(nb)){
                net_adj[i].push_back(face_index[nb]);
            }
        }
    }

    // compute possible box dimensions (L,W,H) such that surface area = F
    vector<tuple<int,int,int>> candidates;
    int MAX_WH = 26; // coordinates limited to 0..25 roughly -> surface dims small
    for(int L=1; L<=MAX_WH; ++L){
        for(int W=1; W<=MAX_WH; ++W){
            for(int H=1; H<=MAX_WH; ++H){
                long long surface = 2LL*(L*W + L*H + W*H);
                if(surface == F) candidates.emplace_back(L,W,H);
                if(surface > F && W==1 && H==1) break;
            }
        }
    }

    if(candidates.empty()){
        cout << 0 << '\n';
        return 0;
    }

    auto build_surface = [&](int L,int W,int H,
                             vector<vector<int>>& surf_adj,
                             vector<tuple<int,int,int>>& tile_info)->void{
        tile_info.clear();
        
        int counts[6];
        counts[0] = W*H; counts[1] = W*H; counts[2] = L*H; counts[3] = L*H; counts[4] = L*W; counts[5] = L*W;
        vector<vector<vector<int>>> face_index_map(6);
        for(int f=0; f<6; ++f){
            // dims:
            int di = 0, dj = 0;
            if(f==0||f==1){ di = W; dj = H; } // (y,z)
            if(f==2||f==3){ di = L; dj = H; } // (x,z)
            if(f==4||f==5){ di = L; dj = W; } // (x,y)
            face_index_map[f].assign(di, vector<int>(dj, -1));
        }
        int tid = 0;
        for(int f=0; f<6; ++f){
            int di=0,dj=0;
            if(f==0||f==1){ di = W; dj = H; }
            if(f==2||f==3){ di = L; dj = H; }
            if(f==4||f==5){ di = L; dj = W; }
            for(int i=0;i<di;++i) for(int j=0;j<dj;++j){
                face_index_map[f][i][j] = tid++;
                tile_info.emplace_back(f,i,j);
            }
        }
        surf_adj.assign(tid, {});
       
        auto gid = [&](int f,int i,int j)->int{
            return face_index_map[f][i][j];
        };
        
        for(int t=0;t<tid;++t){
            auto [f,i,j] = tile_info[t];
            int di,dj;
            if(f==0||f==1){ di=W; dj=H; }
            if(f==2||f==3){ di=L; dj=H; }
            if(f==4||f==5){ di=L; dj=W; }
            
            auto add_edge = [&](int nf,int ni,int nj){
                if(nf<0) return;
                int nt = gid(nf,ni,nj);
                surf_adj[t].push_back(nt);
            };
            // +i
            if(i+1 < di){
                add_edge(f, i+1, j);
            } else {
                
                if(f==0){ 
                    if(W>0){
                        int nf = 2; int ni = 0; int nj = j;
                        add_edge(nf,ni,nj);
                    }
                } else if(f==1){ 
                    if(W>0){
                        int nf = 3; int ni = 0; int nj = j;
                        add_edge(nf,ni,nj);
                    }
                } else if(f==2){ 
                    int nf = 1; int ni = i; int nj = j; 
                    add_edge(nf,ni,nj);
                } else if(f==3){ // -Y
                    int nf = 0; int ni = i; int nj = j;
                    add_edge(nf,ni,nj);
                } else if(f==4){ // +Z
                    int nf = 0; int ni = j; int nj = ???; // complex
                }
                // The explicit full mapping is long and error-prone; instead we will build the cube in 3D coordinates and determine adjacency there (simpler).
            }
            // We'll postpone: break out to implement adjacency via actual 3D position of tile centers.
        }
        // fallback: instead of hand-mapping, rebuild using 3D tile center coordinates:
        // Build mapping of each surface tile to its 3D unit-square cell (we pick integer coordinates for cube cells), then adjacency if tile centers share an edge along surface (and both on surface).
        // Rebuild a simpler structure:
        surf_adj.assign(0, {});
        tile_info.clear();
        // We'll represent cuboid with cells 0..L-1,0..W-1,0..H-1. Each surface tile corresponds to a face of a cell that lies on exterior.
        // tiles list: for each cell (x,y,z) and each face dir (0..5), if face is exterior, that's a surface tile.
        struct TI { int x,y,z,dir; };
        vector<TI> tiles;
        auto is_exterior = [&](int x,int y,int z,int dir)->bool{
            if(dir==0){ // +X face of cell at x => exterior if x==L-1
                return x==L-1;
            } else if(dir==1){ // -X
                return x==0;
            } else if(dir==2){ // +Y
                return y==W-1;
            } else if(dir==3){ // -Y
                return y==0;
            } else if(dir==4){ // +Z
                return z==H-1;
            } else { // -Z
                return z==0;
            }
        };
        for(int x=0;x<L;++x) for(int y=0;y<W;++y) for(int z=0;z<H;++z){
            for(int d=0;d<6;++d){
                if(is_exterior(x,y,z,d)){
                    tiles.push_back({x,y,z,d});
                }
            }
        }
        int M = tiles.size();
        tile_info.resize(M);
        for(int t=0;t<M;++t){
            tile_info[t] = make_tuple(tiles[t].dir, tiles[t].x, tiles[t].y); 
        }
        surf_adj.assign(M, {});
        auto same_surface_adj = [&](int a,int b)->bool{
            return false;
        };
        };


    auto build_surface_graph = [&](int L,int W,int H,
                                   vector<vector<int>>& adj_out,
                                   vector<tuple<int,int,int,int>>& info_out)->void{
        struct Tile { int x,y,z,dir; };
        vector<Tile> tiles;
        auto is_exterior = [&](int x,int y,int z,int dir)->bool{
            if(dir==0) return x==L-1; // +X
            if(dir==1) return x==0;   // -X
            if(dir==2) return y==W-1; // +Y
            if(dir==3) return y==0;   // -Y
            if(dir==4) return z==H-1; // +Z
            return z==0;              // -Z
        };
        for(int x=0;x<L;++x) for(int y=0;y<W;++y) for(int z=0;z<H;++z){
            for(int d=0;d<6;++d){
                if(is_exterior(x,y,z,d)){
                    tiles.push_back({x,y,z,d});
                }
            }
        }
        int M = tiles.size();
        adj_out.assign(M, {});
        info_out.clear();
        for(auto &t: tiles) info_out.emplace_back(t.x,t.y,t.z,t.dir);
       
        auto face_vertices = [&](int cx,int cy,int cz,int dir)->vector<array<int,3>>{
            
            vector<array<int,3>> v(4);
            if(dir==0){ // +X face at x+1 plane for cell (x,y,z)
                int X = cx+1;
                v[0] = {X, cy, cz};
                v[1] = {X, cy+1, cz};
                v[2] = {X, cy+1, cz+1};
                v[3] = {X, cy, cz+1};
            } else if(dir==1){ // -X face at x plane
                int X = cx;
                v[0] = {X, cy, cz};
                v[1] = {X, cy, cz+1};
                v[2] = {X, cy+1, cz+1};
                v[3] = {X, cy+1, cz};
            } else if(dir==2){ // +Y face at y+1 plane
                int Y = cy+1;
                v[0] = {cx, Y, cz};
                v[1] = {cx+1, Y, cz};
                v[2] = {cx+1, Y, cz+1};
                v[3] = {cx, Y, cz+1};
            } else if(dir==3){ // -Y face at y plane
                int Y = cy;
                v[0] = {cx, Y, cz};
                v[1] = {cx, Y, cz+1};
                v[2] = {cx+1, Y, cz+1};
                v[3] = {cx+1, Y, cz};
            } else if(dir==4){ // +Z face at z+1 plane
                int Z = cz+1;
                v[0] = {cx, cy, Z};
                v[1] = {cx+1, cy, Z};
                v[2] = {cx+1, cy+1, Z};
                v[3] = {cx, cy+1, Z};
            } else { // -Z face at z plane
                int Z = cz;
                v[0] = {cx, cy, Z};
                v[1] = {cx, cy+1, Z};
                v[2] = {cx+1, cy+1, Z};
                v[3] = {cx+1, cy, Z};
            }
            return v;
        };

        auto share_edge = [&](const Tile &A, const Tile &B)->bool{
            
            auto va = face_vertices(A.x,A.y,A.z,A.dir);
            auto vb = face_vertices(B.x,B.y,B.z,B.dir);
            int common = 0;
            for(auto &pa: va) for(auto &pb: vb) if(pa==pb) ++common;
            return common==2;
        };

        for(int i=0;i<M;++i) for(int j=i+1;j<M;++j){
            Tile A = tiles[i], B = tiles[j];
            if(share_edge(A,B)){
                adj_out[i].push_back(j);
                adj_out[j].push_back(i);
            }
        }
    };

    auto try_embed = [&](int L,int W,int H)->long long{
        vector<vector<int>> surf_adj;
        vector<tuple<int,int,int,int>> info;
        build_surface_graph(L,W,H,surf_adj,info);
        int M = surf_adj.size();
        if(M != F) return 0; 
        vector<int> map_net_to_tile(F, -1);
        vector<int> map_tile_to_net(M, -1);
        vector<int> order(F);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a,int b){ return net_adj[a].size() > net_adj[b].size(); });

        function<bool(int)> dfs = [&](int pos)->bool{
            if(pos==F) return true;
            int u = order[pos];
            if(map_net_to_tile[u] != -1) return dfs(pos+1);
            for(int t=0;t<M;++t){
                if(map_tile_to_net[t] != -1) continue;
                
                bool ok = true;
                for(int v : net_adj[u]){
                    if(map_net_to_tile[v] != -1){
                        int tv = map_net_to_tile[v];
                        
                        bool found=false;
                        for(int w: surf_adj[t]) if(w==tv){ found=true; break; }
                        if(!found){ ok=false; break; }
                    }
                }
                if(!ok) continue;
                
                map_net_to_tile[u] = t;
                map_tile_to_net[t] = u;
                if(dfs(pos+1)) return true;
                map_net_to_tile[u] = -1;
                map_tile_to_net[t] = -1;
            }
            return false;
        };

        bool ok = dfs(0);
        if(ok) return 1LL * L * W * H;
        return 0;
    };

    for(auto &tpl : candidates){
        int L,W,H; tie(L,W,H) = tpl;
        long long vol = try_embed(L,W,H);
        if(vol>0){
            cout << vol << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}