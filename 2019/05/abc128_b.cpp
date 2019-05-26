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

/**
 * 6
 * khabarovsk 20
 * moscow 10
 * kazan 50
 * kazan 35
 * moscow 60
 * khabarovsk 40
 */
int main() {
    int n;
    cin >> n;
    map<string, priority_queue<pair<int, int> > > cop; // city_name -> pair<int, int> ( first -> score, second -> index)
    string line, city;
    int score;
    for (int i = 0; i < n; ++i) {
        cin >> city;
        cin >> score;
        if (cop.find(city) != cop.end()) {
            cop[city].push(make_pair(score, i + 1));
        } else {
            priority_queue<pair<int, int>> q;
            q.push(make_pair(score, i + 1));
            cop[city] = q;
        }
    }

    for (auto p : cop) {
        auto q = p.second;
        while (!q.empty()) {
            auto pa = q.top();
            q.pop();
            cout<<pa.second<<endl;
        }
    }

    return 0;
}
