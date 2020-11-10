#include<bits/stdc++.h>
using namespace std;
const int N=1510, M=5e5+10;;
int h,w,n,m;
int a[M],b[M],c[M],d[M];
int g[N][N],is_lit[N][N]; // 1 for bulbs, 2 for blocks
int main() {
    cin>>h>>w>>n>>m;
    for(int i=0;i<n;++i) {
        cin>>a[i]>>b[i];
        g[a[i]][b[i]]=1;
    }
    for(int i=0;i<m;++i) {
        cin>>c[i]>>d[i];
        g[c[i]][d[i]]=2;
    }
    bool fg=false;
    for(int r=1;r<=h;++r) {
        for(int c=1;c<=w;++c) {
            if(g[r][c]==1) fg=true;
            else if(g[r][c]==2) fg=false;
            if(fg) is_lit[r][c]=1;
        }
        fg=false;
    }
    for(int r=1;r<=h;++r) {
        for(int cc=1;cc<=w;++cc) {
            int c=w-cc+1;
            if(g[r][c]==1) fg=true;
            else if(g[r][c]==2) fg=false;
            if(fg) is_lit[r][c]=1;
        }
        fg=false;
    }
    for(int c=1;c<=w;++c) {
        for(int r=1;r<=h;++r) {
            if(g[r][c]==1) fg=true;
            else if(g[r][c]==2) fg=false;
            if(fg) is_lit[r][c]=1;
        }
        fg=false;
    }
    for(int c=1;c<=w;++c) {
        for(int rr=1;rr<=h;++rr) {
            int r=h-rr+1;
            if(g[r][c]==1) fg=true;
            else if(g[r][c]==2) fg=false;
            if(fg) is_lit[r][c]=1;
        }
        fg=false;
    }
    long long cnt=0;
    for(int r=1;r<=h;++r) {
        for(int c=1;c<=w;++c) {
            if(is_lit[r][c]) ++cnt;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
