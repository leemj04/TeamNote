int dfs(int n){
    d[n]=++id;
    s.push(n);
    
    int res=d[n];
    for(int& next : adj[n]){
        if(!d[next]) res=min(res,dfs(next));
        else if(!used[next]) res=min(res,d[next]);
    }
    
    if(res==d[n]){
        vi scc;
        while(true){
            int top=s.top(); s.pop();
            scc.push_back(top);
            used[top]=true;
            if(top==n) break;
        }
        sort(scc.begin(),scc.end());
        ans.push_back(scc);
        cnt++;
    }
    
    return res;
}

void scc(int n){
    for(int i=0;i<n;i++){
        if(!d[i]) dfs(i);
    }
}
