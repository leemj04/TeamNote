// ll tree[n], arr[n];
void fenwick_update(int idx, ll val){
    for(;idx<=n;idx+=idx&-idx) tree[idx] += val;
}

ll fenwick_query(int idx){
    ll res = 0;
    for(;idx;idx-=idx&-idx) res += tree[idx];
    return res;
}

void fenwick_build(){
    for(int i=1;i<=n;i++) fenwick_update(i, arr[i]);
}
