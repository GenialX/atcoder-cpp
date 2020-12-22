#include<bits/stdc++.h>
using namespace std;
int solve(int N, int M, int *A, int *B) {
    // N<M
    int ans=M-N;
    int f[M+5][M+5];
    memset(f,0,sizeof f);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            // f[i][j] = f[i-1][j-1] + 1,  i==j
            // f[i][j] = f[i-1][j], f[i][j-1] i!=j
            if (A[i] == B[j]) {
                f[i][j]=f[i-1][j-1]+1;
            }
            f[i][j] = max(f[i][j], f[i-1][j]);
            f[i][j] = max(f[i][j], f[i][j-1]);
            //cout<<"i:"<<i<<" j:"<<j<<" f:"<<f[i][j]<<endl;
        }
    }
    //cout<<"f[i][j]:"<<f[N][M]<<endl;
    ans += (N - f[N][M])*2;
    return ans;
}
int main() {
    int N,M,A[1010],B[1010];
    cin>>N>>M;
    for (int i=1;i<=N;++i) cin>>A[i];
    for (int j=1;j<=M;++j) cin>>B[j];
    int ans;
    if (N<M) {
        ans=solve(N,M,A,B);
    } else {
        ans=solve(M,N,B,A);
    }
    cout<<ans<<endl;
    return 0;
}
