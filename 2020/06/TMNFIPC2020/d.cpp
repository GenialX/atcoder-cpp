#include<bits/stdc++.h>
using namespace std;
const int N = 3e5;
int n, q, v[N], w[N];
int f[N], idx[N];
int p(int x) {
    if (x == 1) return -1;
    return x / 2;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }

    cin >> q;

    while (q--) {
        int u, L;
        cin >> u >> L;
        memset(f, 0, sizeof f);
        memset(idx, 0, sizeof idx);
        int cnt = 0;
        while (u > 0) {
            idx[++cnt] = u;
            u = p(u);
        }
        for (int i = 1; i <= cnt; ++i) {
            for (int j = L; j >= w[idx[i]]; --j) {
                f[j] = max(f[j], f[j - w[idx[i]]] + v[idx[i]]);
            }
        }
        cout << f[L] << endl;
    }

    return 0;
}
