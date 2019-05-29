/**
 * https://atcoder.jp/contests/abc128/tasks/abc128_d
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 6 4
 -10 8 2 1 2 6
 */
int main() {
    int n, k;
    cin >> n >> k;
    if (k <= 0) return 0;
    vector<int> odata(n, 0);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        odata[i] = v;
    }
    int R = min(n, k);

    int ans = 0;
    for (int r = 1; r <= R; ++r) {
        int lk = k - r;
        for (int l = 0; l <= r; ++l) {
            vector<int> data{};
            for (int i = 0; i < l; ++i) {
                data.push_back(odata[i]);
            }
            for (int i = n - 1; n - 1 - i < (r - l); --i) {
                data.push_back(odata[i]);
            }
            sort(data.begin(), data.end());
            int p = 0;
            for (p = 0; p < lk; ++p) {
                if (data[p] >= 0) {
                    break;
                }
            }
            int sum = accumulate(data.begin() + p, data.end(), 0);
            ans = max(ans, sum);
        }
    }
    cout << ans <<endl;
    return 0;
}
