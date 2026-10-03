struct BIT{
    int n;
    vector<int> bit;
    #define lowbit(x) (x & -x)
    void init(int _n){
        n = _n + 2;
        bit = vector<int>(n, 0);
    }
    int _query(int x){
        int ans = 0;
        for( ; x > 0 ; x -= lowbit(x)) ans += bit[x]; 
        return ans;
    }
    void _upd(int x, int v){
        for(; x <= n ; x += lowbit(x)) bit[x] += v;
    }   
    void upd(int x, int v) {_upd(x + 1, v);}
    int query(int x) {return _query(x + 1);}
    int query(int l, int r) {return (query(r) - query(l - 1));}
};
//搭配字元修改 + Hash時的操作
void update(int pos, int ch){
    BIT.update(pos, (ch - s[pos]) * p[pos] % MOD);
    revBIT.update(n-pos+1, (ch-s[pos]) * p[n-pos+1] % MOD);
}