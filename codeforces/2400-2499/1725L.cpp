// Problem: L - Lemper Cooking Competition
// Platform: codeforces
// Contest: Contest-1725
// Rating/Difficulty: 2400
// Language: C++20 (GCC 13-64)
// Verdict: Accepted
// URL: https://codeforces.com/contest/1725/submission/388262097
// Solved on: 2026-08-24T15:54:49.088Z

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
int32_t main()
{
#ifndef __APPLE__
    // freopen("exercise.in", "r", stdin);
    // freopen("exercise.out", "w", stdout);
#endif
    //	ifstream in("/Users/a/Downloads/test_input.txt");
    //	cin.rdbuf(in.rdbuf());
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto solve1 = [](vi &a)
    {
        int n = a.size();
        int s = 0;
        FOR(i, n)
        {
            s += a[i];
            if (s < 0)
            {
                return -1ll;
            }
        }
        s = 0;
        assert(n >= 1);
        RFOR(i, n - 1, 0)
        {
            s += a[i];
            if (s < 0)
            {
                return -1ll;
            }
        }
        int ans = 0;
        // multiset -- less_equal
        tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> st;
        // // multiset_erase
        // s.erase(s.find_by_order(x));
        // // because test of equal is !less(a, b) && !less(b, a)
        // s.find_by_order(k); // returns an iterator to the k-th largest element (counting from zero)
        // s.order_of_key(x);  // the number of items in a set that are strictly smaller than x

        // multiset<int> nst;
        int base = 0;
        FOR(i, n)
        {
            if (a[i] >= 0)
            {
                base += a[i];
                // nst.insert(a[i] - base);
                st.insert(a[i] - base);
            }
            else
            {
                int sai = -a[i] - base;
                // find how many of in st is <= n - 1
                int t = st.order_of_key(sai);
                // int t = 0;
                // for (int x : st)
                // {
                // cerr << x + base << ' ';
                //     if (x < sai) {
                //         t++;
                //     }
                // }
                // cerr << nl;
                // cerr << "t: " << t << nl;
                ans += t + 1;
                // nst.insert(sai);
                st.insert(sai);

                if (i + 1 < n)
                {
                    a[i + 1] += a[i];
                }
            }
        }
        return ans;
    };
    iint(n);
    ivi(a, n);
    cout << solve1(a) << nl;
}