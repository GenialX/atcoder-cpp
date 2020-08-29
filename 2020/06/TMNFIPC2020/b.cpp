#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, v, w, t;
    cin >> a >> v >> b >> w >> t;
    if (v <= w) {
        cout << "NO" << endl;
        return 0;
    }
    int d = abs(a - b);
    int vv = v - w;
    int tt = d / vv + (d % vv > 0 ? 1 : 0);
    if (tt > t) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
            
    return 0;
}
