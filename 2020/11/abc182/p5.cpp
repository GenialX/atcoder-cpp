// WA
// Bad Solution
// Great Solution https://atcoder.jp/contests/abc182/submissions/17998964
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
            //cout<<"r:"<<r<<" c:"<<c<<endl;
            // row
            int lebb, ribb, lebk, ribk;
            int ribbv=-1, lebbv=-1, lebkv=-1, ribkv=-1;
            ribb = upper_bound(rbb[r].begin(), rbb[r].end(), c) - rbb[r].begin();
            lebb = ribb - 1;
            if (ribb < rbb[r].size()) {
                ribbv = rbb[r][ribb];
            }
            if (lebb >= 0) {
                lebbv = rbb[r][lebb];
            }
            ribk = upper_bound(rbk[r].begin(), rbk[r].end(), c) - rbk[r].begin();
            lebk = ribk - 1;
            if (ribk < rbk[r].size()) {
                ribkv = rbk[r][ribk];
            }
            if (lebk >= 0) {
                lebkv = rbk[r][lebk];
            }
            if (lebbv != -1 && lebbv>lebkv) can=true;
            if (ribbv != -1 && (ribbv<ribkv || ribkv ==-1)) can=true;
            // col
            int ubb, dbb, ubk, dbk;
            int ubbv=-1, dbbv=-1, ubkv=-1, dbkv=-1;
            dbb = upper_bound(cbb[c].begin(), cbb[c].end(), r) - cbb[c].begin();
            if (dbb < cbb[c].size()) {
                dbbv = cbb[c][dbb];
            }
            ubb = dbb - 1;
            if (ubb >= 0) {
                ubbv = cbb[c][ubb];
            }

            dbk = upper_bound(cbk[c].begin(), cbk[c].end(), r) - cbk[c].begin();
            if (dbk < cbk[c].size()) {
                dbkv = cbk[c][dbk];
            }
            ubk = dbk - 1;
            if (ubk>=0) {
                ubkv=cbk[c][ubk];
            }
            if (ubbv!=-1 && ubbv>ubkv) can=true;
            if (dbbv!=-1 && (dbbv<dbkv || dbkv==-1)) can=true;
            //cout <<lebbv<<" "<<ribbv<<" "<<lebkv<<" "<<ribkv<<" "<<ubbv<<" "<<dbbv<<" "<<ubkv<<" "<<dbkv<<endl;
            if(can) {/**cout<<"++"<<endl;**/++cnt;}
        }
    }
    cout<<cnt<<endl;
    return 0;
}
