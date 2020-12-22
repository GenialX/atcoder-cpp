#include<bits/stdc++.h>
using namespace std;
int main() {
    int maxn=2e5+10;
    int N,M,A[maxn];
    memset(A,0,sizeof A);
    cin>>N>>M;
    A[0]=0;
    for (int i=1;i<=M;++i) cin>>A[i];
    A[M+1]=N+1;
    sort(A+1,A+1+M);
    vector<int> B;
    int md=INT_MAX;
    for (int i=0;i<=M;++i) {
        int d = A[i+1]-A[i]-1;
        //cout<<"i:"<<i<<" d:"<<d<<endl;
        if (d) {
            B.push_back(d);
            //cout<<"d:"<<d<<endl;
            md=min(md,d);
        }
    }
    if (md==INT_MAX) {
        // no white
        cout<<0<<endl;
        return 0;
    }

    int k=md;
    int ans=0;
    for (int i=0;i<B.size();++i) {
        ans += B[i]/k + ((B[i]%k!=0) ? 1 : 0);
    }
    cout<<ans<<endl;
    return 0;
}
