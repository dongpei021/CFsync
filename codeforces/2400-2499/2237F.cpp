// Problem: F - Paint the Array
// Platform: codeforces
// Contest: Contest-2237
// Rating/Difficulty: 2400
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2237/submission/387142175
// Solved on: 2026-08-15T11:11:22.348Z

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

template <typename T>
struct SegTree {
    struct Node {
        int idx;
        T mn, mx, lz;
        Node() : idx(0), mn(INF), mx(-INF), lz(INF) {}
    };
    friend std::ostream &operator<<(std::ostream &out, const SegTree::Node &v) {
        // return out << "s:" << v.s << " mxLSum:" << v.mxLSum << " mxRSum:" << v.mxRSum << " mxSum:" << v.mxSum << " lz:" << v.lz_assign;
        return out << "mn:" << v.mn << " mx:" << v.mx;
    }
    vector<Node> st;
    int size;
    SegTree(int _size) : size(_size), st(vector<Node>(_size * 4 + 5)) {}
    SegTree(int _size, T initV) : size(_size), st(vector<Node>(_size * 4 + 5)) {
        vector<T> a(_size, initV);
        build(a);
    }

    void _nodeUpdate(Node &a, T &lz, int l1, int r1) {
        chmin(a.lz, lz);
        chmin(a.mn, a.lz);
        chmin(a.mx, a.lz);
    }

    Node _merge(Node &a, Node &b) {
        Node v;
        v.mn = min(a.mn, b.mn);
        if (v.mn == a.mn) {
            v.idx = a.idx;
        } else {
            v.idx = b.idx;
        }
        v.mx = max(a.mx, b.mx);
        v.lz = INF;
        return v;
    }

    void _push(Node &p, Node &a, Node &b, int l1, int r1) {
        int mid = (l1 + r1) / 2;
        if (p.lz < INF) {
            _nodeUpdate(a, p.lz, l1, mid);
            _nodeUpdate(b, p.lz, mid + 1, r1);
            p.lz = INF;
        }
    }

    void _rangeUpdate(int v, int l1, int r1, int upL, int upR, T upV) {
        if (upL <= l1 && r1 <= upR) {
            _nodeUpdate(st[v], upV, l1, r1);
            // dbg(v, l1, r1, st[v]);
            return;
        }
        _push(st[v], st[2 * v], st[2 * v + 1], l1, r1);
        int mid = (l1 + r1) >> 1;
        if (upL <= mid) {
            _rangeUpdate(2 * v, l1, mid, upL, upR, upV);
        }
        if (upR >= mid + 1) {
            _rangeUpdate(2 * v + 1, mid + 1, r1, upL, upR, upV);
        }
        st[v] = _merge(st[2 * v], st[2 * v + 1]);
        // dbg(v, l1, r1, st[v]);
    }
    void rangeUpdate(int upL, int upR, T upV) {
        _rangeUpdate(1, 0, size - 1, upL, upR, upV);
    }

