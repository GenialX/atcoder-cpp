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


unordered_map<int, unordered_map<int, unordered_map<int, int>>> memo;
int gcd(int a, int b, int c) {
    if (memo.find(a) != memo.end() && memo[a].find(b) != memo[a].end() &&
            memo[a][b].find(c) != memo[a][b].end()) {
        return memo[a][b][c];
    }
    int ans = 1;
    int minv = min(a, min(b, c));

    for (int i = minv; i >= 1; --i) {
        if ((a % i) == 0 && (b % i) == 0 && (c % i) == 0) {
            ans = i;
            break;
        }
    }

    memo[a][b][c] = ans;
    return ans;
}

int gcd2(int a,int b) {
    if(a==b)
        return a;
    if(a>b)
        return gcd2(a-b,b);
    if(a<b)
        return gcd2(b-a,a);
    return 0;
}


unordered_map<int, int> memo2;
int main() {
    int k;
    cin >> k;
    int ans = 0;
    for (int a = 1; a <= 200; ++a) {
        for (int b = a; b <= 200; ++b) {
            int key = (a<<8) + b;
            memo2[key] = gcd2(a, b);
        }
    }
    for (int a = 1; a <= k; ++a) {
        for (int b = 1; b <= k; ++b) {
            for (int c = 1; c <= k; ++c) {
                vector<int> nums{a, b, c};
                sort(nums.begin(), nums.end());
   //             cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
                int key = (nums[0] << 8) + nums[1];
                key = (memo2[key] << 8) + nums[2];
                ans += memo2[key];
            }
        }
    }

    cout << ans << endl;
    return 0 ;
}
