// AC
// N 写错了，导致 WA、RE，血的教训
#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
char grid[N][N];
int dist[N][N];
bool vis[30];
int d[5] = {0,1,0,-1,0};
int maxv = 0x3f3f3f3f;
int main() {
    int R, C;
    cin>>R>>C;
    int er,ec;
    memset(dist, 0x3f, sizeof dist);
    memset(vis, false, sizeof vis);
    // 'a' -> {{r,c},{r,c}...}
    vector<vector<pair<int, int>>> pos(30,vector<pair<int,int>>(0));
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            char ch;
            cin>>ch;
            if (ch=='G') {
                er=r,ec=c;
            } else if (ch-'a'>=0 && 'z'-ch>=0) {
                pos[ch-'a'].push_back({r,c});
            }
            grid[r][c] = ch;
        }
    }
    dist[er][ec]=0;
    queue<pair<int, int>> q;
    q.push({er, ec});
    while(!q.empty()) {
        auto po = q.front();q.pop();
        int cch = grid[po.first][po.second];
        int r = po.first, c = po.second;
        //cout<<"cr:"<<r<<" cc:"<<c<<endl;
        for (int di = 0; di<4;++di) {
            int nr = po.first + d[di];
            int nc = po.second +d[di+1];
            if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
            if (dist[nr][nc] != maxv) continue;
            if (grid[nr][nc] == '#') continue;
            dist[nr][nc] = min(dist[nr][nc], dist[r][c] + 1);
            if (grid[nr][nc] == 'S') {
                cout<<dist[nr][nc]<<endl;
                return 0;
            }
            //cout<<"nr:"<<nr<<" nc:"<<nc<<" grid:"<<grid[nr][nc]<<" dist:"<<dist[nr][nc]<<endl;
            q.push({nr, nc});
        }
        if (cch - 'a' >= 0 && 'z' - cch >= 0 && vis[cch-'a']==false) {
            vis[cch-'a']=true;
            // a - z
            //cout<<"cur a-z:"<<cch<<endl;
            if (pos[cch-'a'].size() > 0) {
                for (auto&v:pos[cch-'a']) {
                    if (dist[v.first][v.second] != maxv) continue;
                    dist[v.first][v.second] = dist[r][c] + 1;
                    //cout<<"cur a-z,push:"<<v.first<<" " <<v.second<<" dist:"<<dist[v.first][v.second]<<endl;
                    q.push({v.first, v.second});
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
