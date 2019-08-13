#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define PB push_back
#define MP make_pair

using namespace std;

const double eps = 1e-8;

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;

unordered_map<int, int> memo;

int isKValid(vector<int>& d, int k) {
    if (memo.find(k) != memo.end()) return memo[k];
    //cout<<"isKValid k:"<<k<<endl;
    int ecnt = 0, dcnt = 0;
    for (auto& n : d) {
        if (n >= k) dcnt++;
        else ecnt++;
    }
    int ans = 0;
    if (ecnt == dcnt) ans = 0;
    else if (ecnt < dcnt) ans = -1;
    else ans = 1;
    //cout<<"ans:"<<ans<<endl;
    memo[k] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> d(n, 0);
    int l = 0, h = 0, m = 0, lm = 100000, hm = 1;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (lm > d[i]) lm = d[i];
        if (hm < d[i]) hm = d[i];
    }
    int lb = 0, ub = 0;

    // found the upper bound
    l = lm, h = hm;
    int last_m = -1;
    while (l < h) {
        m = (l + h) / 2;
        if (last_m == m) break;
        last_m = m;
        //cout<<"up l:"<<l<<" h:"<<h<<" m:"<<m<<endl;
        int r = isKValid(d, m);
        if (r < 0) {
            // k is small
            l = m + 1;
        } else if (r > 0) {
            // k is big
            h = m;
        } else {
            l = m;
            if (l == h - 1) {
                if (isKValid(d, h) == 0) {
                    l = h;
                    break;
                } else {
                    break;
                }
            }
        }
    }
    ub = l;
    //cout<<"upper bound:"<<ub<<endl;

    // found the lower bound
    l = lm, h = hm;
    last_m = -1;
    while (l < h) {
        m = (l + h) / 2;
        if (last_m == m) break;
        last_m = m;
        //cout<<"lw l:"<<l<<" h:"<<h<<" m:"<<m<<endl;
        int r = isKValid(d, m);
        if (r < 0) {
            // k is small
            l = m + 1;
        } else if (r > 0) {
            // k is big
            h = m;
        } else {
            h = m + 1;
            if (m == l + 1) {
                if (isKValid(d, l) == 0) {
                    break;
                } else {
                    l = m;
                    break;
                }
            }
        }
    }
    lb = l;

    //cout<<"lower bound:"<<lb<<endl;

    if (isKValid(d, ub) == 0 && isKValid(d, ub) == 0) {
        cout<<ub - lb + 1<<endl;
    } else {
        cout<<0<<endl;
    }

    return 0;
}