    Node _rangeQuery(int v, int l1, int r1, int queryL, int queryR) {
        if (queryL <= l1 && r1 <= queryR) {
            // dbg(v, l1, r1, st[v]);
            return st[v];
        }
        _push(st[v], st[2 * v], st[2 * v + 1], l1, r1);
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

    auto solve1 = [](int n, int m, vi &a) {
        vvi d(n + 1, vi(m + 1, INF));
        d[1][1] = a[1] != 1;
        FOR(i, 1, n - 1) {
            FOR(v, 1, m) {
                if (d[i][v] == INF) {
                    continue;
                }
                if (v != m) {
                    chmin(d[i + 1][v + 1], d[i][v] + (a[i + 1] != v + 1));
                }
                if (i + 1 <= n - m + 1) {
                    chmin(d[i + 1][1], d[i][v] + (a[i + 1] != 1));
                }
                if (v == m) {
                    FOR(x, 2, m) {
                        if (i + 1 - (x - 1) >= 1) {
                            chmin(d[i + 1][x], d[i][v] + (a[i + 1] != x));
                        }
                    }
                }
            }
        }
        return d[n][m];
    };

    auto solve2 = [](int n, int m, vi &a) {
        deque<int> d(m + 1, INF);
        d[1] = a[1] != 1;
        FOR(i, 1, n - 1) {
            int mn = INF;
            FOR(v, 1, m) {
                chmin(mn, d[v]);
            }
            int dm = d[m];
            RFOR(v, m - 1, 1) {
                d[v + 1] = d[v] + 1;
            }
            d[a[i + 1]]--;

            d[1] = INF;
            if (i <= n - m) {
                d[1] = mn + (a[i + 1] != 1);
            }

            FOR(x, 2, min(m, i + 1)) {
                chmin(d[x], dm + 1);
            }
            if (a[i + 1] <= min(m, i + 1)) {
                chmin(d[a[i + 1]], dm);
            }
        }
        return d[m];
    };

    auto solve3 = [](int n, int m, vi &a) {
        vvi d(n + 1, vi(n + 1, INF));
        d[1][1] = a[1] != 1;
        FOR(i, 1, n - 1) {
            FOR(lst, max(i - m + 1, 1ll), i) {
                int v = i - lst + 1;
                if (v != m) {
                    chmin(d[i + 1][lst], d[i][lst] + (a[i + 1] != v + 1));
                }
                if (i + 1 <= n - m + 1) {
                    chmin(d[i + 1][i + 1], d[i][lst] + (a[i + 1] != 1));
                }
                if (v == m) {
                    FOR(x, 2, m) {
                        if (i + 1 - (x - 1) >= 1) {
                            chmin(d[i + 1][i + 1 - x + 1], d[i][lst] + (a[i + 1] != x));
                        }
                    }
                }
            }
        }
        return d[n][n - m + 1];
    };

    auto solve4 = [](int n, int m, vi &a) {
        vi d(n + 1, INF);
        d[1] = a[1] != 1;
        FOR(i, 1, n - 1) {
            int mn = INF;
            FOR(lst, max(i - m + 1, 1ll), i) {
                chmin(mn, d[lst]);
            }
            int dm = i - m + 1 >= 1 ? d[i - m + 1] : INF;
            FOR(lst, max(i - m + 2, 1ll), i) {
                d[lst]++;
            }
            if (i + 1 - a[i + 1] + 1 >= 1) {
                d[i + 1 - a[i + 1] + 1]--;
            }
            if (i <= n - m) {
                chmin(d[i + 1], mn + (a[i + 1] != 1));
            }

            FOR(lst, i + 2 - min(m, i + 1), i) {
                chmin(d[lst], dm + 1);
            }
            int lst = i + 2 - a[i + 1];
            if (lst >= 1 && lst <= n - m + 1) {
                chmin(d[lst], dm);
            }
        }
        return d[n - m + 1];
    };

    auto solve41 = [](int n, int m, vi &a) {
        vi d(n + 1, INF);
        d[1] = a[1] != 1;
        int base = 0;
        FOR(i, 1, n - 1) {
            int mn = INF;
            FOR(lst, max(i - m + 1, 1ll), i) {
                chmin(mn, d[lst]);
            }
            int dm = i - m + 1 >= 1 ? d[i - m + 1] : INF;
            base++;
            // FOR(lst, max(i - m + 2, 1ll), i) {
            //     d[lst]++;
            // }
            if (i + 1 - a[i + 1] + 1 >= 1) {
                d[i + 1 - a[i + 1] + 1]--;
            }
            if (i <= n - m) {
                chmin(d[i + 1], mn + (a[i + 1] != 1) - 1);
            }

            FOR(lst, i + 2 - min(m, i + 1), i) {
                chmin(d[lst], dm);
            }
            int lst = i + 2 - a[i + 1];
            if (lst >= 1 && lst <= n - m + 1) {
                chmin(d[lst], dm - 1);
            }
        }
        return base + d[n - m + 1];
    };

    auto solve5 = [](int n, int m, vi &a) {
        SegTree<int> seg(n + 1);
        // vi d(n + 1, INF);
        // d[1] = a[1] != 1;
        seg.rangeUpdate(1, 1, a[1] != 1);
        int base = 0;
        FOR(i, 1, n - 1) {
            int mn = seg.rangeQuery(max(i - m + 1, 1ll), i).mn;
            // int mn = INF;
            // FOR(lst, max(i - m + 1, 1ll), i) {
            //     chmin(mn, d[lst]);
            // }
            // int dm = i - m + 1 >= 1 ? d[i - m + 1] : INF;
            int dm = i - m + 1 >= 1 ? seg.rangeQuery(i - m + 1, i - m + 1).mn : INF;

            base++;
            int id = i + 1 - a[i + 1] + 1;
            if (id >= 1) {
                // d[id]--;
                int v = seg.rangeQuery(id, id).mn;
                seg.rangeUpdate(id, id, v - 1);
            }
            if (i <= n - m) {
                seg.rangeUpdate(i + 1, i + 1, mn + (a[i + 1] != 1) - 1);
                // chmin(d[i + 1], mn + (a[i + 1] != 1) - 1);
            }

            seg.rangeUpdate(i + 2 - min(m, i + 1), i, dm);
            // FOR(lst, i + 2 - min(m, i + 1), i) {
            //     chmin(d[lst], dm + 1);
            // }
            int lst = i + 2 - a[i + 1];
            if (lst >= 1 && lst <= n - m + 1) {
                // chmin(d[lst], dm);
                seg.rangeUpdate(lst, lst, dm - 1);
            }
        }
        return base + seg.rangeQuery(n - m + 1, n - m + 1).mn;
    };
    iint(TESTS);
    FOR(T, TESTS) {
        iint(n, m);
        ivi(a, n);
        a.insert(a.begin(), 0);
        cout << solve5(n, m, a) << nl;
    }
}