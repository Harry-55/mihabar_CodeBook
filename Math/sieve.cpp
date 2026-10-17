/* 12721, 13331, 14341, 75577, 123457, 222557, 556679
* 999983, 1097774749, 1076767633, 100102021, 999997771
* 1001010013, 1000512343, 987654361, 999991231
* 999888733, 98789101, 987777733, 999991921, 1010101333
* 1010102101, 1000000000039, 1000000000000037
* 2305843009213693951, 4611686018427387847
* 9223372036854775783, 18446744073709551557 */
const int MXN = 1e8 + 50;
const int SQRTMXN = 1e4 + 50;
bitset<MXN> isprime;
vector<int> p(MXN, 0);
void sieve() {
    isprime[1] = 1;
    for (int i = 2; i <= SQRTMXN; i++) {
        if (!isprime[i]) 
            for (int j = i * i; j < MXN; j += i) {
                isprime[j] = 1;
                if(!p[j]) p[j] = i;
            }
    }
}
vector<int> factor(int x) {
    vector<int> fac{1};
    while (x > 1) {
        int prime = isprime[x] ? p[x] : x;
        int cnt = 0;
        while (x % prime == 0) {
            x /= prime;
            cnt++;
        }
        int sz = fac.size();
        int pw = 1;
        for (int k = 1; k <= cnt; k++) {
            pw *= prime;
            for (int i = 0; i < sz; i++)
                fac.push_back(fac[i] * pw);
        }
    }
    return fac;
}