void solve(int n) {
    set<Segment> s;
    s.insert({n, 1, 0});  // sort by (len, L) desc, so len first, then -L
    vector<int> ans(n+1);
    for(int i = 1; i <= n; ++i) {
        auto seg = *s.begin(); 
        s.erase(s.begin());
        int L = seg.l, R = seg.r;
        int mid = (L + R) >> 1;
        ans[mid] = i;
        if (L <= mid-1) s.insert({mid-L, L, mid-1});
        if (mid+1 <= R) s.insert({R-mid, mid+1, R});
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << "\n";
}
