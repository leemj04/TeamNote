// p(n) with O(n^(3/2))
for(int i=1; i<=500000; i++) {
    for(int j=1; j*(3*j-1)/2<=i; j++)
        P[i] += (j%2?1:-1)*P[i-j*(3*j-1)/2], P[i] %= MOD;
    for(int j=1; j*(3*j+1)/2<=i; j++)
        P[i] += (j%2?1:-1)*P[i-j*(3*j+1)/2], P[i] %= MOD;
    P[i] += MOD, P[i] %= MOD;
}