struct Pos{
    ll x,y,p,q;

    Pos(){}
    Pos(ll a,ll b):x(a),y(b),p(0),q(0){}

    bool operator < (const Pos& rhs) const{
        if(p*rhs.q!=q*rhs.p) return p*rhs.q>q*rhs.p;
        if(y!=rhs.y) return y<rhs.y;
        return x<rhs.x;
    }
};

int CCW(Pos& p1,Pos& p2,Pos& p3){
    ll x1=p2.x-p1.x;
    ll x2=p3.x-p2.x;
    ll y1=p2.y-p1.y;
    ll y2=p3.y-p2.y;

    if(x1*y2-x2*y1>0) return 1;
    else if(x1*y2-x2*y1==0) return 0;
    return -1;
}
