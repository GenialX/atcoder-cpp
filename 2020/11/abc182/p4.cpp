// AC
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
int n;
LL a[N], lmax[N];
int t; // 1, 2, 3,....
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
        //cout << "i:" << a[i] << endl;
    }
    lmax[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        if (a[i] > lmax[i - 1]) {
            lmax[i] = a[i];
        } else {
            lmax[i] = lmax[i - 1];
        }
    }
    LL p = 0, maxp = 0;
    for (int i = 1; i <= n; ++i) {
        p += a[i];
        //cout << "i:" << i << " p:" << p << endl;
        if (maxp < (p - a[i] + lmax[i])) {
            maxp = p - a[i] + lmax[i];
        }
    }
    cout << maxp << endl;
    return 0;
}
