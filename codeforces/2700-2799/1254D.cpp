// Problem: D - Tree Queries
// Platform: codeforces
// Contest: Contest-1254
// Rating/Difficulty: 2700
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/1254/submission/387635814
// Solved on: 2026-08-19T05:01:41.339Z

#include "assert.h"
#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

// #include <ranges>
// #include <ext/rope>
// #include <math.h>
// #include <bits/stdc++.h>
// clang-format off
using namespace std;

template <typename T, size_t N> istream &operator>>(istream &in, array<T, N> &a);
template <typename T> istream &operator>>(istream &in, vector<T> &a) {
    for (size_t i = 0; i < a.size(); ++i) { in >> a[i];} return in; }
template <typename T, size_t N> istream &operator>>(istream &in, array<T, N> &a) {
    for (int i = 0; i < N; ++i) { in >> a[i]; } return in; }
template <typename T> T min(vector<T> &a) {
    T ans = a[0]; for (size_t i = 1; i < a.size(); ++i) { if (a[i] < ans) { ans = a[i]; } } return ans; }
template <typename T> T max(vector<T> &a) {
    T ans = a[0]; for (size_t i = 1; i < a.size(); ++i) { if (a[i] > ans) { ans = a[i]; } } return ans; }

// #define FOR3(i, a, b) for (int i=(int)(a); i<=(int)(b); i++)
// #define FOR2(i, a) for (int i=0; i<(int)(a); i++)
// #define GET_MACRO2(_1,_2,_3,NAME,...) NAME
// #define FOR(...) GET_MACRO2(__VA_ARGS__, FOR3, FOR2)(__VA_ARGS__)
// #define RFOR(i, b, a) for (int i=(int)(b); i>=(int)(a); i--)
#define FOR3(i, a, b) for (long long i=(long long)(a); i<=(long long)(b); i++)
#define FOR2(i, a) for (long long i=0; i<(long long)(a); i++)
#define GET_MACRO2(_1,_2,_3,NAME,...) NAME
#define FOR(...) GET_MACRO2(__VA_ARGS__, FOR3, FOR2)(__VA_ARGS__)
#define RFOR(i, b, a) for (long long i=(long long)(b); i>=(long long)(a); i--)
    
template<class T1, class T2>bool chmax(T1 &a, const T2 &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T1, class T2>bool chmin(T1 &a, const T2 &b) { if (b<a) { a = b; return 1; } return 0; }

#define int long long
#define ar array
#define nl "\n"
#define pb push_back
#define all(x) begin(x),end(x)
using ii = ar<int, 2>;
using iii = ar<int, 3>;
using iiii = ar<int, 4>;
using vi = vector<int>;
using vii = vector<ii>;
using viii = vector<iii>;
using viiii = vector<iiii>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vvii = vector<vector<ii>>;
#define iint1(a) int a; cin >> a;
#define iint2(a, b) int a, b; cin >> a >> b;
#define iint3(a, b, c) int a, b, c; cin >> a >> b >> c;
#define iint4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d;
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define iint(...) GET_MACRO(__VA_ARGS__, iint4, iint3, iint2, iint1)(__VA_ARGS__)
#define ivi(a, n) vi a(n); cin >> a;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef __APPLE__
int __lg(int n) { return 64 - 1 - __builtin_clzll(n); }
#include "debug.h"
#elif defined(__ORB__)
#include "debug.h"
#else
#define dbg(...) 42
#endif

const int M = 1e9 + 7;
const int INF = INT_MAX / 2;
const long long LINF = LLONG_MAX / 2;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dir[4] = {'U', 'R', 'D', 'L'};
const double eps = 1e-9;


const int MOD = 998244353;
class ModInt {
  public:
    unsigned x;
    ModInt() : x(0) {}
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    friend ostream& operator<<(ostream &os, const ModInt &m) {
        return os << m.get(); }
    friend istream& operator>>(istream &in,  ModInt &m) {
        int t; in >> t; m.x = (t % MOD + MOD) % MOD; return in; }
    ModInt &operator+=(ModInt that) {
        if ((x += that.x) >= MOD)
            x -= MOD;
        return *this;
    }
    ModInt &operator-=(ModInt that) {
        if ((x += MOD - that.x) >= MOD)
            x -= MOD;
        return *this;
    }
    ModInt &operator*=(ModInt that) {
        x = (unsigned long long)x * that.x % MOD;
        return *this;
    }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
//     bool operator>(ModInt that) const { return x > that.x; }
//     bool operator<(ModInt that) const { return x < that.x; }    
    ModInt operator-() const {
        ModInt t;
        t.x = x == 0 ? 0 : MOD - x;
        return t;
    }
    ModInt pow(long long k) const {
        ModInt t = *this, ans = 1;
        while (k > 0) {
            if (k & 1) {
                ans *= t;
            }
            t *= t;
            k >>= 1;
        }
        return ans;
    }
    static ModInt pow(ModInt t, long long k) {
        return t.pow(k);
    }
};
typedef ModInt mint;

struct HLD {
    vvi &a;
    int n, root;
    vi sz, dep, par;
    vi hc;
    vi tin, tout, tseq;
    vi top;
    int time;

    HLD(vvi &_a, int _root) : a(_a), root(_root), n(a.size()), sz(n), dep(n), par(n, -1), hc(n, -1), tin(n), tout(n), top(n) {
        dfssz(root, -1);
        time = 0;
        dfs2(root, -1, root);
    }

    void dfssz(int u, int p) {
        sz[u] = 1;
        if (p > -1) {
            dep[u] = dep[p] + 1;
            par[u] = p;
        }
        int mx = 0;
        for (auto v : a[u]) {
            if (v != p) {
                dfssz(v, u);
                sz[u] += sz[v];
                if (chmax(mx, sz[v])) {
                    hc[u] = v;
                }
            }
        }
    };

    void dfs2(int u, int p, int tp) {
        tseq.pb(u);
        tin[u] = time++;
        top[u] = tp;

        if (hc[u] != -1) {
            dfs2(hc[u], u, tp);
        }
        for (int v : a[u]) {
            if (v != p && v != hc[u]) {
                dfs2(v, u, v);
            }
        }
        tout[u] = time - 1;
    };

    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = par[top[u]];
            } else {
                v = par[top[v]];
            }
        }
        if (dep[u] > dep[v]) {
            return v;
        } else {
            return u;
        }
    }

    vii path(int u, int v) {
        vii ans;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                ans.pb({u, top[u]});
                u = par[top[u]];
            } else {
                ans.pb({v, top[v]});
                v = par[top[v]];
            }
        }
        if (dep[u] > dep[v]) {
            ans.pb({u, v});
        } else {
            ans.pb({v, u});
        }
        return ans;
    }

    vii patht(int u, int v) {
        vii ans = path(u, v);
        for (auto &[x, anc] : ans) {
            swap(x, anc);
            x = tin[x];
            anc = tin[anc];
        }
        return ans;
    }
};

