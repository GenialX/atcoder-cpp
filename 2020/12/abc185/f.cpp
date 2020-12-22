#include<bits/stdc++.h>
using namespace std;
int B[300010];
int n;
void update(int x, int y) {
    for (int i=x;i<=n;i+=i&-i) {
        //cout<<"i:"<<i<<endl;
        B[x] ^= y;
    }
}
int query(int x) {
    int ans=0;
    //cout<<"query"<<endl;
    for (;x;x-=x&-x) {
        ans ^= B[x];
    }
    return ans;
}
int main() {
    int N,Q;
    cin>>N>>Q;
    memset(B,0,sizeof B);
    n=N;
    int A[300010];
    for (int i=1;i<=N;++i) cin>>A[i];
    while(Q--) {
        int T, x, y;
        cin>>T>>x>>y;
        //cout<<"Q:"<<Q<<endl;
        if (T==1) {
            update(x, y);
        } else {
            int a=query(y),b=query(x-1);
            cout<<(a^b)<<endl;
        }
    }
    return 0;
}
