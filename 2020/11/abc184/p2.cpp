#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,x;
    string s;
    cin>>n>>x;
    cin>>s;
    for (auto& c:s) {
        if (c=='o') {
            ++x;
        } else {
            --x;
        }
        if (x < 0) x = 0;
    }
    cout <<x <<endl;
    return 0;
}

