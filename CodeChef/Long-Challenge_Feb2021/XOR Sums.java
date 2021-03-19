//devanshjsr 
 
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()
 
//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
//const ll MOD = 998244353;
//const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxb[4] = {-1, 1, 1, -1};
const int dyb[4] = {-1, 1, -1, 1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const ll bt = 30;

#define sizef 2000012
const int MOD = 998244353;
ll fact[sizef], factrev[sizef];

ll combi(ll n, ll r)
{
    ll val=(fact[n] * factrev[r]) % MOD;
    val=(val* factrev[n - r]) % MOD;
    
    return val;
}


ll mdlexp(ll b, ll p) 
{
    if (p == 0) 
    {
        return 1;
    } 
    else 
    {
        ll pval = mdlexp(b, p / 2);
        
        pval = pval * pval; 
        pval = pval % MOD;
        
        if (p % 2 == 1)
        {
            pval = pval * b;
            pval = pval % MOD;
        }
        
        return pval;
    }
}

ll invfunc(ll b) 
{
    int v1 = MOD;
    int v2= b;
    int v3 = 0;
    int v4 = 1;
    
    while (v2 != 0) 
    {
        int q = v1 / v2;
        v1 %= v2;
        
        swap(v1, v2);
        
        v3 -= q * v4;
        
        swap(v3, v4);
    }
    
    return v3 < 0 ? v3+MOD : v3;
}

/*
    FFT Source Code
    Author: isaf27 (Ivan Safonov), Codeforces
*/

 
// //easy functions
// template< typename T >
// inline T gcd(T a, T b)
// {
//     while (a)
//     {
//         b %= a;
//         swap(a, b);
//     }
//     return b;
// }
// template< typename T >
// inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
// inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
// inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
// inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
 
// //random
// //mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// mt19937_64 rnd(239);
 
// //constants
// const int M = 2e5 + 239;
// const int N = (2 * M);
// const int L = 18;
// const int T = (1 << 21);
// const int B = trunc(sqrt(M)) + 1;
// const int X = 110;
 
// //fft

// const ll MOD2 = (ll)MOD * (ll)MOD;
// const ll root = 3;
// const ll sub = 15311432;
// const ll sub_inv = 469870224;
 
// int st[T], rev[T];
// int p_fft, w_fft, z_fft, s_fft, k_fft;
 
// inline int power(int a, ll n)
// {
//     int ans = 1;
//     while (n)
//     {
//         if (n & 1LL) ans = 1LL * ans * a % MOD;
//         a = (1LL * a * a) % MOD;
//         n >>= 1LL;
//     }
//     return ans;
// }
 
// inline int invfunc(int x)
// {
//     return power(x, MOD - 2);
// }
 
// inline void fft(vector<int> &a)
// {
//     for (int i = 0; i < s_fft; i++)
//         if (i < rev[i])
//             swap(a[i], a[rev[i]]);
//     for (int k = 1; k < s_fft; k <<= 1)
//         for (int i = 0; i < s_fft; i += k + k)
//             for (int j = i, t = i + k; j < i + k; j++, t++)
//             {
//                 z_fft = 1LL * a[t] * st[t - i] % MOD;
//                 a[t] = a[j] - z_fft;
//                 if (a[t] < 0) a[t] += MOD;
//                 a[j] = a[j] + z_fft;
//                 if (a[j] >= MOD) a[j] -= MOD;
//             }
// }
 
// inline vector<int> multiply(vector<int> a, vector<int> b)
// {
//     k_fft = ((int)a.size() + (int)b.size()) - 1;
//     p_fft = 0;
//     while ((1 << p_fft) < k_fft) p_fft++;
//     //cerr << p_fft << "!!\n";
//     s_fft = (1 << p_fft);
//     for (int i = 0; i < s_fft; i++) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (p_fft - 1));
//     st[0] = 0;
//     st[1] = 1;
//     for (int b = 1; b < p_fft; b++)
//     {
//         w_fft = power(sub, 1 << (22 - b));
//         for (int i = (1 << (b - 1)); i < (1 << b); i++)
//         {
//             st[i << 1] = st[i];
//             st[(i << 1) + 1] = 1LL * st[i] * w_fft % MOD;
//         }
//     }
//     while (a.size() < s_fft) a.push_back(0);
//     while (b.size() < s_fft) b.push_back(0);
//     fft(a);
//     fft(b);
//     for (int b = 1; b < p_fft; b++)
//     {
//         w_fft = power(sub_inv, 1 << (22 - b));
//         for (int i = (1 << (b - 1)); i < (1 << b); i++)
//         {
//             st[i << 1] = st[i];
//             st[(i << 1) + 1] = 1LL * st[i] * w_fft % MOD;
//         }
//     }
//     vector<int> v;
//     for (int i = 0; i < s_fft; i++) v.push_back(1LL * a[i] * b[i] % MOD);
//     fft(v);
//     while (v.back() == 0) v.pop_back();
//     k_fft = invfunc(s_fft);
//     for (int i = 0; i < (int)v.size(); i++) v[i] = 1LL * k_fft * v[i] % MOD;
//     return v;
// }

// // FFT Source code ends


/*
    NTT Source Code
    Author: isaf27 (Ivan Safonov), Codeforces
*/


    vector<ll> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    ll root;
 
    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }
 
    int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;
 
        return max(n, 1);
    }
 
    // Given n (a power of two), finds k such that n == 1 << k.
    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }
 
    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<ll> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);
 
            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }
 
        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }
 
    void find_root() {
        max_size = 1 << __builtin_ctz(MOD - 1);
        root = 2;
 
        // Find a max_size-th primitive root of MOD.
        while (!(mdlexp(root, max_size) == 1 && mdlexp(root, max_size/2) != 1))
            root++;
    }
 
    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();
 
        assert(n <= max_size);
 
        if ((int) roots.size() >= n)
            return;
 
        int length = get_length(roots.size());
        roots.resize(n);
 
        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            ll z = mdlexp(root, max_size >> (length+1));
 
            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = (roots[i] * z)%MOD;
            }
 
            length++;
        }
    }
 
    void fft_iterative(int N, vector<ll> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);
 
        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    ll even = values[start + i];
                    ll odd = values[start + n + i] * roots[n + i];
                    odd %= MOD;
                    values[start + n + i] = even - odd + MOD;
                    values[start + i] = even + odd;
                    values[start + n + i] %= MOD;
                    values[start + i] %= MOD;
                }
    }
 
    const int FFT_CUTOFF = 150;
 
    vector<ll> mod_multiply(vector<ll> left, vector<ll> right) {
        int n = left.size();
        int m = right.size();
 
        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1, 0);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);
 
                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= MOD;
                }
 
            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;
 
            return vector<ll>(result.begin(), result.end());
        }
 
        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);
 
        bool equal = left == right;
        fft_iterative(N, left);
 
        if (equal)
            right = left;
        else
            fft_iterative(N, right);
 
        ll inv_N = invfunc(N);
 
        for (int i = 0; i < N; i++) {
            left[i] *= (right[i] * inv_N)%MOD;
            left[i] %= MOD;
        }
 
        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
        return left;
    }
 
    vector<ll> mod_power(const vector<ll> &v, int exponent) {
        assert(exponent >= 0);
        vector<ll> result = {1};
 
        if (exponent == 0)
            return result;
 
        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);
 
            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }
 
        return result;
    }
 
    vector<ll> mod_multiply_all(const vector<vector<ll>> &polynomials) {
        if (polynomials.empty())
            return {1};
 
        struct compare_size {
            bool operator()(const vector<ll> &x, const vector<ll> &y) {
                return x.size() > y.size();
            }
        };
 
        priority_queue<vector<ll>, vector<vector<ll>>, compare_size> pq(polynomials.begin(), polynomials.end());
 
        while (pq.size() > 1) {
            vector<ll> a = pq.top(); pq.pop();
            vector<ll> b = pq.top(); pq.pop();
            pq.push(mod_multiply(a, b));
        }
 
        return pq.top();
    }


