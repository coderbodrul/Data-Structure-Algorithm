#include <bits/stdc++.h>
#define max_n 100
#define empty_value -1

using namespace std;
using i64 = long long;
const int inf = 1e7;

int weight[max_n + 1][max_n + 1];
int mem[max_n + 1];
int n;

int shortest_length(int u, int n) {

    if (u == n - 1) return 0;
    if (mem[u] != empty_value) return mem[u];

    int ans = inf;
    for (int v = 0; v < n; v++) {
        if (weight[u][v] != inf) {
            ans = min(ans, shortest_length(v, n) + weight[u][v]);
        }
    }
    mem[u] = ans;
    return mem[u];
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int edge;
    cin >> n >> edge;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            weight[row][col] = inf;
        }
    }

    int u, v, w;
    for (int i = 0; i < edge; i++) {
        cin >> u >> v >> w;
        weight[u][v] = w;
    }

    memset(mem, empty_value, sizeof(mem));

    return 0;
}
