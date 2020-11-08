// AC
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
int main() {
    LL n, t;
    cin >> n;
    t = n;
    if (n % 3 ==0) {
        cout << 0 << endl;
        return 0;
    }
    if (n < 10) {
       cout << -1 << endl;
       return 0;
    }
    int cnt1 = 0, cnt2 = 0, l = 0;
    while (t) {
        LL mod = (t % 10);
        if (mod % 3 == 1) cnt1++;
        if (mod % 3 == 2) cnt2++;
        t /= 10;
        ++l;
    }
    if (n % 3 == 1) {
        if (cnt1 > 0) {
            cout << 1 << endl;
        } else {
            if (cnt2 >= 2 && l > 2) {
                cout << 2 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    } else {
        // 2
        if (cnt2 > 0) {
            cout << 1 << endl;
        } else {
            if (cnt1 >= 2 && l > 2) {
                cout << 2 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    
    return 0;
}
