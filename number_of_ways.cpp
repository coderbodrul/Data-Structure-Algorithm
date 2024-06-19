#include <bits/stdc++.h>
#define max_n 100
#define empty_value -1

using namespace std;
using i64 = long long;
int mem[max_n + 1][max_n + 1];
int n, m;
char grid[max_n + 1][max_n + 1];

int f(int i, int j) {
    if (i == n - 1 and j == m - 1) return 1;
    if (i == n or j == m or grid[i][j] == 'x') return 0;
    if (mem[i][j] != empty_value) return mem[i][j];
    mem[i][j] = f(i + 1, j + 1) + f(i + 1, j) + f(i, j + 1);
    return mem[i][j];
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    }

    memset(mem, empty_value, sizeof(mem));
    cout << f(0, 0) << endl;

    return 0;
}
