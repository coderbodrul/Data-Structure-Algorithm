#include <bits/stdc++.h>
#define int long long
#define mx 100

using namespace std;

vector<pair<int, pair<int, int>>> edge;
int par[mx + 1];

int find(int c) {
    if(par[c] == c) return c;
    int p = find(par[c]);
    par[c] = p;
    return p;
} 

void _union(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    par[p1] = p2;
}
 
int32_t main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, e; cin >> n >> e;
    for (int i = 1; i <= n; i++) par[i] = i;
    
    int u, v, w;
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }

    sort(edge.begin(), edge.end());
    vector<pair<int, int>> ans;
    for (int i = 0; i < edge.size(); i++) {
        u = edge[i].second.first;
        v = edge[i].second.second;
        if (find(u) != find(v)) {
            _union(u, v);
            ans.push_back({u, v});
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cerr << ans[i].first << " " << ans[i].second << "\n";
    }

 
    return 0;
}