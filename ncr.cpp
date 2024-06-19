#include <bits/stdc++.h>
#define max_n 100
#define empty_value -1

using namespace std;
using i64 = long long;
int mem[max_n + 1][max_n + 1];
int n, r;

int n_c_r(int r, int n) {
    if (r == n or r == 0) return 1;
    if (r > n) return 0;
    if (mem[r][n] != empty_value) return mem[r][n];

    mem[r][n] = n_c_r(r - 1, n - 1) + n_c_r(r, n - 1);
    return mem[r][n];
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> r;
    memset(mem, empty_value, sizeof(mem));
    cout << n_c_r(r, n) << endl;

    return 0;
}
