int jump[N][logN];
for(int i = 1; i <= log2(N); i++){ 
    for(int now = 1; now <= N; now++){
        jump[now][i] = jump[jump[now][i - 1]][i - 1];
    }
}
//查詢
int query(int x,int k){
    int i = log2(k);
    while(k){
        if((1<<i) <= k){
            x = jump[x][i];
            k -= (1<<i);
        }
        i--;
    }
    return x;
}