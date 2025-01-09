#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b; cin >> a >> b;
    int n, m;
    n = a.size(), m = b.size();

    int distance[n + 1][m + 1];
    for (int i = 0; i <= m; i++) distance[0][i] = i;

    for (int i = 0; i <= n; i++) distance[i][0] = i;

    auto cost = [&](int i, int j) {
        return !(a[i] == b[j]);
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            distance[i][j] = min({distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i - 1][j - 1] + cost(i - 1, j - 1)});
        }
    }


    return 0;    
}
