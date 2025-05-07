vector<ll> grp(n+1), size(n+1, 1);
iota(grp.begin(), grp.end(), 0);
function<ll(ll)> _find = [&](ll x) {
    if (x == grp[x]) return x;
    return grp[x] = _find(grp[x]);
};
function<void(ll, ll)> _union = [&](ll x, ll y) {
    x = _find(x);
    y = _find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    grp[y] = x;
    size[x] += size[y];
};
