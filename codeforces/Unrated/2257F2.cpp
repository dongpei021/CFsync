// Problem: F2 - Beaver's Jumping Track (Hard Version)
// Platform: codeforces
// Contest: Contest-2257
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2257/submission/387792148
// Solved on: 2026-08-20T12:34:50.764Z

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

int x = 5;

struct Node {
    int a[10][11];
    Node() {
        FOR(i, x) {
            fill(all(a[i]), LINF);
        }
    }
    Node(ii v) : Node() {
        assign(v);
    }
    void assign(ii v) {
        auto [d, p] = v;
        FOR(l, 0, min(x - 1, d - 1)) {
            FOR(r, 0, x) {
                // jump from cell 1 + l to cell d + r
                int len;
                len = d + r - l - 1;
                if (len < 0) {
                    a[l][r] = LINF;
                } else if (len == 0) {
                    a[l][r] = 0;
                } else {
                    a[l][r] = ((len + x - 1) / x - (r > 0)) * p;
                }
                // dbg(l, r, d, len, a.a[l][r]);
            }
        }
    }
    Node operator+(const Node &b) {
        // auto &a = *this;
        // Node v;
        // FOR(l, x) {
        //     if (a.a[l][0] == LINF) {
        //         continue;
        //     }
        //     FOR(k, 1, x) {
        //         if (b.a[k - 1][0] == LINF) {
        //             continue;
        //         }
        //         FOR(r, 0, x) {
        //             chmin(v.a[l][r], a.a[l][k] + b.a[k - 1][r]);
        //         }
        //     }
        // }
        // return v;
        auto &a = *this;
        Node v;
        FOR(l, x) {
            if (a.a[l][0] == LINF)
                continue;
            int row[11];
            FOR(r, 0, x) {
                row[r] = LINF;
            }
            FOR(k, 1, x) {
                if (b.a[k - 1][0] == LINF)
                    continue;
                // int base = a.a[l][k];
                FOR(r, 0, x) {
                    chmin(row[r], a.a[l][k] + b.a[k - 1][r]);
                }
            }
            FOR(r, 0, x) {
                v.a[l][r] = row[r];
            }
        }
        return v;
    }
};
const int BS = 16;
const int N = 1 << 16;
Node st[N * 2 + 5];
int segsz;

void _pointUpdate(int v, int l1, int r1, int upIdx, const Node &upV) {
    if (l1 == r1) {
        st[v] = upV;
        return;
    }
    int mid = (l1 + r1) >> 1;
    if (upIdx <= mid) {
        _pointUpdate(2 * v, l1, mid, upIdx, upV);
    } else {
        _pointUpdate(2 * v + 1, mid + 1, r1, upIdx, upV);
    }
    st[v] = st[2 * v] + st[2 * v + 1];
}
void pointUpdate(int upIdx, const Node &upV) {
    _pointUpdate(1, 0, segsz - 1, upIdx, upV);
}

Node _rangeQuery(int v, int l1, int r1, int queryL, int queryR) {
    if (queryL <= l1 && r1 <= queryR) {
        // dbg(v, l1, r1, st[v]);
        return st[v];
    }
    int mid = (l1 + r1) >> 1;
    if (queryR <= mid) {
        return _rangeQuery(2 * v, l1, mid, queryL, queryR);
    }
    if (queryL > mid) {
        return _rangeQuery(2 * v + 1, mid + 1, r1, queryL, queryR);
    }
    return _rangeQuery(2 * v, l1, mid, queryL, queryR) + _rangeQuery(2 * v + 1, mid + 1, r1, queryL, queryR);
}
Node rangeQuery(int queryL, int queryR) {
    return _rangeQuery(1, 0, segsz - 1, queryL, queryR);
}

