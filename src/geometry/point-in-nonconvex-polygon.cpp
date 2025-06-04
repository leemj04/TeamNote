bool isInside_nonconvex(vector <pll>& CH, pll point) {
    int cnt = 0;
    for (int i = 0; i < CH.size(); i++) {
        pll p1 = CH[i], p2 = CH[(i + 1) % CH.size()];
        if (p1.second < p2.second) swap(p1, p2);
 
        pll v1 = p2v(p1, point);
        pll v2 = p2v(point, p2);
 
        if (ccw(v1, v2) == 0) {
            if (min(p1.first, p2.first) <= point.first && point.first <= max(p1.first, p2.first)
                && min(p1.second, p2.second) <= point.second && point.second <= max(p1.second, p2.second))
                return true;
        }
 
        if (max(p1.first, p2.first) < point.first) continue;
        if (p1.second <= point.second) continue;
        if (p2.second > point.second) continue;
        if (min(p1.first, p2.first) > point.first) cnt++;
        else if (ccw(v1, v2) > 0) cnt++;
    }
 
    return cnt % 2;
}