// Problem Title: Maximum Distance in a Tree

// Problem Description:
// You are given a tree consisting of n nodes.
// Your task is to find, for each node, the maximum distance to another node in the tree.

// Input:

// The first line contains an integer n: the number of nodes. The nodes are numbered 1, 2, ..., n.
// The following n-1 lines describe the edges. Each line contains two integers a and b indicating an edge between nodes a and b.

// Output:

// Print n integers, representing the maximum distance to another node for each node 1, 2, ..., n.
// In this problem you are expected to write code from scratch 

// Constraints:

// 1 ≤ n ≤ 2 × 10^5
// 1 ≤ a, b ≤ n

// Example:

// Input:

// 5
// 1 2
// 1 3
// 3 4
// 3 5

// Output:
// 2 3 2 3 3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
long long mod=1e9+7;
#define pll pair<ll, ll>
void pyes(){ cout<<"YES"<<endl; }
void pno(){ cout<<"NO"<<endl; }

ll lcm(ll num1,ll num2){
    ll lcm, gcd, temp;
    ll a = num1;  
    ll b = num2;     
    while (num2 != 0) {  
        temp = num2;  
        num2 = num1 % num2;  
        num1 = temp;  
    }  
    gcd = num1;  
    lcm = (a * b) / gcd;
    return lcm;    
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

long long power(long long x, long long y) {
    long long res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
long long modInverse(ll x) {
    return power(x, mod - 2);
}
long long modadd(long long a, long long b) {
    return (a % mod + b % mod + 2 * mod) % mod;
}
long long modmult(long long a, long long b) {
    return (a % mod * b % mod) % mod;
}
long long moddiv(long long a, long long b) {
    return (a % mod * modInverse(b)) % mod;
}
void print(ll ans){
    cout << ans << endl;
}
class DSU{
    vector<ll>parent;
    vector<ll>ranks;
    public:
    void init(ll n){
        parent.assign(n+1,-1);
        ranks.assign(n+1,0);
    }
    ll find(ll x){
        if(parent[x]==-1){
            return x;
        }
        return find(parent[x]);
    }
    void uni(ll x,ll y){
        ll xpar=find(x);
        ll ypar=find(y);
        if(ranks[xpar]>ranks[ypar]){
            parent[ypar]=xpar;
        }
        else if(ranks[ypar]>ranks[xpar]){
            parent[xpar]=ypar;
        }
        else{
            parent[ypar]=xpar;
            ranks[xpar]++;
        }
    }
};

ll subtree[200001];
ll dp[200001];
void dfs(ll node,ll papa,vector<ll>adj[]){
    subtree[node]=0;
    for(ll i:adj[node]){
        if(i!=papa){
            dfs(i,node,adj);
            subtree[node]=max(subtree[node],1+subtree[i]);
        }
    }
}
void dfs2(ll node,ll papa,vector<ll>adj[],ll upar){
    dp[node]=max(subtree[node],upar);
    multiset<ll>st;
    st.insert(0);
    for(ll i:adj[node]){
        if(i!=papa){
            st.insert(subtree[i]+2);
        }
    }
    for(ll i:adj[node]){
        if(i!=papa){
            ll idhar=subtree[i]+2;
            auto it=st.lower_bound(idhar);
            st.erase(it);
            auto itt=st.rbegin();
            ll best=max(upar+1,(*itt));
            dfs2(i,node,adj,best);
            st.insert(idhar);
        }
    }
}

// ======================= DO NOT EDIT ABOVE THIS LINE =======================

void solve() {
    

}

// ======================= DO NOT EDIT BELOW THIS LINE =======================

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll t = 1;
    while(t--) {
        solve();
    }
}
