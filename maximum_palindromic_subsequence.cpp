#include <bits/stdc++.h>
#define int long long
#define mx 10000
using namespace std;

string s;
int dp[mx + 1][mx + 1];

int f(int b, int e) {
    if (b > e) return 0;
    if (b == e) return 1;
    if (dp[b][e] != -1) return dp[b][e];

    if (s[b] == s[e]) dp[b][e] = 2 + f(b + 1, e - 1);
    else dp[b][e] = max(f(b, e - 1), f(b + 1, e));
    return dp[b][e];
}


void solve () {
    cin >> s;
    int b = 0;
    int e = s.size();

    memset(dp, -1, sizeof(dp));

    int ans = 0;

    for (int i = 0; i < e; i++) {
        for (int j = i; j < e; j++)
            ans = max(ans, f(i, j));
    }

    cout << ans << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}