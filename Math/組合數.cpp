const int MXN = 1e6 + 5;
int fac[MXN], inv[MXN];
fac[0] = 1;
for(int i = 1 ; i < MXN ; i++) fac[i] = fac[i - 1] * i % MOD;
inv[MXN - 1] = fpow(fac[MXN - 1], MOD - 2);
for(int i = N - 2 ; i >= 0 ; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
int C(int n, int k){return fac[n] * inv[k] % MOD * inv[n - k] % MOD;}