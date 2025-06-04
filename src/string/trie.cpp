struct Node {
    Node* child[10];
    bool isFinished;
    
    Node() {
        memset(child, 0, sizeof(child));
        isFinished = false;
    }
    ~Node() {
        for(int i=0; i<10; ++i) if(child[i]) {
            delete child[i];
        }
    }
    
    void insert(const char* ch) {
        if(*ch == '\0') {
            isFinished = true;
            return;
        }
        
        int cur = *ch - '0';
        if(!child[cur]) child[cur] = new Node();
        child[cur]->insert(ch+1);
    }
    
    bool traverse() {
        bool leaf = true, ret = false;
        for(int i=0;i<10;i++){
            if(!child[i]) continue;
            leaf = false;
            ret |= child[i]->traverse();
        }
        
        if(isFinished && !leaf) return true;
        
        return ret;
    }
};
