// Problem: E2 - N-MEX (Counting Version)
// Platform: codeforces
// Contest: Contest-2207
// Rating/Difficulty: 2400
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2207/submission/388099100
// Solved on: 2026-08-23T06:09:26.488Z

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

const int MOD = 1e9 + 7;
class mint {
  public:
    unsigned x;
    mint() : x(0) {}
    mint(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    mint(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    friend ostream &operator<<(ostream &os, const mint &m) {
        return os << m.get();
    }
    mint &operator+=(mint that) {
        if ((x += that.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(mint that) {
        if ((x += MOD - that.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator*=(mint that) {
        x = (unsigned long long)x * that.x % MOD;
        return *this;
    }
    mint &operator/=(mint that) { return *this *= that.inverse(); }
    mint operator+(mint that) const { return mint(*this) += that; }
    mint operator-(mint that) const { return mint(*this) -= that; }
    mint operator*(mint that) const { return mint(*this) *= that; }
    mint operator/(mint that) const { return mint(*this) /= that; }
    mint inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        return mint(u);
    }
    bool operator==(mint that) const { return x == that.x; }
    bool operator!=(mint that) const { return x != that.x; }
    mint operator-() const {
        mint t;
        t.x = x == 0 ? 0 : MOD - x;
        return t;
    }
    mint pow(long long k) const {
        mint t = *this, ans = 1;
        while (k > 0) {
            if (k & 1) {
                ans *= t;
            }
            t *= t;
            k >>= 1;
        }
        return ans;
    }
    static mint pow(mint t, long long k) {
        return t.pow(k);
    }

    static vector<mint> iv;
    static void prepare_inv(int RANGE) {
        // inverse of 1..n, module MOD
        iv.resize(RANGE + 1);
        iv[1] = 1;
        for (int i = 2; i <= RANGE; ++i) {
            iv[i] = -iv[MOD % i] * (MOD / i);
        }
    }
    static vector<mint> fac;
    static vector<mint> finv;
    static void prepare_fac(int RANGE) {
        prepare_inv(RANGE);
        fac.resize(RANGE + 1);
        finv.resize(RANGE + 1);
        fac[0] = 1;
        for (int i = 1; i <= RANGE; ++i)
            fac[i] = fac[i - 1] * i;
        finv[0] = 1;
        for (int i = 1; i <= RANGE; ++i)
            finv[i] = finv[i - 1] * iv[i];
    }
    static mint choose(int n, int m) {
        return m > n ? 0 : (fac[n] * finv[m] * finv[n - m]);
    }
};
vector<mint> mint::iv;
vector<mint> mint::fac;
vector<mint> mint::finv;

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

    mint::prepare_fac(2e5);

    iint(TESTS);
    FOR(T, TESTS) {
        iint(n);
        ivi(a, n);
        a.insert(a.begin(), n);
        int free = 0;
        mint ans = 1;
        bool valid = true;
        FOR(i, 1, n) {
            if (a[i] > n || a[i] > a[i - 1]) {
                valid = false;
                break;
            }
            if (a[i] != a[i - 1]) {
                int gap = a[i - 1] - a[i] - 1;
                if (free < gap) {
                    valid = false;
                    break;
                }
                ans *= i;
                if (gap) {
                    ans *= mint::fac[free] * mint::finv[free - gap];
                    free -= gap;
                }
            } else {
                free++;
            }
        }
        // dbg(ans, free);
        ans *= mint::fac[free];
        cout << (valid ? ans : 0) << nl;
    }
}