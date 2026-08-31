// Problem: D - Magic Tiles
// Platform: codeforces
// Contest: Contest-2258
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2258/submission/389022431
// Solved on: 2026-08-31T16:51:01.711Z

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

    auto ccompress = [](vi &a) {
        vi va = a;
        sort(va.begin(), va.end());
        va.erase(unique(va.begin(), va.end()), va.end());
        for (int &x : a) {
            x = lower_bound(va.begin(), va.end(), x) - va.begin();
        }
        return va;
    };

    auto solve1 = [](vii &lra, vii &lrb) {
        set<ii> sa, sb;
        map<int, int> sega, segb;
        for (auto [l, r] : lra) {
            sa.insert({r - l + 1, l});
            sega[l] = r;
        }
        for (auto [l, r] : lrb) {
            sb.insert({r - l + 1, l});
            segb[l] = r;
        }
        auto eras = [&](set<ii> &st, map<int, int> &seg, int l, int r) {
            vi toe;
            vii toa;
            auto it = seg.upper_bound(l);
            if (it != seg.begin()) {
                it--;
            }
            while (it != seg.end()) {
                auto [sl, sr] = *it;
                if (sl > r) {
                    break;
                }
                if (sl < l) {
                    if (sr < l) {
                    } else if (sr <= r) {
                        toe.pb(sl);
                        toa.pb({sl, l - 1});
                    } else {
                        toe.pb(sl);
                        toa.pb({sl, l - 1});
                        toa.pb({r + 1, sr});
                    }
                } else {
                    if (sr <= r) {
                        toe.pb(sl);
                    } else {
                        toe.pb(sl);
                        toa.pb({r + 1, sr});
                    }
                }
                it++;
            }
            for (auto sl : toe) {
                auto sr = seg[sl];
                seg.erase(sl);
                st.erase({sr - sl + 1, sl});
            }
            for (auto [sl, sr] : toa) {
                if (sl <= sr) {
                    seg[sl] = sr;
                    st.insert({sr - sl + 1, sl});
                }
            }
        };
        vi ans;
        while (!sa.empty() && !sb.empty()) {
            auto [lena, la] = *sa.rbegin();
            auto [lenb, lb] = *sb.rbegin();
            if (lena > lenb || lena == lenb && la > lb) {
                ans.pb(lena);
                eras(sb, segb, la, la + lena - 1);
                sa.erase(--sa.end());
                sega.erase(sega.find(la));
            } else {
                ans.pb(lenb);
                eras(sa, sega, lb, lb + lenb - 1);
                sb.erase(--sb.end());
                segb.erase(segb.find(lb));
            }
        }
        for (auto [lena, la] : sa) {
            ans.pb(lena);
        }
        for (auto [lenb, lb] : sb) {
            ans.pb(lenb);
        }
        sort(all(ans), greater<int>());
        return ans;
    };

    auto solve2 = [&](vii lra, vii lrb) {
        int n = lra.size(), m = lrb.size();
        vi xs;
        FOR(i, n) {
            xs.pb(lra[i][0] - 1);
            xs.pb(lra[i][0]);
            xs.pb(lra[i][1]);
        }
        FOR(i, m) {
            xs.pb(lrb[i][0] - 1);
            xs.pb(lrb[i][0]);
            xs.pb(lrb[i][1]);
        }
        auto vx = ccompress(xs);
        int L = vx.size();
        FOR(i, n) {
            lra[i][0] = lower_bound(all(vx), lra[i][0]) - vx.begin();
            lra[i][1] = lower_bound(all(vx), lra[i][1]) - vx.begin();
        }
        FOR(i, m) {
            lrb[i][0] = lower_bound(all(vx), lrb[i][0]) - vx.begin();
            lrb[i][1] = lower_bound(all(vx), lrb[i][1]) - vx.begin();
        }
        auto clear = [](vii &lra, vii &lrb) {
            vii nlra;
            for (auto [l, r] : lra) {
                int i = upper_bound(all(lrb), ii{l, INF}) - lrb.begin() - 1;
                if (i >= 0 && i < lrb.size() && lrb[i][0] <= l && lrb[i][1] >= r) {

                } else {
                    nlra.pb({l, r});
                }
            }
            return nlra;
        };
        lra = clear(lra, lrb);
        lrb = clear(lrb, lra);
        // dbg(lra);
        // dbg(lrb);
        n = lra.size();
        m = lrb.size();
        vi prea(L, L), preb(L, L);
        FOR(i, n) {
            FOR(j, lra[i][0], lra[i][1]) {
                prea[j] = lra[i][0];
            }
        }
        FOR(i, m) {
            FOR(j, lrb[i][0], lrb[i][1]) {
                preb[j] = lrb[i][0];
            }
        }
        // dbg(prea);
        // dbg(preb);
        vector<multiset<int, greater<int>>> d(L);
        FOR(i, 1, L - 1) {
            d[i] = d[i - 1];
            int pre = min(prea[i], preb[i]);
            if (pre < L) {
                FOR(j, pre, i) {
                    multiset<int, greater<int>> st;
                    if (j) {
                        st = d[j - 1];
                    }
                    st.insert(vx[i] - vx[j] + 1);
                    chmax(d[i], st);
                    if (i > j) {
                        st = d[j];
                        st.insert(vx[i] - vx[j]);
                        chmax(d[i], st);
                    }
                }
            }
            // dbg(i, vx[i], d[i]);
        }
        vi ans(all(d[L - 1]));
        // multiset<int, greater<int>> a{4, 4}, b{2, 3, 4};
        // dbg(a > b);
        return ans;
    };

    auto solve3 = [&](vii lra, vii lrb) {
        int n = lra.size(), m = lrb.size();
        auto clear = [](vii &lra, vii &lrb) {
            vii nlra;
            for (auto [l, r] : lra) {
                int i = upper_bound(all(lrb), ii{l, INF}) - lrb.begin() - 1;
                if (i >= 0 && i < lrb.size() && lrb[i][0] <= l && lrb[i][1] >= r) {

                } else {
                    nlra.pb({l, r});
                }
            }
            return nlra;
        };
        lra = clear(lra, lrb);
        lrb = clear(lrb, lra);
        n = lra.size();
        m = lrb.size();

        vi xs;
        FOR(i, n) {
            xs.pb(lra[i][0] - 1);
            xs.pb(lra[i][0]);
            xs.pb(lra[i][1]);
        }
        FOR(i, m) {
            xs.pb(lrb[i][0] - 1);
            xs.pb(lrb[i][0]);
            xs.pb(lrb[i][1]);
        }
        auto vx = ccompress(xs);
        int L = vx.size();
        FOR(i, n) {
            lra[i][0] = lower_bound(all(vx), lra[i][0]) - vx.begin();
            lra[i][1] = lower_bound(all(vx), lra[i][1]) - vx.begin();
        }
        FOR(i, m) {
            lrb[i][0] = lower_bound(all(vx), lrb[i][0]) - vx.begin();
            lrb[i][1] = lower_bound(all(vx), lrb[i][1]) - vx.begin();
        }
        // dbg(lra);
        // dbg(lrb);

        vi prea(L, L), preb(L, L);
        FOR(i, n) {
            FOR(j, lra[i][0], lra[i][1]) {
                prea[j] = lra[i][0];
            }
        }
        FOR(i, m) {
            FOR(j, lrb[i][0], lrb[i][1]) {
                preb[j] = lrb[i][0];
            }
        }
        // dbg(prea);
        // dbg(preb);
        vector<multiset<int, greater<int>>> d(L);
        int cid = -1;
        FOR(i, 1, L - 1) {
            d[i] = d[i - 1];
            int pre = min(prea[i], preb[i]);
            if (pre < L) {
                if (pre < i - 4) {
                    dbg(vx);
                    dbg(prea);
                    dbg(preb);
                    dbg(lra);
                    dbg(lrb);
                    dbg(prea[i], preb[i]);
                    dbg(pre, i);
                }
                assert(pre >= i - 4);
                FOR(j, pre, i) {
                    multiset<int, greater<int>> st;
                    if (j) {
                        st = d[j - 1];
                    }
                    st.insert(vx[i] - vx[j] + 1);
                    chmax(d[i], st);
                    if (i > j) {
                        st = d[j];
                        st.insert(vx[i] - vx[j]);
                        chmax(d[i], st);
                    }
                }
            }
            while (cid + 1 < pre - 1 && cid + 1 < i) {
                d[++cid].clear();
            }
            // dbg(i, vx[i], d[i]);
        }
        vi ans(all(d[L - 1]));
        // multiset<int, greater<int>> a{4, 4}, b{2, 3, 4};
        // dbg(a > b);
        return ans;
    };

    auto solve31 = [&](vii lra, vii lrb) {
        int n = lra.size(), m = lrb.size();
        auto clear = [](vii &lra, vii &lrb) {
            vii nlra;
            for (auto [l, r] : lra) {
                int i = upper_bound(all(lrb), ii{l, INF}) - lrb.begin() - 1;
                if (i >= 0 && i < lrb.size() && lrb[i][0] <= l && lrb[i][1] >= r) {

                } else {
                    nlra.pb({l, r});
                }
            }
            return nlra;
        };
        lra = clear(lra, lrb);
        lrb = clear(lrb, lra);
        n = lra.size();
        m = lrb.size();

        vi xs;
        FOR(i, n) {
            xs.pb(lra[i][0]);
            xs.pb(lra[i][1] + 1);
        }
        FOR(i, m) {
            xs.pb(lrb[i][0]);
            xs.pb(lrb[i][1] + 1);
        }
        auto vx = ccompress(xs);
        int L = vx.size();
        FOR(i, n) {
            lra[i][0] = lower_bound(all(vx), lra[i][0]) - vx.begin();
            lra[i][1] = lower_bound(all(vx), lra[i][1] + 1) - vx.begin();
        }
        FOR(i, m) {
            lrb[i][0] = lower_bound(all(vx), lrb[i][0]) - vx.begin();
            lrb[i][1] = lower_bound(all(vx), lrb[i][1] + 1) - vx.begin();
        }
        // dbg(lra);
        // dbg(lrb);

        vi prea(L, L), preb(L, L);
        FOR(i, n) {
            FOR(j, lra[i][0] + 1, lra[i][1]) {
                prea[j] = lra[i][0];
            }
        }
        FOR(i, m) {
            FOR(j, lrb[i][0] + 1, lrb[i][1]) {
                preb[j] = lrb[i][0];
            }
        }
        // dbg(prea);
        // dbg(preb);
        // dbg(vx);

        vector<multiset<int, greater<int>>> d(L);
        int cid = -1;
        FOR(i, 1, L - 1) {
            d[i] = d[i - 1];
            int pre = min(prea[i], preb[i]);
            assert(pre >= i - 3);
            FOR(j, pre, i - 1) {
                multiset<int, greater<int>> st;
                st = d[j];
                st.insert(vx[i] - vx[j]);
                chmax(d[i], st);
            }
            while (cid + 1 < pre - 1 && cid + 1 < i) {
                d[++cid].clear();
            }
            // dbg(i, vx[i], d[i], pre, cid);
        }
        vi ans(all(d[L - 1]));
        return ans;
    };

    auto solve32 = [&](vii lra, vii lrb) {
        int n = lra.size(), m = lrb.size();
        auto clear = [](vii &lra, vii &lrb) {
            vii nlra;
            for (auto [l, r] : lra) {
                int i = upper_bound(all(lrb), ii{l, INF}) - lrb.begin() - 1;
                if (i >= 0 && i < lrb.size() && lrb[i][0] <= l && lrb[i][1] >= r) {

                } else {
                    nlra.pb({l, r});
                }
            }
            return nlra;
        };
        lra = clear(lra, lrb);
        lrb = clear(lrb, lra);
        n = lra.size();
        m = lrb.size();

        vi xs;
        FOR(i, n) {
            xs.pb(lra[i][0]);
            xs.pb(lra[i][1] + 1);
        }
        FOR(i, m) {
            xs.pb(lrb[i][0]);
            xs.pb(lrb[i][1] + 1);
        }
        auto vx = ccompress(xs);
        int L = vx.size();
        FOR(i, n) {
            lra[i][0] = lower_bound(all(vx), lra[i][0]) - vx.begin();
            lra[i][1] = lower_bound(all(vx), lra[i][1] + 1) - vx.begin();
        }
        FOR(i, m) {
            lrb[i][0] = lower_bound(all(vx), lrb[i][0]) - vx.begin();
            lrb[i][1] = lower_bound(all(vx), lrb[i][1] + 1) - vx.begin();
        }
        // dbg(lra);
        // dbg(lrb);

        vi prea(L, L), preb(L, L);
        FOR(i, n) {
            FOR(j, lra[i][0] + 1, lra[i][1]) {
                prea[j] = lra[i][0];
            }
        }
        FOR(i, m) {
            FOR(j, lrb[i][0] + 1, lrb[i][1]) {
                preb[j] = lrb[i][0];
            }
        }
        // dbg(prea);
        // dbg(preb);
        // dbg(vx);
        auto add = [](vi &a, int x) {
            a.pb(x);
            RFOR(i, a.size() - 1, 1) {
                if (a[i] > a[i - 1]) {
                    swap(a[i], a[i - 1]);
                } else {
                    break;
                }
            }
        };

        vvi d(L);
        int cid = -1;
        FOR(i, 1, L - 1) {
            d[i] = d[i - 1];
            int pre = min(prea[i], preb[i]);
            assert(pre >= i - 3);
            FOR(j, pre, i - 1) {
                auto st = d[j];
                add(st, vx[i] - vx[j]);
                chmax(d[i], st);
            }
            while (cid + 1 < pre - 1 && cid + 1 < i) {
                d[++cid].clear();
            }
            // dbg(i, vx[i], d[i], pre, cid);
        }
        return d[L - 1];
    };

    auto solve4 = [&](vii lra, vii lrb) {
        // int n = lra.size(), m = lrb.size();
        auto clear = [](vii &lra, vii &lrb) {
            vii nlra;
            for (auto [l, r] : lra) {
                int i = upper_bound(all(lrb), ii{l, LINF}) - lrb.begin() - 1;
                if (i >= 0 && i < lrb.size() && lrb[i][0] <= l && lrb[i][1] >= r) {

                } else {
                    nlra.pb({l, r});
                }
            }
            return nlra;
        };
        vvii lr(2);
        lr[0] = clear(lra, lrb);
        lr[1] = clear(lrb, lr[0]);
        vi ans;
        vi id(2);
        while (id[0] < lr[0].size() && id[1] < lr[1].size()) {
            int cid = 0;
            if (lr[1][id[1]][0] < lr[0][id[0]][0]) {
                cid = 1;
            }
            vii seg;
            while (id[cid] < lr[cid].size()) {
                seg.pb(lr[cid][id[cid]++]);
                if (id[1 - cid] < lr[1 - cid].size() && lr[1 - cid][id[1 - cid]][0] > lr[cid][id[cid] - 1][1]) {
                    break;
                }
                cid ^= 1;
            }
            if (seg.size() == 1) {
                ans.pb(seg[0][1] - seg[0][0] + 1);
                continue;
            }
            multiset<int, greater<int>> sfull, swait;
            FOR(i, seg.size()) {
                if (i == 0) {
                    sfull.insert(seg[0][1] - seg[0][0] + 1);
                    swait.insert(seg[1][0] - seg[0][0]);
                } else if (i == seg.size() - 1) {
                    int l1 = seg[i][1] - seg[i - 1][1];
                    int l2 = seg[i][1] - seg[i][0] + 1;
                    sfull.insert(l1);
                    swait.insert(l2);
                    auto nstf = max(sfull, swait);
                    swap(nstf, sfull);
                } else {
                    int l1 = seg[i][1] - seg[i - 1][1];
                    int l2 = seg[i][1] - seg[i][0] + 1;
                    sfull.insert(l1);
                    swait.insert(l2);
                    auto nstf = max(sfull, swait);
                    sfull.erase(sfull.find(l1));
                    swait.erase(swait.find(l2));

                    l1 = seg[i + 1][0] - seg[i - 1][1] - 1;
                    l2 = seg[i + 1][0] - seg[i][0];
                    sfull.insert(l1);
                    swait.insert(l2);
                    auto nstw = max(sfull, swait);

                    swap(nstf, sfull);
                    swap(nstw, swait);
                }
            }
            // dbg(seg);
            // dbg(sfull);
            for (int x : sfull) {
                ans.pb(x);
            }
        }
        FOR(cid, 2) {
            while (id[cid] < lr[cid].size()) {
                auto [l, r] = lr[cid][id[cid]++];
                ans.pb(r - l + 1);
            }
        }
        sort(all(ans), greater<int>());
        return ans;
    };

    auto solve41 = [&](vii lra, vii lrb) {
        // int n = lra.size(), m = lrb.size();
        auto clear = [](vii &lra, vii &lrb) {
            vii nlra;
            for (auto [l, r] : lra) {
                int i = upper_bound(all(lrb), ii{l, LINF}) - lrb.begin() - 1;
                if (i >= 0 && i < lrb.size() && lrb[i][0] <= l && lrb[i][1] >= r) {

                } else {
                    nlra.pb({l, r});
                }
            }
            return nlra;
        };
        vvii lr(2);
        lr[0] = clear(lra, lrb);
        lr[1] = clear(lrb, lr[0]);
        vi ans;
        vi id(2);
        while (id[0] < lr[0].size() && id[1] < lr[1].size()) {
            int cid = 0;
            if (lr[1][id[1]][0] < lr[0][id[0]][0]) {
                cid = 1;
            }
            vii seg;
            while (id[cid] < lr[cid].size()) {
                seg.pb(lr[cid][id[cid]++]);
                if (id[1 - cid] < lr[1 - cid].size() && lr[1 - cid][id[1 - cid]][0] > lr[cid][id[cid] - 1][1]) {
                    break;
                }
                cid ^= 1;
            }
            if (seg.size() == 1) {
                ans.pb(seg[0][1] - seg[0][0] + 1);
                continue;
            }

            auto add = [](vi &a, int x) {
                a.pb(x);
                RFOR(i, a.size() - 1, 1) {
                    if (a[i] > a[i - 1]) {
                        swap(a[i], a[i - 1]);
                    } else {
                        break;
                    }
                }
            };
            vi sfull, swait;
            FOR(i, seg.size()) {
                if (i == 0) {
                    add(sfull, seg[0][1] - seg[0][0] + 1);
                    add(swait, seg[1][0] - seg[0][0]);
                } else if (i == seg.size() - 1) {
                    int l1 = seg[i][1] - seg[i - 1][1];
                    int l2 = seg[i][1] - seg[i][0] + 1;
                    add(sfull, l1);
                    add(swait, l2);
                    auto nstf = max(sfull, swait);
                    swap(nstf, sfull);
                } else {
                    int l1 = seg[i][1] - seg[i - 1][1];
                    int l2 = seg[i][1] - seg[i][0] + 1;
                    auto b0 = sfull, b1 = swait;
                    add(sfull, l1);
                    add(swait, l2);
                    auto nstf = max(sfull, swait);

                    l1 = seg[i + 1][0] - seg[i - 1][1] - 1;
                    l2 = seg[i + 1][0] - seg[i][0];
                    add(b0, l1);
                    add(b1, l2);
                    auto nstw = max(b0, b1);

                    swap(nstf, sfull);
                    swap(nstw, swait);
                }
            }
            // dbg(seg);
            // dbg(sfull);
            for (int x : sfull) {
                ans.pb(x);
            }
        }
        FOR(cid, 2) {
            while (id[cid] < lr[cid].size()) {
                auto [l, r] = lr[cid][id[cid]++];
                ans.pb(r - l + 1);
            }
        }
        sort(all(ans), greater<int>());
        return ans;
    };
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    bool TTT = false;
    // TTT = true;
    if (TTT) {
        uniform_int_distribution<int> dist01(0, 1);
        uniform_int_distribution<int> dist(1, 6); // including both ends
        FOR(T, 10000) {
            vii lra, lrb;
            // int n = 2, m = 1;
            int n = 5, m = 5;
            vi cov(500);
            int lst = 0;
            int mx = 0;
            FOR(i, n) {
                int l = lst + 1 + dist(rng);
                int r = l + dist(rng) - 1;
                lst = r;
                chmax(mx, r);
                FOR(j, l, r) {
                    cov[j] = 1;
                }
                lra.pb({l, r});
            }
            lst = 0;
            FOR(i, m) {
                int l = lst + 1 + dist(rng);
                int r = l + dist(rng) - 1;
                lst = r;
                chmax(mx, r);
                FOR(j, l, r) {
                    cov[j] = 1;
                }
                lrb.pb({l, r});
            }
            int tot = accumulate(all(cov), 0);
            auto ans1 = solve2(lra, lrb);
            auto ans2 = solve4(lra, lrb);
            // int tans = accumulate(all(ans), 0);
            // if (tot != tans) {
            if (ans1 != ans2) {
                dbg(T);
                cerr << n << ' ' << m << nl;
                FOR(i, n) {
                    cerr << lra[i][0] << ' ' << lra[i][1] << nl;
                }
                FOR(i, m) {
                    cerr << lrb[i][0] << ' ' << lrb[i][1] << nl;
                }
                dbg(lrb);
                dbg(ans1);
                dbg(ans2);
                break;
            }
        }
    } else {
        iint(TESTS);
        FOR(T, TESTS) {
            iint(n, m);
            vii lra(n), lrb(m);
            cin >> lra >> lrb;
            auto ans = solve41(lra, lrb);
            cout << ans.size() << nl;
            for (int x : ans) {
                cout << x << ' ';
            }
            cout << nl;
        }
    }
}