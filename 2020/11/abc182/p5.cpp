// Not submitted
#include<bits/stdc++.h>
using namespace std;
const int N = 1510;
int h,w,n,m;
int a[N], b[N], c[N], d[N];
int g[N][N]; // 1 for blocks, 2 for bulbs, 0 for nothing
vector<int> cbb[N], rbb[N], cbk[N], rbk[N];
int main() {
    cin>>h>>w>>n>>m;
    for(int i=0;i<n;++i) {
        cin>>a[i]>>b[i];
        g[a[i]][b[i]]=2;
        rbb[a[i]].push_back(b[i]);
        cbb[b[i]].push_back(a[i]);
    }
    for(int i=0;i<m;++i) {
        cin>>c[i]>>d[i];
        g[c[i]][d[i]]=1;
        rbk[c[i]].push_back(d[i]);
        cbk[d[i]].push_back(c[i]);
    }
    for(int r=1;r<=h;++r) {
        sort(rbb[r].begin(), rbb[r].end());
        sort(rbk[r].begin(), rbk[r].end());
    }
    for(int c=1;c<=w;++c) {
        sort(cbb[c].begin(), cbb[c].end());
        sort(cbk[c].begin(), cbk[c].end());
    }
    int cnt=0;
    for(int r=1;r<=h;++r) {
        for(int c=1;c<=w;++c) {
            //cout<<r<< " "<<c<<" "<<g[r][c]<<endl;
            if(g[r][c]==2) {
                ++cnt;
                continue;
            }
            if(g[r][c]!=0) continue;
            bool can = false;
            cout<<"r:"<<r<<" c:"<<c<<endl;
            // row
            int lebb, ribb, lebk, ribk;
            lebb = lower_bound(rbb[r].begin(), rbb[r].end(), c) - rbb[r].begin();
            ribb = lebb - 1;
            ribk = lower_bound(rbk[r].begin(), rbk[r].end(), c) - rbk[r].begin();
            lebk = ribk - 1;
            if (lebb>lebk || ribb<ribk) can=true;
            // col
            int ubb, dbb, ubk, dbk;
            dbb = lower_bound(cbb[c].begin(), cbb[c].end(), r) - cbb[c].begin();
            ubb = dbb - 1;
            dbk = lower_bound(cbk[c].begin(), cbk[c].end(), c) - cbk[c].begin();
            ubk = dbk - 1;
            if(ubb>ubk || dbb<dbk) can=true;
            cout <<lebb<<" "<<ribb<<" "<<lebk<<" "<<ribk<<" "<<ubb<<" "<<dbb<<" "<<ubk<<" "<<dbk<<endl;
            if(can) {/**cout << "r:" << r << " c:" << c << " +1" << endl;**/++cnt;}
        }
    }
    cout<<cnt<<endl;
    return 0;
}
