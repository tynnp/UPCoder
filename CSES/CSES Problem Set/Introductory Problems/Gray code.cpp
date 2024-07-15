#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
vector<string> ans;

signed main() {
    fastIO;
    cin >> n;
    ans.push_back("");
    
    for (int i = 0; i < n; i++) {
        int size = ans.size();
        for (int j = size-1; j >= 0; j--) 
            ans.push_back(ans[j]);
            
        size *= 2;
        for (int j = 0; j < size; j++)
            ans[j] += j < ans.size()/2 ? '0' : '1';
    }
    
    for (string x : ans) 
        cout << x << endl;
    
    return 0;
}