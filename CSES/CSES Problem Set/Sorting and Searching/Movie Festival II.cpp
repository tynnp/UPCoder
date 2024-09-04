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

int n, k, ans;
vector<pair<int, int>> vp;
multiset<int> res;

signed main() {
    fastIO;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    
    sort(vp.begin(), vp.end(), [] (auto x, auto y) {
        return x.second < y.second;
    });
    
    while (k--)
        res.insert(0);
    
    for (int i = 0; i < n; i++) {
        auto it = res.upper_bound(vp[i].first);
        if (it != res.begin()) {
            --it;
            res.erase(it);
            res.insert(vp[i].second);
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}