int32_t main() {
#ifndef __APPLE__
    // freopen("exercise.in", "r", stdin);
    // freopen("exercise.out", "w", stdout);
#endif
    //	ifstream in("/Users/a/Downloads/test_input.txt");
    //	cin.rdbuf(in.rdbuf());
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto solve1 = [&](vii a, viii &qs) {
        int n = a.size();
        int bn = (n + BS - 1) / BS;
        segsz = bn;

        function<Node(int, int)> cal = [&](int l, int r) {
            Node nd(a[l]);
            FOR(i, l + 1, r) {
                nd = nd + Node(a[i]);
            }
            return nd;
        };
        auto calbi = [&](int bi) {
            int st = bi * BS;
            return cal(st, min(n - 1, st + BS - 1));
        };

        function<void(int, int, int)> _build = [&](int v, int l1, int r1) {
            if (l1 == r1) {
                st[v] = calbi(l1);
                return;
            }
            int mid = (l1 + r1) >> 1;
            _build(2 * v, l1, mid);
            _build(2 * v + 1, mid + 1, r1);
            st[v] = st[2 * v] + st[2 * v + 1];
        };
        _build(1, 0, segsz - 1);
        // FOR(bi, bn) { // very important slow down
        //     pointUpdate(bi, calbi(bi));
        // }

        auto update = [&](int i, ii v) {
            int bi = i / BS;
            pointUpdate(bi, calbi(bi));
        };

        vi ans;
        for (auto [tp, l, r] : qs) {
            if (tp == 0) {
                if (l / BS + 1 <= r / BS - 1) {
                    Node nd = cal(l, (l / BS + 1) * BS - 1) + rangeQuery(l / BS + 1, r / BS - 1) + cal(r / BS * BS, r);
                    ans.pb(nd.a[0][0]);
                } else {
                    ans.pb(cal(l, r).a[0][0]);
                }
            } else if (tp == 1) {
                auto i = l, x = r;
                a[i][0] = x;
                update(i, a[i]);
            } else if (tp == 2) {
                auto i = l, x = r;
                a[i][1] = x;
                update(i, a[i]);
            }
        }
        return ans;
    };

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    bool TTT = false;
    // TTT = true;
    if (TTT) {
        uniform_int_distribution<int> disttp(0, 2); // including both ends
        uniform_int_distribution<int> dist(1, 20);  // including both ends
        uniform_int_distribution<int> dista(1, 7);
        uniform_int_distribution<int> distb(1, 5);
        // uniform_int_distribution<int> dista(1, 1e7);
        // uniform_int_distribution<int> distb(1, 1e5);
        FOR(T, 100000) {
            int n = dist(rng);
            vii a(n);
            FOR(i, n) {
                a[i] = {dista(rng), distb(rng)};
            }
            int Q = 2;
            viii qs(Q);
            uniform_int_distribution<int> distn(0, n - 1);

            FOR(i, Q) {
                int tp = disttp(rng);
                if (tp == 0) {
                    int l = distn(rng), r = distn(rng);
                    if (l > r) {
                        swap(l, r);
                    }
                    qs[i] = {0, l, r};
                } else {
                    int l = distn(rng);
                    int v = tp == 1 ? dista(rng) : distb(rng);
                    qs[i] = {tp, l, v};
                }
            }

            auto ans1 = solve1(a, qs);
            // auto ans2 = solve2(a, qs);
            // if (ans1 != ans2) {
            //     dbg(T);
            //     cerr << n << ' ' << Q << ' ' << x << nl;
            //     FOR(i, n) {
            //         cerr << a[i][0] << ' ';
            //     }
            //     cerr << nl;

            //     FOR(i, n) {
            //         cerr << a[i][1] << ' ';
            //     }
            //     cerr << nl;
            //     FOR(i, Q) {
            //         auto [tp, l, r] = qs[i];
            //         cerr << (tp ? (char)('0' + tp) : '?') << ' ';
            //         if (tp == 0) {
            //             cerr << l + 1 << ' ' << r + 1 << nl;
            //         } else {
            //             cerr << l + 1 << ' ' << r << nl;
            //         }
            //     }
            //     dbg(ans1);
            //     dbg(ans2);
            //     break;
            // }
        }
    } else {

        iint(n, Q);
        cin >> x;
        vii a(n);
        FOR(i, n) {
            cin >> a[i][0];
        }
        FOR(i, n) {
            cin >> a[i][1];
        }
        viii qs;
        while (Q--) {
            char tp;
            cin >> tp;
            if (tp == '?') {
                iint(l, r);
                l--, r--;
                qs.pb({0, l, r});
            } else {
                iint(id);
                id--;
                iint(x);
                qs.pb({tp - '0', id, x});
            }
        }
        auto ans = solve1(a, qs);
        for (int x : ans) {
            cout << x << nl;
        }
    }
}

// int nu = 1 << (__lg(n) + 1);
// assert(mx1 < nu);
// assert(mx < nu * 2);
// dbg(n, nu * 2, mx);
// learn: segtree can use 4n nodes, but if we avoid 2^n, like 1e6, it can use as less as 2.2e6 nodes. If we limit
// {
//     int N = 1e6;
//     uniform_int_distribution<int> dist(1, N);
//     int mx = 0, mx1 = 0;
//     vi vt(N * 4 + 1);
//     function<void(int, int, int)> build = [&](int v, int l, int r) {
//         if (l == r) {
//             chmax(mx, v);
//             return;
//         }
//         chmax(mx1, v);
//         vt[v] = 1;
//         int m = (l + r) / 2;
//         build(2 * v, l, m);
//         build(2 * v + 1, m + 1, r);
//     };
//     double mxr = 0;
//     int mxn;
//     FOR(T, 10000) {
//         int n = dist(rng);
//         // int n = 8297;
//         // int n = 1e6;
//         mx = 0;
//         mx1 = 0;
//         fill(all(vt), 0);
//         build(1, 0, n - 1);
//         int cnt = 0;
//         FOR(i, 1, n * 4) {
//             cnt += vt[i];
//         }
//         // dbg(cnt, mx1);
//         if (chmax(mxr, mx1 * 1.0 / n)) {
//             // if (chmax(mxr, mx1)) {
//             dbg(T, mxr, n, mx1);
//             mxn = n;
//         }
//         // break;
//     }
//     dbg("finish");
// }

// no use to detect uninitialized variable, running over the same dataset.
// int s = 0;
// FOR(T, 10000) {
//     s += solve1(a, qs)[0];
// }
// dbg(s);
