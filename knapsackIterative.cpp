#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int n, nOfObject; cin >> n >> nOfObject;
    int weights[nOfObject + 1];

    weights[0] = 0;
    for (int i = 1; i <= n; i++) cin >> weights[i];

    vector<int> possible(n + 1, 0);
    possible[0] = 1;
    for (int i = 1; i <= nOfObject; i++) {
        for (int x = n; x >= 0; x--) {
            if (possible[x] and x + weights[i] <= n) possible[x + weights[i]] = 1;
        }
    }

    return 0;    
}
