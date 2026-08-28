// Problem: E - Bored Bakry
// Platform: codeforces
// Contest: Contest-1592
// Rating/Difficulty: 2400
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/1592/submission/388683250
// Solved on: 2026-08-28T13:51:53.055Z

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

    auto solve1_TLE = [](vi &a) {
        int n = a.size();
        int M = 20;
        int ans = 0;
        RFOR(k, M - 1, 0) {
            int ps2 = 0, s = 0;
            ar<map<ii, int>, 2> mp;
            mp[1][{0, 0}] = -1;
            FOR(i, n) {
                FOR(j, k + 1, M - 1) {
                    if (a[i] & (1 << j)) {
                        ps2 ^= 1 << j;
                    }
                }
                if ((a[i] & (1 << k)) == 0) {
                    s++; // notice that s will only increase. it's useless to store old values in mpi when s increases.
                }
                auto &mpi = mp[i & 1];
                if (mpi.contains({ps2, s})) {
                    chmax(ans, i - mpi[{ps2, s}]);
                } else {
                    mpi[{ps2, s}] = i;
                }
            }
        }
        return ans;
    };

    auto solve2 = [](vi &a) {
        int n = a.size();
        int M = 20;
        int ans = 0;
        RFOR(k, M - 1, 0) {
            int ps2 = 0, s = 0;
            ar<map<int, int>, 2> mp;
            mp[1][0] = -1;
            FOR(i, n) {
                FOR(j, k + 1, M - 1) {
                    if (a[i] & (1 << j)) {
                        ps2 ^= 1 << j;
                    }
                }
                if ((a[i] & (1 << k)) == 0) {
                    mp[0].clear();
                    mp[1].clear();
                    s++;
                }
                auto &mpi = mp[i & 1];
                if (mpi.contains(ps2)) {
                    chmax(ans, i - mpi[ps2]);
                } else {
                    mpi[ps2] = i;
                }
            }
        }
        return ans;
    };

    auto solve3 = [](vi &a) {
        int n = a.size();
        int M = 20;
        int ans = 0;
        vvi mp(2, vi(1 << M, INF));
        vvi ch(2);
        auto clear = [&]() {
            FOR(j, 2) {
                for (auto x : ch[j]) {
                    mp[j][x] = INF;
                }
                ch[j].clear();
            }
        };
        RFOR(k, M - 1, 0) {
            int ps2 = 0, s = 0;
            mp[1][0] = -1;
            ch[1].pb(0);
            FOR(i, n) {
                FOR(j, k + 1, M - 1) {
                    if (a[i] & (1 << j)) {
                        ps2 ^= 1 << j;
                    }
                }
                if ((a[i] & (1 << k)) == 0) {
                    clear();
                    s++;
                }
                auto &mpi = mp[i & 1];
                if (mpi[ps2] < INF) {
                    chmax(ans, i - mpi[ps2]);
                } else {
                    mpi[ps2] = i;
                    ch[i & 1].pb(ps2);
                }
            }
            clear();
        }
        return ans;
    };
    iint(n);
    ivi(a, n);
    cout << solve3(a) << nl;
}

// L153> k=2, i=0, ps2=8
// L153> k=2, i=1, ps2=8
// L153> k=2, i=2, ps2=8
// L153> k=2, i=3, ps2=8
// L153> k=2, i=4, ps2=8
// L153> k=2, i=5, ps2=8
// L153> k=1, i=0, ps2=8
// L153> k=1, i=1, ps2=8
// L153> k=1, i=2, ps2=8
// L153> k=1, i=3, ps2=8
// L157> k=1, i=3, ps2=8, mpi[ps2]=1
// L153> k=1, i=4, ps2=8
// L153> k=1, i=5, ps2=8
// L153> k=0, i=0, ps2=8
// L153> k=0, i=1, ps2=8
// L153> k=0, i=2, ps2=10
// L153> k=0, i=3, ps2=8
// L157> k=0, i=3, ps2=8, mpi[ps2]=1
// L153> k=0, i=4, ps2=8
// L157> k=0, i=4, ps2=8, mpi[ps2]=0
// L153> k=0, i=5, ps2=10