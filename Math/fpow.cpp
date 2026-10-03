int fpow(int a, int b){
    int ret = 1;
    for(;b; b>>=1, a=a*a%MOD) if(b&1) ret = ret*a%MOD;
    return ret;
}