//NTT Source code ends

//MOD defined earlier


void calc()
{
    fact[0] = 1;
    factrev[0] = 1;
    factrev[1] = 1;
    
    for(int i = 1; i < sizef; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    for(int i = 2; i < sizef; i++)
    {
        factrev[i] = (MOD - MOD / i) * factrev[MOD % i] % MOD;
    }
    
    for(int i = 1; i < sizef; i++)
    {
        factrev[i] = (factrev[i - 1] * factrev[i]) % MOD;
    }
}



signed main() 
{
    calc();
    
    int n;
    cin >> n;
    
    
    vector<int> ipval(n, 0);
    
    int sum = 0;
    
    for (int i = 0 ; i < n ; i++)
    {
        int temp;
        cin >> temp;
        
        ipval[i]=temp;
        
    }
    
    vector<int> bitvec(31, 0);
    
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < 31 ; j++)
        {
            if (ipval[i] & (1 << j))
            {
                bitvec[j]++;
            }
        }
        
        sum = (sum%MOD + ipval[i]%MOD)%MOD;
        
    }

    vector<int> ansvec(n + 2, 0);
    
    ansvec[1] = sum;
    
    for (int bind= 0 ; bind < 31 ; bind++)
    {
        int cnt1 = bitvec[bind];
        int cnt0 = n - cnt1;
        
        vector<ll> vec0(cnt0+1,0);
        vector<ll> vec1(cnt1+1,0);
        
        
        
        for (int i = 0 ; i <= n ; i++)
        {
            if (i % 2 && i <= cnt1)
            {
                vec1[i] = combi(cnt1,i);
            }
            
            if (i <= cnt0)
            {
                vec0[i] = combi(cnt0, i);
            }
        }
        
        auto res = mod_multiply(vec0, vec1);
        
        for (int i = 2 ; i <= n ; i++)
        {
            ansvec[i] = (ansvec[i] + (((1<<bind)%MOD) * (res[i]%MOD))) % MOD;
        }
    }
    
    
    for (int i= 2 ; i <= n ; i++)
    {
        ansvec[i] += ansvec[i-1];
        
        ansvec[i] %= MOD;
        
    }
    
    int q;
    cin >> q;
    
    while (q--)
    {
        int m;
        cin >> m;
        
        cout << ansvec[m] << "\n";
    }
}

