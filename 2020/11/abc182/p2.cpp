// AC
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k, lcnt = 0;
    for (int i = 1000, cnt = 0; i >= 2; --i) {
        cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] >= i && a[j] % i == 0) ++cnt;
        }
        //cout << "i:" << i << " cnt:" << cnt << endl;
        if (lcnt < cnt) {
            lcnt = cnt;
            k = i;
        }
    }

    cout << k << endl;

    return 0;
}
