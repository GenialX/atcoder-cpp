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
    f[0][0]=0;
    for(int i=0;i<=n;++i) {
        for(int j=0;j<=m;++j) {
            if (i==0 || j==0) {
                f[i][j] = max(i,j);
                continue;
            }
            f[i][j] = min(f[i][j],f[i-1][j]+1);
            f[i][j] = min(f[i][j],f[i][j-1]+1);
            int col = (a[i] != b[j]) ? 1 : 0;
            f[i][j] = min(f[i][j],f[i-1][j-1] + col);
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
