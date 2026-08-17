// Problem: D - Ghostfires
// Platform: codeforces
// Contest: Contest-2209
// Rating/Difficulty: 1800
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2209/submission/387364340
// Solved on: 2026-08-17T09:02:27.556Z

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

    // FOR(lst, 27) {
    //     FOR(r, 7) {
    //         FOR(g, 7) {
    //             FOR(b, 7) {
    //                 iii cnt{r, g, b};
    //                 vi mx;
    //                 vi p;
    //                 int x = lst / 9;
    //                 int y = lst % 9 / 3;
    //                 int z = lst % 3;
    //                 if (x == y || y == z) {
    //                     continue;
    //                 }
    //                 p.pb(x);
    //                 p.pb(y);
    //                 p.pb(z);
    //                 function<void(int)> dfs = [&](int i) {
    //                     if (p.size() > mx.size()) {
    //                         mx = p;
    //                     }
    //                     if (cnt == iii{0, 0, 0}) {
    //                         return;
    //                     }
    //                     FOR(j, 3) {
    //                         if (cnt[j]) {
    //                             if (i && p[i - 1] == j) {
    //                                 continue;
    //                             }
    //                             if (i - 3 >= 0 && p[i - 3] == j) {
    //                                 continue;
    //                             }
    //                             cnt[j]--;
    //                             p.pb(j);
    //                             dfs(i + 1);
    //                             p.pop_back();
    //                             cnt[j]++;
    //                         }
    //                     }
    //                 };
    //                 dfs(3);
    //                 if (mx.size() < r + g + b) {
    //                     int mxv = *max_element(all(cnt));
    //                     int s = accumulate(all(cnt), 0);
    //                     if (mxv > s - mxv + 1) {
    //                         continue;
    //                     }
    //                     if (*min_element(all(cnt)) == 0) {
    //                         continue;
    //                     }
    //                     dbg(cnt, mx);
    //                 }
    //                 if (cnt == iii{2, 2, 2}) {
    //                     dbg(cnt, mx);
    //                 }
    //             }
    //         }
    //     }
    // }
    auto solve1 = [](iii tot) {
        vi ans;
        int mxv = *max_element(all(tot));
        int sv = accumulate(all(tot), 0);
        if (mxv >= sv - mxv + 1) {
            int mxi = max_element(all(tot)) - tot.begin();
            ans.pb(mxi);
            tot[mxi]--;
        }

        while (tot != iii{0, 0, 0}) {
            iii cnt{};
            int mxv = *max_element(all(tot));
            if (mxv > 6) {
                FOR(j, 3) {
                    if (tot[j] == mxv) {
                        cnt[j] += 2;
                        tot[j] -= 2;
                    } else if (tot[j]) {
                        cnt[j]++;
                        tot[j]--;
                    }
                }
            } else {
                cnt = tot;
                tot = {0, 0, 0};
            }
            int len = ans.size();
            vi mx;
            vi p;
            function<bool(int)> dfs = [&](int i) {
                if (p.size() > mx.size()) {
                    mx = p;
                }
                if (cnt == iii{0, 0, 0}) {
                    return true;
                }
                FOR(j, 3) {
                    if (cnt[j]) {
                        if (i && ans[i - 1] == j) {
                            continue;
                        }
                        if (i - 3 >= 0 && ans[i - 3] == j) {
                            continue;
                        }
                        cnt[j]--;
                        ans.pb(j);
                        p.pb(j);
                        if (dfs(i + 1)) {
                            return true;
                        }
                        ans.pop_back();
                        p.pop_back();
                        cnt[j]++;
                    }
                }
                return false;
            };
            // dbg(tot, cnt, ans);
            if (!dfs(len)) {
                ans.insert(ans.end(), all(mx));
                if (mx.size() == 0) {
                    break;
                }
            }
        }
        return ans;
    };
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    bool TTT = false;
    // TTT = true;
    if (TTT) {
        // uniform_int_distribution<int> dist01(0, 1);
        uniform_int_distribution<int> dist(0, 6); // including both ends
        FOR(T, 10000) {
            iii tot;
            FOR(j, 3) {
                tot[j] = dist(rng);
            }
            dbg(tot);
            auto ans1 = solve1(tot);
            // auto ans2 = solve2();
            // if (ans1 != ans2) {
            //     dbg(T);
            //     dbg(ans1);
            //     dbg(ans2);
            //     break;
            // }
        }
    } else {
        iint(TESTS);
        FOR(T, TESTS) {
            iii tot;
            cin >> tot;
            auto ans = solve1(tot);
            string s = "RGB";
            for (int x : ans) {
                cout << s[x];
            }
            cout << nl;
        }
    }
}
// auto solve1 = [](iii tot) {
//     vi ans;
//     while (true) {
//         int s = 0;
//         iii cnt{};
//         FOR(j, 3) {
//             if (tot[j] > 6) {
//                 s++;
//                 cnt[j]++;
//                 tot[j]--;
//             }
//         }
//         int len = ans.size();
//         vi mx;
//         vi p;
//         function<bool(int)> dfs = [&](int i) {
//             if (p.size() > mx.size()) {
//                 mx = p;
//             }
//             if (cnt == iii{0, 0, 0}) {
//                 return true;
//             }
//             FOR(j, 3) {
//                 if (cnt[j]) {
//                     if (i && ans[i - 1] == j) {
//                         continue;
//                     }
//                     if (i - 3 >= 0 && ans[i - 3] == j) {
//                         continue;
//                     }
//                     cnt[j]--;
//                     ans.pb(j);
//                     p.pb(j);
//                     if (dfs(i + 1)) {
//                         return true;
//                     }
//                     ans.pop_back();
//                     p.pop_back();
//                     cnt[j]++;
//                 }
//             }
//             return false;
//         };
//         if (s >= 2) {
//             dbg(ans, cnt);
//             assert(dfs(len) == true);
//             // if (!dfs(len)) {
//             //     ans.insert(ans.end(), all(mx));
//             // }
//         } else if (s == 1) {
//             int mxi = -1;
//             FOR(j, 3) {
//                 if (tot[j] + cnt[j] <= 6 && tot[j]) {
//                     if (mxi == -1 || tot[j] > tot[mxi]) {
//                         mxi = j;
//                     }
//                 }
//             }
//             if (mxi == -1) {
//                 dfs(len);
//                 break;
//             } else {
//                 tot[mxi]--;
//                 cnt[mxi]++;
//                 dfs(len);
//             }
//         } else {
//             cnt = tot;
//             if (!dfs(len)) {
//                 ans.insert(ans.end(), all(mx));
//             }
//             break;
//         }
//     }
//     return ans;
// };