// AC
#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
const int N = 110;
LD f[N][N][N]; // 以i,j,k为初始状态下，达成任意颜色硬币的数量到100时的期望价值（Expected Value）
int a,b,c; // 初始状态
LD dfs(int aa, int bb, int cc) {
    if(aa==100 || bb==100 || cc==100) return aa-a+bb-b+cc-c;
    LD *ans=&f[aa][bb][cc];
    //cout<<"ans:"<<*ans<<endl;
    if(*ans != -1.0) return *ans;
    int tot=aa+bb+cc;
    *ans=((LD)aa/(LD)tot)*dfs(aa+1,bb,cc);
    *ans+=((LD)bb/(LD)tot)*dfs(aa,bb+1,cc);
    *ans+=((LD)cc/(LD)tot)*dfs(aa,bb,cc+1);
    //cout<<"aa:"<<aa<<" bb:"<<bb<<" cc:"<<cc<<" ans:"<<*ans<<endl;
    return *ans;
}
int main() {
    cin>>a>>b>>c;
    for(int i=0;i<=100;++i)
        for(int j=0;j<=100;++j)
            for(int k=0;k<=100;++k)
                f[i][j][k]=-1;
    auto ans = dfs(a,b,c);
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}
