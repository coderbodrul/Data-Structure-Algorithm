#include <bits/stdc++.h>
#define max_n 100
#define empty_value -1

using namespace std;
using i64 = long long;
string s, w;
int n, m;
int mem[max_n][max_n];

int LCS(int i, int j) {
    if (mem[i][j] != empty_value) return mem[i][j];
    if (i == n or j == m) return 0;
    if (s[i] == w[j]) mem[i][j] = 1 + LCS(i + 1, j + 1);
    else mem[i][j] = max(LCS(i + 1, j), LCS(i, j + 1));
    return mem[i][j];
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> s >> w;
    n = s.size();
    m = w.size();

    memset(mem, -1, sizeof(mem));

    cout << LCS(0, 0) << endl;

    return 0;
}
