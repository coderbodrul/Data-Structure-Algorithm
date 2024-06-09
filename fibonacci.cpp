#include <bits/stdc++.h>
#define max_n 100
#define empty_value -1

using namespace std;
using i64 = long long;

int memo[max_n + 1];

int nth_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = nth_fibonacci(n - 1) + nth_fibonacci(n - 2);
    return memo[n];
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    memset(memo, empty_value, sizeof(memo));

    cout << nth_fibonacci(6) << endl;

    return 0;
}
