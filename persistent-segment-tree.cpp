struct PST{
    ll n;
    vector<ll> data;
    vector<vector<pll>> tree;
    PST(ll n):n(n), data(n), tree(4*n) {}
    void seg_init(ll idx, ll s, ll e){
        if(s==e){
            tree[idx].push_back({0, data[s]});
            return;
        }
        ll mid=(s+e)>>1;
        seg_init(idx<<1, s, mid);
        seg_init(idx<<1|1, mid+1, e);
        tree[idx].push_back({0, tree[idx<<1].back().second+tree[idx<<1|1].back().second});
    }
    void seg_update(ll idx, ll s, ll e, ll pos, ll val, ll ord){
        if(pos<s || pos>e) return;
        if(s==e){
            tree[idx].push_back({ord, val});
            return;
        }
        ll mid=(s+e)>>1;
        seg_update(idx<<1, s, mid, pos, val, ord);
        seg_update(idx<<1|1, mid+1, e, pos, val, ord);
        tree[idx].push_back({ord, tree[idx<<1].back().second+tree[idx<<1|1].back().second});
    }
    ll seg_query(ll idx, ll s, ll e, ll l, ll r, ll ord){
        if(l>e || r<s)return 0;
        if(l<=s && e<=r) {
            return prev(ranges::lower_bound(tree[idx], pll(ord, LLONG_MAX)))->second;
        }
        ll mid=(s+e)>>1;
        return seg_query(idx<<1, s, mid, l, r, ord)
                +seg_query(idx<<1|1, mid+1, e, l, r, ord);
    }
    void init(const vector<ll>&arr){
        data=arr;
        seg_init(1, 0, n-1);
    }
    void update(ll pos, ll val, ll ord){
        seg_update(1, 0, n-1, pos, val, ord);
    }
    ll query(ll l, ll r, ll ord){
        if(l>r)return 0;
        else return seg_query(1, 0, n-1, l, r, ord);
    }
};
