// https://atcoder.jp/contests/abc185/tasks/abc185_e
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[n+1],b[m+1];
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=m;++i) {
        cin>>b[i];
    }
    int f[n+1][m+1];
    memset(f,0x3f,sizeof f);
    f[0][0] = 0;
    for (int i=0;i<=n;++i) {
        for (int j=0;j<=m;++j) {
            if (i == 0 || j == 0) {
                // f[0][1] = 1, f[3][0] = 3
                f[i][j] = max(i,j);
                continue;
            }
            // 删除 i
            f[i][j] = min(f[i][j], f[i-1][j]+1);
            // 删除 j
            f[i][j] = min(f[i][j], f[i][j-1]+1);
            // 保留 i 和 j
            f[i][j] = min(f[i][j], f[i-1][j-1] + ((a[i] != b[j]) ? 1 : 0));
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
