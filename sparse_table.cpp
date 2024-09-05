#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
int t[N][17], a[N];

void build(int n) {
    for (int i = 0; i < n; i++) t[i][0] = a[i];

    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            t[i][k] = t[i][k - 1] | t[i + (1 << (k - 1))][k - 1];
        }
    }
}

int query(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return (t[l][k] | t[r - (1 << k) + 1][k]);
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    
    return 0;
}