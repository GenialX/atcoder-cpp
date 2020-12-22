#include<bits/stdc++.h>
using namespace std;
int main() {
    long long C[210][210];
    memset(C,0,sizeof C);
    int L;
    cin>>L;
    for (int i=0;i<=205;++i) {
        C[i][0]=1;
        for (int j=1;j<=i;++j) {
            C[i][j] = C[i-1][j]+C[i-1][j-1];
        }
    }
    cout<<C[L-1][11]<<endl;
    return 0;
}
