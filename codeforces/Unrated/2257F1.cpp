// Problem: F1 - Beaver's Jumping Track (Easy Version)
// Platform: codeforces
// Contest: Contest-2257
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2257/submission/387472347
// Solved on: 2026-08-17T17:38:45.778Z

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
const int INF = INT_MAX / 4;
const long long LINF = LLONG_MAX / 4;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dir[4] = {'U', 'R', 'D', 'L'};
const double eps = 1e-9;

// clang-format on

using aar = array<array<int, 6>, 5>;
int x = 5;

struct SegTree {
    struct Node {
        aar a;
        Node() {
            FOR(i, x) {
                FOR(j, x + 1) {
                    a[i][j] = LINF;
                }
            }
        }
    };
    friend std::ostream &operator<<(std::ostream &out, const SegTree::Node &v) {
        return out << "s:";
    }
    vector<Node> st;
    int size;
    SegTree(int _size) : size(_size), st(vector<Node>(_size * 4 + 5)) {}

    void _nodeAssign(Node &a, ii v, int l1, int r1) {
        auto [d, p] = v;
        FOR(l, 0, min(x - 1, d - 1)) {
            FOR(r, 0, x) {
                // jump from cell 1 + l to cell d + r
                int len;
                len = d + r - l - 1;
                if (len < 0) {
                    a.a[l][r] = LINF;
                } else if (len == 0) {
                    a.a[l][r] = 0;
                } else {
                    a.a[l][r] = ((len + x - 1) / x - (r > 0)) * p;
                }
                // dbg(l, r, d, len, a.a[l][r]);
            }
        }
    }

    Node _merge(Node &a, Node &b) {
        Node v;
        FOR(l, x) {
            FOR(r, 0, x) {
                v.a[l][r] = LINF;
                FOR(k, 1, x) {
                    chmin(v.a[l][r], a.a[l][k] + b.a[k - 1][r]);
                }
            }
        }
        return v;
    }

    void _build(vector<ii> &a, int v, int l1, int r1) {
        if (l1 == r1) {
            _nodeAssign(st[v], a[l1], l1, l1);
            return;
        }
        int mid = (l1 + r1) >> 1;
        _build(a, 2 * v, l1, mid);
        _build(a, 2 * v + 1, mid + 1, r1);
        st[v] = _merge(st[2 * v], st[2 * v + 1]);
    }
    void build(vector<ii> &a) {
        size = a.size();
        _build(a, 1, 0, size - 1);
    }

    void _pointUpdate(int v, int l1, int r1, int upIdx, ii upV) {
        if (l1 == r1) {
            _nodeAssign(st[v], upV, l1, r1);
            return;
        }
        int mid = (l1 + r1) >> 1;
        if (upIdx <= mid) {
            _pointUpdate(2 * v, l1, mid, upIdx, upV);
        } else {
            _pointUpdate(2 * v + 1, mid + 1, r1, upIdx, upV);
        }
        st[v] = _merge(st[2 * v], st[2 * v + 1]);
    }
    void pointUpdate(int upIdx, ii upV) {
        _pointUpdate(1, 0, size - 1, upIdx, upV);
    }

    Node _rangeQuery(int v, int l1, int r1, int queryL, int queryR) {
        if (queryL <= l1 && r1 <= queryR) {
            // dbg(v, l1, r1, st[v]);
            return st[v];
        }
        int mid = (l1 + r1) >> 1;
        Node ans; // This part need to be double checked.
        bool first = true;
        if (queryL <= mid) {
            auto r = _rangeQuery(2 * v, l1, mid, queryL, queryR);
            first ? (ans = r, first = false) : (ans = _merge(ans, r), 0);
        }
        if (queryR > mid) {
            auto r = _rangeQuery(2 * v + 1, mid + 1, r1, queryL, queryR);
            first ? (ans = r, first = false) : (ans = _merge(ans, r), 0);
        }
        // dbg(v, l1, r1, ans);
        return ans;
    }
    Node rangeQuery(int queryL, int queryR) {
        return _rangeQuery(1, 0, size - 1, queryL, queryR);
    }
};

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
    cin >> x;
    vii a(n);
    FOR(i, n) {
        cin >> a[i][0];
    }
    FOR(i, n) {
        cin >> a[i][1];
    }
    SegTree seg(n);
    seg.build(a);

    while (Q--) {
        char tp;
        cin >> tp;
        if (tp == '?') {
            iint(l, r);
            l--, r--;
            auto v = seg.rangeQuery(l, r).a;
            cout << v[0][0] << nl;
        } else if (tp == '1') {
            iint(i);
            i--;
            iint(x);
            // dbg(i, x);
            a[i][0] = x;
            seg.pointUpdate(i, a[i]);
        } else if (tp == '2') {
            iint(i);
            i--;
            iint(x);
            a[i][1] = x;
            seg.pointUpdate(i, a[i]);
        }
    }
}