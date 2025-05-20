void mulmat(vector<vector<ll>> &a, vector<vector<ll>> b) {
    ll n = a.size();
    ll m = a[0].size();
    ll k = b[0].size();

    vector ret(n, vector<ll>(k, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < k; j++) {
            for (ll l = 0; l < m; l++) {
                ret[i][j] += a[i][l] * b[l][j];
                ret[i][j] %= mod;
            }
        }
    }

    a = ret;
}

void powmat(vector<vector<ll>> &ret, vector<vector<ll>> &a, ll n) {
    while (n) {
        if (n & 1) mulmat(ret, a);
        mulmat(a, a);
        n >>= 1;
    }
}