#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ara;
vector<int> subset;
vector<vector<int>> psubset;


void search(int k) { 
    if (k == n) {
        psubset.push_back(subset);
    }
    else {
        search(k+1);
        subset.push_back(ara[k]);
        search(k+1);
        subset.pop_back(); 
    }
}

 
int32_t main() {

    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ara.push_back(a);
    }
    search(0);
    for (int i = 0; i < psubset.size(); i++) {
        for (int j = 0; j < psubset[i].size(); j++) cout << psubset[i][j] << " ";
            cout << endl;
    }
 
    return 0;
}