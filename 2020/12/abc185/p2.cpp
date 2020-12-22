#include<bits/stdc++.h>
using namespace std;
int main() {
    int N,M,T;
    int NN;
    int A[1010],B[1010];
    cin>>N>>M>>T;
    NN=N;
    for (int i=0;i<M;++i) {
        cin>>A[i]>>B[i];
    }
    int t=0;
    for(int i=0;i<M;++i) {
        int ct=A[i], lt=B[i];
        // t -> ct
        N -= (ct-t);
        if (N <= 0) {
            cout<<"No"<<endl;
            return 0;
        }
        // ct -> lt
        N += (lt-ct);
        N=min(N,NN);
        t=lt;
    }
    N -= (T-t);
    if (N <= 0) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;

}
