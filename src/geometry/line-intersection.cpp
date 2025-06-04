bool isIntersect(pair<pii, pii> l1, pair<pii, pii> l2) {
    pii p1 = l1.first;
    pii p2 = l1.second;
    pii p3 = l2.first;
    pii p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (p1p2 == 0 && p3p4 == 0) {
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);
        
        return p3 <= p2 && p1 <= p4;
    }
    return p1p2 <= 0 && p3p4 <= 0;
}