/**
 * https://atcoder.jp/contests/abc128/tasks/abc128_c
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(m); // bulb -> vector<int> (the lights id)
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int l;
            cin >> l;
            f[i].push_back(l);
        }
    }
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            int cp = 0;
            for (auto& bi : f[j]) {
                cp += ((i >> (bi - 1)) & 1);
            }
            if ((cp % 2) != p[j]) {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;
    }
    cout << ans << endl;
    return 0;
}
