#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int d[N], n[N], m[N];
int nn, k, sum;
int main() {
    cin >> nn >> k;
    for (int i = 1; i <= nn; ++i) {
        cin >> n[i];
    }
    memset(m, 0, sizeof m);
    for (int i = 1; i <= k; ++i) {
        sum = 0;
        memset(d, 0, sizeof d);
        for (int j = 1; j <= nn; ++j) {
            sum += d[j];
            m[j]++;
            m[j] += sum;
            if (n[j] > 0) {
                d[j + 1] ++;
                d[j + n[j] + 1 >= N ? N - 1 : j + n[j] + 1] --;
            }
            //cout << "j:" << j << " d[j]:" << d[j] << " sum:" <<sum << endl;
        }
        /**
        cout << "k1:" << i << endl;
        for (int i = 1; i <= nn; ++i) {
            cout << m[i] << " " ;
        }
        cout << endl;
        **/
        memset(d, 0, sizeof d);
        sum = 0;
        for (int j = nn; j >= 1; --j) {
            sum += d[j];
            //m[j]++;
            m[j] += sum;
            if (n[j] > 0) {
                d[j - 1] ++;
                d[j - (n[j] + 1) < 0 ? 0 : j - (n[j] + 1)] --;
            }
        }
        memcpy(n, m, sizeof m);
        memset(m, 0, sizeof m);
        //cout << "k2:" << i << endl;
        /**
        for (int i = 1; i <= nn; ++i) {
            cout << n[i] << " " ;
        }
        cout << endl;
        **/
    }
    for (int i = 1; i <= nn; ++i) {
        cout << n[i] << " " ;
    }
    return 0;
}
