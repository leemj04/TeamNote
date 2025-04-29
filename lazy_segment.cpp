struct LazySeg {
    ll n;
    vector<ll> data, tree, lazy;
    LazySeg(ll n): n(n), data(n) {
        ll h = (ll)ceil(log2(n));
        ll sz = 1ll<<(h+1);
        tree.resize(sz);
        lazy.resize(sz);
    }
    void seg_init(ll idx, ll s, ll e) {
        if (s == e) {
            tree[idx] = data[s];
            return;
        }
        ll mid = (s + e) >> 1;
        seg_init(idx<<1, s, mid);
        seg_init(idx<<1|1, mid+1, e);
        tree[idx] = tree[idx<<1] + tree[idx<<1|1];
    }
    void update_lazy(ll idx, ll s, ll e) {
        if (lazy[idx] != 0) {
            tree[idx] += (e-s+1) * lazy[idx];
            if (s != e) {
                lazy[idx<<1] += lazy[idx];
                lazy[idx<<1|1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }
    void seg_update(ll idx, ll s, ll e, ll l, ll r, ll d) {
        update_lazy(idx, s, e);
        if (l > e || r < s) return;
        if (l <= s && e <= r) {
            tree[idx] += (e-s+1) * d;
            if (s != e) {
                lazy[idx<<1] += d;
                lazy[idx<<1|1] += d;
            }
            return;
        }
        ll mid = (s + e) >> 1;
        seg_update(idx<<1, s, mid, l, r, d);
        seg_update(idx<<1|1, mid+1, e, l, r, d);
        tree[idx] = tree[idx<<1] + tree[idx<<1|1];
    }
    ll seg_query(ll idx, ll s, ll e, ll l, ll r) {
        update_lazy(idx, s, e);
        if (l > e || r < s) return 0;
        if (l <= s && e <= r) return tree[idx];
        ll mid = (s + e) >> 1;
        ll lsum = seg_query(idx<<1, s, mid, l, r);
        ll rsum = seg_query(idx<<1|1, mid+1, e, l, r);
        return lsum + rsum;
    }
    // seg.init(v);
    void init(const vector<ll>&v) {
        data = v;
        seg_init(1, 0, n-1);
    }
    // seg.update(l-1, r-1, d);
    void update(ll l, ll r, ll d) {
        seg_update(1, 0, n-1, l, r, d);
    }
    // seg.query(l-1, r-1);
    ll query(ll l, ll r) {
        if (l > r) return 0;
        return seg_query(1, 0, n-1, l, r);
    }
};