// zero based
template <class T>
struct BIT {
    vector<T> bit;
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    BIT(vector<T> &a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    T psum(int r) {
        T s = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            s += bit[r];
        return s;
    }
    void add(int r, T val) {
        for (; r < n; r = r | (r + 1))
            bit[r] += val;
    }
    T get(int l, int r) {
        return psum(r) - (l > 0 ? psum(l - 1) : 0);
    }
};

// clang-format on
int32_t main() {
#ifndef __APPLE__
    // freopen("exercise.in", "r", stdin);
    // freopen("exercise.out", "w", stdout);
#endif
    //	ifstream in("/Users/a/Downloads/test_input.txt");
    //	cin.rdbuf(in.rdbuf());
    ios::sync_with_stdio(0);
    cin.tie(0);

    iint(n, Q);
    vector<vi> a(n);
    FOR(i, n - 1) {
        iint(x, y);
        x--, y--;
        a[x].pb(y);
        a[y].pb(x);
    }

    HLD hld(a, 0);
    auto &par = hld.par;
    auto &sz = hld.sz;
    vi wt(n);
    FOR(i, 1, n - 1) {
        int p = hld.par[i];
        wt[i] = n - hld.sz[p] - hld.sz[i];
    }
    // dbg(wt);
    vi val(n);
    mint base;
    auto &tin = hld.tin;

    BIT<mint> bit(n);
    while (Q--) {
        iint(tp);
        if (tp == 1) {
            iint(u, d);
            u--;
            base += sz[u] * d;
            val[u] += d;
            if (hld.hc[u] != -1) {
                bit.add(tin[u], d * wt[hld.hc[u]]);
            }
        } else {
            iint(u);
            u--;
            mint ans = base + (n - sz[u]) * val[u];
            auto pth = hld.path(u, 0);
            FOR(i, pth.size()) {
                auto [u, fu] = pth[i];
                if (u != fu) {
                    ans += bit.get(tin[fu], tin[par[u]]);
                }
                if (i + 1 < pth.size()) {
                    ans += wt[fu] * val[par[fu]];
                }
            }
            // while (par[u] != -1) {
            //     ans += wt[u] * val[par[u]];
            //     u = par[u];
            // }
            cout << ans / n << nl;
        }
    }
}