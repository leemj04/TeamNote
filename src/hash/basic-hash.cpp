struct chash {
    size_t operator()(const pll& _x) const {
        auto [x, y] = _x;
        size_t hx = hash<ll>()(x);
        size_t hy = hash<ll>()(y);
        return ((hx<<22) | (hx>>22)) ^ hy;
    }
    size_t operator()(const tuple<ll, string, ll>& _x) const {
        auto [x, y, z] = _x;
        size_t hx = hash<ll>()(x);
        size_t hy = hash<string>()(y);
        size_t hz = hash<ll>()(z);
        return ((hx<<22) | (hx>>22)) ^ ((hy<<17) | (hy>>17)) ^ hz;
    }
};

int main() {
    unordered_map<pll, ll, chash> a;
}