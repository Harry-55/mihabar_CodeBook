struct trie{
    trie *nxt[26];//01trie改2
    int cnt; //紀錄有多少個字串以此節點結尾
    int sz;  //有多少字串的前綴包括此節點
    trie():cnt(0),sz(0){
        memset(nxt,0,sizeof(nxt));
    }
};
trie *root = new trie();
 	void insert(string& s){
    trie *now = root;
    for(auto i:s){//01trie改高位元往下
        now->sz++;
        if(now->nxt[i-'a'] == NULL){
            now->nxt[i-'a'] = new trie();
        }
        now = now->nxt[i-'a'];
    }
    now->cnt++;
    now->sz++;
}
int query_prefix(string& s){
    trie *now = root;
    for(auto i:s){
        if(now->nxt[i-'a'] == NULL){
            return 0;
        }
        now = now->nxt[i-'a']; 
    }
    return now->sz;
}
int query_count(string& s){
    trie *now = root;
    for(auto i:s){
        if(now->nxt[i-'a'] == NULL){
            return 0;
        }
        now = now->nxt[i-'a'];
    }
    return now->cnt;
}
