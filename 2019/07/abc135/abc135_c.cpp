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

int main() {
    int n;
    cin >> n;
    vector<int> monsters{}, heros{};
    for (int i = 0, t = 0; i < n + 1; ++i) {
        cin >> t;
        monsters.push_back(t);
    }
    for (int i = 0, t = 0; i < n; ++i) {
        cin >> t;
        heros.push_back(t);
    }
    long carry = 0;
    long sum = 0;
    for (int i = n; i >= 1; --i) {
        long at_cnt = carry + heros[i - 1];
        sum += min(at_cnt, (long)monsters[i]);
        carry = at_cnt - monsters[i] > heros[i - 1] ? heros[i - 1] : at_cnt - monsters[i];
        carry = carry < 0 ? 0 : carry;
    }
    sum += min(carry, (long)monsters[0]);
    cout << sum << endl;
    return 0;
}
