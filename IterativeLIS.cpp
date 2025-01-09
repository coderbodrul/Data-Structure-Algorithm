#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> ara(n);
    for (auto &u : ara) cin >> u;

    vector<int> length(n);
    for (int k = 0; k < n; k++) {
        length[k] = 1;
        for (int i = 0; i < k; i++) {
            if (ara[i] < ara[k]) {
                length[k] = max(length[k], length[i] + 1);
            }
        }
    }

    return 0;    
}
