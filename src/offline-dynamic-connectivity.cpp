struct OFDC {
    vector<tlll> query;
    vector<ll> grp, sz;
    vector<vector<pll>> tree;
    map<pll, ll> conn;
    ll n, q;
    OFDC(ll n, ll q): n(n), q(q), query(q+1), grp(n+1), sz(n+1, 1), tree(4*(q+1)) {
        iota(grp.begin(), grp.end(), 0);
    }
    void update(ll node, ll s, ll e, ll l, ll r, pll edge) {
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[node].push_back(edge);
            return;
        }
        ll mid = (s + e) >> 1;
        update(node << 1, s, mid, l, r, edge);
        update(node << 1 | 1, mid + 1, e, l, r, edge);
    }
    ll _find(ll x) {
        if (grp[x] == x) return x;
        return _find(grp[x]);
    }
    pll _union(ll x, ll y) {
        x = _find(x), y = _find(y);
        if (x == y) return {-1, -1};
        if (sz[x] < sz[y]) swap(x, y);
        grp[y] = x;
        sz[x] += sz[y];
        return {x, y};
    }
    void _delete(ll u, ll v) {
        sz[u] -= sz[v];
        grp[v] = v;
    }
    void dfs(ll node, ll s, ll e) {
        vector<pll> rconn;
        for (auto& [u, v]: tree[node]) {
            auto [x, y] = _union(u, v);
            if (x != -1) rconn.push_back({x, y});
        }
        if (s == e) {
            if (get<0>(query[s]) == 3) {
                cout << (_find(get<1>(query[s])) ==
                    _find(get<2>(query[s]))) << '\n';
            }
        } else {
            ll mid = (s + e) >> 1;
            dfs(node << 1, s, mid);
            dfs(node << 1 | 1, mid + 1, e);
        }
        for (auto& [u, v]: rconn) {
            _delete(u, v);
        }
    }
    void run() {
        for (ll i = 0; i < q; i++) {
            auto& [type, u, v] = query[i];
            cin >> type >> u >> v;
            if (u > v) swap(u, v);
            if (type == 1) {
                conn[{u, v}] = i;
            } else if (type == 2) {
                update(1, 0, q, conn[{u, v}], i, {u, v});
                conn.erase({u, v});
            }
        }
        for (auto&[edge, time] : conn) {
            auto&[u, v] = edge;
            update(1, 0, q, time, q, {u, v});
        }
        dfs(1, 0, q);
    }
};
