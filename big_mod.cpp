#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;

i64 big_mod(i64 a, i64 b) {
    if (b == 0) return 1;
    i64 x = big_mod(a, b / 2);
    x = (x * x) % mod;
    if (b % 2) x = (x * a) % mod;
    return x;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    i64 a, b; cin >> a >> b;
    cout << big_mod(a, b) << endl;

    return 0;
}
