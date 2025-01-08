#include<bits/stdc++.h>
#define int long long
using namespace std;


const int inf = 1e7 + 9;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int amo, nOfCoin; cin >> amo >> nOfCoin;

    vector<int> coins(nOfCoin);
    for (auto &u : coins) cin >> u;

    vector<int> result(amo + 1, 0), path(amo + 1);

    result[0] = 1;
    for (int x = 1; x <= amo; x++) {
        for (auto c : coins) {
            if (x - c >= 0) result[x] += result[x - c];
        }
    }

    return 0;    
}
