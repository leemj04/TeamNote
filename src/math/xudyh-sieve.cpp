// S(N) = sum of k = 1..N, phi(k) with O(N^(3/4)) complexity
#define MAX 500003

ll phi[MAX];
std::unordered_map<int, ll> mp;

void preprocess() {
    for (i = 1; i < MAX; ++i) {
		phi[i] += i;
		for (j = 2; j*i < MAX; ++j) phi[j*i] -= phi[i];
		phi[i] += phi[i-1];
	}
}

ll S(ll x) {
	int i, j;
	if (x < MAX) return phi[x];
	if (mp.find(x) != mp.end()) return mp[x];
	ll ret = x * (x + 1LL) / 2;
	for (i = 2; i <= x; i = j+1) {
		j = x / (x / i);
		ret -= (j - i + 1) * S(x / i);
	}
	return mp[x] = ret;
}