#include <bits/stdc++.h>
#define max_n 100
#define empty_value -1

using namespace std;
using i64 = long long;

int mem[max_n + 1];
int ara[max_n + 1];
int path[max_n + 1];
int n;

int LIS(int i) {
    if (mem[i] != empty_value) return mem[i];
    int ans = 0;
    for (int j = i + 1; j < n; j++) {
        if (ara[j] > ara[i]) {
            int sub_ans = LIS(j);
            if (sub_ans > ans) {
                ans = sub_ans;
                path[i] = j;
            }
        }
    }
    mem[i] = ans + 1;
    return mem[i];
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ara[i];

    for (int i = 0; i < n; i++) mem[i] = empty_value, path[i] = empty_value;

    int ans = 0, start_ind = -1;
    for (int i = 0; i < n; i++) {
        int sub_ans = LIS(i);
        if (sub_ans > ans) {
            ans = sub_ans;
            start_ind = i;
        }
    }

    //path_printing
    cout << "Length of LIS is " << ans << "\n";
    while(start_ind != -1) {
        cout << start_ind << " ";
        start_ind = path[start_ind];
    }

    return 0;
}
