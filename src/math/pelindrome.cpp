ll peli(string n) {
    ll len = n.size(), cnt = 0;
    for (int i = 1; i < len; i++) cnt += 9 * pow(10, (i - 1) / 2);
    string half = n.substr(0, (len + 1) / 2);
    ll halfNum = stoll(half), base = pow(10, (len - 1) / 2);
    cnt += halfNum - base;
    string rev = half.substr(0, len / 2);
    reverse(rev.begin(), rev.end());
    string full = half + rev;
    if (full <= n) cnt++;
    return cnt;
}