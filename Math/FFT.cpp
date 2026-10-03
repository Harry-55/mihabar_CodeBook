typedef long long ll;
typedef long double ld;
typedef complex<ld> cplx;
const int MAXN = 262144;          // 必須是 2^k，且 >= 結果長度
const ld PI = acosl(-1);
const cplx I(0, 1);
cplx omega[MAXN + 1];
cplx arr[MAXN + 1];
// 使用前先呼叫一次
void pre_fft() {
    for (int i = 0; i <= MAXN; i++)
        omega[i] = exp(i * 2 * PI / MAXN * I);
}
// n 必須是 2^k，且 n <= MAXN
void fft(int n, cplx a[], bool inv = false) {
    int theta = MAXN / n;
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for (int i = 0; i < mh; i++) {
            cplx w = omega[inv ? MAXN - (i * theta % MAXN)
                               : i * theta % MAXN];
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                cplx x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta = (theta * 2) % MAXN;
    }
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
    if (inv) for (i = 0; i < n; i++) a[i] /= n;
}
// ans = a * b，a 長度 _n，b 長度 _m，ans 長度 _n + _m - 1
void mul(int _n, const ll a[], int _m, const ll b[], ll ans[]) {
    int sum = _n + _m - 1, n = 1;
    while (n < sum) n <<= 1;
    assert(n <= MAXN);
    for (int i = 0; i < n; i++) {
        ld x = (i < _n ? a[i] : 0), y = (i < _m ? b[i] : 0);
        arr[i] = cplx(x + y, x - y);
    }
    fft(n, arr);
    for (int i = 0; i < n; i++) arr[i] = arr[i] * arr[i];
    fft(n, arr, true);
    for (int i = 0; i < sum; i++)
        ans[i] = llroundl(arr[i].real() / 4);   // 負數係數也正確
}
int main() {
    pre_fft();
    ll a[] = {1, 2, 3};   // 1 + 2x + 3x^2
    ll b[] = {4, 5};      // 4 + 5x
    ll ans[4];
    mul(3, a, 2, b, ans);
    for (int i = 0; i < 4; i++) cout << ans[i] << ' ';
    // 4 13 22 15
}
