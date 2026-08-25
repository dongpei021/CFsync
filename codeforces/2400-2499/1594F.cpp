// Problem: F - Ideal Farm
// Platform: codeforces
// Contest: Contest-1594
// Rating/Difficulty: 2400
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/1594/submission/388311775
// Solved on: 2026-08-25T04:56:36.198Z

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
    auto solve1 = [](int s, int n, int k) {
        if (k > s) {
            return false;
        }
        if (k == s) {
            return true;
        }
        // select n - 1 different numbers from 1 ... s - 1 , then plus, 0, and s
        // in the selection (n + 1) numbers, do we guarantee that there exists b_j - b_i == k
        // we ask a different question, if we try to keep x and x + k not selected at the same time, at most how many can we select?
        // so we group numbers based on their mod k result.
        // we know k cannot be selected(0 is in), s - k cannot be selected (s is in)

        // 0, 1, 2, ... s % k, each group has s / k + 1 member
        // s % k + 1, ... k - 1, each group has s / k member;
        int m = s / k;
        int mx;
        if (s % k == 0) {
            // 0 and s are selected, and in the same group;
            mx = ((m + 1 - 4 + 1) / 2 + 2) + (k - 1) * ((m + 1) / 2);
        } else {
            mx = (s % k + 1) * ((m + 1 + 1) / 2) + (k - s % k - 1) * ((m + 1) / 2);
        }
        // assert(s % k * (m + 1) + (k - s % k) * m == s);
        // dbg(mx, n);
        return mx < n + 1;
    };
    auto solve2 = [](int s, int n, int k) {
        vi vt(s + 1);
        vt[0] = 1;
        vt[s] = 1;

        function<bool(int, int)> dfs = [&](int i, int lst) {
            // dbg(i, lst, vt);
            if (i == n) {
                return s - k < 0 || !vt[s - k];
            }
            if ((s - lst - 1) + i < n) {
                return false;
            }
            FOR(j, lst + 1, s - 1) {
                if (j - k < 0 || !vt[j - k]) {
                    vt[j] = 1;
                    if (dfs(i + 1, j)) {
                        return true;
                    }
                    vt[j] = 0;
                }
            }
            return false;
        };

        return !dfs(1, 0);
    };
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    bool TTT = false;
    // TTT = true;
    if (TTT) {
        uniform_int_distribution<int> dist01(0, 1);
        uniform_int_distribution<int> dist(1, 6); // including both ends
        FOR(T, 10000) {
            int n = dist(rng), s = dist(rng), k = dist(rng);
            if (s < n) {
                swap(n, s);
            }
            while (k > s) {
                k = dist(rng);
            }
            auto ans1 = solve1(s, n, k);
            auto ans2 = solve2(s, n, k);
            if (ans1 != ans2) {
                dbg(T);
                cerr << s << ' ' << n << ' ' << k << nl;
                dbg(ans1);
                dbg(ans2);
                break;
            }
        }
    } else {
        iint(TESTS);
        FOR(T, TESTS) {
            iint(s, n, k);
            cout << (solve1(s, n, k) ? "YES" : "NO") << nl;
        }
    }
}