// Problem: E - Wonderful Teddy Bears
// Platform: codeforces
// Contest: Contest-2096
// Rating/Difficulty: 2400
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2096/submission/388413960
// Solved on: 2026-08-26T03:26:33.408Z

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

    auto solve1 = [](string &s) {
        int n = s.size();
        int bc = 0;
        int ans = 0;
        int lst = 0;
        RFOR(i, n - 1, 0) {
            if (s[i] == 'B') {
                bc++;
            } else {
                ans += (bc + 1) / 2;
                if (lst == 1) {
                    if (bc % 2 == 1) {
                        ans--;
                    }
                    lst = 0;
                } else {
                    lst = bc % 2;
                }
            }
        }
        return ans;
    };
    auto solve2 = [](string s) {
        int n = s.size();
        int bc = 0;
        int tot = 0;
        RFOR(i, n - 1, 0) {
            if (s[i] == 'B') {
                bc++;
            } else {
                tot += bc;
            }
        }
        int ans = 0;
        while (tot) {
            // dbg(s);

            bool found2 = false;
            FOR(i, 0, n - 1 - 2) {
                string s0 = s.substr(i, 3);
                if (s0 == "PPB" || s0 == "PBB") {
                    sort(s.begin() + i, s.begin() + i + 3);
                    ans++;
                    tot -= 2;
                    found2 = true;
                } else if (s0 == "BPP" || s0 == "BBP" || s0 == "PPP" || s0 == "BBB") {
                    // no move
                }
            }
            if (!found2) {
                FOR(i, 0, n - 1 - 2) {
                    string s0 = s.substr(i, 3);
                    if (s0 == "PBP" || s0 == "BPB") {
                        sort(s.begin() + i, s.begin() + i + 3);
                        tot--;
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    };
    auto solve3 = [](string &s) {
        int n = s.size();
        int bc = 0;
        int ans = 0;
        int lst = 0;
        RFOR(i, n - 1, 0) {
            if (s[i] == 'B') {
                bc++;
            } else {
                if (lst == 0) {
                    ans += bc / 2;
                    lst = bc % 2;
                } else {
                    if (bc > lst + 1) {
                        int k = (bc - lst) / 2;
                        ans += k;
                    }
                    if (bc % 2 == lst % 2) {
                        ans += lst;
                        lst--;
                    } else {
                        lst++;
                    }
                    // if (bc == lst + 1) {
                    //     lst++;
                    // } else {
                    //     ans += lst;
                    //     lst--;
                    // }
                }
            }
        }
        int k = lst / 2;
        ans += k * (k + 1);
        if (lst % 2 == 1) {
            ans += k + 1;
        }
        return ans;
    };

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    bool TTT = false;
    // TTT = true;
    if (TTT) {
        uniform_int_distribution<int> dist01(0, 1);
        uniform_int_distribution<int> dist(1, 6); // including both ends
        FOR(T, 10000) {
            int n = 19;
            string s(n, ' ');
            FOR(i, n) {
                s[i] = dist01(rng) ? 'B' : 'P';
            }
            auto ans1 = solve3(s);
            auto ans2 = solve2(s);
            if (ans1 != ans2) {
                dbg(T);
                cerr << n << nl;
                cerr << s << nl;
                dbg(ans1);
                dbg(ans2);
                break;
            }
        }
    } else {
        iint(TESTS);
        FOR(T, TESTS) {
            iint(n);
            string s;
            cin >> s;
            cout << solve3(s) << nl;
        }
    }
}