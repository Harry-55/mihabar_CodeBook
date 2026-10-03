typedef long long LL;

LL mul(LL a, LL b, LL m) { return (__int128)a * b % m; }
LL add(LL a, LL b, LL m) { return ((__int128)a + b) % m; }
// with mypow / witness / miller_rabin
LL f(LL x, LL c, LL mod) { return add(mul(x, x, mod), c, mod); }
LL pollard_rho(LL n) {
    LL c = 1, x = 0, y = 0, p = 2, q, t = 0;
    while (t++ % 128 || __gcd(p, n) == 1) {
        if (x == y) c++, y = f(x = 2, c, n);
        if ((q = mul(p, abs(x - y), n))) p = q;
        x = f(x, c, n); y = f(f(y, c, n), c, n);
    }
    return __gcd(p, n);
}

