#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int value[n + 1][m + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> value[i][j];
    }
    
    int sum[n + 1][m + 1];
    memset(sum, 0, sizeof(sum));
    sum[1][1] = value[1][1];

    //first row
    for (int i = 2; i <= m; i++) sum[1][i] += sum[1][i - 1] + value[1][i];
    //first column
    for (int i = 2; i <= n; i++) sum[i][1] += sum[i - 1][1] + value[i][1];

    for (int y = 2; y <= n; y++) {
        for (int x = 2; x <= m; x++) {
            sum[y][x] = max(sum[y][x-1],sum[y-1][x])+value[y][x];
        }
    }


    return 0;    
}
